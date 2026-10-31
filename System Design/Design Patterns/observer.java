// -------------------------------------------- Observer Design Pattern ------------------------------------------------->
// -------------------------------------------------- The Problem ------------------------------------------------------------------>
// The Problem : Imagine you are building an e-commerce platform. When a customer places an order, several downstream actions must occur
//             : Like : Send a confirmation email.
//                    : Update warehouse inventory levels.
//                    : Trigger an invoice generation service.
//                    : Notify the logistics and shipping provider.

// A naive implementation inside your OrderService looks like this :
/*
public class OrderService {
    private final EmailService emailService;
    private final InventoryService inventoryService;
    private final InvoiceService invoiceService;
    private final ShippingService shippingService;

    // Constructor injection of all downstream dependencies...

    public void placeOrder(Order order) {
        // 1. Save order to database
        database.save(order);

        // 2. Tightly coupled direct calls
        emailService.sendConfirmationEmail(order);
        inventoryService.updateStock(order);
        invoiceService.generateInvoice(order);
        shippingService.scheduleDispatch(order);
    }
}
*/

// Why This Code Fails (SOLID Violations) : Single Responsibility Principle (SRP) Violation : The OrderService is no longer just managing orders; it is directly orchestrating emails, inventories, invoices, and shipping workflows.Single Responsibility Principle (SRP) Violation: The OrderService is no longer just managing orders; it is directly orchestrating emails, inventories, invoices, and shipping workflows.
//                                        : Open/Closed Principle (OCP) Violation : Every time a new feature is added (e.g., "Send SMS notification" or "Award loyalty points"), you must hack open the OrderService and add another method call.
//                                        : Rigid Dependency Web : Testing OrderService requires mocking four or five unrelated downstream services.

// -------------------------------------------------- The Solution ------------------------------------------------------------------>
// The Solution : The Observer Pattern establishes a one-to-many dependency between objects. The central object (the Subject or Publisher) maintains a list of dependents (Observers or Subscribers).
//              : When the Subject changes state, it broadcasts an update notification to all registered observers automatically, with zero knowledge of what those observers actually do.

// Anatomy of the Observer Pattern : The Subject (Publisher) : The core object whose state changes. It exposes methods to attach, detach, and notify observers.
//                                 : The Observer (Subscriber) Interface : Defines a uniform notification method (e.g., update(State s) or onEvent(Event e)).
//                                 : Concrete Observers : Subsystems that implement the observer interface and react to notifications in their own custom ways.

// Enterprise-Grade Implementation (Java / Event-Driven)
// Let's build a production-grade Order Event Publisher using clean Java interfaces. In modern enterprise systems, this pattern scales from in-memory listeners into distributed message brokers like Kafka or RabbitMQ.
// Step 1 : Define the Event and Observer Interface
/*
public class OrderEvent {
    private final String orderId;
    private final double totalAmount;

    public OrderEvent(String orderId, double totalAmount) {
        this.orderId = orderId;
        this.totalAmount = totalAmount;
    }

    public String getOrderId() { return orderId; }
    public double getTotalAmount() { return totalAmount; }
}

public interface OrderObserver {
    void onOrderPlaced(OrderEvent event);
}
*/

// Step 2 : Implement Concrete Observers (Subscribers)
/*
@Component
public class EmailNotificationListener implements OrderObserver {
    @Override
    public void onOrderPlaced(OrderEvent event) {
        System.out.println("[Email Service] Sending confirmation email for Order: " + event.getOrderId());
    }
}

@Component
public class InventoryUpdateListener implements OrderObserver {
    @Override
    public void onOrderPlaced(OrderEvent event) {
        System.out.println("[Inventory Service] Deducting stock quantities for Order: " + event.getOrderId());
    }
}

@Component
public class LoyaltyPointsListener implements OrderObserver {
    @Override
    public void onOrderPlaced(OrderEvent event) {
        System.out.println("[Loyalty Service] Crediting reward points for Order total: $" + event.getTotalAmount());
    }
}
*/

// Step 3 : Build the Subject (Publisher / Event Dispatcher)
/*
@Component
public class OrderEventPublisher {
    private final List<OrderObserver> observers = new CopyOnWriteArrayList<>();

    // Spring automatically injects all beans implementing OrderObserver
    public OrderEventPublisher(List<OrderObserver> observers) {
        this.observers.addAll(observers);
    }

    public void subscribe(OrderObserver observer) {
        observers.add(observer);
    }

    public void unsubscribe(OrderObserver observer) {
        observers.remove(observer);
    }

    public void publishOrderPlaced(OrderEvent event) {
        System.out.println("Publishing Order Placed event for ID: " + event.getOrderId());
        for (OrderObserver observer : observers) {
            observer.onOrderPlaced(event); // Broadcast notification
        }
    }
}
*/

// Step 4 : Clean Service Integration
/*
@Service
public class OrderPlacementService {
    private final OrderEventPublisher eventPublisher;

    public OrderPlacementService(OrderEventPublisher eventPublisher) {
        this.eventPublisher = eventPublisher;
    }

    public void placeOrder(String orderId, double amount) {
        // Core business logic: Validate and save order to database...
        System.out.println("Order " + orderId + " successfully persisted to database.");

        // Publish event — Zero awareness of emails, inventory, or loyalty points!
        eventPublisher.publishOrderPlaced(new OrderEvent(orderId, amount));
    }
}
*/

// Rest you will learn buy implementing this pattern in solving problems

// -------------------------------------------------- Nuances, Gotchas, and Best Practices ------------------------------------------------------------------>
// The Lapsed Listener Problem (Memory Leaks) : Gotcha : If an observer registers with a long-lived subject but fails to unregister when it is destroyed, the subject holds a strong reference to the observer. This prevents the garbage collector from reclaiming memory, leading to severe memory leaks.
//                                            : Fix : Use WeakReference collections where appropriate, or ensure explicit cleanup (unsubscribe()) when lifecycle boundaries are crossed (e.g., closing UI components). In containerized frameworks like Spring, singleton beans rarely face this because both publisher and listeners live for the entire app lifecycle.

// Synchronous Blocking & Cascading Failures : Gotcha : By default, standard observer notification loops execute synchronously on the publisher's thread. If the EmailNotificationListener hangs or throws an exception due to a third-party API timeout, it blocks the entire OrderPlacementService transaction.
//                                           : Fix : Wrap observer notification logic in asynchronous dispatchers or thread pools (CompletableFuture.runAsync(), or Spring's @Async event listeners) so that slow subscribers never bottleneck core transaction flows.

// Order of Execution Uncertainty : Gotcha : Relying on a specific execution sequence among observers (e.g., expecting Inventory to update before Email sends) is dangerous. Standard lists iterate in registration order, which can shift unpredictably during refactoring.
//                                : Fix : If execution order matters, your architecture is likely evolving past a simple observer pattern into a pipeline or workflow engine. Explicitly sort observers using priority annotations or orchestrate them via a saga pattern.

// -------------------------------------------------- When to Use vs. When NOT to Use ------------------------------------------------------------------>
// When to Use (Triggers) : A change to one object requires changing others, and you don't know beforehand how many objects need to be changed.
//                        : You want to decouple core business domain logic from cross-cutting side effects (logging, auditing, notifications).
//                        : Building event-driven UI architectures, pub/sub loggers, or reactive stream handlers.

// When NOT to Use : The notification flow must be strictly sequential, transactional, and roll back entirely if any single subscriber fails.
//                 : You only have a single, direct, hardcoded dependency that will never expand or change.
//                 : The overhead of asynchronous event tracking introduces unnecessary debugging complexity for simple procedural scripts.

// ---------------------------------------- How to Spot Strategy Opportunities in System Design ------------------------------------------------------------------>
// Note : Whenever you notice a core service triggering a cascade of secondary notifications (sendEmail(), updateAuditLog(), triggerWebhook(), invalidateCache()), you are looking at a classic candidate for the Observer Pattern.
// Examples across domains : UI Frameworks : Button click listeners (OnClickListener) updating view states.
//                         : Caching Layers : Database write operations notifying cache managers to evict stale keys.
//                         : Webhooks : Subscription dispatchers firing HTTP POST payloads to external partner endpoints when tenant events occur.

// Always to explore, know & learn more...