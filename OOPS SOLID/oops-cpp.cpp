// -------------------------------------- C++ OOPS Overview & Quick Notes ------------------------------------------->
// -------------------------------- Syllabus : Most Important Topics & Concepts ------------------------------------------->
// 1. Classes & Objects
// 2. Data Members & Member Functions
// 3. Access Modifiers : Private, Public & Protected
// 4. Padding, Alignment & Greedy Alignment
// 5. Constructors & Types : Default, Parameterized, Copy
// 5. Methods & Constructors outside of the class with "::"
// 6. Static & Dynamic Creation of objects
// 7. "this" keyword
// 8. Shallow, Deep Copy Constructor & Assignment Operator
// 9. Destructors
// 10. "static" keyword & usage
// 11. "static" methods & usage
// 12. Array of objects
// 13. "friend" function & "friend" class
// 14. Practice some real world applications, usage and examples of classes and objects so far.
// 15. Pillars of OOPS : Encapsulation, Polymorphism, Abstraction, Inheritance
// 16. Encapsulation & Implementation
// 17. Fully Encapsulated Class
// 18. Inheritance & Implementation
// 19. Inheritance Types : Single, Multiple, Multi-level, Hierarchial & Hybrid
// 20. Inheritance & Derivation - public, private, protected
// 21. Inheritance Ambiguity & Resolution with "::"
// 22. Constructors participation in inheritance
// 23. Diamond Problem in inheritance
// 24. Use of initializer list
// 25. Virtual Base Class using "virtual" keyword
// 26. Polymorphism & Types
// 27. Compile time polymorphism : Method overloading & operator overloading
// 28. Runtime polymorphism : Method overriding, Virtual functions & Base/Derived class pointers
// 29. Method Overloading & examples
// 30. Operator Overloading & examples
// 31. Method overriding & examples
// 32. Virtual Functions & examples
// 33. Base/Derived class pointers & examples
// 34. Abstract base class & pure virtual functions
// 36. Data Abstraction
// 37. Data Abstraction vs Encapsulation
// 38. Class vs Structures
// 39. More usage of "this" pointer
// 40. Complex examples and implementations of all the topics & concepts together.

// ------------------------------------------- Short & Quick Notes ------------------------------------------->
// Classes & Objects : A Class is a user-defined blueprint or data type containing state (variables) and behavior (functions). An Object is a real-world instance of a class that occupies memory.
//                   : Empty class in C++ occupies 1 byte of memory to ensure each instance has a unique memory address.
//                   : Empty class in Java occupies 16 byte of memory to ensure each instance has a unique memory address. Because of JVM Object Header

// Data Members & Member Functions : Variables declared inside a class that define the state/properties of an object.
//                                 : Functions inside a class that define actions/behaviors using those data members.
//                                 : Member functions do not increase the size of an object. Only data members contribute to the object's sizeof. All objects of a class share the exact same copy of member functions in the code segment.

// Access Modifiers : Private, Public & Protected 
//                  : Define the scope and visibility of class members from outside the class.
//                  : Private : Only within the class
//                  : Protected : Within the class or in the derived class
//                  : Public : Anywhere outisde the class
//                  : In C++, "struct" members default to public, whereas "class" members default to private.

// Padding, Alignment & Greedy Alignment : Alignment Requirement : CPUs read memory in word chunks (4 or 8 bytes). Data types must align at memory addresses that are multiples of their own size (e.g., a 4-byte int aligns at addresses divisible by 4).
//                                       : Padding : Extra unused bytes added by the compiler between variables or at the end of a class to satisfy alignment requirements.
//                                       : Greedy Alignment (Member Reordering) : Manually ordering class members from largest data type to smallest data type to minimize padding space.

// Constructors & Types : Default, Parameterized, Copy
// Default : No parameter, No return type, Initialize data members with garbage value
// Parameterized : Initialize parameters values to data members
// Copy : Initialize an object with existing object of the same class
// Important Points : Pass-by-Reference Rule for Copy Constructor : The parameter in a copy constructor must be passed by reference (const Hero& temp). Passing by value (Hero temp) requires making a copy first, which would trigger the copy constructor again, leading to an infinite recursive loop that causes a stack overflow compile error.
//                  : Constructor Overwrite Rule : As soon as you define any custom constructor (parameterized or copy), the compiler stops generating its implicit default constructor. Attempting Hero h1; without writing your own parameterless constructor will trigger a compile-time error.
//                  : Shallow vs Deep Copy : The default compiler-provided copy constructor performs a shallow copy (bitwise member-to-member copy). If a class contains dynamic heap pointers, a shallow copy points both objects to the exact same memory address. Modifying or freeing memory in one object corrupts the other. You must write a custom copy constructor to allocate separate memory for a deep copy.

// Methods & Constructors Outside the Class (::)
// Class functions and constructors can be declared inside the class body and defined outside using the Scope Resolution Operator (::).

// Static vs. Dynamic Allocation of Objects
// Static Allocation : Created on the Stack. Memory is allocated automatically and reclaimed when the object goes out of scope. Ex - Hero h1;
// Dynamic Allocation : Created on the Heap using the new keyword. Returns a pointer to the memory location. Must be freed manually using delete to prevent memory leaks. Ex - Hero h1 = new Hero();

// "this" Keyword : "this" is a constant pointer that stores the memory address of the current object invoking the member function (this == &obj).
//                : Use case : Differentiates data members from constructor/method parameters when they share the exact same name (this->health = health).
//                           : Returning *this by reference allows chaining multiple method calls together (h1.setHealth(80).setLevel('A');).
//                           : Used in assignment operators (if (this != &other)).

// Shallow, Deep Copy Constructor & Assignment Operator
// Shallow Copy : Performs a bitwise, member-by-member copy. If a class contains dynamically allocated memory (pointers), a shallow copy duplicates the pointer address itself—meaning both objects end up pointing to the exact same heap memory location.
//              : Danger : Modifying memory via one object alters the other object. Additionally, when both objects go out of scope, their destructors attempt to free the same heap address twice, triggering a Double Free Crash.
//                       : This will cause "memory leak".
// Deep Copy : Allocates a brand-new chunk of memory on the heap for the target object and copies the actual values over. Both objects remain completely independent.

// Copy Constructor vs. Copy Assignment Operator (operator=)
// Although both handle copying data from one object to another, their triggering contexts are distinct
// Copy Constructor : Invoked when a new object is being created/initialized from an existing object.
// Assignment Operator : Invoked when an already existing, fully initialized object is assigned values from another existing object.
// Core Interview Checklist : Why check if (this == &temp) in operator=?
//                          : If an object is assigned to itself (h1 = h1), skipping this check deletes the underlying memory before copying, causing dangling pointers and undefined behavior.

// Destructors : A Destructor is a special member function that is executed automatically when an object goes out of scope or is explicitly destroyed via delete. Its primary role is to release resources (heap memory, file handles, database connections) allocated by the object during its lifetime.
//             : Shares the exact same name as the class, preceded by a tilde (~). It takes no arguments and returns no values (not even void).
// Core Interview Points : Unlike constructors, destructors cannot be overloaded. A class can have only one destructor because it takes no parameters.
//                       : Automatic vs. Manual Invocation : Static Allocation (Stack) : The destructor is invoked automatically when the object goes out of scope.
//                                                         : Dynamic Allocation (Heap) : The destructor is NOT called automatically when a pointer goes out of scope. You must explicitly call delete ptr; to invoke the destructor and free heap memory.
//                       : Execution Order : Destructors are executed in the exact reverse order of constructor execution (Last In, First Out - LIFO).
// Interview Scenario : If you delete a derived class object using a base class pointer, and the base class destructor is not virtual, only the base class destructor will execute. This leaves the derived class's resources uncleaned, causing memory leaks.
//                    : Always declare the destructor of a base class as virtual. So that, always the derived class destructor will be called even if the pointer is of base class.

// "static" Data Members & Usage : A static data member belongs to the class itself rather than any specific object instance. Only one copy is created in global/static memory, shared across all objects of that class.
//                               : Static data members cannot be initialized inside the class body (prior to C++17 inline variables). They must be defined and initialized outside the class using the scope resolution operator ::.
//                               : Allocated when the program starts (in the data segment) and destroyed when the program terminates. Does not add to sizeof(Object).

// "static" Member Functions & Usage : A static member function belongs to the class and can be called without creating an object using ClassName::functionName().
//                                   : Access Restrictions : Can only directly access static data members and call other static member functions.
//                                                         : Cannot access non-static data members or instance methods because static functions run without an object context.
//                                                         : Have no this pointer (since this points to a specific instance).
// Interview Checklist : "sizeof" Impact : Static data members do not increase the size of an object. sizeof(Hero) counts only non-static data members (+ alignment padding).
//                     : Common use : Counters & Shared State : Tracking instance counts (totalPlayers, activeConnections).
//                                  : Utility Methods : Math functions (e.g., Math::max()) that don't depend on instance state.
//                                  : Factory Design Pattern : Static methods used to instantiate and return objects.

// Array of Objects : An array of objects allows you to store multiple instances of a class under a single variable name, accessed via index notation (arr[i]).
//                  : Memory Layout : Objects in an array are stored in contiguous memory locations on the Stack or Heap, just like an array of primitive data types.
//                  : Construction Trigger : Creating an array of size "N" invokes the class constructor "N" times consecutively.
// Declaration & Initialization Options : Static Array (Stack) with Default Constructor : Example : Hero squad[3]; squad[0].function();
//                                      : Static Array with Parameterized Constructors : Example : Hero squad[3] = { Hero(80), Hero(90), Hero(100) };
//                                      : Dynamic Array (Heap) : Hero* squad = new Hero[3]; squad[0].health = 50; (squad + 1)->health = 60; delete[] squad;
// Interview Checklist : Mandatory Default Constructor for Dynamic Arrays : When you allocate a dynamic array on the heap using new Hero[N], C++ requires a default constructor to exist. If you define a parameterized constructor without defining a default constructor, new Hero[N] fails at compile time.
//                     : delete vs delete[] : delete ptr; frees memory for a single object and calls the destructor once.
//                                          : delete[] ptr; reads hidden array allocation metadata (the chunk size), invoking the destructor for every element in the array before freeing the entire heap block. Using delete on an array pointer results in undefined behavior and memory leaks.

// "friend" Function & "friend" Class
// "friend" function : A friend function is a non-member function that is granted access to the private and protected members of a class. It breaks encapsulation intentionally for specific operations.
// "friend" class : A friend class is a class whose member functions are granted direct access to another class's private and protected members. "friend class ClassName" declared inside the host class.
// Key Characteristics : It is not a member function of the class (it cannot be called using the dot operator obj.func()).
//                     : It accepts objects of the class as parameters to access private data (func(obj)).
//                     : It can be declared anywhere inside the class (private, public, or protected) without changing its behavior.
//                     : Friendship is non-reciprocal and non-transitive : If Class A is a friend of Class B, Class B is not automatically a friend of Class A. If A is a friend of B, and B is a friend of C, A is not automatically a friend of C.
//                     : Not Inherited : If a parent class has a friend class, child classes do not inherit that friendship.
// Core Interview : Encapsulation Dilemma: Inter-viewers often ask: "Does friend destroy encapsulation?"
//                : It selectively weakens strict encapsulation for closely linked helper classes/functions, controlled entirely by the host class itself (the host class explicitly declares who its friends are).

// The 4 Pillars of OOP : The four fundamental principles that govern Object-Oriented Programming are designed to make code modular, reusable, scalable, and maintainable.
// Encapsulation (Data Hiding + Binding) : Wrapping data members (variables) and member functions (methods) into a single unit (a class), while restricting direct access to the data from outside the class.
//                                       : Mechanism : Achieved using access specifiers (private, protected). Data is kept private and accessed via public getter and setter methods.
//                                       : Why use it : Ensures data security, validation, and control over state mutation.
// Abstraction (Hiding Complexity) : Displaying only essential features to the outside world while hiding implementation details.
//                                 : Mechanism : Achieved using Abstract Classes (containing pure virtual functions in C++) or Interfaces (in Java).
//                                 : Why Use It : Reduces code complexity. Users interact with a clean interface without worrying about internal logic (e.g., pressing a car accelerator without knowing how the engine injects fuel).
// Inheritance (Code Reusability) : The mechanism by which a derived class (child) inherits properties and behaviors from a base class (parent).
//                                : Mechanism : Represents an "Is-A" relationship (e.g., Dog is-a Animal).
//                                : Why Use It : Eliminates redundant code and establishes a hierarchical classification.
// Polymorphism ("Many Forms") : The ability of a message, function, or object to take on multiple forms depending on context.
//                             : Types : Compile-Time (Static) Polymorphism: Function Overloading & Operator Overloading. Resolved during compilation.
//                                     : Run-Time (Dynamic) Polymorphism: Method Overriding using virtual functions and base class pointers. Resolved during execution.
//                             : Why Use It : Allows writing generic code that works across related object hierarchies

// Fully Encapsulated Class : A class is considered fully encapsulated if and only if all of its data members are declared as private.
//                          : Zero data members are left public. If even one variable is left exposed as public, the class fails strict full encapsulation guidelines.

// Inheritance Types : Single Inheritance : A single derived class inherits from one base class (A <- B).
//                   : Multi-level Inheritance : A class inherits from a derived class, forming a chain (A <- B <- C).
//                   : Multiple Inheritance : A single derived class inherits directly from two or more base classes (A, B <- C). (Supported in C++, but forbidden for classes in Java).
//                   : Hierarchical Inheritance : Multiple derived classes inherit from a single base class (A <- B and A <- C).
//                   : Hybrid Inheritance : A combination of two or more inheritance types (e.g., combining Multiple and Hierarchical inheritance).
// Inheritance & Access Modes (Derivation Rules) : The visibility of base class members inside a derived class depends on the Access Specifier used during derivation (class Derived : <access-mode> Base).
//                                               : The visibility only goes narrower in the derived class based upon the access modifier used.
//                                               : Interview Point : Private members of a base class are inherited in terms of memory footprint, but are never directly accessible by the derived class functions.

// Inheritance Ambiguity & Resolution with "::" 
// When a derived class inherits from multiple base classes that contain member functions with the exact same name and signature, calling that function triggers a compile-time ambiguity error.
// Resolution : Use the Scope Resolution Operator (::) to explicitly specify which parent's function to invoke.

// Constructor Participation in Inheritance 
// Constructor Execution Order : Executed in top-down order, starting from the Base class first, followed by the Derived class.
// Destructor  Execution Order : Executed in bottom-up order, starting from the Derived class first, followed by the Base class (LIFO order).
// Multiple Inheritance Order : Constructors run in the exact order base classes are listed in the class definition line, NOT the order listed in the initialization list.

// Diamond Problem in Inheritance : The Diamond Problem occurs in Hybrid/Multiple inheritance when a derived class inherits from two parent classes that both inherit from a common grandparent class.
//                                : The Problem : The bottom class receives two duplicate copies of the grandparent's data members—one through Parent1 and one through Parent2. This causes both memory duplication and compile-time ambiguity.
//                                : The Solution : Use Virtual Base Classes (virtual public) when inheriting the grandparent class. This instructs the compiler to share a single, unified instance of the grandparent subobject.

// Use of Initializer List : A Member Initializer List directly initializes class data members before the constructor body executes. It is specified after the constructor signature using a colon (:).
//                         : Syntax : ClassName(params) : member1(val1), member2(val2) { ... }
//                         : Interviews Core : Initializing const data members : A const variable is locked the moment it is born. You cannot create it empty and fill it in later.
//                                                                             : Why Initializer List Works : It sets the value at birth (during memory allocation), whereas writing code inside { } attempts to change an already-created variable (which causes a compile error).
//                                           : Initializing reference variables (&) : A reference in C++ is an alias (nickname) for another variable. A nickname cannot exist in the air—it must point to a real variable from the second it is created.
//                                                                                  : Why Initializer List Works : Binds the nickname instantly when the object is created.
//                                           : Forwarding Parameters to Parent (Base) Class : A child cannot exist without its parent being created first. If the parent requires details (like a name) to be created, you must hand those details over before the child's constructor body runs.
//                                           : Member Objects Without Default Constructors : If your class contains another complex object inside it (e.g., a Car containing an Engine), C++ tries to build that Engine first. If Engine doesn't have a zero-argument default constructor, C++ panics unless you tell it how to build it.
//                         : Performance Optimization (Avoiding Double Work) : Without Initializer List (Inside { }) : You buy a house pre-painted white (step 1: default constructor), and then immediately hire painters to repaint it blue (step 2: assignment operator inside body). You paid twice!
//                                                                           : With Initializer List : You order the house built with blue paint from day one (step 1: direct initialization).

// Compile-Time Polymorphism : Method Overloading : Defining multiple functions in the same scope with the same name but different parameter signatures (different count, data types, or sequence of types).
//                                                : Interview Note : Changing only the return type does NOT constitute method overloading, it causes a compile-time error.
//                           : Operator Overloading : Giving specialized custom logic to C++ built-in operators (like +, -, <<, ==) when applied to user-defined objects.
//                                                  : Non-Overloadable Operators in C++: ., ::, sizeof, ?: (ternary operator).

// Runtime Polymorphism, Virtual Functions & Base Pointers
// Base & Derived Class Pointers : A Base class pointer can store the memory address of a Derived class object (Upcasting).
//                               : Without virtual : Calling a method through a Base pointer executes the Base class implementation regardless of the underlying Derived object (early binding based on pointer type).
// Virtual Functions & Dynamic Dispatch Mechanics : Marking a base class method as virtual instructs the compiler to enable Late/Dynamic Binding.
//                                                : vptr (Virtual Pointer): A hidden pointer added to every object of a class containing virtual functions.
//                                                : vtable (Virtual Table) : A static lookup table created per class storing function pointers to its virtual functions.
//                                                : At runtime, ptr->print() dereferences vptr to find the correct vtable slot and calls Derived::print().
//                                                : Size Overhead : Adding even one virtual function increases sizeof(Object) by the size of one pointer (vptr = 4 or 8 bytes).

// Abstract Base Class & Pure Virtual Functions
// Pure Virtual Function : A function declared in a base class with no implementation, set equal to 0 (virtual void draw() = 0;).
// Abstract Base Class (ABC) : Any class containing at least one pure virtual function.
// Interview Core : You cannot instantiate an abstract base class (Shape s; is a compile error).
//                : Any derived class must override all pure virtual functions; otherwise, the derived class also becomes an abstract base class.
//                : Serves as a pure contract/interface provider (equivalent to an interface in Java).

// Data Abstraction vs Encapsulation
// These two concepts are frequently confused in technical interviews, but they address entirely distinct software design concerns
// Abstraction is a Design/Conceptual level idea : It answers "What does the object do?"
// Encapsulation is an Implementation/Security level technique : It answers "How is the object's data protected?"
// Differences : Problem Solved : Reduces code complexity and interface coupling.
//                              : Protects data integrity and prevents invalid state mutations.
//             : How Applied : Outer View : Shows what an object does (e.g., calling sort()).
//                           : Inner View: Controls how data is wrapped and restricted inside.
//             : Real-World Analogy : Driving a car using the steering wheel and pedals without inspecting the combustion engine.
//                                  : Wrapping sensitive medical records inside a locked cabinet accessible only by authorized doctors.

// Class vs. Structure (struct) in C++
// In C++, class and struct are virtually identical in power—both can have member functions, constructors, destructors, access specifiers, and inheritance. Their only difference lies in their default access rules.
// Default in classes is "private" but in "struct" is "public"
// In C, class and struct are completely different things, In pure C, a struct is strictly a passive data container. It has no built-in support for object-oriented programming.
// In C++, a "struct" can inherit from another "struct" or "class" both. And can also get inherited by a "class"
// C++ kept the struct keyword from the C language for backwards compatibility. However, Bjarne Stroustrup (the creator of C++) decided to upgrade struct so that it can do everything a class can do, rather than introducing a completely restricted type.
// In modern C++ development, the choice between them is purely a matter of convention: developers usually use struct for plain data configurations and class when they need complex objects with logic and private data.

// Advanced Usages of this Pointer
// Beyond resolving naming ambiguities inside constructors, this serves critical roles in advanced C++ design patterns
// Method Chaining (Fluent Interface Pattern) : By returning *this (dereferenced pointer) as a reference, methods can be chained together sequentially in a single expression.
//                                            : Example : h1.setHealth(100).setLevel(5);
// Preventing Self-Assignment in Copy Assignment Operators : When overloading operator=, this is compared against the address of the incoming object (&other) to prevent deleting dynamic memory before copying it.
//                                                         : Example : Conditional check "if (this == &other)"
// Passing Current Object to External Functions / Callbacks : When an object needs to register itself with an event listener or pass its own instance to an external manager class.

// -------------------------------------------------- Core C++ Done ---------------------------------------------------------------------------------------------------------------------------------------->
// Always more to explore...
