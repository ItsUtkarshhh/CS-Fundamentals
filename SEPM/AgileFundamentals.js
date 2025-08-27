// ------------------------------------------- Software Development Life Cycle (SDLC) ---------------------------------------------->
// What is SDLC : Software Development Life Cycle (SDLC) is a structured process used for developing software applications.
//              : It defines phases that guide the development from initial idea to final deployment and maintenance.

// SDLC Phases : Requirement Gathering & Analysis : Understand what the client or user needs.
//                                                : Document functional and non-functional requirements.
//             : System Design : Create architecture and design specifications.
//                             : Decide on technologies, database design, UI/UX, etc.
//             : Implementation (Coding) : Developers write code based on design documents.
//                                       : Use programming languages, frameworks, and tools.
//             : Testing : Verify that the software works as intended.
//                       : Includes unit testing, integration testing, system testing, and user acceptance testing.
//             : Deployment : Release the software to production. Can be done in phases or all at once.
//             : Maintenance : Fix bugs, update features, and ensure performance. Ongoing support and enhancements.

// SDLC Models (Approaches to Execute SDLC): There are multiple models to implement SDLC. Each has its own philosophy and use cases :
// 1. Waterfall Model : Linear and sequential.
//                    : Each phase must be completed before the next begins.
//                    : Best for projects with well-defined requirements.
// 2. V-Model (Validation and Verification) : Extension of Waterfall with testing at every stage.
//                                          : Emphasizes quality and validation.
// 3. Incremental Model : Develop software in small increments.
//                      : Each increment adds functionality.
// 4. Spiral Model : Combines iterative development with risk analysis.
//                 : Suitable for large, complex projects.
// 5. Big Bang Model : No formal planning.
//                   : Developers start coding with minimal requirements.
//                   : High risk, low structure.
// 6. Agile Model : Iterative and incremental.
//                : Focuses on collaboration, customer feedback, and flexibility.
//                : Delivers working software in short cycles (sprints).

// ------------------------------------------- Agile Fundamentals ---------------------------------------------->
// Here, our focus is more on Agile SDLC! So we will move forward with that. Hence starting with Agile Methodology.
// Agile still includes all SDLC phases, but they are repeated in every sprint : Requirements → Design → Development → Testing → Deployment → Feedback.

// What is Agile : Agile is a mindset and methodology focused on, Iterative development, Customer collaboration, Responding to change, Delivering value quickly.
//               : It’s not a single method but a collection of principles and frameworks that guide how teams work and deliver software (or other products).

// Agile Manifesto (The Foundation) : Created in 2001 by 17 software experts, the Agile Manifesto defines the core philosophy of Agile. These 4 core values encourages to Deliver faster, Stay customer-focused, Improve team collaboration & Build better products. They shift the focus from rigid control to flexible, value-driven development.
//                                  : 4 Core Values : Individuals and interactions over processes and tools : Agile values people and communication more than rigid processes or fancy tools. While tools and processes are useful, they should support collaboration—not replace it.
//                                                                                                          : Imagine a team using Jira to track tasks. If they rely solely on Jira updates and never talk to each other, misunderstandings can happen. Agile encourages daily stand-ups and face-to-face (or virtual) conversations to solve problems faster.
//                                                                                                          :  Agile mindset: “Let’s talk and solve this together” rather than “Let’s wait for the tool to update.”
//                                                  : Working software over comprehensive documentation : Delivering functional software is more valuable than producing extensive documentation. Agile prefers lightweight, just-enough documentation that supports development—not slows it down.
//                                                                                                      : In traditional models, teams might spend months writing requirement documents before coding begins. In Agile, teams start building early and adjust based on feedback. A simple user story like : “As a user, I want to reset my password so I can regain access” is often enough to start development.
//                                                                                                      : Agile mindset: “Let’s build and show something that works” rather than “Let’s write everything before we start.”
//                                                  : Customer collaboration over contract negotiation : Agile encourages ongoing collaboration with customers rather than sticking strictly to a contract. The goal is to deliver what the customer truly needs, even if it changes over time.
//                                                                                                     : A client initially asks for a mobile app with 10 features. After seeing the first version, they realize 3 features aren’t needed and want 2 new ones. Agile teams welcome this change and adapt, rather than saying, “That’s not in the contract.”
//                                                                                                     :  Agile mindset: “Let’s work together to build the right thing” rather than “Let’s stick to what we agreed months ago.”
//                                                  : Responding to change over following a plan : Agile embraces change as a natural part of development. While planning is important, Agile teams are flexible and ready to pivot based on feedback or new insights.
//                                                                                               : A startup builds a web app and plans to launch in 3 months. Midway, user feedback shows a major feature isn’t useful. Instead of sticking to the original plan, the team changes direction and builds something better.
//                                                                                               : Agile mindset: “Let’s adapt to what we learn” rather than “Let’s follow the original plan no matter what.”
//                                   : 12 Principles : Our highest priority is to satisfy the customer through early and continuous delivery of valuable software : Example: Instead of waiting 6 months for a full app, deliver a login feature in 2 weeks, then add more features in future sprints.
//                                                   : Welcome changing requirements, even late in development. Agile processes harness change for the customer's competitive advantage : Example: A client wants to change the dashboard layout after seeing a demo. Agile teams say, “Sure, let’s adjust,” instead of “It’s too late.”
//                                                   : Deliver working software frequently, from a couple of weeks to a couple of months, with a preference to the shorter timescale : Example: A team releases a new feature every 2 weeks (sprint), keeping users engaged and getting feedback fast.
//                                                   : Business people and developers must work together daily throughout the project : Example: A product owner (business side) joins daily stand-ups with developers to clarify requirements and priorities.
//                                                   : Build projects around motivated individuals. Give them the environment and support they need, and trust them to get the job done : Example: A manager lets the team choose their tools and approach, offering support but not micromanaging.
//                                                   : The most efficient and effective method of conveying information to and within a development team is face-to-face conversation : Example: Instead of sending a long email, a developer walks over (or hops on a call) to clarify a requirement in minutes.
//                                                   : Working software is the primary measure of progress : Example: A team shows a working login page, not just a design mockup or a status report.
//                                                   : Agile processes promote sustainable development. The sponsors, developers, and users should be able to maintain a constant pace indefinitely : Example: Teams work in 2-week sprints with realistic goals—not 80-hour weeks before deadlines.
//                                                   : Continuous attention to technical excellence and good design enhances agility : Example: Developers write unit tests and refactor code regularly to keep it maintainable.
//                                                   : Simplicity—the art of maximizing the amount of work not done—is essential : Example: Instead of building a complex reporting system, start with a simple export feature that meets the user’s immediate need.
//                                                   : The best architectures, requirements, and designs emerge from self-organizing teams : Example: A team decides how to split tasks and solve problems without waiting for a manager’s instructions.
//                                                   : At regular intervals, the team reflects on how to become more effective, then tunes and adjusts its behavior accordingly : Example: After each sprint, the team holds a retrospective to discuss what went well and what could be better—and makes changes. 

// ------------------------------------------- Working with Agile ---------------------------------------------->
// Agile follows an iterative lifecycle, often broken into sprints (short development cycles) :
// 1. Concept – Define the product vision.
// 2. Inception – Build the team, define initial backlog.
// 3. Iteration/Sprint Planning – Plan what to build in the next sprint.
// 4. Execution – Develop and test features.
// 5. Review – Demo the work to stakeholders.
// 6. Retrospective – Reflect and improve the process.
// 7. Release – Deliver working software to users.
// Here, this cycle repeats every 1–4 weeks.

// Agile Frameworks (Ways to Implement Agile) : Agile is implemented through various frameworks, each with its own structure!
//                                            : Scrum (Most Popular) : Roles : Product Owner, Scrum Master, Development Team.
//                                                                   : Events : Sprint, Daily Scrum, Sprint Review, Sprint Retrospective
//                                                                   : Artifacts : Product Backlog, Sprint Backlog, Increment.
//                                            : Kanban : Visual workflow using a Kanban board.
//                                                     : Focus on continuous delivery and limiting work in progress.
//                                            : Extreme Programming (XP) : Emphasizes technical excellence
//                                                                       : Practices : TDD, Pair Programming, Continuous Integration
//                                            : Lean : Focuses on eliminating waste and maximizing value.
//                                            : SAFe (Scaled Agile Framework) : Designed for large enterprises. Combines Agile, Lean, and DevOps

// ------------------------------------------- Working with Agile - Scrum Specific ---------------------------------------------->
// Note : Going further we will studying, scrum specific roles, events & artifacts. But similar roles, events & artifacts exists in other agile frameworks also!

// Scrum Specific :
// Agile Roles (Who Does What) : These roles are Scrum-specific, but similar roles exist in other Agile frameworks.
//                             : Product Owner : What they do : Owns the product vision and prioritizes what gets built.
//                                             : Example : Decides that the login feature is more important than the profile page for the next sprint.
//                                             : Key responsibility : Manages the Product Backlog.
//                             : Scrum Master : What they do : Ensures the team follows Scrum practices and removes obstacles.
//                                            : Example : Helps resolve a blocker like a server issue or a miscommunication with stakeholders.
//                                            : Key responsibility : Facilitates meetings and coaches the team.
//                             : Development Team : What they do : Builds, tests, and delivers the product.
//                                                : Example : Developers, testers, designers working together to create a feature.
//                                                : Key trait : Cross-functional—they have all the skills needed to deliver.
// Agile Artifacts (Key Documents & Tools) : These are Scrum-specific, but similar concepts exist in other Agile methods.
//                                         : Product Backlog : A prioritized list of everything the product needs.
//                                                           : Example : “Add search bar”, “Enable password reset”, “Improve loading speed”.
//                                         : Sprint Backlog : Items selected from the product backlog for the current sprint.
//                                                          : Example : For this sprint, the team picks “Add search bar” and “Improve loading speed”.
//                                         : Increment : The sum of all completed work in a sprint that adds value.
//                                                     : Example : After Sprint 1, the login and registration features are working and ready to use.
// Agile Events (Scrum-Specific) : These are Scrum ceremonies, but other Agile frameworks have similar practices.
//                               : Sprint Planning : Plan what to build in the upcoming sprint.
//                                                 : Example : Team decides to build the search feature and fix a bug.
//                               : Daily Stand-up : A short daily meeting (15 mins) to sync progress.
//                                                : Example : “Yesterday I fixed the login bug, today I’ll work on the search bar.”
//                               : Sprint Review : Demo the completed work to stakeholders.
//                                               : Example : Show the new search feature to the client and get feedback.
//                               : Sprint Retrospective : Reflect on what went well and what can improve.
//                                                      : Example : “Let’s improve communication and reduce last-minute changes.”
// Agile Metrics (How to Measure Progress) : These are general Agile concepts, used in Scrum and other frameworks.
//                                         : Velocity : Amount of work completed in a sprint (measured in story points).
//                                                    : Example : Team completes 30 story points this sprint.
//                                         : Burndown Chart : Shows remaining work over time.
//                                                          : Example : A graph showing how many tasks are left each day in the sprint.
//                                         : Lead Time & Cycle Time : Lead Time : Time from request to delivery.
//                                                                  : Cycle Time : Time from starting work to finishing it.
//                                                                  : Example : A feature requested on Monday and delivered on Friday has a lead time of 5 days.

// General :
// Agile Tools (Software for Agile Teams) : These tools are general Agile tools, used across Scrum, Kanban, SAFe, etc.
//                                        : Popular Tools : Jira : Most widely used for Scrum and Kanban boards.
//                                                        : Trello : Simple visual board for task tracking.
//                                                        : Azure DevOps : Integrates Agile boards with CI/CD pipelines.
//                                                        : Asana : Task and project management with Agile templates.
//                                                        : ClickUp : All-in-one productivity and Agile management tool.
// Agile Mindset & Culture : This is a general Agile concept, not tied to any specific framework.
//                         : Key Traits : Embrace Change : Agile teams adapt quickly.
//                                      : Promote Collaboration : Everyone works together—no silos.
//                                      : Focus on Customer Value : Build what users need, not just what was planned.
//                                      : Encourage Continuous Improvement : Always look for ways to get better.
// After each sprint, the team reflects and decides to improve communication or reduce technical debt.

// ------------------------------------------- Working with Agile - Agile User Stories ---------------------------------------------->
// What Are Agile User Stories : User Stories are short, simple descriptions of a feature told from the perspective of the end user. They help teams understand what the user wants, why they want it, and how it adds value.
//                             : Format of a User Story : The most common format is, "As a [type of user], I want [some goal] so that [some reason]."
//                                                      : This format keeps the focus on user needs, not technical details.
//                             : Example User Stories : As a registered user, I want to reset my password so that I can regain access to my account.
//                                                    : As a shopper, I want to filter products by price so that I can find affordable options.
//                                                    : As an admin, I want to view user activity logs so that I can monitor system usage.
//                             : Why Are User Stories Important : They simplify requirements.
//                                                              : They keep the team user-focused.
//                                                              : They help in prioritizing work.
//                                                              : They are easy to discuss, estimate, and test.
//                             : How User Stories Fit into Agile : User stories are part of the Product Backlog. During Sprint Planning, the team selects stories to work on and breaks them into tasks.
//                             : Additional Elements of a User Story : To make a user story actionable, teams often add Acceptance Criteria & Story Points.
//                                                                   : Acceptance Criteria : Conditions that must be met for the story to be considered “done.”
//                                                                                         : Example for the password reset story : User receives a reset link via email. Link expires after 24 hours. & Password must meet security rules.
//                                                                   : Story Points : A number representing the effort required to complete the story.
//                                                                                  : Helps in estimating and planning sprints.
//                             : Are User Stories Scrum-Specific? : No—they’re used in Scrum, Kanban, SAFe, and other Agile frameworks. They’re a general Agile practice.

// ------------------------------------------- Working with Agile -  Agile Estimation & Planning ---------------------------------------------->
// Agile estimation and planning are collaborative, flexible, and value-driven. Unlike traditional methods, Agile doesn’t aim for perfect predictions—it focuses on realistic planning based on team capacity and prioritized work.
// Agile Estimation Techniques : Agile estimation helps teams evaluate the effort required to complete user stories or tasks.
//                             : Story Points : A relative measure of effort, complexity, and risk. Not tied to hours—just a way to compare tasks.
//                                            : Example : Login page = 3 points, Dashboard = 8 points, Password reset = 5 points.
//                                            : Think of it like comparing apples, oranges, and watermelons—not measuring exact weight.
//                             : Planning Poker : A collaborative estimation game using cards (usually Fibonacci numbers: 1, 2, 3, 5, 8, 13…).
//                                              : Each team member picks a card to estimate a story.
//                                              : If estimates differ, the team discusses and re-votes.
//                                              : Story : “Add search filter” Dev A: 3 points, Dev B: 8 points → Discussion → Agree on 5 points
//                             : T-Shirt Sizing : Uses sizes like XS, S, M, L, XL to estimate effort. Good for high-level estimation before breaking into story points.
//                                              : Example : “Build user profile” = M, “Integrate payment gateway” = XL.
//                             : Ideal Days : Estimate how many days a task would take without interruptions. Less common in Agile due to its time-based nature, but still used in some teams.

// Agile Planning Techniques : Agile planning happens at multiple levels
//                           : Release Planning : High-level planning for a major product release.
//                                              : Focuses on what features will be delivered and when.
//                                              : Based on velocity and prioritized backlog.
//                                              : Example : “Release v1.0 in 3 months with login, dashboard, and search features.”
//                           : Iteration (Sprint) Planning : Detailed planning for the next sprint (usually 1–4 weeks).
//                                                         : Team selects stories from the backlog based on priority and capacity.
//                                                         : Example : Sprint Goal : “Improve user onboarding”
//                                                                   : Selected Stories : “Signup page”, “Welcome email”, “Tutorial video”
//                           : Daily Planning (Stand-ups) : Quick daily sync to plan the day’s work.
//                                                        : Helps identify blockers and adjust tasks.
//                                                        : Example : “Yesterday I finished the login page. Today I’ll start the dashboard. I’m blocked by API access.”
//                           : Backlog Refinement (Grooming) : Regular session to review, clarify, and estimate backlog items.
//                                                           : Ensures stories are ready for future sprints.
//                                                           : Example : Team discusses “Add dark mode” story, clarifies requirements, and estimates it as 8 points. 

// How Estimation & Planning Work Together : Estimate stories using story points or planning poker.
//                                         : Use velocity (average points per sprint) to plan how many stories fit in a sprint.
//                                         : Plan releases based on total effort and team capacity.
//                                         : Continuously refine and adjust based on feedback and progress.

// ------------------------------------------- Important Topics Completed! - Keep exploring & understanding better ---------------------------------------------->