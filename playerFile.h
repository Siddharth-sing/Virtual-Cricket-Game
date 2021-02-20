/* Player Details will be stored in this library */

#include <string>


class Player {

public:
		std::string name;
		int index;
		int runsScored;
		int ballsPlayed;
		int ballsBowled;
		int runsGiven;
		int wicketsTaken;
    Player()
        {
            runsScored = 0;
            ballsPlayed = 0;
            ballsBowled = 0;
            runsGiven = 0;
            wicketsTaken = 0;
        }
};
