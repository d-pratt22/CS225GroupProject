//Start of Project!!

/*

What is the game
-Control army to conquer map
-Build up army with different units to battle other armies (type object pattern?)
-AI agent for the enemy armies for them to move around (decision trees?)
-Similar to Total War games

*/

/*

Structure of game
-Start game
--Short introduction and worldbuilding
--Build first army with a limited amount of funds and some help
--Overview of map and what symbols mean

-Game loop-
-Movement phase
--Player moves ships to new system or doesn't move at all
--AI moves ships around
-Battle phase
--If two different armies are on the same spot they enter a battle
--If player is in a battle then they will designate positions for units and begin the battle
--In the back end the numbers are just going and doing damage and all of that kind of stuff
--After battle remenant of losing fleet will move a space back
--Winning army will take the space and claim it
--If the battle takes place in a home system and the losers were the owners they are out of the game
-Build phase
--Players can build more ships using resources if they are on a starbase
--If on a spot that has no starbase the player is able to build one for resources
--AI also builds things
-Back to the top until a winner is declared

-End game
--If a player has taken every square and/or killed every army they will win and get a victory message
--If the player has lost a battle in their home system they lose

*/

/*

To Do List
-Set up the army builder
--Possibly type object to make creation easier

-Need the following parameters for the army/units
--Size of army
--Type of units in army
--Amount of each unit in army
--Strength of the army
--Strength of individual units

-Create the army class

-Create class and maybe use case diagram before beginning coding

-Make a simmple AI agent to control enemy armies
--Use something like a decision tree or simple neural network

-Start visuals
--Install some packages for graphics

*/