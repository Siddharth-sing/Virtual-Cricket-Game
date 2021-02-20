/* Main Function */

#include"game.h"
using namespace std;

int main()
{
    Game game;
    game.welcome();
    cout<< "\n Press Enter to continue \n";
    getchar();
    game.showAllPlayers();

    cout<< "\n Press Enter to continue \n";
    getchar();
    game.selectPlayer();

    game.displayTeam();

        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|===============        Let's Toss      ===============|"<<endl;
        cout<<"|------------------------------------------------------|"<<endl;

    cin.ignore(numeric_limits<streamsize>::max(),'\n'); //To remove input buffer memory
    cout<< "\n Press Enter to Toss \n";
    getchar();
    game.toss();

    game.startFirstInning();
    cout<< "\n Players are resting press enter for further information ... \n";

    cin.ignore(numeric_limits<streamsize>::max(),'\n'); //To remove input buffer memory
    cout<< "\n Press Enter to start second Inning \n";
    getchar();
    game.startSecondInning();


return 0;
}
