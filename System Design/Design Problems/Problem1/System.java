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
//        : GateType (Iterface) : Entry Gate & Exit Gate can be concrete impls
//        : Entry Gate (Entity Class) : Number of gates can increase
//        : Exit Gate (Entity Class) : Number of gates can increase
//        : Ticket (Entity Class) : Creates & saves ticket state & details
//        : Payment Service (Service Class) : Uses different payment strategies & other classes for payement related operations
//        : Payment (Interface) : Provides some default methods & behaviours
//        : Payment Providers (Concrete Implementation Class) : Implements the payment interface & can increase in numbers
//        : Payment Status (Enum) : Three possible values
//        : Parking Lot Manager (Orchestrator Class) : Behaves like admin class, to keep a check on the system, ticket, slot booking, extensibility

// Step 2 : Properties & State
//        : Building : Building Number, List of Floors, List of Entry Gate, List of Exit Gate
//        : Floor : Floor Number, List of parking slots
//        : Parking Slot : Slot Number, Slot Type, Slot Availability Status
//        : Slot Type : SMALL, MEDIUM, BIG
//        : Vehicle (Entity Abstract Class) : Vehicle number, vehicle type, ticket vehicle is holding
//        : Vehicle Impl Class : HatchBack, SUV, Truck
//        : Vehicle Types : HatchBack, SUV, Truck
//        : Entry Gate : Gate Number, Gate type, Parking Lot Manager refernce
//        : Exit Gate : Gate Number, Gate type, Parking Lot Manager, Payment Service
//        : Ticket : Ticket ID, Timestamp, Vehicle class refernce, Ticket valid status, Parking slot
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