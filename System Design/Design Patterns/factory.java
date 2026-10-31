// -------------------------------------------- Factory Design Pattern ------------------------------------------------->
// -------------------------------------------------- The Problem ------------------------------------------------------------------>
// Problem : Imagine you are building a reporting engine. Users can export reports in PDF, CSV, or Excel formats.
//         : A naive implementation scatters object instantiation across your controllers or services

/*
class ReportService {
    public void generateReport(String format, ReportData data) {
        ReportExporter exporter;
        
        if (format.equalsIgnoreCase("PDF")) {
            exporter = new PdfExporter(); // Tight coupling!
        } else if (format.equalsIgnoreCase("CSV")) {
            exporter = new CsvExporter();
        } else if (format.equalsIgnoreCase("EXCEL")) {
            exporter = new ExcelExporter();
        } else {
            throw new IllegalArgumentException("Unknown format");
        }
        
        exporter.export(data);
    }
}
*/

// Why This Code Fails (SOLID Violations) : Tight Coupling : The ReportService is tightly bound to concrete classes (PdfExporter, CsvExporter), making it impossible to add new exporters without modifying core service code.
//                                        : Open/Closed Principle (OCP) Violation : Every new format requires hacking open existing methods to add another else-if branch.
//                                        : Scattered Initialization : If PdfExporter ever requires complex configuration (like setting up font directories or security certificates), that messy initialization code leaks directly into your business services.

// -------------------------------------------------- The Solution ------------------------------------------------------------------>
// The Solution : The Factory Pattern introduces a dedicated creator component whose sole responsibility is to instantiate and configure objects based on input parameters or configuration, returning them through a shared interface.
// Anatomy of the Factory Pattern : Simple Factory : A single class with a static method that decides which class to instantiate based on parameters.
//                                : Factory Method Pattern : Defines an interface for creating an object, but lets subclasses decide which class to instantiate (deferred instantiation).
//                                : Abstract Factory Pattern : Provides an interface for creating families of related or dependent objects without specifying their concrete classes.

// Note : In modern enterprise engineering, the Simple Factory combined with a Strategy/Registry map is the most common and maintainable pattern.

// Rest you will learn buy implementing this pattern in solving problems

// -------------------------------------------------- Nuances, Gotchas, and Best Practices ------------------------------------------------------------------>
// The "God Factory" Anti-Pattern : Gotcha : Writing a single massive factory class that creates hundreds of unrelated domain objects using giant switch-case blocks.
//                                : Fix : Keep factories scoped to specific domain aggregates (e.g., a PaymentGatewayFactory should only create payment processors, not user profiles or database connections).

// Factory vs. Dependency Injection Containers : Gotcha : Wondering why you need a factory when you have Spring (@Autowired).
//                                             : Clarification : Spring manages object lifecycles when dependencies are static and known at startup. However, when object creation depends on runtime input data (e.g., parsing an incoming webhook payload to determine which event processor to build), dependency injection alone cannot resolve it. You need a Factory to handle runtime parameters.

// Parameterized Factories : Sometimes concrete products require specific runtime constructor arguments (e.g., building a file parser that needs the target file path). Ensure your factory methods accept necessary initialization parameters cleanly without violating encapsulation.

// -------------------------------------------------- When to Use vs. When NOT to Use ------------------------------------------------------------------>
// When to Use (Triggers) : Object creation involves complex logic, configuration parsing, or conditional selection.
//                        : You want to shield client code from the exact concrete classes being instantiated.
//                        : The exact type of object to create is only known at runtime based on user input, database state, or file headers.

// When NOT to Use : Objects can be instantiated cleanly via simple constructor calls (new MyObject()) with no configuration overhead.
//                 : You only ever have one concrete implementation of an interface and zero plans for expansion.
//                 : Over-engineering simple domain models by wrapping every entity creation step in a dedicated factory.

// ---------------------------------------- How to Spot Strategy Opportunities in System Design ------------------------------------------------------------------>
// Note : Whenever you notice code that inspects an object's properties or configuration strings and then decides which class to instantiate using new, you are looking at a prime candidate for the Factory Pattern.
// Examples across domains : Parsers : Instantiating JSON, YAML, XML, or Markdown parsers based on file extensions.
//                         : Notification Connectors : Creating Firebase, Twilio, or SMTP client instances based on tenant configuration.
//                         : Payment Gateways : Initializing Stripe, PayPal, or Razorpay client wrappers based on regional currency rules.

// Always to explore, know & learn more...