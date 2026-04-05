#include "Battle.h"

void SetupBattlefield(std::vector<UnitType>& army) {
	std::vector<Unit> units;


}
/*
-Grab list of armies
-One by one ask player/ai to enter in/wasd their ships in a deployment zone warhammer style
-After that is all done, save the x and y and send out that
--Use the Unit.h to create a bunch of references to the objects and then use those in the actual battle

for (int i = 0; i < chosenIndexes.size(); ++i) {
    const UnitType& type = unitTypes[chosenIndexes[i]];

    int x = deployment logic ;
    int y =  deployment logic ;

    units.emplace_back(type, x, y);
}

return units**
*/

/*
-Grab list of armies
-Set up loop to go through each ship one by one
--See if ship is in range of another ship
--If not then move ships based on their movement speed
-If in range then attack the other ships and take into account how armor and all that

-Basically each ship needs to run through a loop to either move or shoot, then play a numbers game
*/