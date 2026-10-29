// ------------------------------------------------------- System Understanding & Overview ------------------------------------------------------------->
// : There are vehicles of different types : Lets take Hatch Back Car, Compact SUV Car, SUV Car, Van, Truck, Bus for now
//                              : Then there are some Parking Buildings : Lets take one two buildings for now
//                              : Every building will have multiple floors : Lets take building 1 as 5 floors & building 2 has 4 floors
//                              : Every floor will have multiple parking slots : Lets take each floor has 45 parkig slots in both buildings for now
//                              : Every parking slot can contain different type of vehicle : SlotType A-F
//                              : Every building has one single entry point for any vehicle, and from there it must go to its own parking slot
//                              : Every parking slot can be used by any vehicle if the size of the parking slot is enough for the vehicle to park, so its like one type or parking slots can have multiple type of vehicle, but it depends on the size of parking slot, like hatch back can park in truck lets say E slotType, but truck cannot be parked in the hatch back slotType lets say A
//                              : If two vehicles tries to book one parking slot at the same time, then handle the concurrency there
//                              : The system should be extensible & scalable friendly to future requirements, if number of vehicles, floors, buildings, parking slots increases, it should be able to handle it well
//                              : Once the vehicle gets parked, it should simply send notifications to the user about the vehicle is parked
//                              : When the vehicle enters the gate, the selection of the slot will be bottom up approach, which means first it will be checked whether it can be accommodated in the ground floor or not and then keep on checking on every floor from bottom up (Or will see the strategy for the lookup and allocation)
//                              : Life cycle : Arrival - Look Up Starts - Slot Found? Yes : Confirm Payment - Payment Done? Yes - Slot Confirmed - Generate the ticket with the building number, floor number, slot number, vehicle type
//                                                                                                          - Payment Done? No - Slot cannot be confirmed
//                                                                      - Slot Found? No : Can't proceed with slot allocation
//                                           : Slot Status : Allocated / Unallocated

// Core Entities, Actors, Behaviours & Relationships : Entities & Actors : Building (Class), Floor (Class), Slot (Class), SlotType (Enum), Vehicle (Interface), Concrete Vehicles (Class), PaymentDetails (Class & DTO), NotificationDetails (Class & DTO)

// 


// If slot available then confirm for the payment, If slot is available generate the ticket mentioning the building number, floor number & slot number for the vehicle type
//                                           : If after look up, its been seen that there is no space available for the vehicle type, then simply decline

// Problem Statement : 