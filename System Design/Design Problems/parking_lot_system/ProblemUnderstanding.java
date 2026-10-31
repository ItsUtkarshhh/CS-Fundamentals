// ------------------------------------------------------- System Understanding & Overview ------------------------------------------------------------->
// Objects
// Building has floors & following properties : building number, number of floors, building availability - 2 buildings for now
// Floors has parking slots & following properties : floor number, floor availibility, number of parking slots - 20 per floor
// Parking slots has vehicles & following properties : slot number, slot size/type, slot availability
// Vehicle has types & following properties : vehicle number, vehicle size/type - Hatch Back, Compact SUV, SUV, Van, Truck, Bus
// One Building has one entry gate : On Arrival : Check vehicle number & vehicle type
//                                 : Look Up : Check in both buildings for the availability on the basis of  few factors : vehicle type, floor wise slot availability, any vehicle can accomodate in slot size >= vehicle size & nearest floor to reach.
//                                 : Look Up Successful? (Availability) : Can Proceed with Payment
//                                                                      : Choose Payement Provider -> Payment is Processed -> Book the slot in the floor & update the building/floor/slot availbility.
//                                                                      : Print a simple receipt
//                                 : Look Up Un Successful? (No Availability) : Cannot proceed with Payment

// Relationships
// Building & Entry Gate : One-to-Many
// Building & Floors : One-to-Many
// Floors & Slots : One-to-Many
// Vehicle & Slots : One-to-One
// Vehicle & Vehicle Type : One-to-One
// Slots & Slot Type : One-to-One
// User & Payment : One-to-One
// Reciept & Parking Ticket : One-to-One