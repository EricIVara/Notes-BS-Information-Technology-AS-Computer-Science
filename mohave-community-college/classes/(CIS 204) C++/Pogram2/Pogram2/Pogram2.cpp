// Invasion of the Alien Race

#include <iostream>
#include <string>
#include <vector>
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
            cout << "--------------------------------------------------------" << endl;
            cout << "Weclcome to the main menu" << endl;
            cout << "Please choose from the following if you wish to continue:" << endl; // menu path1 user selection
            cout << "  1) Begin your adventure\n  2) Enter the Item shop\n  9) Exit the game\n" << endl;
            cin >> command;
        } while (!(command == 1 || command == 2 || command == 9));

        if (command == 1)
        {
            cout << "\nNow that you've accept this brave task, please select the route you wish to travel\n";
            cout << "Be careful, whatever path you choose can effect or even terminate your journey.\n\n";

            do
            {
                cout << "Curent Row = " << currentMapRow << " Curent Column = " << currentMapColumn << endl;
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
                    cout << "Invalid option, please try again" << endl;
                    cin >> choice;
                }
            } while (!donePlaying);

        }
        else if (command == 2)    // item shop not finished
        {
            int command = 0;
            vector<string> inventory;
            inventory.push_back("  simple spaceship");
            inventory.push_back("  simple armor");
            inventory.push_back("  simple laser");

            cout << "\n--------------------------" << endl;
            cout << "Weclcome to the item shop" << endl;
            cout << "you have " << inventory.size() << " items currently in your inventory:"<< endl;

            for (unsigned int i = 0; i < inventory.size(); ++i)
            {
                cout << inventory[i] << endl;
            }
            cout << endl;

            cout << "Please select from the following items in the item shop:" << endl;
            cout << "  1) simple NASA ship\n  2) simple sheild\n  3) simple cannon\n  4) exit item shop\n" << endl;
            cin >> command;

            do
            {
                if (command == 1)
                {
                    inventory[0] = "simple NASA ship";
                    cout << "\nYou've switched your simple spaceship with a simple NASA spaceship" << endl;
                    cout << "Please select another item to change, or [4] to exit the item shop:";
                    cin >> command;
                }
                else if (command == 2)
                {
                    inventory[1] = "simple sheilds";
                    cout << "\nYou've switched your simple armor with a simple sheild" << endl;
                    cout << "Please select another item to change, or [4] to exit the item shop:";
                    cin >> command;
                }
                else if (command == 3)
                {
                    inventory[2] = "simple cannon";
                    cout << "\nYou've switched your simple laser with a simple cannon" << endl;
                    cout << "Please select another item to change, or [4] to exit the item shop:";
                    cin >> command;
                }
                else if (command == 4)
                {

                }
                else if (command == 9)
                {
                    cout << "Thanks for playing, Goodbye!" << endl;
                    exit(0);
                }
                else
                {
                    cout << "Invalid option, please try again\n" << endl;
                    cin >> command;
                }
            } while (command != 4);
        }
        else if (command == 9)
        {
            cout << "\nThanks for playing, Goodbye!";
            exit(0);
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
    roomName[0][0] = "North America";
    roomDescription[0][0] = "You enter the atmosphere of North America and begin to decide what location to attack first.";
    roomDirection[0][0] = "\nShould you go [south] towards Dallas, or [east] towards New York.\nPlease enter your next location: ";
    north[0][0] = false;
    south[0][0] = true;
    east[0][0] = true;
    west[0][0] = false;

    roomName[0][1] = "New York City";
    roomDescription[0][1] = "You fly into New York City and fight off thousands of alien forces. You managed to help establish a defense stronghold to help fend off the rest of the invading forces located in this area.";
    roomDirection[0][1] = "\nFrom here, you may only travel [south]\nPlease enter your next location: ";
    north[0][1] = false;
    south[0][1] = true;
    east[0][1] = false;
    west[0][1] = true;

    roomName[0][2] = "Blank Room";
    roomDescription[0][2] = "Blank Room";
    roomDirection[0][2] = "\nThis is a blank room, you may not enter";
    north[0][2] = false;
    south[0][2] = false;
    east[0][2] = false;
    west[0][2] = false;

    roomName[0][3] = "Storage Facility";
    roomDescription[0][3] = "You find a storage facility to store and house your gear or other materials found along the way. You stock up your gear and venture back into the invasion of the alien race.";
    roomDirection[0][3] = "\nFrom here, you may only travel [south]\nPlease enter your next location: ";
    north[0][3] = false;
    south[0][3] = true;
    east[0][3] = false;
    west[0][3] = true;

    /*********************Row 1*********************/
    roomName[1][0] = "Dallas";
    roomDescription[1][0] = "you fly into Dallas and begin gaining back full control of the area from invading forces located in their largest alien operating base.";
    roomDirection[1][0] = "\nFrom here, you may only travel [north] or [east]\nPlease enter your next location: ";
    north[1][0] = true;
    south[1][0] = false;
    east[1][0] = true;
    west[1][0] = false;

    roomName[1][1] = "Hospital";
    roomDescription[1][1] = "After fighting off invading forces in the previous locations, you stumble a pond a hospital to recover from any injuries during battle.";
    roomDirection[1][1] = "\nFrom here, you may travel in any direction [north] [south] [east] or [west]\nPlease enter your next location: ";
    north[1][1] = true;
    south[1][1] = true;
    east[1][1] = true;
    west[1][1] = true;

    roomName[1][2] = "Armory";
    roomDescription[1][2] = "You found an unoccupied abandon armory full of weapons ready for restock. unfortunately, you had to fight off alien invaders protecting the area. After receiving loads of ammunition and gear, you pull out your map and begin planning your next location.";
    roomDirection[1][2] = "\nFrom here, you may only travel [east] or [west]\nPlease enter your next location: ";
    north[1][2] = false;
    south[1][2] = false;
    east[1][2] = true;
    west[1][2] = true;

    roomName[1][3] = "Retreat";
    roomDescription[1][3] = "You managed to fly right into a large fleet of invading alien forces and was forced to immediately retreat in hopes of escaping the overwhelming attacks. After a tragic retreat, you begin to plan your next location.";
    roomDirection[1][3] = "\nFrom here, you may only travel [north] [south] or [west]\nPlease enter your next location: ";
    north[1][3] = true;
    south[1][3] = true;
    east[1][3] = false;
    west[1][3] = true;

    /*********************Row 2*********************/
    roomName[2][0] = "Blank Room";
    roomDescription[2][0] = "Blank Room";
    roomDirection[2][0] = "\nThis is a blank room, you may not enter";
    north[2][0] = false;
    south[2][0] = false;
    east[2][0] = false;
    west[2][0] = false;

    roomName[2][1] = "Battle of Central America";
    roomDescription[2][1] = "You along with some refugees, prepare for the biggest battle of history and head right into a swarm of invading alien forced hyper-jumping right into the heart of America. After a long successful battle, you begin to decide where to travel next.";
    roomDirection[2][1] = "\nFrom here, you may only travel [north] or [south]\nPlease enter your next location: ";
    north[2][1] = true;
    south[2][1] = true;
    east[2][1] = false;
    west[2][1] = false;

    roomName[2][2] = "Blank Room";
    roomDescription[2][2] = "Blank Room";
    roomDirection[2][2] = "This is a blank room, you may not enter";
    north[2][2] = false;
    south[2][2] = false;
    east[2][2] = false;
    west[2][2] = false;

    roomName[2][3] = "Refugee Camp";
    roomDescription[2][3] = "While on your way to your next battle location. You managed to spot a refugee camps off in the distance. After scouting the area, you've successfully discovered refugees sheltered from adjacent alien forces.";
    roomDirection[2][3] = "From here, you may only travel [north] or [south]\nPlease enter your next location: ";
    north[2][3] = true;
    south[2][3] = true;
    east[2][3] = false;
    west[2][3] = false;

    /*********************Row 3*********************/
    roomName[3][0] = "Hangar";
    roomDescription[3][0] = "After long encounters and deadly blows to your ship, you spot an aircraft hangar not too far from your location. after scouting the abandoned area, you managed to find an unoccupied spaceship with double the capabilities of your previous ship.";
    roomDirection[3][0] = "From here, you may only travel back [east]\nPlease enter your next location: ";
    north[3][0] = false;
    south[3][0] = false;
    east[3][0] = true;
    west[3][0] = false;

    roomName[3][1] = "Camp Klan";
    roomDescription[3][1] = "You find a friendly camp awaiting your arrival for refuel and recharge. You've received max health and max ammunition from friendly forces along with extra manpower for your ship.";
    roomDirection[3][1] = "From here, you may only travel [north] [west] or [east]\nPlease enter your next location: ";
    north[3][1] = true;
    south[3][1] = false;
    east[3][1] = true;
    west[3][1] = true;

    roomName[3][2] = "Escort";
    roomDescription[3][2] = "After flying over a camp with potential friendlies, you turn around and result to escorting thousands of friendly refugees back to Camp Klan. your bravery has granted you extra support on your mission against the invading aliens";
    roomDirection[3][2] = "From here, you may only travel [east] or [west]\nPlease enter your next location: ";
    north[3][2] = false;
    south[3][2] = false;
    east[3][2] = true;
    west[3][2] = true;

    roomName[3][3] = "Echelon";
    roomDescription[3][3] = "After successfully surviving your adventure, you travel back to your space station to receive father guidance from higher authorities.";
    roomDirection[3][3] = "From here, you may only travel [north] or [west]\nPlease enter your next location: ";
    north[3][3] = true;
    south[3][3] = false;
    east[3][3] = false;
    west[3][3] = true;

    for (int i = 0; i < 4; i++)
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