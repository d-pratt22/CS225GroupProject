#include "ErrorHandling.h"

int BetweenTwoValues(int min, int max, int input) {
	if (min == max) {
		std::cout << "ERROR... NOT POSSIBLE RETURNING 0";
		return 0;
	}

    while (true) {
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "ERROR... INVALID INPUT TYPE... PLEASE ENTER A NUMBER: ";
        }
        else if (input >= min && input <= max) {
            return input;
        }
        else {
            std::cout << "ERROR... INVALID INPUT... PLEASE ENTER A VALUE BETWEEN "
                << min << " AND " << max << ": ";
        }

        std::cin >> input;
    }
}