// ------------------------------------------------------------- Parking Lot System ------------------------------------------------------------->
// ------------------------------------------------------- System Understanding & Overview ------------------------------------------------------------->
// Step 0 : Flow, Requirements & Scope
//        : In Scope Flow : Vehicle(s) arrived at our entry gate(s).
//                        : Entry Gate(s) started to look up for availability of slots in the building(s)
//                        : If Slot Found : The Entry Gate allocates a slot for the vehicle
//                                        : Entry Gate generated a receipt with vehicle details & time stamp 
//                                        : Vehicle gets a reciept/ticket to enter. With some details mentioned including building, slot & floor number
//                                        : Vehicle goes there to the exact slot & parks the vehicle. 
//                                        : Vehicle comes back at the Exit Gate(s) and return the ticket. The Exit Gate verifies the ticket & checks the details & timestamp. And calculates money to pay depending upon time
//                                        : Exit Gate asks asks for the Payment with different payment providers
//                                        : Vehicle proceeds with the payment & the slot gets un-allocated again.
//                         : If Slot Not Found : No Slot Available message displays
//        : Out Of Scope & Future Improvements : Bigger slots can accomodate any one smaller vehicle
//                                             : Multi-level parking complex routing algorithms (shortest path to slot)
//                                             : Dynamic pricing based on normal vs peak hours
//                                             : EV charging station allocation
//                                             : Some buildings/floors/slots are opened some are closes

// Step 1 : Domain Modeling & Extensibility
//        : Building (Entity Class) : Number of buildings can increase
//        : Floor (Entity Class) : Number of floors can increase
//        : Parking Slot (Entity Class) : Number of slots can increase
//        : SlotType (Enum) : Number of slotype can increase
//        : Vehicle (Entity Abstract Class) : Base model class for shared properties
//        : Vehicles Subclass (Entity Class) : Varies in types
//        : VehicleType (Enum) : Number of vehicle types can increase
//        : GateType (Interface) : Entry Gate & Exit Gate can be concrete impls
//        : Entry Gate (Entity Class) : Number of gates can increase
//        : Exit Gate (Entity Class) : Number of gates can increase
//        : Ticket (Entity Class) : Saves ticket state & details
//        : Payment (Interface) : Provides some default methods & behaviours
//        : Payment Providers (Concrete Implementation Class) : Implements the payment interface & can increase in numbers
//        : Payment Service (Service Class) : Uses different payment strategies & other classes for payement related operations
//        : Payment Status (Enum) : Three possible values
//        : Parking Lot Manager (Orchestrator Class) : Behaves like admin class, to keep a check on the system, ticket, slot booking, extensibility

// Step 2 : Properties & State
//        : Building : Building Number, List of Floors, List of Entry Gate, List of Exit Gate
//        : Floor : Floor Number, List of parking slots
//        : Parking Slot : Slot Number, Slot Type, Slot Availability Status (true/false)
//        : Slot Type : SMALL, MEDIUM, BIG
//        : Vehicle (Entity Abstract Class) : Vehicle number, vehicle type, ticket vehicle is holding
//        : Vehicle Impl Class : HatchBack, SUV, Truck
//        : Vehicle Types : HatchBack, SUV, Truck
//        : Entry Gate : Gate Number, Gate type, Parking Lot Manager refernce
//        : Exit Gate : Gate Number, Gate type, Parking Lot Manager, Payment Service
//        : Ticket : Ticket ID, Timestamp, Vehicle class reference, Ticket valid status, Parking slot
//        : Payment Interface : No State
//        : Payment Providers Classes : Transaction ID, Transaction Date, Transaction Time, Transaction amount, Payment status
//        : Payment Status : NEW, PENDING, SUCCESS
//        : Parking Lot Manager : List of buildings, List of active tickets

// Step 3 : Behaviors & Core Contracts
//        : Building : Add/RemoveFloor(), Add/RemoveEntryGate(), Add/RemoveExitGate()
//        : Floor : Add/RemoveParkingSlots()
//        : Parking Slot : setSlotAvailability()
//        : Vehicle : getVehicleNumber(), keepTicket(), giveTicket()
//        : Gate : CheckVehicleDetails(), Parking Lots HandleTicket()
//        : Entry Gate : CheckVehicleDetails(), HandleTicket() - Generates Ticket
//        : Exit Gate : CheckVehicleDetails(), HandleTicket() - Revokes Ticket
//        : 

// Steps 0-3 In Effect!
// Building (Entity Class) : Properties : buildingNumber, List of floors, List of entry gates, List of exit gates
//                         : Behaviours : addFloor(), 


// Suppose I am solving the parking lot system problem... I am designing the building entity right now... With these properties : buildingNumber, List of floors, List of entry gates, List of exit gates And now.. I also want to add a behaviour that is addFloors()... should I add it here in this class?? Explain in proper realisitic manner! 

Adding addFloor() (or mutating physical infrastructure) directly inside an operational domain entity like Building depends heavily on what stage of the system lifecycle this class represents.

In a realistic, enterprise-grade Parking Lot System, no, you generally should not treat addFloor() as a core runtime behavior of Building, or at least not without strictly distinguishing between administrative management vs. operational tracking.

The Realistic Reality: Administration vs. Operations
A parking lot system serves two distinct purposes:

Operational Runtime: Gate entry/exit, ticket generation, spot allocation, fee calculation.

Back-Office Configuration (Admin/Provisioning): Onboarding new garages, adding floors, reconfiguring layouts, setting rates.

If your Building class represents the live system entity handling real-time parking operations, adding physical floors mid-operation isn't a runtime responsibility—it is an administrative workflow.

Why Not Directly in Building?
1. Real-World Lifespan & Concurrency
Floors are not dynamically created during parking lot operations. Adding a floor is a rare, schema-altering event that impacts:

Overall parking lot capacity

Navigation & routing algorithms

Spot indexing (e.g., floor number prefixes, spot numbering)

Sensor/display board mappings

If multiple threads or microservices are querying available spots or routing vehicles to floors, exposing a naive addFloor(Floor floor) method on an in-memory Building aggregate opens up synchronization and consistency hazards unless wrapped inside a dedicated transaction and audit pipeline.

2. Single Responsibility Principle (SRP)
The Building entity’s responsibility is to maintain the state and structure of the building.

Who validates that the floor number isn't duplicate?

Who ensures the new floor has minimum required parking bays, emergency exits, or electrical infrastructure mapped?

Who triggers database migrations or invalidates cache entries?

Handling this logic inside Building bloats the entity with administrative validation rules.

Where It Actually Belongs
In modern object-oriented and Domain-Driven Design (DDD) patterns, you separate the entity's internal encapsulation from the management service.

Option A: Clean Layering (Service + Guarded Mutation)
Keep the internal mutation minimal and protected, and drive the behavior through an administrative service.

Java
// Domain Entity
public class Building {
    private final String buildingId;
    private final List<Floor> floors = new ArrayList<>();
    private final List<Gate> entryGates = new ArrayList<>();
    private final List<Gate> exitGates = new ArrayList<>();

    // Package-private or protected constructor/mutation:
    // Only domain factories or administrative services should invoke this.
    void attachFloor(Floor floor) {
        // Enforce invariants only (e.g., no duplicate floor IDs)
        if (floors.stream().anyMatch(f -> f.getFloorNumber() == floor.getFloorNumber())) {
            throw new DuplicateFloorException("Floor already exists: " + floor.getFloorNumber());
        }
        this.floors.add(floor);
    }

    public List<Floor> getFloors() {
        return Collections.unmodifiableList(floors);
    }
}
Java
// Application / Admin Service
public class ParkingInfrastructureService {
    private final BuildingRepository buildingRepo;
    private final CapacityRegistry capacityRegistry;

    public void addFloorToBuilding(String buildingId, FloorCreationRequest request) {
        Building building = buildingRepo.findById(buildingId);
        
        Floor newFloor = new Floor(request.getFloorNumber(), request.getSpots());
        building.attachFloor(newFloor);
        
        // Recompute indexes, update persistence, notify display boards
        buildingRepo.save(building);
        capacityRegistry.recalculate(buildingId);
    }
}
Option B: Builder / Immutability Pattern (Recommended for LLD Interviews)
In Low-Level Design (LLD) machine-coding interviews, physical layout is typically configured once at startup and read frequently:

Treat the building layout as essentially immutable during runtime.

Use a Building.Builder or an InfrastructureManager during initialization.

Java
Building building = new Building.Builder("B-1")
    .addFloor(new Floor(1))
    .addFloor(new Floor(2))
    .addEntryGate(new EntryGate("G-IN-1"))
    .addExitGate(new ExitGate("G-OUT-1"))
    .build();
The Verdict
If this is a small simulation or builder pattern: Having an addFloor(Floor floor) or doing it via a Builder is fine for structural construction.

If this is a production-like design: Keep Building focused on tracking state and answering queries (e.g., getAvailableSpots(), findNearestFloorWithSpace()). Delegate structural changes (addFloor, decommissionFloor) to a dedicated Administrative/Infrastructure Service that manages validations, persistence, and system-wide capacity updates.