// -------------------------------------- OOPS Overview & Quick Notes ------------------------------------>
// -------------------------------- Syllabus : Most Important Topics & Concepts ------------------------------------------->
// 1. Imperative & Declarative Programming Paradigms
// 2. Object-Oriented vs. Procedural vs. Functional Paradigm
// 3. Objects, Classes, and State Management
// 4. Message Passing & Method Execution Flow
// 5. Encapsulation : Data Hiding, Invariants, Accessors vs. Mutators
// 6. Abstraction : Interface vs. Implementation, Hiding Complexity
// 7. Inheritance : "Is-A" Relationship, Code Reusability vs. Tight Coupling
// 8. Polymorphism : "One Interface, Multiple Forms", Static vs. Dynamic Binding
// 9. Relationships between objects : Association, Aggregation, Composition
// 10. Association (Unidirectional / Bidirectional)
// 11. Aggregation ("Has-A" / Weak Ownership)
// 12. Composition ("Part-Of" / Strong Ownership & Shared Lifetime)
// 13. Delegation & Forwarding
// 14. Inheritance vs. Composition ("Favor Composition over Inheritance")
// 15. Tight Coupling vs. Loose Coupling
// 16. High Cohesion vs. Low Cohesion
// 17. Fragile Base Class Problem
// 18. Anemic Domain Model vs. Rich Domain Model
// 19. God Object / Spaghetti Code Anti-Patterns

// ------------------------------------------- Short & Quick Notes ------------------------------------------->
// Imperative vs. Declarative Programming Paradigms
// Programming paradigms define how a software system structures its execution logic and state modifications.
// Imperative : Focuses on HOW to achieve a result. You write explicit, step-by-step instructions that mutate state over time.
//            : Examples : C, C++, Java, Python, Javascript, PHP etc.
// Declarative : Focuses on WHAT result you want. You express the desired outcome/logic without explicitly detailing control flow or step-by-step state changes.
//             : Examples : SQL, HTML, CSS etc

// Imperative Sub-Paradigms : Imperative programming splits primarily into Procedural and Object-Oriented approaches. Both focus on state mutation and step-by-step execution, but they organize code differently.
//                          : Procedural Programming : Code is structured around procedures (also known as functions or subroutines) operating on shared data structures.
//                                                   : Key Characteristics : Data and logic are decoupled. Data structures are passive entities passed into global or standalone functions.
//                                                   : As programs scale, tracking which function modified global or shared state becomes difficult.
//                                                   : Example : C etc.
//                          : Object-Oriented Programming (OOP) : Code is structured around Objects that bundle data (state) and behavior (methods) together into a single cohesive unit.
//                                                              : Key Characteristic : Data hiding and encapsulation. Objects control their own internal state; external code interacts only via public interfaces.
//                                                              : Example : C++ & Java etc.

// Declarative Sub-Paradigms : Declarative programming splits into Functional and Logic / Domain-Specific approaches, focusing on expressions and rules rather than step-by-step state changes.
//                           : Functional Programming (FP) : Computation is treated as the evaluation of pure mathematical functions, avoiding mutable state and side effects.
//                                                         : Key Mechanisms : First-class functions, immutability, higher-order functions (map, filter, reduce), and function composition.
//                                                         : Example : Javascript, Modern Java etc.
//                           : Logic / Rule-Based Programming : Programmers declare a set of facts and rules (the knowledge base). The execution engine uses an inference engine (like unification or resolution) to deduce answers to queries.
//                                                            : Key Characteristics : No explicit algorithms, loops, or functions are defined. You state relationships, and the language runtime computes the solution space.
//                                                            : Example : ProLog
//                           : Database Query Languages (Domain-Specific Declarative) : Expresses what data to select, project, join, or aggregate without detailing index traversal algorithms or disk I/O routines.
//                                                                                    : Example : SQL etc.

// Object Identity vs. Equality : How different languages determine if two instances are identical in memory vs. equivalent in state.
//                              : In language-agnostic software architecture, objects are defined by three properties: State, Behavior, and Identity.
//                              : Identity (== reference check) : Refers to whether two object variables point to the exact same memory location.
//                              : Equality (equals() or == overload) : Refers to whether two distinct objects hold equivalent state data inside.
//                              : Example : Object A (Memory: 0x1000) -> { id: 101, name: "Alice" }
//                                        : Object B (Memory: 0x2000) -> { id: 101, name: "Alice" }
//                                        : A == B - FALSE (Different Identity / Memory locations)
//                                        : A.equals(B) - TRUE  (Identical Value / State)

// State Management: Mutable vs. Immutable Objects
// In C++, state is typically mutable. However, in enterprise architecture and concurrent programming, Immutable Objects are vital for safety.
// Mutable State (Classic OOP) : Object fields can be modified after creation.
//                             : Risk : Concurrent access leads to race conditions and unintended side effects across shared references.
// Immutable State : Once an object is initialized, its state can never change. Operations return a new object instance with updated state instead of modifying the existing one.

// Message Passing : Message passing means one object communicates with another object by requesting it to perform some action.
// Method/Function Calling : Method calling is the actual process of invoking/executing a method (member function) of an object.
// These two are more or less the same thing, just difference between perspectives.

// Encapsulation :
// Data Hiding : Data hiding is the mechanism of concealing the internal state of an object from external intervention.
//             : Implemented using access modifiers - "private", "public" & "protected"
// Class Invariants : An invariant is a logical condition or rule that must always hold true for an object throughout its entire lifecycle (after construction and between method calls).
//                  : Example : In a BankAccount class, an invariant might be balance >= 0. Without data hiding, external code could set balance = -500.00, violating the invariant.
// Accessors & Mutators : To allow controlled interaction with hidden data, classes expose standard method types: Accessors and Mutators.
//                      : Implemented using getters & setters

// Abstraction : 
// Interface vs Implementation : This distinction separates the contract exposed to the outside world from the internal mechanics that fulfill that contract.
//                             : Interface (The "What") : Defines the public contract or behavior an object promises to provide, without exposing any underlying logic.
//                             : Implementation (The "How") : The actual concrete execution details, algorithms, and data structures used to fulfill that contract.
// Hiding Complexity : Abstraction allows developers to work with high-level concepts without needing to understand all the low-level execution steps underneath.
//                   : Benefit : Code using an abstract interface remains decoupled from implementation details. If the underlying engine changes, the driver's interface stays the same.
// Abstract Classes vs. Interfaces : In object-oriented languages (like Java or C++), abstraction is primarily enforced using two tools
//                                 : Interface : Defines a pure behavioral contract ("can-do" relationship).
//                                             : Cannot hold instance state (only public static final constants).
//                                             : Traditionally pure abstract methods (until Java 8 default methods).
//                                             : A class can implement multiple interfaces.
//                                 : Abstract Class : Serves as a partially implemented base class ("is-a" relationship).
//                                                  : Can hold member variables and instance state.
//                                                  : Can mix abstract methods with fully implemented concrete methods.
//                                                  : A class can extend only one abstract class (single inheritance).

// Polymorphism :
// "One Interface, Multiple Forms" : You define a single method contract in a parent class or interface, but each subclass provides its own specific implementation.
// Static Binding : Multiple methods in the same class share the same name but have different parameters.
// Dynamic Binding : A subclass provides a specific implementation of a method already defined in its superclass/interface.

// Objects Relationships
// Object relationships represent varying degrees of coupling. They exist on a spectrum based on ownership and lifecycle dependency.
// Association (Loose Link) : Association represents a binary relationship between two independent objects. It expresses a link where objects know about each other and use each other's services, but neither object owns the other.
//                          : Lifecycle : Completely independent. Creating or destroying one object has zero impact on the other.
//                          : Multiplicity : Can be 1 to 1, 1 to N, or N to M.
//                          : Real-world Analogy : A Doctor and a Patient. A doctor treats many patients; a patient visits many doctors. Destroying a doctor record does not delete the patient.
// Aggregation ("Has-A" Weak Ownership) : Aggregation is a specialized form of Association that represents a "Has-A" relationship with weak ownership.
//                                      : Lifecycle : Independent. The container object holds references to child objects, but the child objects can exist outside the scope of the parent.
//                                      : Shared Ownership : The child object can belong to multiple parent objects simultaneously.
//                                      : Real-world Analogy : A Department and a Teacher. A department has teachers. If the department is closed down, the teachers still exist; they can simply move to another department.
// Composition ("Has-A" Strong Ownership) : Composition is a strict, specialized form of Aggregation representing "Has-A" with strong ownership and shared lifecycles.
//                                        : Lifecycle : Dependent. The child object cannot exist independently of the parent. When the parent object is destroyed, all of its composed child objects are destroyed along with it.
//                                        : Exclusive Ownership : The child object belongs to exactly one parent container.
//                                        : Real-world Analogy : A Building and a Room (or a Car and its Engine). A room cannot exist without a building. If the building is demolished, the rooms are destroyed.

// Composition vs Inheritance :
// Why Inheritance Fails at Scale : The Fragile Base Class Problem : Inheritance creates a tight coupling between parent and child classes. If a developer alters an internal method implementation in a parent class, it can unexpectedly break subclasses that override or invoke that method.
//                                : Rigid Compile-Time Hierarchies : Inheritance is static and defined at compile time. An object cannot change its superclass behavior dynamically at runtime.
//                                : Violation of Encapsulation : Inheritance exposes the internal implementation details of the parent class to child classes (protected fields/methods), breaking encapsulation barriers.
// How Composition Solves These Problems : Instead of inheriting behavior, a class delegates work to composed objects that implement specific behaviors.
//                                       : Runtime Flexibility : You can change an object's behavior at runtime simply by injecting a different instance implementation (e.g., swapping V8Engine for ElectricEngine).
//                                       : Loose Coupling : The Vehicle class only depends on the Engine interface, not concrete engine implementations.
//                                       : No Class Explosion: Instead of creating dozens of subclasses for every permutation of features, you assemble objects like LEGO blocks.
//                                       : Preserved Encapsulation: Composed objects interact strictly through clean public interfaces.

// Tight Coupling & Dependency Injection : When you instantiate an object directly using new inside a class, you are hardcoding a specific implementation directly into your code.
//                                       : Solution : Interface & Dependency Injection

// The Recipe for Loose Coupling : To achieve true loose coupling in your software design, combine three tools
//                               : Relationships (Association / Aggregation / Composition) : Define how your objects relate and interact.
//                               : Interfaces (Abstraction) : Define what capabilities those objects provide without specifying how they do it.
//                               : Dependency Injection (DI) : Pass those object implementations in from the outside instead of calling new internally.

// Delegation & Forwarding : At the end of the day, both Delegation and Forwarding are just ways for one object to say : "I don't want to do this work myself. I'm going to pass the job to a helper object."
//                         : The only real difference between them is how much information the helper gets about who assigned the job.
// Forwarding (Blind Handoff) : The Manager hands a document to the Assistant and says: "Hey, proofread this text."
//                            : The Assistant does not need to know who the Manager is or anything about the Manager’s personal calendar, office, or identity.
//                            : Implementation : The outer object calls the helper method and passes only the raw data (like a string or number). The helper has no idea who called it.
// Delegation (Context Aware Handoff) : The Manager hands a task to the Assistant and says: "Hey, write an expense report for my department. Here is my badge (this) so you can access my department's private files."
//                                    : The Assistant knows who assigned the job and uses the Manager's context (this) to finish it.
//                                    : Implementation : The outer object calls the helper method and passes itself (this) so the helper can pull data back from the outer object.

// Cohesion : Cohesion measures how focused and single-purposed a class, module, or method is. It asks the question: Do all the elements inside this class logically belong together, working toward a single, well-defined goal?
// High Cohesion : Every method and field within a class is tightly aligned toward fulfilling one single, well-defined responsibility.
//               : Example : A class has low cohesion when it mixes multiple responsibilities—such as business logic, data persistence, and communication protocols—into a single unit.
// Low Cohesion : A class contains fields and methods that handle multiple, unrelated tasks or domain concerns.
//              : Example : A class has high cohesion when it isolates a single responsibility and delegates unrelated tasks to specialized classes. This aligns directly with the Single Responsibility Principle (SRP).

// Fragile Base Class Problem : The Fragile Base Class Problem is a fundamental architectural drawback of inheritance (extends).
//                            : It occurs when seemingly harmless changes to a base (parent) class unexpectedly break derived (child) classes, even if the child class code was not touched.
//                            : The parent class is called "fragile" because small internal modifications cause a cascading failure across its entire inheritance hierarchy.
// The Cause : Tight Coupling via Implementation Inheritance
//           : When a child class extends a parent class, it doesn't just inherit the public interface—it becomes tightly bound to the parent's internal implementation details.
//           : If the parent class changes how its internal methods call each other, or adds a new method with a name that conflicts with a child method, the child class breaks silently or behaves unpredictably.

// Anemic Domain Model : Holds raw data with public getters and setters without business logic.
//                     : Shifts validation and rules into external service layers, breaking strict encapsulation.
//                     : Increases risks of invalid states due to unrestricted direct property modifications.
// Rich Domain Model : Bundles data and business operations together inside a single domain entity.
//                   : Enforces business invariants internally by hiding raw setters from external modification.
//                   : Improves cohesion and code maintainability by keeping rules alongside the data.

// Anti-Patterns :
// God Object : A God Object (also known as a Monster Class) is an anti-pattern where a single class holds too much responsibility, knows too much, and performs too much work for the system.
//            : Core Cause : Severe violation of the Single Responsibility Principle (SRP) and extreme Low Cohesion.
//            : Key Characteristic : Instead of distributing tasks among specialized objects, helper classes are reduced to dumb data holders (anemic models), while the God Class orchestrates everything.
//            : Why it Hurts : It becomes a single point of failure. Modifying one feature risks breaking completely unrelated features, and unit testing the class requires setting up nearly the entire application.
// Spaghetti Code : Spaghetti Code refers to a codebase with an unstructured, tangled control flow where dependencies, execution paths, and call stacks are impossible to follow.
//                : Core Cause: Lack of architecture, heavy misuse of global state, deep nesting, and tight coupling between unrelated modules.
//                : Key Characteristic : Code execution jumps unpredictably across layers. High coupling means changing one line of code in Module A breaks an unrelated function in Module Z.
//                : Why it Hurts : Refactoring becomes nearly impossible. Developers cannot trace what calling a method will actually do without stepping through dozens of nested, interdependent calls.

// ---------------------------------------------------- Quick Short Notes ----------------------------------------------------------------------->
// Core Relationships & Coupling
// Association : Peer-to-peer relationship where objects interact independently without owning each other's lifecycles.
// Aggregation : Weak ownership relationship where the child object can exist independently of the parent container.
// Composition : Strong ownership relationship where the child object's lifecycle is completely managed by the parent container.
// Tight Coupling : Direct dependency on concrete classes (e.g., using new internally), making code rigid and hard to test.
// Dependency Injection (DI) : Passing required dependencies into a class from the outside rather than creating them internally.
// Abstraction / Interfaces : Defining contracts that hide implementation details, enabling loose coupling and easy swapping of dependencies.

// Behavioral Delegation & Encapsulation
// Delegation : Passing a task to a helper object along with a reference to this (caller context) for explicit back-references.
// Forwarding : Blindly handing off a method invocation to an internal helper object without passing the caller's context.
// Anemic Domain Model : Procedural data containers with public getters/setters that lack internal business logic (violates OOP).
// Rich Domain Model : Encapsulated entities bundling data with business logic to enforce validation rules internally.
// Encapsulation : Hiding internal object state and requiring all interactions to occur through intent-revealing public methods.

// Architectural Cohesion & Inheritance Safety
// High Cohesion : Designing a class or module to focus exclusively on a single, well-defined responsibility.
// Low Cohesion : Packing multiple unrelated responsibilities into a single class, leading to fragile code.
// Single Responsibility Principle (SRP) : Ensuring a class has only one reason to change by isolating distinct concerns.
// Open/Closed Principle (OCP) : Designing entities to be open for extension (via interfaces) but closed for modification.
// Fragile Base Class Problem : Cascading failures in child classes caused by subtle internal implementation changes in parent base classes.
// Composition over Inheritance : Favoring dynamic object composition and forwarding over rigid compile-time inheritance hierarchies (extends).

// Code Smells & Systemic Anti-Patterns
// God Object : A massive monolithic class that centralizes systemic control and handles far too many responsibilities.
// Spaghetti Code : Entangled control flows and unorganized dependencies across modules that make code execution paths unreadable.

// -------------------------------------------------- Core OOPS Done ---------------------------------------------------------------------------------------------------------------------------------------->
// Always more to explore...