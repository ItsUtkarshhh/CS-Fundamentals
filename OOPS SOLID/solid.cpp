// -------------------------------------- SOLID Overview & Quick Notes ------------------------------------>
// -------------------------------- Syllabus : Most Important Topics & Concepts ------------------------------------------->
// S - Single Responsibility Principle (SRP)
//   - One reason to change
//   - Cohesion vs. Responsibility separation
//   - Code smell identification & Refactoring strategies
// O - Open/Closed Principle (OCP)
//   - Open for extension, closed for modification
//   - Achieving OCP via Abstraction, Interfaces, and Polymorphism
// L - Liskov Substitution Principle (LSP)
//   - Subtypes must be substitutable for their base types
//   - Behavioral subtyping and Design by Contract
//   - LSP Violations (e.g., Square-Rectangle problem, throwing UnsupportedOperationException)
// I - Interface Segregation Principle (ISP)
//   - No client should be forced to depend on methods it does not use
//   - Fat/Bloated Interfaces vs. Role Interfaces
// D - Dependency Inversion Principle (DIP)
//   - High-level modules should not depend on low-level modules; both should depend on abstractions
//   - Abstractions should not depend on details; details should depend on abstractions
//   - Dependency Injection (DI) vs. Inversion of Control (IoC)
// GRASP & Complementary Principles
// Law of Demeter (Principle of Least Knowledge / "Don't talk to strangers")
// DRY (Don't Repeat Yourself) & KISS (Keep It Simple, Stupid)
// YAGNI (You Aren't Gonna Need It)

// ---------------------------------------------------------------------------------------------------------------------------->
// S - Single Responsibility Principle
// The Idea : A class should have one reason to change.
// Interview Based Explanation : Single Responsibility Principle says that a class should have one reason to change. It encourages high cohesion by keeping closely related responsibilities together while separating unrelated responsibilities. This makes code easier to test, understand, and modify.
// Scenario : Violating : class Employee { calculateSalary() saveToDatabase() generateReport() sendEmail() }
//          : Compliant : class SalaryCalculator { calculateSalary() }
//                      : class DatabaseSaver { saveToDatabase() }
//                      : class ReportGenerator { generateReport() }
//                      : class EmailService { sendEmail() }
// Pros : smaller classes, easier testing, easier debugging, lower coupling, easier code reviews, better separation of concerns
// Trade offs : Too many small classes can make code harder to navigate

// O - Open Closed Principle
// The Idea : Software entities should be open for extension but closed for modification.
// Interview Based Explanation : The Open/Closed Principle says that software should be open to extension but closed to modification. New behavior should ideally be introduced through abstractions and polymorphism without repeatedly modifying stable existing code.
// Scenario : Violating : class PaymentService { if("UPI") {...} if("CC") {...} }
//          : Compliant : interface PaymentService { pay(); }
//                      : class UPIPaymentService implements PaymentService { pay() {...} }
//                      : class CCPaymentService implements PaymentService { pay() {...} }
// Misconception : "Never modify existing code."
// Design stable areas of the system so that predictable new variations can be introduced through extension rather than repeatedly modifying core logic.
// Trade offs : Too many abstractions can cause over-engineering

// L - Liskov Substitution Principle
// The Idea : Objects of a subtype should be usable wherever objects of the parent type are expected without breaking the correctness of the program.
//          : If B is truly a subtype of A, replacing A with B should not break the program's expected behavior.
// Interview Based Explanation : Liskov Substitution Principle states that subtypes must honor the behavioral contract of their base types so that they can be substituted for those base types without breaking client expectations.
// Scenario Example : Bird & FlyingBird problem with Penguin & Sparrow
// Trade offs : May require redesigning inheritance hierarchies or using composition

// I - Interface Segregation Principle
// The Idea : Clients should not be forced to depend on methods they don't use.
//          : Prefer several small, focused interfaces over one giant interface.
// Interview Based Explanation : Interface Segregation Principle says that clients should not be forced to depend on methods they do not use. Interfaces should be cohesive and focused around the needs of their clients.
// Scenario Example : Worker & Robot Problem
//                  : Worker has multiple responsibilities : eat() sleep() attendMeeting() code() work(), but robot need not to have eat() & sleep() responsibilities.
//                  : Due to which, Robot cannot implement Worker
//                  : Better Design : Interfaces - Workable {} Sleepable{} Eatable {} & Human class can implement all these, but Robot class can only implement Workable {}
// Pros : fewer unnecessary dependencies, simpler implementations, easier mocking, easier testing, lower coupling, clearer APIs, better separation of responsibilities.
// Trade offs : Too many small interfaces can cause fragmentation

// D - Dependency Inversion Principle
// The Idea : High-level modules should not depend directly on low-level implementation details. Both should depend on abstractions.
//          : Abstractions should not depend on details; details should depend on abstractions.
// Interview Based Explanation : 
// Scenario Example : Suppose OrderService which is a "High Level Component" & it needs to save orders using MySQL which is a "Low Level Component"
//                  : Here the high level component "OrderService" is directly depending on the low level implementation details of "saving the order"
//                  : Solution is create an interface OrderRepository with a save() method. Now let MySQLOrderRepository class implement this interface & its details.
//                  : Now, OrderService can simply use the reference of OrderRepository, and if client passes the object of MySQLOrderRepository, the dependency will be injected automatically.
//                  : Decouples the system, but not enforcing strict implementation onn the OrderService class.
// Dependency Inversion vs Dependency Injection : These are not the same thing.
//                                              : First one is a design principle, concept & idea & second one is a technique to provide dependencies which basically helps to implement that principle.
// Trade offs : Adds interfaces, indirection, and configuration

// Important : Don't apply SOLID blindly. Use it when the benefit of reducing coupling or handling future change is greater than the complexity introduced by the abstraction.
//           : More change / variation - More value from SOLID
//           : Less change / simple code - Keep it simple

// ----------------------------------------------------------------------------------------------------------------------------------------------------->
// The GRASP Principles (General Responsibility Assignment Software Patterns (or Principles)) :
// 1. Controller : Assign system/event handling responsibilities to a suitable controller.

// 2. Information Expert : Give a responsibility to the class that has the information needed to perform it.

// 3. Creator : A class should create another object when it closely uses, contains, or has the information needed to create it.

// 4. Low Coupling : Keep dependencies between classes as low as reasonably possible.

// 5. High Cohesion : Keep closely related responsibilities together.

// 6. Law of Demeter : Principle of Least Knowledge
//                   : An object should know as little as possible about the internal structure of other objects.
//                   : Trade offs : Strictly following Law of Demeter everywhere can create too many forwarding methods. Use it to protect meaningful boundaries, not to eliminate every method chain.

// 7. DRY - Don't Repeat Yourself : Avoid duplicating knowledge or business logic in multiple places.
//                                : DRY is about duplicated knowledge/logic, not simply identical-looking code.

// 8. KISS — Keep It Simple, Stupid : Prefer the simplest design that correctly solves the problem.
//                                  : Don't introduce complexity just to demonstrate design patterns or SOLID.
//                                  : Trade offs : Too much simplicity can eventually make code difficult to extend.Too much simplicity can eventually make code difficult to extend.

// 9. YAGNI — You Aren't Gonna Need It : Don't build functionality or abstractions before you actually need them.
//                                     : YAGNI protects against premature abstraction, unnecessary code, unnecessary complexity, wasted development time.
//                                     : But don't use YAGNI as an excuse for ignoring obvious architectural boundaries.

// ----------------------------------------------------------------------------------------------------------------------------------------------------->
// Rest explore codebases, use your thinking & learn more.