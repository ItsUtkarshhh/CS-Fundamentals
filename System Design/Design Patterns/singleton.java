// -------------------------------------------- Factory Design Pattern ------------------------------------------------->
// -------------------------------------------------- The Problem ------------------------------------------------------------------>
// The Problem : Imagine you are building a database connection pool manager or a heavy configuration loader that reads environment properties from disk.
//             : If every service component in your application instantiates its own manager using new ConfigurationManager(), you run into severe issues
//             : Issues : Resource Exhaustion : Opening dozens of redundant connection pools or file streams.
//                      : State Inconsistency : Different parts of your app reading or modifying diverging copies of configuration data in memory.
//                      : Race Conditions : Multiple loggers trying to write to the same log file without synchronized file locks.

// -------------------------------------------------- The Solution ------------------------------------------------------------------>
// The Solution : The Singleton Pattern restricts instantiation of a class to exactly one object and provides a globally accessible static point of access to that instance.

// Anatomy of the Singleton Pattern : Private Constructor : Prevents external code from calling new MyClass().
//                                  : Private Static Instance Variable : Holds the single reference to the class.
//                                  : Public Static Accessor Method (getInstance()) : Provides global access to the instance, creating it if it doesn't already exist.

// Different Implementations : Naive Implementation : Broken in Multi-threading
//                                                  : Because, In a multi-threaded server (like Spring Boot), two threads could evaluate instance == null simultaneously, resulting in two separate instances being created in memory.
/*
public class NaiveSingleton {
    private static NaiveSingleton instance;

    private NaiveSingleton() {} // Private constructor

    public static NaiveSingleton getInstance() {
        if (instance == null) { // Race condition here!
            instance = new NaiveSingleton();
        }
        return instance;
    }
}
*/

//                           : The Bill Pugh Singleton : This approach leverages the Java Language Specification (JLS) guarantees regarding class loading. Inner static classes are not loaded until they are referenced.
//                                                     : Why its elite : It is thread-safe, achieves lazy initialization without synchronization overhead (synchronized keywords slow down high-throughput methods), and is performant.
/*
public class ConfigurationManager {
    
    private ConfigurationManager() {
        // Initialize expensive resources or read config files once
        System.out.println("Initializing Configuration Manager...");
    }

    // Static inner helper class - loaded on-demand when getInstance() is called
    private static class Holder {
        private static final ConfigurationManager INSTANCE = new ConfigurationManager();
    }

    public static ConfigurationManager getInstance() {
        return Holder.INSTANCE;
    }

    public String getProperty(String key) {
        return "mock_value_for_" + key;
    }
}
*/

//                           : The Enum Singleton : If your singleton doesn't require lazy initialization, Joshua Bloch (author of Effective Java) recommends using an enum.
//                                                : Why it's bulletproof : Enum singletons are inherently serializable, thread-safe, and completely immune to advanced attacks using Java Reflection or deserialization hacks.
/*
public enum Logger {
    INSTANCE; // The single, global instance

    public void log(String message) {
        System.out.println(message);
    }
}
*/

// Rest you will learn buy implementing this pattern in solving problems

// -------------------------------------------------- Nuances, Gotchas, and Best Practices ------------------------------------------------------------------>
// The Testing Nightmare (Global State Pollution) : Gotcha : Singletons introduce hidden global state. If Singleton A modifies shared state during Unit Test 1, Unit Test 2 running afterward may fail because it inherits mutated state.
//                                                : Fix : Avoid stateful singletons where possible. If your singleton holds state, provide a reset method for testing or favor dependency injection containers (like Spring beans) that manage lifecycles cleanly.

// Reflection and Deserialization Vulnerabilities : Gotcha : Standard class-based singletons can be subverted using Java Reflection by making private constructors accessible (constructor.setAccessible(true)), creating a second instance. Similarly, serializing and deserializing a singleton can spawn a duplicate object.
//                                                : Fix : If using standard classes, throw an exception inside the private constructor if an instance already exists, and implement readResolve() for serialization safety. Or, simply use the Enum Singleton approach, which blocks reflection hacks automatically.

// Singleton vs. Spring Beans (@Scope("singleton")) : Gotcha : Developers often confuse the GoF Singleton pattern with Spring's container-managed singleton scope.
//                                                  : Clarification : A GoF Singleton restricts a class to one instance per JVM. A Spring singleton bean restricts a class to one instance per Spring IoC Container ApplicationContext. In enterprise microservices with multiple containers or testing contexts, Spring beans provide better testability and dependency management.

// -------------------------------------------------- When to Use vs. When NOT to Use ------------------------------------------------------------------>
// When to Use (Triggers) : Controlling access to a shared physical or virtual resource (e.g., database connection pool, hardware printer spooler).
//                        : Managing a centralized configuration state or in-memory cache registry read once at application startup.
//                        : Cross-cutting infrastructure services like application-wide logging coordinators.

// When NOT to Use : You need multiple instances configured differently across different workflows or user sessions.
//                 : Code requires high test isolation, where unit tests must run concurrently without state pollution.
//                 : You are using it merely as an excuse to avoid passing dependencies through constructors (Anti-pattern: Service Locator / Global Variable substitute).


// ---------------------------------------- How to Spot Strategy Opportunities in System Design ------------------------------------------------------------------>
// Note : Whenever you notice a component that manages a shared system resource, coordinates global state, or acts as an expensive read-only lookup table initialized once at startup, consider a Singleton.
// Examples across domains : Caches : In-memory LRU token caches or user permission lookup tables.
//                         : Drivers & Pools : Thread pool executors or socket connection managers.
//                         : Registries : Event bus routers or plugin registry managers.

// Always to explore, know & learn more...