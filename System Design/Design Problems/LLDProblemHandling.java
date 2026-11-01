// ----------------------------------- End-to-End LLD Problem Handling & Solving Blueprint ----------------------------------->
// ------------------------------------------------------ Time Management ---------------------------------------------------------------->
// Time budget for a 45-60 minute round : Clarify & scope : 5-8 min - Actors, use cases, non-goals, flow
//                                      : Domain model : 8-10 min - Entities, relationships, signatures
//                                      : Interfaces & patterns : 5-7 min - Extension points identified
//                                      : Implementation : 20-25 min - One flow fully coded, concurrency handled
//                                      : Edge cases & wrap-up : 5-7 min - Vulnerabilities, trade-offs, extensions

// ------------------------------------------------ Phase Wise Goal Distribution --------------------------------------------------------------------------->
// Phase 1 : Goal : Turn a vague prompt (“design a parking lot”) into a written contract.
//         : Find the actors : who or what triggers something in this system? There are three kinds : Human Actors, System Actors, Time as an actor
//                           : Human Actors : customer, admin, driver, attendant etc.
//                           : System actors : a payment gateway, a notification service, a scheduler or timer. These matter because they usually become interfaces.
//                           : Time as an actor : expiry, TTL, overdue fines, cron jobs. Candidates often miss this one.
//                           : Note : For each actor, write what they want to do. Those wishes are your use cases.
//         : Define 3-5 core use cases : Phrase each as Actor + verb + object: “Driver parks a vehicle”, “Driver exits and pays”. Stop at 3-5. Everything else is an extension you will mention later.
//         : Ask clarifying questions in five buckets : Scope : single location or multiple? Which features are in? 
//                                                    : Entities and variants : what types exist (vehicle types, seat categories, user roles)?
//                                                    : Rules : pricing, limits, cancellation, priorities.
//                                                    : Scale and concurrency : can multiple users act at once? (This is a hint that Phase 4 needs locking.)
//                                                    : Failure and edge behavior : what happens if payment fails, the spot is taken, or the request times out?
//                                                    : Note : Don’t ask 30 questions. Ask 6-8 sharp ones, and state your assumption when the interviewer says “your call”.
//         : State non-goals explicitly : Example : “No UI, no DB, no real payment integration (mocked behind an interface), single node, in-memory storage.” This protects you from scope creep and shows seniority.
//         : Write the flow : A 5-7 line numbered happy path plus one or two alternate paths. Keep it on the board as your coding target.

// Phase 2 : Nouns to candidate classes, verbs to methods : Underline nouns in your use cases, then sort each one:
//                                                        : Has identity and a lifecycle : Becomes Entity class. Example : Ticket, Booking, Order
//                                                        : A fixed set of categories : Becomes Enum. Example : VehicleType, SeatStatus
//                                                        : Immutable data with no identity : Becomes Value object. Example : Money, TimeRange, Address
//                                                        : A rule or algorithm : Becomes Interface plus implementations. Example : PricingStrategy
//                                                        : A coordinator of operations : Becomes Service/manager class. Example : ParkingLot, BookingService
//                                                        : A synonym or duplicate : Leave it
//         : Decide where each behavior lives : This is where most designs go wrong. Use three questions:
//                                            : Who owns the data? The class that owns the state should own the behavior that mutates it. Example : A ParkingSpot owns its occupied/free state, so spot.assign(vehicle) belongs on it. Don’t set its fields from outside.
//                                            : Does it involve several entities? If so it belongs in a service/orchestrator. Example : (ParkingLot.park() coordinates the spot, the ticket and the vehicle).
//                                            : Will this rule change or vary? Pull it out behind an interface.
//                                            : Note : Avoid two traps. A god class does everything, so split it. An anemic model has only getters and setters with all logic in one service, so push behavior into the entities.
//         : Relationships : Is-a (inheritance) : use only when subtypes truly behave differently. Prefer composition otherwise. Example: Vehicle with a VehicleType enum beats Car/Bike/Truck subclasses if they don’t differ in behavior.
//                         : Has-a, composition (child cannot exist without the parent) : Floor has Spots.
//                         : Has-a, association (independent lifecycles) : Ticket references a Vehicle.
//                         : Cardinality : state it (1 lot has many floors, 1 floor has many spots).
//         : State machines : Anything with a lifecycle (order, booking, ride, elevator) should be modeled as an enum of states plus the legal transitions. Draw them: CREATED -> PAID -> SHIPPED -> DELIVERED, with CANCELLED allowed from the first two. This also catches bugs and gives you edge cases for free.
//         : Deliverable : Class names, key fields, and method signatures only. State “I’ll fill logic after we agree on the structure”. Get a nod from the interviewer. That checkpoint prevents you from coding the wrong thing for 20 minutes.

// Phase 3 : Interfaces, SOLID and patterns
//         : The extension-point question : For every rule in your requirements, ask: “If the interviewer says ‘now add X’, what changes?” If the answer is “I edit an if-else in a core class”, that rule needs an interface.
//         : Pattern trigger table : Don’t pick patterns first. Recognize triggers...
//         : Rule of thumb : 2-4 patterns max. Name each and say what problem it solves (“Strategy here so pricing can change without touching ParkingLot”).
//         : SOLID as a checklist : S - can you describe each class in one sentence without “and”?
//                                : O - can new variants be added by writing a new class instead of editing old ones?
//                                : L - can any implementation replace its interface without surprising callers?
//                                : I - are interfaces small? (Notifier.send() shouldn’t also carry schedule().)
//                                : D - do high-level services depend on interfaces and receive them through the constructor?
//         : Note : Dependency injection - pass strategies and gateways into constructors. That single habit satisfies D, O and testability.

// Phase 4 : Implementation and concurrency
//         : How much to code : Code one complete vertical slice (the happy flow from Phase 1) in full, compilable. Stub the rest with signatures or a comment. In-memory HashMap/List is perfectly acceptable.
//         : Complexity dial : Start at level 1 and move up only if the interviewer asks.
//                           : L1 - Core : Entities, happy path, one strategy interface (Always, by minute 25)
//                           : L2 - Robust : Validation, state-transition checks, thread safety on hot paths (Default target)
//                           : L3 - Extended : Extra patterns, notifications, retries, multiple strategies (Only if asked or time remains)
//                           : L4 - Distributed : Sharding, consensus, DBs (Never - that’s HLD)
//                           : Note : If you catch yourself designing a message broker in an LLD round, stop and say “that would be the HLD extension”.
//         : Clean-code habits that score points : Meaningful names, early returns and guard clauses instead of nested if-else, small methods, enums instead of strings, custom exceptions (SpotUnavailableException), and immutable fields where possible.
//         : Finding concurrency hotspots : Ask : “Which shared mutable data could two threads change at once?” Hotspots follow a pattern: check-then-act on shared state.
//                                        : Two users book the same seat/spot/room - Both see “available”, both book - Atomic claim on that resource (per-resource lock or atomic compare-and-set)
//                                        : Balance/stock decrement - Lost update - Lock per account/product, or atomic ops
//                                        : Counters and IDs - Duplicate values - AtomicLong
//                                        : Lazy singleton - Two instances - Enum singleton or double-checked locking with volatile
//                                        : Shared collections - Corruption - ConcurrentHashMap, CopyOnWriteArrayList, or guard with a lock
//                                        : Transfers between two accounts - Deadlock - Always lock in a consistent order (for example, by account ID)
//         : Tools, from simplest to most advanced : synchronized on a small critical section.
//                                                 : ReentrantLock (with tryLock(timeout) to avoid hanging).
//                                                 : ConcurrentHashMap atomic ops: computeIfAbsent, putIfAbsent, remove(key, value), compute.
//                                                 : AtomicInteger/AtomicReference with compare-and-set.
//                                                 : Optimistic locking with a version number (retry on conflict).
//                                                 : ReadWriteLock when reads vastly outnumber writes.
//         : Principles : lock at the finest sensible granularity (per spot or per show, not the whole system), keep critical sections tiny, never call external or slow code (payment, network) while holding a lock, and two-phase long flows: reserve with a TTL, then confirm (movie seat hold, then payment).

// Phase 5 : Edge cases and wrap-up
//         : Go through this list out loud, and fix a few in code if time permits
//         : Input validation : null, empty, negative, duplicate IDs, unknown IDs.
//         : Invalid state transitions : paying twice, cancelling a shipped order, exiting without parking.
//         : Resource exhaustion : lot full, no drivers, out of stock. Return a clear result or exception, not a crash.
//         : Failures : payment fails after a spot is reserved. Roll back or compensate (release the hold), and use timeouts and a retry policy with a cap.
//         : Idempotency : operations that may be retried (payment, booking confirm, unpark) must produce the same result. Use an idempotency key or a state check (“already CONFIRMED, return the existing result”).
//         : Expiry : holds and reservations must time out so resources don’t leak.
//         : Time handling : use an injectable clock so the logic is testable.
//         : Extensions : name 2-3 you’d add next and show they fit without rewriting (new vehicle type, new pricing rule, new notification channel).
//         : Trade-offs : say something like “I used one lock per spot for throughput; the cost is slightly more complex code than a global lock.”

// --------------------------------------------------- In Short ----------------------------------------------------------------------->
// My Thought Process : Step 0 - Flow, Requirements & Scope : Clarify Functional Requirements (core user/system actions) and Non-Functional Requirements (concurrency, extensibility, scale).
//                    : Step 1 - Domain Modeling & Extensibility : Identify core Actors and Objects. Anticipate what will change or scale in the future (Open-Closed Principle).
//                    : Step 2 - Properties & State : Define the state and attributes each object needs to hold.
//                    : Step 3 - Behaviors & Core Contracts : Define what actions each object performs (methods/interfaces).
//                    : Step 4 - Relationships & Cardinality : Establish associations (Composition, Aggregation, Association, Inheritance) and cardinality (1:N, N:M).
//                    : Step 5 - Architectural Blueprint (Class Diagram) : Finalize Interfaces, Abstract Classes, concrete Classes, and Enums. Ensure adherence to SOLID principles here to prevent structural refactoring later.
//                    : Step 6 - Design Patterns (Contextual) : Introduce design patterns only where they solve a specific problem. Generally 2-3 are enough
//                    : Step 7 - Concurrency & Thread Safety : Identify shared mutable state, potential race conditions, deadlocks, and select appropriate synchronization mechanisms or thread-safe data structures.
//                    : Step 8 - Implementation & Coding : Write clean, modular code in your chosen language, keeping concurrency considerations baked in from the beginning.
//                    : Step 9 - Resilience, Error Handling, & Edge Cases : Implement input validation, custom exceptions, idempotency checks, memory cleanup/expiries (e.g., TTL caches), and graceful failure recovery.
//                    : Step 10 - Final Walkthrough & Dry Run : Simulate a complex end-to-end execution flow through your code to verify correctness under edge cases.

// There will be some refinement loops : The Code-to-Design Loop (Steps 5 ⇄ 8) : Reason - No matter how clean your class diagram looks on paper, the moment you start writing actual code, you discover hidden tight coupling, missing parameters, or awkward method signatures. This forces you to jump back to Step 5 to adjust your interfaces or abstract classes.
//                                     : The Concurrency-to-State Loop (Steps 2/3 ⇄ 7) : Reason - When you design an object, you might initially give it a simple mutable property (like a balance or a counter). But when you implement multi-threading (Step 7), you realize that property is prone to race conditions. This forces you to loop back to modify the object's behaviors (e.g., adding synchronization, locks, or atomic variables) or change its property structure entirely.
//                                     : The Resilience-to-Behavior Loop (Steps 3 ⇄ 9) : Reason - While handling failures (like database timeouts, invalid states, or retries), you often realize your objects need new behaviors. For example, a PaymentProcessor object suddenly needs a rollback() method or a getState() check that wasn't in your original list of behaviors.