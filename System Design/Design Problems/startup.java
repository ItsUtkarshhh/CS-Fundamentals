// ----------------------------------- End-to-End LLD Problem Handling & Solving Blueprint ----------------------------------->
// Phase 1 : Clarify & Scope
//         : Core : Do not write a single line of code. Actively narrow down the problem.
//         : Identify the Actors : Who or what interacts with the system? (e.g., Guest, Registered Customer, Admin, System System).
//         : Define Use Cases : Establish 3–5 core features.
//         : Establish Boundaries (Crucial) : Explicitly state what you are not doing.
//         : The Blueprint : Write these down as simple bullet points on the whiteboard/editor. This acts as your contract for the rest of the interview.
//         : Define the Final Flow of working

// Phase 2 : Core Domain Modeling & Schema
//         : Core : Translate your use cases into physical objects and structural relationships
//         : Nouns to Classes : Look at your requirements. Nouns generally become classes, and verbs generally becomes methods.
//         : Define Relationships : Define Relationships - Use object-oriented principles.
//         : The Blueprint : Sketch out the class headers, fields, and method signatures. Do not write the internal method logic yet.

// Phase 3 : Interface Design & Patterns
//         : Core : Decouple your system using interfaces and design patterns so it conforms to SOLID principles.
//         : SOLID Principles : Applying these principles to make your code more readable & scalable
//         : Design Patterns : Applying design patterns if the system demands & make the system and code more scalable

// Phase 4 : Implementation & Concurrency
//         : Core : Flesh out the core business logic while ensuring it safely survives a multi-threaded environment.
//         : Write Clean Code : Use meaningful variable names. Avoid deep nesting (if-else hell). Use early returns.
//         : Identify Concurrency Hotspots : Where will two threads try to modify the same data?
//         : Implement Thread Safety : Locks/Synchronizations, Thread-safe collections, Double checked locking

// Phase 5 : Edge Cases & Wrap-Up
//         : Core : Proactively point out vulnerabilities in your design before the interviewer does.
//         : Input Validation : Handle null pointers, empty strings, or negative values
//         : System Failures : Identify potential system failure & related preventive measures and fallbacks possible
//         : Idempotency : Ensure the idempotency nature is maintained where it needs to.

// ----------------------------------- Scope of Interview Expectations ------------------------------------------------------>
// Expectations : Working Code : At least one core use case must be coded completely and compilable/executable logically.
//              : Extensibility : If they ask to add a feature at the final minutes, your existing classes shouldn't shatter.
//              : SOLID Application : Demonstrable understanding of loose coupling and interface-driven design.
//              : Concurrency Awareness : Knowing exactly where a race condition can happen and explaining how to prevent it.

// Out Of Expectations : Flawless Syntax : Missing a semicolon or a bracket won't fail you; architectural flaws will.
//                     : UI/UX or DB Layer : You don't need to write real SQL queries or HTML. In-memory data structures (Lists, Maps) are perfect.
//                     : Over-engineering : Don't throw 12 design patterns at a simple problem just to look smart. Use them only where they solve a problem.
//                     : Perfect distributed systems : LLD focuses on single-machine multi-threading, not cluster-wide distributed consensus (that's HLD).