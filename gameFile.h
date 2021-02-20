/* This library stores every detail needed for the game */


#include<iostream>
#include<cstdlib>
#include<limits>
#include<ctime>
#include"team.h"
using namespace std;
class Game
{
public:
    Game()
    {
        playersPerTeam=4;
        maxBalls=6;
        totalPlayers=11;

        players[0] = "Virat";
        players[1] = "Rohit";
        players[2] = "Dhawan";
        players[3] = "Pant";
        players[4] = "D.Karthik";
        players[5] = "KLRahul";
        players[6] = "Jadeja";
        players[7] = "Hardik";
        players[8] = "Bumrah";
        players[9] = "BKumar";
        players[10] = "Ishant";

        isFirstInning=false;
        teamA.name="Team-A";
        teamB.name="Team-B";
    }

       int playersPerTeam;
       int maxBalls;
       int totalPlayers;
       std::string players[11];

       bool isFirstInning;
       Team teamA,teamB;
       Team *battingTeam,*bowlingTeam;
       Player *batsman,*bowler;

    void welcome()
        {
            cout << "______________________________________________________"<<endl;
            cout << "|*********************** SUPER-OVER *****************|"<<endl;
            cout << "|                                                    |"<<endl;
            cout << "|              Welcome to Virtual SUPER-OVER         |"<<endl;
            cout << "|****************************************************|"<<endl;
            cout << "|____________________________________________________|\n"<<endl;


            cout << "_________________________________________________________________________________"<<endl;
            cout << "================================ Instruction ====================================|\n"<<endl;
            cout << "|******************************* SUPER-OVER *************************************|"<<endl;
            cout << "|                                                                                |"<<endl;
            cout << "|1.Create two teams(Team-A and Team-B) with 4 players each from 11 players pool. |"<<endl;
            cout << "|2.Lead the toss and decide the choice of play.                                  |"<<endl;
            cout << "|3.Since it is super over so only 6 balls are available.                         |"<<endl;
            cout << "|                                                                                |"<<endl;
            cout << "|********************************************************************************|"<<endl;
            cout << "|________________________________________________________________________________|"<<endl;
        }
    void showAllPlayers()
    {
        cout<<"-----------------------------------------------"<<endl;
        cout<<"|===============Pool of Players===============|"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        for(int i=0;i<11;i++)
        {
            cout<<"\t\tPlayer "<<i<<" : "<<players[i]<<endl;
        }
    }
    int takeIntegerInput()
    {
       int n;

        while (!(cin >> n))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please try again with valid input: ";
        }
     return n;
    }
    void selectPlayer()
    {
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|=============== Create Team-A & Team-B ===============|"<<endl;
        cout<<"|------------------------------------------------------|"<<endl;
        for(int i=0;i<playersPerTeam;i++)
        {
            teamASelection:
            cout<<"Select player "<<i+1<<" for Team-A : ";
            int playerIndexTeamA=takeIntegerInput();
            if(playerIndexTeamA < 0 || playerIndexTeamA > 10)
            {
                cout<<"Enter Valid Index Please\n";
                goto teamASelection;
            }
            else if(validatePlayer(playerIndexTeamA))
            {
                cout<<"Player has been selected already\n";
                goto teamASelection;
            }
            else
            {
                Player teamAPlayer;
                teamAPlayer.index=playerIndexTeamA;
                teamAPlayer.name=players[playerIndexTeamA];
                teamA.players.push_back(teamAPlayer);

            }

            teamBSelection:
            cout<<"Select player "<<i+1<<" for Team-B : ";
            int playerIndexTeamB=takeIntegerInput();
            if(playerIndexTeamB < 0 || playerIndexTeamB > 10)
            {
                cout<<"Enter Valid Index Please\n";
                goto teamBSelection;
            }
            else if(validatePlayer(playerIndexTeamB))
            {
                cout<<"Player has been selected already\n";
                goto teamBSelection;
            }
            else
            {
                Player teamBPlayer;
                teamBPlayer.index=playerIndexTeamB;
                teamBPlayer.name=players[playerIndexTeamB];
                teamB.players.push_back(teamBPlayer);
            }
        }

    }
    bool validatePlayer(int index)
    {
        int n;
        vector<Player>players;
        players=teamA.players;
        n=players.size();
        for(int i=0;i<n;i++)
        {
            if(players[i].index==index)
            {
                return true;
            }
        }

        players=teamB.players;
        n=players.size();
        for(int i=0;i<n;i++)
        {
            if(players[i].index==index)
            {
                return true;
            }
        }
      return false;
    }
    void displayTeam()
    {
        cout << endl << endl;
        cout << "--------------------------\t\t--------------------------" << endl;
        cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
        cout << "--------------------------\t\t--------------------------" << endl;

        for (int i = 0; i < playersPerTeam; i++)
        {
            cout << "|\t" << "[" << i << "] " << teamA.players[i].name << "\t |"
                << "\t\t"
                << "|\t" << "[" << i << "] " << teamB.players[i].name << "\t |" << endl;
        }
        cout << "--------------------------\t\t--------------------------" <<endl<<endl;
    }
    void toss()
    {
        srand(time(NULL));
        int randomValue = rand() % 2;	// 0 or 1

        switch (randomValue)
        {
            case 0:
                cout << "Team-A won the toss" << endl << endl;
                tossChoice(teamA);
                break;
            case 1:
                cout << "Team-B won the toss" << endl << endl;
                tossChoice(teamB);
                break;
        }
    }
    void tossChoice(Team tossWinnerTeam)
    {
          cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" << endl
        	 << "2. Bowl " << endl;

        int tossInput = takeIntegerInput();

        cin.ignore(numeric_limits<streamsize>::max(),'\n');

	  switch (tossInput)
        {
            case 1:
                cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;

                if (tossWinnerTeam.name.compare("Team-A") == 0) {	 // if Team-A is the toss winner
                    battingTeam = &teamA;
                    bowlingTeam = &teamB;
                } else {	// else Team-B is the toss winner
                    battingTeam = &teamB;
                    bowlingTeam = &teamA;
                }

                break;
            case 2:
                cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

                if (tossWinnerTeam.name.compare("Team-A") == 0) {	// if Team-A is the toss winner
                    bowlingTeam = &teamA;
                    battingTeam = &teamB;
                } else {	// else Team-B is the toss winner
                    bowlingTeam = &teamB;
                    battingTeam = &teamA;
                }

                break;
            default:
                cout << endl << "Invalid input. Please try again:" << endl << endl;
                tossChoice(tossWinnerTeam);
                break;
        }
    }

    void startFirstInning()
    {
      cout<<"\t\t ||| FIRST INNING STARTS ||| \t\t"<<endl<<endl;
      isFirstInning=true;

      initializePlayers(isFirstInning);
      playInnings();
    }
    void startSecondInning()
    {
      cout<<"\t\t ||| SECOND INNING STARTS ||| \t\t"<<endl<<endl;
      isFirstInning=false;

      Team *temp;
      temp=battingTeam;
      battingTeam=bowlingTeam;
      bowlingTeam=temp;
      initializePlayers(isFirstInning);
      playInnings();
    }


    void initializePlayers(bool first)
    {
       if(first==true)
        {
               batsman=&battingTeam->players[0];
               bowler=&bowlingTeam->players[0];
               cout<<battingTeam->name<<"-->"<<batsman->name<<" is batting "<<endl;
               cout<<bowlingTeam->name<<"-->"<<bowler->name<<" is bowling "<<endl;
        }
       else
        {
               batsman=&battingTeam->players[0];
               bowler=&bowlingTeam->players[0];
               cout<<battingTeam->name<<"-->"<<batsman->name<<" is batting "<<endl;
               cout<<bowlingTeam->name<<"-->"<<bowler->name<<" is bowling "<<endl;
        }
    }

    void playInnings()
    {
        for(int i=0;i<6;i++)
        {
            cout<< "\n Press Enter to bowl ... \n";
            getchar();
            cout<< "\nBowling ... \n";
            bat();

            if(!validateInningsScore())
                break;
        }
    }
    void bat()
    {
        srand(time(NULL));
        int runsScored=rand()%7;
        //update batting team
        batsman->runsScored = batsman->runsScored + runsScored;
        battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
        batsman->ballsPlayed = batsman->ballsPlayed + 1;

        //update bowling team
        bowler->ballsBowled = bowler->ballsBowled + 1;
        bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
        bowler->runsGiven = bowler->runsGiven + runsScored;

       if(runsScored!=0)
        {
            cout<<"\n"<<bowler->name<< " given "<<runsScored<<" runs to "<<batsman->name<<endl<<endl;
            showGameScoreCard();
        }
       else
        {
            cout<<bowler->name<< " taken wicket of "<<batsman->name<<endl<<endl;
            showGameScoreCard();
            battingTeam->wicketLost = battingTeam->wicketLost + 1;
            bowler->wicketsTaken = bowler->wicketsTaken + 1;

            batsman=&battingTeam->players[battingTeam->wicketLost];
        }
    }
    bool validateInningsScore()
    {
        if(isFirstInning)
        {
            if(battingTeam->wicketLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
            {
                cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

                cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "<< battingTeam->wicketLost << " (" << bowlingTeam->totalBallsBowled<< ")" << endl;

                cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1<< " runs to win the match" << endl << endl;

                return false;
            }

        }
        else
        {
            if(bowlingTeam->totalRunsScored < battingTeam->totalRunsScored)
            {
                cout << "\t\t ||| SECOND INNINGS ENDS ||| " << endl << endl;
                announceWinner();
            }
            else
            {
                if(battingTeam->wicketLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
                {
                        cout << "\t\t ||| SECOND INNINGS ENDS ||| " << endl << endl;
                        cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "<< battingTeam->wicketLost << " (" << bowlingTeam->totalBallsBowled<< ")" << endl;
                        announceWinner();
                }
            }

        }
      return true;
    }
    void showGameScoreCard()
    {

        cout<<"\nThis is scorecard\n";
        cout << "--------------------------------------------------------------------------" << endl;

        cout << "\t" << battingTeam->name << "  " << battingTeam->totalRunsScored << " - "<< battingTeam->wicketLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name<< " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "<< bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

        cout << "--------------------------------------------------------------------------" << endl << endl;
    }
    void announceWinner()
    {
        if(bowlingTeam->totalRunsScored < battingTeam->totalRunsScored)
        {
            cout<<"|**********************************************************************************|"<<endl;
            cout<<"|        CONGRATULATION TO "<<battingTeam->name<<" YOU WILL BRING THE CUP          |"<<endl;
            cout<<"|**********************************************************************************|"<<endl;
        }
        else if(bowlingTeam->totalRunsScored > battingTeam->totalRunsScored)
        {
            cout<<"\n|**********************************************************************************|"<<endl;
            cout<<"       ||| CONGRATULATION TO "<<bowlingTeam->name<<" YOU WILL BRING THE CUP|||      "<<endl;
            cout<<"|**********************************************************************************|"<<endl;
        }
        else
        {
            cout<<"|**********************************************************************************|"<<endl;
            cout<<"|                                  IT's A TIE :(                                   |"<<endl;
            cout<<"|**********************************************************************************|"<<endl;
        }

        cout<<"\n\n\t\t||||||MATCH ENDS||||||\t\t\n\n";


        cout<<"Awesome Match, Press enter for further information ...\n";

        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //To remove input buffer memory
        cout<<"Press Enter to see Match Stats ...";
        getchar();


        cout<<"\n\nMatch Stats\n\n";
            cout<<battingTeam->name<<endl;
            cout<<"Player \t\t Batting \t\t Bowling"<<endl;
            cout<< " ------------------------------------- " <<endl;
        for(int i=0;i<4;i++)
        {
            cout <<"  "<<battingTeam->players[i].name <<"\t\t"<<battingTeam->players[i].runsScored<< "(" << battingTeam->players[i].ballsPlayed<< ")\t\t" << battingTeam->players[i].ballsBowled<<"-"<< battingTeam->players[i].runsGiven<< "-" << battingTeam->players[i].wicketsTaken << endl;
            cout<< " ------------------------------------- " <<endl;
        }

        cout<<"\n\n"<<bowlingTeam->name<<endl;
        cout<<"Player \t Batting \t Bowling"<<endl;
            cout<< " ------------------------------------- " <<endl;
        for(int i=0;i<4;i++)
        {
            cout <<bowlingTeam->players[i].name <<"\t\t"<<bowlingTeam->players[i].runsScored<< "(" << bowlingTeam->players[i].ballsPlayed<< ")\t\t" << bowlingTeam->players[i].ballsBowled<<"-"<< bowlingTeam->players[i].runsGiven<< "-" << bowlingTeam->players[i].wicketsTaken << endl;
            cout<< " ------------------------------------- " <<endl;
        }

    }


};
