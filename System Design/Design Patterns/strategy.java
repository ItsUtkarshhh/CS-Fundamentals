// -------------------------------------------- Strategy Design Pattern ------------------------------------------------->
// -------------------------------------------------- The Problem ------------------------------------------------------------------>
// Problem : Imagine you are building an e-commerce checkout engine. Customers can pay via Credit Card, PayPal, UPI, or Crypto.
//         : A Naive Implementation would look like this :

/* 
class CheckoutService {
    public void processPayment(String paymentType, double amount) {
        if (paymentType.equals("CREDIT_CARD")) {
            // 50 lines of credit card validation and gateway calls
            System.out.println("Processing credit card of $" + amount);
        } else if (paymentType.equals("PAYPAL")) {
            // 40 lines of PayPal OAuth and API calls
            System.out.println("Processing PayPal of $" + amount);
        } else if (paymentType.equals("UPI")) {
            // 30 lines of UPI VPA verification
            System.out.println("Processing UPI of $" + amount);
        } else {
            throw new IllegalArgumentException("Unsupported payment type");
        }
    }
}
*/

// Why This Code Fails (SOLID Violations) : Open/Closed Principle (OCP) Violation : Every time you add a new payment method (e.g., Apple Pay), you must modify this class, risking regressions in working code.
//                                        : Single Responsibility Principle (SRP) Violation : The CheckoutService is doing two distinct things: managing the checkout flow and knowing the internal implementation details of every payment gateway.
//                                        : Cyclomatic Complexity Explosion : As conditional branches multiply, readability plummets, and unit testing becomes a combinatorial nightmare.

// -------------------------------------------------- The Solution ------------------------------------------------------------------>
// The Solution : The Strategy Pattern extracts each branch of that conditional monster into its own dedicated class implementing a common interface. The context delegates the execution without knowing or caring how the underlying algorithm works.
// Anatomy of the Strategy Pattern : The Strategy Interface (PaymentStrategy) : Defines the contract that all concrete algorithms must follow.
//                                 : Concrete Strategies (CreditCardStrategy, PayPalStrategy) : Encapsulate specific algorithmic implementations.
//                                 : The Context (CheckoutService) : Maintains a reference to a strategy object and delegates execution to it.

// More you will understand while actually implementing it whole solving multiple problems.

// -------------------------------------------------- Nuances, Gotchas, and Best Practices ------------------------------------------------------------------>
// Statelessness & Thread Safety : Best Practice : Strategies should almost always be stateless. Because services and strategy beans are typically singletons in containers like Spring
//                                               : Holding mutable state (like instance variables storing user data or transaction amounts) inside a strategy will cause severe race conditions in concurrent multi-threaded environments.
//                               : Fix : Pass required data as parameters into the strategy method (strategy.pay(amount, userContext)) rather than storing state in the strategy object.

// Strategy Parameterization Discrepancies : Gotcha : What happens when different strategies require completely different parameter sets? (e.g., Credit Card needs CVV and card number; Crypto needs wallet address and gas fee).
//                                         : Fix : Avoid forcing a rigid method signature if strategies vary widely. Instead, pass a generic Context or Payload object (e.g., pay(PaymentRequest request)), or have the concrete strategy extract what it needs from a shared payload.

// Combining with Factory or Registry : Never let client code instantiate concrete strategies (new CreditCardStrategy()). Use either a Factory Pattern or a Spring Bean Registry Map to hide creation and selection logic from the caller.

// -------------------------------------------------- When to Use vs. When NOT to Use ------------------------------------------------------------------>
// When to Use (Triggers) : You have multiple conditional branches (if-else/switch) executing variations of the same business operation.
//                        : Algorithms need to be swapped, tested, or mocked independently at runtime.
//                        : Business rules change frequently per client, region, or tier (e.g., tax calculation engines, routing algorithms, pricing tiers).

// When NOT to Use : You only have 1 or 2 straightforward code paths that are guaranteed never to change or expand.
//                 : The overhead of creating multiple interfaces and classes obscures simple business logic rather than clarifying it.
//                 : The behaviors share little to no structural similarity, meaning forcing them into an interface is artificial.

// ---------------------------------------- How to Spot Strategy Opportunities in System Design ------------------------------------------------------------------>
// Note : Whenever you encounter a requirement containing phrases like "depending on," "based on the type," "dynamically calculated," or "pluggable rules," think Strategy Pattern immediately.
// Examples across domains : Export Engines : Exporting reports to PDF, CSV, Excel, or JSON.
//                         : Pricing & Discount Engines : Applying seasonal discounts, VIP tier discounts, or coupon codes.
//                         : Authentication Providers : Authenticating via OAuth2, LDAP, JWT, or API Key.
//                         : Notification Dispatchers : Sending alerts via Email, SMS, Push Notification, or Slack Webhook.

// Always to explore, know & learn more...