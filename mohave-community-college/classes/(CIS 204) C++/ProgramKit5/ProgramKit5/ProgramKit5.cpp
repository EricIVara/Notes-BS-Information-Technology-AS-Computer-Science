// Invasion of the Alien Race

#include <iostream>
#include <string>
using namespace std;

class Room
{
public:
    Room(string nm, string dr, string di, bool n, bool s, bool e, bool w)
    {
        name = nm;
        description = dr;
        directions = di;
        north = n;
        south = s;
        east = e;
        west = w;
    }
    Room()
    {
        name = "Blank";
        description = "Blank Room *ERROR*";
        directions = "No Directions *ERROR*";
        north = false;
        south = false;
        east = false;
        west = false;
    }

    void PrintRoom()
    {
        cout << endl << "-----------------------------------------------------------------------" << endl;
        cout << "You enter " << name << ":" << endl;
        cout << description << endl;
    }

    string GetChoice()
    {
        bool validChoice = false;
        string myChoice = "";

        cout << directions << endl;

        do
        {
            cout << "Command: [north], [south], [east], [west]?" << endl;
            cin >> myChoice;

            if (myChoice == "north" && north == true)
                validChoice = true;
            else if (myChoice == "south" && south == true)
                validChoice = true;
            else if (myChoice == "east" && east == true)
                validChoice = true;
            else if (myChoice == "west" && west == true)
                validChoice = true;
            else if (north == false && south == false && east == false && west == false)
            {
                validChoice = true;
                myChoice = "Game Over";
            }
            else
                cout << "Invalid choice!" << endl;

        } while (!validChoice);

        return myChoice;
    }

private:
    string name;
    string description;
    string directions;
    bool north, south, east, west;
};

void IntroductionStory()
{
    cout << "Once during an unusual time, there was a broken and dark planet called" << endl; // intorduction
    cout << "Earth. Earth was invaded and overrun by a different species not from this" << endl;
    cout << "universe. While the humans fought bravely, the invading alien race fought" << endl;
    cout << "harder. During this long and violent battle against the alien race, the humans" << endl;
    cout << "eventually became overwhelmed, imprisoned, and now rely on hope or some other" << endl;
    cout << "entity to save them from this unprepared alien invasion. It is up to you hero to" << endl;
    cout << "turn the tide of this war. Will you accept this journey to save the humans from" << endl;
    cout << "their imprisonment?\n" << endl;

    cout << "To play the game, use the keyboard to select the differernt menu options" << endl;
    cout << "along the way. Becareful though, some of the paths your required to take may" << endl;
    cout << "result in altering your journey, or possiably lose the game entirely. to win" << endl;
    cout << "the game, you must make it to the end of the selection path without losing" << endl;
    cout << "the game. you may exit the game by pressing the number 9 during any of the" << endl;
    cout << "selection paths. Good luck on your journey to take back planet Earth.\n" << endl;
}

Room dungeonMap[4][4];

void PlayGame()     // game loop
{
    bool donePlaying = false;
    while (!donePlaying)
    {
        string choice = "";
        int command = 0;
        int currentMapRow = 0;
        int currentMapColumn = 0;

        do
        {
            cout << "Please chose from the following if you wish to continue:\n"; // menu path1 user selection
            cout << "  1) Begin your adventure\n  2) Enter the Item shop\n  9) Exit the game\n" << endl;
            cin >> command;
        } while (!(command == 1 ||command == 2 || command == 9));

        if (command == 1)
        {
            cout << "\nNow that you've accept this brave task, please select the route you wish to travel\n";
            cout << "Be careful, whatever path you chose can effect or even terminate your journey.\n\n";

            do
            {
                cout << "Curent Row = " << currentMapRow << " Curent Column = "<< currentMapColumn << endl;
                dungeonMap[currentMapRow][currentMapColumn].PrintRoom();
                choice = dungeonMap[currentMapRow][currentMapColumn].GetChoice();

                if (choice == "north")
                {
                    currentMapRow--;
                }
                else if (choice == "south")
                {
                    currentMapRow++;
                }
                else if (choice == "east")
                {
                    currentMapColumn++;
                }
                else if (choice == "west")
                {
                    currentMapColumn--;
                }
                else
                {
                    donePlaying = true;
                }
            } while (!donePlaying);

        } else if (command == 2)
        {
            cout << "Weclcome to the item shop" << endl;
            cout << "You travel back to your spaceship.\n" << endl;    // item shop not finished
            donePlaying = true;
        } else if (command = 9)
        {
            cout << "\nThanks for playing, Goodbye!";
            donePlaying = true;
        }
    }
}

void initializeVars()
{
    string roomName[4][4];
    string roomDescription[4][4];
    string roomDirection[4][4];
    bool north[4][4];
    bool south[4][4];
    bool east[4][4];
    bool west[4][4];

    /*********************Row 0*********************/
    roomName[0][0] = "";
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    /*********************Row 1*********************/
    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    /*********************Row 2*********************/
    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    /*********************Row 3*********************/
    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    roomName[0][0];
    roomDescription[0][0];
    roomDirection[0][0];
    north[0][0];
    south[0][0];
    east[0][0];
    west[0][0];

    for(int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            dungeonMap[i][j] = Room(roomName[i][j], roomDescription[i][j], roomDirection[i][j], north[i][j], south[i][j], east[i][j], west[i][j]);
        }
}

int main()
{
    IntroductionStory();
    PlayGame();

    return 0;
}