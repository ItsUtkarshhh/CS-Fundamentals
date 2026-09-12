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

