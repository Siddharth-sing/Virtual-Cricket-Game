/* Team Details will be stored in this library */


#include<vector>
#include"player.h"
class Team
{
public:
   std::string name;
   int totalRunsScored;
   int totalBallsBowled;
   int wicketLost;
   std::vector<Player>players;
  Team()
    {
        totalRunsScored=0;
        wicketLost=0;
        totalBallsBowled=0;
    }
};
