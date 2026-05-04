// --------------------------------------------------------------------------- System Design Introduction ---------------------------------------------------------------------------->
// Introduction : System Design is the process of defining the architecture, components, modules, interfaces, and data for a system to satisfy specified requirements.
//              : Think of it as the blueprint for a building. Before you start laying bricks (writing code), you need to know how the plumbing works, where the load-bearing walls are, and how many people the building can hold.

// Types of System Design : High Level Design & Low Level Design
//                        : HLD : HLD focuses on the macro-view of the system. It describes the overall architecture and how different services interact with one another.
//                              : Examples : Database choice (SQL vs. NoSQL), load balancers, microservices vs. monolith, and third-party integrations.
//                              : Conclusion : A bird's-eye view diagram showing the flow of data across the entire platform.
//                        : LLD : LLD focuses on the micro-view. It gets into the "nitty-gritty" details of how specific components are built.
//                              : Examples : Class diagrams, method signatures, design patterns (like Singleton or Factory), and specific logic flows.
//                              : Conclusion : Detailed documentation that a developer can use to write the actual code.

// Real World Application : System design is what allows your favorite apps to handle millions of users without crashing.
//                        : Here is where it is applied : Scalable Social Media (e.g., Instagram, X) : The Challenge : Millions of people posting and viewing content simultaneously.
//                                                                                                   : The Design : ses Load Balancers to distribute traffic and Caching (like Redis) to show you your feed instantly without hitting the main database every time.
//                                                      : Streaming Services (e.g., Netflix, YouTube) : The Challenge : Delivering high-definition video globally with zero lag.
//                                                                                                    : The Design : Uses Content Delivery Networks (CDNs). These are servers placed all over the world that store copies of videos closer to the user’s physical location.
//                                                      : E-commerce Platforms (e.g., Amazon) : The Challenge : Managing inventory and processing payments across different time zones.
//                                                                                            : The Design : Uses Microservices. The "Payment" service is completely separate from the "Search" service. If the search bar breaks, you can still finish your checkout.
//                                                      : Financial Systems (e.g., Banking Apps) : The Challenge : Data integrity. You cannot "lose" a transaction.
//                                                                                                : The Design : Focuses on Database ACID properties (Atomicity, Consistency, Isolation, Durability) to ensure that every cent is accounted for, even if the system loses power mid-transaction.

// Overall, without proper system design, an app might work fine for 10 users but explode when it reaches 10,000. It is the difference between a small local shop and a global franchise.

// --------------------------------------------------------------------------- OOPS ---------------------------------------------------------------------------->
