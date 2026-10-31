// -------------------------------------- Java OOPS Overview & Quick Notes ------------------------------------------->
// -------------------------------- Syllabus : Most Important Topics & Concepts ------------------------------------------->
// 1. Class Loading, JVM Memory Stack vs. Heap Allocation
// 2. Primitive Types vs. Reference Types / Wrapper Classes
// 3. Garbage Collection Basics & Object Lifecycle
// 4. Access Modifiers : private, default, protected & public
// 5. Packages and Module System (Java 9+)
// 6. Constructors & Types
// 7. Default, Parameterized, and Copy Constructors
// 8. Instance Initializer Blocks vs. Static Initializer Blocks
// 9. Constructor Chaining (this(), super())
// 10. "finalize()" deprecation and modern cleanup (Cleaner, AutoCloseable, try-with-resources)
// 11. "static" Keyword : Variable, Method, Static Block, Inner Class
// 12. "final" Keyword : Variable (Constants), Method (Prevent Overriding), Class (Prevent Inheritance)
// 13. "this" and "super" References
// 14. abstract Classes vs. interface
// 15. Method Overloading (Compile-Time) & Widening vs. Autoboxing rules
// 16. Method Overriding (Runtime) & @Override annotation
// 17. Dynamic Method Dispatch & Virtual Method Table (vtable in JVM)
// 18. Covariant Return Types
// 19. interface Features : default methods, static methods, private methods (Java 9+)
// 20. Abstract Class vs. Interface (When to use which)
// 21. Multiple Inheritance via Interfaces & Resolution Rules
// 22. equals() and hashCode() Contract (Overriding rules, Hash Collisions)
// 23. toString(), clone() (Shallow vs. Deep Copy, Cloneable interface)
// 24. getClass() and Intro to Reflection API
// 25. Nested & Inner Classes (Static Nested, Inner, Local, Anonymous Classes)
// 26. Sealed Classes & Interfaces (sealed, permits - Java 17+)
// 27. Records (record for Immutable Data Holders - Java 16+)
// 28. Enumerations (enum with Fields, Methods, and Interfaces)
// 29. Generics & Type Erasure (Bounded Wildcards ? extends T, ? super T)

// ------------------------------------------------------------------------------------------------------------------->
// Class Loader & Mechanism :
// When you run a Java program, the JVM doesn't load every single class into memory at once. It loads classes dynamically on-demand using the Class Loader Subsystem.
// The 3 Phases of Class Loading : Loading : Reads the .class bytecode file and creates a binary representation.
//                                         : Uses the Delegation Hierarchy Principle : The load request moves up from Application/System ClassLoader to Platform/Extension ClassLoader to Bootstrap ClassLoader
//                                                                                   : If the top loader can't find it, the request delegates back down.
//                               : Linking : Verify : Validates that bytecode adheres to JVM safety rules.
//                                         : Prepare : Allocates memory for static variables and sets them to default values (e.g., 0, false, null).
//                                         : Resolve : Replaces symbolic references in code with direct physical memory references.
//                               : Initialization : Executes static initializers and assigns actual values to static variables (e.g., static int x = 10;).

// JVM Memory Organization: Stack vs. Heap
// Once loaded, the JVM partitions system RAM into distinct areas during execution.
// Purpose : Stack Memory : Stores method calls, local variables, and primitive values
//         : Heap Memory : Stores all instantiated Objects and their instance variables
// Scope & Life : Stack Memory : Thread-private. Created per thread; destroyed when method exits
//              : Heap Memory : Thread-shared. Accessible globally; managed by Garbage Collector
// Allocation : Stack Memory : Managed strictly via LIFO (Last-In-First-Out) stack frames
//            : Heap Memory : Dynamic memory allocation
// Size Limit : Stack Memory : Fast, but limited size (Triggers StackOverflowError)
//            : Heap Memory : Larger size (Triggers OutOfMemoryError)

// Primitive vs. Reference Types
// Primitive Types : Examples : int, double, boolean, char, byte, short, long, float
//                 : What Variable Holds : The actual binary value directly.
//                 : Memory Location : Local primitives live on the Stack. Primitives inside objects live on the Heap.
//                 : Default Values : Have defaults when used as instance variables (e.g., 0, false).
//                 : Methods : Have no methods (cannot invoke .length(), .toString()).
//                 : Pass By Value Behaviour : Passes a copy of the value. Changing it inside a method won't affect the caller.
// Reference Types : Examples : Classes, Interfaces, Arrays, String, Integer
//                 : What Variable Holds : A memory address pointing to an object on the Heap.
//                 : Memory Location : Reference variable lives on the Stack; actual Object lives on the Heap.
//                 : Default Values : Default is always null (points to no object).
//                 : Methods : Can invoke object methods defined in their class.
//                 : Pass By Values Behaviour : Passes a copy of the reference address. Modifying object fields inside a method affects the original object.

// Wrapper Classes & Auto-Boxing / Unboxing
// Java's Object-Oriented paradigm relies heavily on objects (such as in Collections like ArrayList or HashMap). Because primitives are not objects, Java provides Wrapper Classes in java.lang to encapsulate primitives.
// Examples : int - Integer
//          : double - Double
//          : char - Character
//          : boolean - Boolean
//          : byte, short, long, float - Byte, Short, Long, Float

// Autoboxing & Unboxing : Since Java 5, the compiler automatically converts between primitives and wrapper objects.
// Autoboxing :  Automatic conversion of a primitive into its corresponding Wrapper Class object (int $\rightarrow$ Integer).
// Unboxing :  Automatic conversion of a Wrapper object back to its primitive value (Integer $\rightarrow$ int).

// Important Pitfalls to Watch For :
// NullPointerException (NPE) during Unboxing : If a Wrapper object is null and Java attempts to unbox it into a primitive, it throws a NullPointerException.
// Integer Cache Trap : Small integers like 0, 1, 10, or -5 are used constantly across applications (for array indices, loop counters, state flags, etc.).
//                    : If Java created a brand-new object on the Heap every single time autoboxing happened for small numbers, thousands of identical Integer objects would clutter Heap memory and trigger frequent Garbage Collection cycles.
//                    : To save memory and boost performance, the JVM automatically pre-creates and caches an array of Integer objects for numbers ranging from -128 to 127.

// Garbage Collection & Object Lifecycle
// Garbage Collection (GC) is the JVM's automatic memory management process that frees developers from manual memory deallocation (free() or delete in C/C++).
// The 7-Stage Object Lifecycle : An object transitions through specific lifecycle states from allocation to memory release
//                              : Created : Memory is allocated on the Heap, constructors run, and field initializations execute.
//                              : In Use (Strongly Reachable) : Held by at least one live reference in a running thread's stack frame or a static context.
//                              : Invisible : Out of scope for current execution block, but the reference frame might briefly remain active in execution (e.g., intermediate compiler optimizations).
//                              : Unreachable : No active references point to the object—it is now eligible for Garbage Collection.
//                              : Collected : The JVM's GC algorithm marks the object and identifies it for destruction.
//                              : Finalized : If the object overrides cleanup methods, JVM queues it for finalization before memory release.
//                              : Deallocated : Physical memory on the Heap is reclaimed.

// When Does an Object Become Eligible for GC?
// An object is eligible for GC when it is unreachable from any GC Root.
// GC Roots include : Local variables living in active thread stack frames.
//                  : Static variables in loaded class definitions.  
//                  : Active Java thread objects.
//                  : JNI (Java Native Interface) global/local references.

// Generational Garbage Collection: Young vs. Old Generation
// Generational Garbage Collection is built on an empirical observation called the Weak Generational Hypothesis : most objects created in an application become unreachable (die) very quickly after their creation (e.g., local method variables, temporary loop objects, HTTP request/response payloads).
// Rather than scanning the entire Heap every time memory needs reclaiming (which would cause massive execution pauses), the JVM divides Heap memory into distinct regions based on the age of objects.
// Breakdown of the Heap Regions : Young Generation
//                               : Old Generation
// Young Generation : The Young Generation is where fresh allocations occur. It is optimized for high-throughput, low-latency collection because 90%+ of these objects will not survive their first GC cycle. It is split into three parts
//                  : Eden Spaces : The entry point. Every time you write new MyObject(), the memory is allocated inside Eden.
//                  : Survivor Spaces (S0 & S1 / From & To) : Two equally-sized spaces (Survivor 0 and Survivor 1). At any given moment, one survivor space is active (holding objects) while the other is completely empty. 
// Old Generation (Tenured) : Contains objects that have survived multiple rounds of Garbage Collection in the Young Generation. These are long-lived components like Spring Beans, Singletons, DB Connection Pools, and global application state caches.

// End-to-End Lifecycle : Allocation in Eden : When your application executes new Order(), memory is allocated in the Eden Space.
//                      : Triggering Minor GC : When Eden becomes completely full, the JVM triggers a Minor GC. Application execution experiences a brief "Stop-The-World" (STW) pause while the collector scans only the Young Generation.
//                      : Copying to Survivor Space : Unreachable objects in Eden are reclaimed immediately.
//                                                  : Live (reachable) objects are copied to the empty Survivor Space (e.g., S0).
//                                                  : Their internal Age Counter (Tenuring Threshold) is set to 1.
//                                                  : Eden is completely cleared.
//                      : Ping-Ponging Between S0 and S1 : On the next Minor GC : Surviving objects from Eden AND S0 are copied over to S1.
//                                                                              : The age counter for surviving objects increments by 1.
//                                                                              : Eden and S0 are wiped clean.
//                                                                              : Roles swap: S1 is now the active "From" space, and S0 becomes the empty "To" target for the next cycle.
//                      : Tenuring (Promotion) to Old Generation : When an object survives enough Minor GC cycles to reach the MaxTenuringThreshold (JVM default is typically 15, configured via -XX:MaxTenuringThreshold), it is promoted to the Old Generation.
//                      : Triggering Major / Full GC : When the Old Generation fills up, the JVM executes a Major GC (or Full GC). This scans the Old Generation (and optionally Metaspace) to clear dead long-lived objects.

// Access Modifiers :
// "private" : Members declared private are accessible only within the class where they are declared. Outer classes cannot be marked private.
// "default" / "package-private" (No Modifier Keyword) : When you don't write any modifier keyword before a member or class, Java assigns it default visibility. It is accessible only by classes within the exact same package.
//                                                     : Utility or helper classes designed strictly for internal library/package usage that shouldn't be exposed to external clients.
// "protected" : Members marked protected are accessible to - Every class inside the same package.
//                                                          - Subclasses residing in different packages (via inheritance).
//             : Exposing framework extension points or template methods for child classes to override without exposing them to the general public.
// "public" : Members or classes declared public are accessible everywhere across all packages in the project.
//          : Exposing API methods, main entry points (public static void main), or core domain models.

// Important Nuances : Top-Level Class Restrictions: Top-level classes can only be public or default. They cannot be declared private or protected (nested/inner classes can be all four).
//                   : Method Overriding Rule (Crucial for Interviews) : When overriding a method in a child class, you cannot reduce its visibility.
//                                                                     : This is done to follow the "Liskov Substitution Principle" which says : Any code expecting an instance of a Parent class must be able to accept an instance of a Child class without breaking or failing unpredictably.

// Packages and Module System (Java 9+)
// Java Packages : Namespace Management
//               : A package is a folder directory structure that groups related classes, interfaces, and sub-packages.
//               : Why Use Packages : Prevents Name Collisions : Two classes can have the same name (e.g., java.util.Date vs java.sql.Date) as long as they reside in different packages.
//                                  : Access Control : Enables default (package-private) visibility.
//                                  : Naming Convention : Reverse domain names are used to guarantee global uniqueness (e.g., com.company.project.module).
//               : Examples : package com.myapp.service; - defines package location
//                          : import com.myapp.model.User; - imports specific class from another package
//                          : import java.util.*; - wildcard import (imports classes, NOT sub-packages)

// Module Systems
// The Core Problem (Pre-Java 9 / Classpath Era) : JAR Files & Classpath: Code was bundled into JAR files (ZIP archives) and run on a flat, unorganized Classpath.
//                                               : Problem 1 : Accidental Internal Leaks: Any class marked public was visible to the entire application. Internal JVM/library tools (like sun.misc.Unsafe) leaked publicly, causing massive breaks when updated.
//                                               : Problem 2 : "JAR Hell" & Lazy Crashes: The Classpath was lazy—it never verified if required dependencies existed at startup. Missing libraries caused delayed, unexpected runtime crashes (NoClassDefFoundError).
//                                               : Problem 3 : Monolithic JDK: The core Java engine was one heavy, unscalable blob (rt.jar).
// The Architectural Solution : Introduced under Project Jigsaw (led by Mark Reinhold at Oracle) to enforce strong boundaries and strict dependency management at both the JVM level and developer level.
//                            : Module : A protected, named boundary surrounding a set of related packages and resources.
//                            : Default Security : Everything inside a module is locked by default. Even public classes remain permanently hidden unless explicitly exported.
// The module-info.java Descriptor File : Placed at the root of the source folder to configure module behavior using 4 core directives
//                                      : "requires" <module> : Declares a dependency on another module. Fails at compile-time or in 1 second at boot-up if missing (eliminates JAR Hell).
//                                      : "exports" <package> : Exposes specific packages publicly. Un-exported packages stay hidden, protecting internal APIs.
//                                      : "exports.. to.." : Qualified export—shares a package exclusively with trusted target modules.
//                                      : "opens" : Permits reflection access to private fields for frameworks (Spring, Hibernate).

// Constructors & Their Types : A Constructor is a special block of code called automatically when an object is created using new. It shares the same name as the class and has no return type (not even void).
// 3 Types : Default Constructor (Implicit) : If you don't write any constructor in your class, the Java compiler automatically inserts a hidden no-argument constructor that initializes fields to default values (0, null, false).
//                                          : Crucial : If you write any custom constructor, Java stops providing the implicit default constructor.
//         : Parameterized Constructor : A constructor that accepts arguments to initialize instance variables with custom values at creation time.
//         : Copy Constructor : Java doesn't have a built-in copy constructor like C++, but you create one by passing an instance of the same class to duplicate its state into a new object.

// Static Initializer Blocks vs. Instance Initializer Blocks
// Initializer blocks execute code during class loading or object instantiation without needing to put the logic inside a constructor.
// Static Initializer Blocks : A static initializer block is used to initialize class-level (static) variables or run setup logic that only needs to happen once when the class is first loaded into memory by the JVM.
//                           : Key Characteristics : Trigger : Executes automatically when the JVM's ClassLoader loads the class into the Metaspace (usually when the class is first referenced, instantiated, or its static members are accessed).
//                                                 : Frequency : Executes exactly once per JVM lifecycle.
//                                                 : Scope Limits : Can only access static fields and static methods. It cannot access instance variables or use this/super because no object exists yet.
//                                                 : Error Handling : Can catch and handle checked exceptions internally, or throw an ExceptionInInitializerError.

// Instance Initializer Blocks : An instance initializer block looks like a method body without a name, placed directly inside the class. It is used to initialize instance-level (object) variables.
//                             : Trigger : Executes every time a new object is created using the new keyword.
//                             : Execution order : Executes after the parent class constructor (super()) completes, but before the code inside the current class constructor runs.
//                             : Frequency : Executes once per instance creation.
//                             : Scope Limits : Can access both static and instance (non-static) members, as well as this and super.

// Constructor Chaining : Constructor Chaining is the process of calling one constructor from another constructor within the same class or from a parent class. It avoids code duplication and ensures objects are built step-by-step.
// "this()" : Another constructor in the same class
//          : Must be the first line of the constructor
//          : Intra-Class Chaining ("this()") : Used to provide default values by delegating smaller constructors to a main constructor.
// "super()" : A constructor in the parent class
//           : Must be the first line of the constructor
//           : Parent-Child Chaining ("super()") : Used in inheritance so the child class initializes parent fields first.
// Important Rules : Must Be First Line : Both this() and super() must be the very first statement inside a constructor body.
//                 : Cannot Coexist : You cannot use both this() and super() in the same constructor, because both demand to be the first line.
//                 : Implicit super() : If you don't write this() or super(), the Java compiler automatically inserts an invisible super() (no-arg call) on line 1.
//                 : No Cyclic Loops : You cannot create circular constructor calls (A calls B, and B calls A)—this throws a compile-time error.

// "finalize()" : The finalize() method in Java is a protected method defined in the java.lang.Object class. It was historically designed to perform cleanup operations (like closing files, flushing connections, or releasing system resources) right before the Garbage Collector destroys an object and reclaims its memory
// Why finalize() Was Deprecated : The JVM invoked protected void finalize() right before an object was garbage-collected. However, this approach suffered from major design flaws...
//                               : Unpredictable Execution Timing : Garbage Collection is not deterministic. finalize() might run minutes, hours, or never after an object becomes unreachable. Holding onto system resources like database connections waiting for GC causes resource starvation.
//                               : Severe Performance Degradation : Objects overriding finalize() are delayed from garbage collection. They must be added to a finalization queue, requiring at least two GC cycles to be fully reclaimed.
//                               : Uncaught Exceptions Swallowed : The default finalizer ignores uncaught exceptions silently, leaving resources in corrupted states without stack traces.

// Modern Cleanup using "AutoCloseable" with "try-with-resources"
// This is the primary method for managing resources in modern Java. It executes deterministically (immediately on scope exit), independent of Garbage Collection.
// How It Works Under the Hood : The Contract : A class implements java.lang.AutoCloseable, committing to provide a public void close() method.
//                             : Compiler Transformation : When you write a try-with-resources block, the Java compiler bytecode-engine secretly transforms your code at compile time.
// Practical Working : Step 1 (Class Definition): You implement AutoCloseable on your resource class and write the logic inside the close() method to release low-level system resources (DB connections, file streams, sockets).
//                   : Step 2 : You declare or instantiate that resource inside the parentheses of a try block. Then this whole cleaup process will work.

// 