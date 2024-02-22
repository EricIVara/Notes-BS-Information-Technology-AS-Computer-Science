/***** Invasion of the Alien Race *****/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
public:
    Item()
    {
        name = BLANK_NAME;
        value = 0;
    }

    Item(string n, int v, string t, int d)
    {
        name = n;
        value = v;
        type = t;
        damage = d;
    }

    void Print()
    {
        cout << "Item: " << name << "  worth: " << value << "  type: " << type << "  damage: " << damage << endl;
    }

    string GetName()
    {
        return name;
    }

    int GetValue()
    {
        return value;
    }

    string GetType()
    {
        return type;
    }

    int GetDamage()
    {
        return damage;
    }

    static const string BLANK_NAME;
    static const string ARMOR_TYPE;
    static const string WEAPON_TYPE;

private:
    string name;
    int value;
    string type;
    int damage;
};

class Inventory
{
public:
    Inventory()
    {
    }

    // Print the Inventory with a beginning line label, next line the list, and then a return
    void Print()
    {
        vector<Item>::const_iterator listIterator;
        for (listIterator = itemList.begin(); listIterator != itemList.end(); listIterator++)
        {
            Item curItem = (*listIterator);
            cout << "  ";
            curItem.Print();
        }

        cout << endl << endl;
    }

    // This function gets the value of "itemName" in the inventory.  If it isn't in the inventory return 0
    int GetItemValue(string itemName)
    {
        vector<Item>::const_iterator listIterator;
        for (listIterator = itemList.begin(); listIterator != itemList.end(); listIterator++)
        {
            Item curItem = (*listIterator);
            if (curItem.GetName() == itemName)
                return curItem.GetValue();
        }

        return 0;
    }

    void Add(Item i)
    {
        itemList.push_back(i);
    }

    Item Remove(string itemName)
    {
        vector<Item>::const_iterator listIterator;
        for (listIterator = itemList.begin(); listIterator != itemList.end(); listIterator++)
        {
            Item curItem = (*listIterator);
            if (curItem.GetName() == itemName)
            {
                Item tmpItem = *listIterator;
                itemList.erase(listIterator);
                return tmpItem;
            }
        }

        return Item();
    }

private:
    vector <Item> itemList;
};

class Hero
{
public:
    Hero()
    {
        name = "No Name Yet";
        gold = 0;
    }

    // This function takes the item named "iName" out of "inv" and puts it into the Hero's inventory.
    // return true if the item can be taken, otherwise false
    bool TakeItem(string iName, Inventory* inv)
    {
        Item takeResult;

        takeResult = inv->Remove(iName);
        if (takeResult.GetName() == Item::BLANK_NAME)
        {
            cout << "You cannot take " << iName << " it is not in the inventory." << endl;
            return false;
        }

        else
        {
            cout << "You add " << iName << " to your hero's inventory." << endl;
            heroInventory.Add(takeResult);
            return true;
        }
    }

    void SetName(string n)
    {
        name = n;
    }

    void SetGold(int g)
    {
        gold = g;
    }

    string GetName()
    {
        return name;
    }

    int GetGold()
    {
        return gold;
    }

    void PrintInventory()
    {
        cout << name << "'s Inventory: " << endl;
    }

private:
    string name;
    int gold;
    Inventory heroInventory;
};

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
    /***** Game Introduction *****/
    cout << "Once during an unusual time, there was a broken and dark planet called" << endl;
    cout << "Earth. Earth was invaded and overrun by a different species not from this" << endl;
    cout << "universe. While the humans fought bravely, the invading alien race fought" << endl;
    cout << "harder. During this long and violent battle against the alien race, the humans" << endl;
    cout << "eventually became overwhelmed, imprisoned, and now rely on hope or some other" << endl;
    cout << "entity to save them from this unprepared alien invasion. It is up to you hero to" << endl;
    cout << "turn the tide of this war. Will you accept this journey to save the humans from" << endl;
    cout << "their imprisonment?\n" << endl;

    /***** Game Instructions *****/
    cout << "To play the game, use the keyboard to select the different menu options" << endl;
    cout << "along the way. Be careful though, some of the paths your required to take may" << endl;
    cout << "result in altering your journey, or possibly lose the game entirely. to win" << endl;
    cout << "the game, you must make it to the end of the selection path without losing" << endl;
    cout << "the game. you may exit the game by pressing the number 9 during any of the" << endl;
    cout << "selection paths. Good luck on your journey to take back planet Earth.\n" << endl;
}

/***** Global Variables *****/
Room dungeonMap[4][4];                          // Map Of the Globe filled with 16 rooms
Inventory shopInventory;                        // Shop inventory with items
Hero theHero;                                   // Hero class with hero storage

/***** Variables for blank items *****/
const string Item::BLANK_NAME = "**No Name**";
const string Item::ARMOR_TYPE = "Armor";
const string Item::WEAPON_TYPE = "Weapon";

void initializeVars()
{
    /***** hero data *****/
    string heroName;
    cout << "Please Enter your Hero's name: ";
    cin >> heroName;
    theHero.SetName(heroName);
    theHero.SetGold(100000);
    cout << endl;

    /**** Adding items to item shop ****/
    shopInventory.Add(Item("[Cannon]", 15000, Item::WEAPON_TYPE, 300));
    shopInventory.Add(Item("[Sheild]", 35000, Item::WEAPON_TYPE, 0));
    shopInventory.Add(Item("[Boosters]", 60000, Item::WEAPON_TYPE, 50));

    /********************************************************************************
    Dungeon Map of the globe
    The map for this prgrom is a 4x4 sqaure that begins in thr upper left corner and ends at the
    bottom right corner. The Goals is to

                Column 0        Column 1        Column 2        Column 3
            -----------------------------------------------------------------
    Row 0   |               |               |               |               |
            -----------------------------------------------------------------
    Row 1   |               |               |               |               |
            -----------------------------------------------------------------
    Row 2   |               |               |               |               |
            -----------------------------------------------------------------
    Row 3   |               |               |               |               |
            -----------------------------------------------------------------
    Row 4   |               |               |               |               |
            -----------------------------------------------------------------

    ********************************************************************************/

    /***** Temporary Varables for the differnt rooms *****/
    string roomName[4][4];
    string roomDescription[4][4];
    string roomDirection[4][4];
    bool north[4][4];
    bool south[4][4];
    bool east[4][4];
    bool west[4][4];

    /***** Row 1 *****/
    /***** Room 1 *****/
    roomName[0][0] = "North America";
    roomDescription[0][0] = "You enter the atmosphere of North America and begin to decide what location to attack first.";
    roomDirection[0][0] = "\nShould you go [south] towards Dallas, or [east] towards New York.\nPlease enter your next location: ";
    north[0][0] = false;
    south[0][0] = true;
    east[0][0] = true;
    west[0][0] = false;

    /***** Room 2 *****/
    roomName[0][1] = "New York City";
    roomDescription[0][1] = "You fly into New York City and fight off thousands of alien forces. You managed to help establish a defense stronghold to help fend off the rest of the invading forces located in this area.";
    roomDirection[0][1] = "\nFrom here, you may only travel [south]\nPlease enter your next location: ";
    north[0][1] = false;
    south[0][1] = true;
    east[0][1] = false;
    west[0][1] = true;

    /***** Room 3 *****/
    roomName[0][2] = "Blank Room";
    roomDescription[0][2] = "Blank Room";
    roomDirection[0][2] = "\nThis is a blank room, you may not enter";
    north[0][2] = false;
    south[0][2] = false;
    east[0][2] = false;
    west[0][2] = false;

    /***** Room 4 *****/
    roomName[0][3] = "Storage Facility";
    roomDescription[0][3] = "You find a storage facility to store and house your gear or other materials found along the way. You stock up your gear and venture back into the invasion of the alien race.";
    roomDirection[0][3] = "\nFrom here, you may only travel [south]\nPlease enter your next location: ";
    north[0][3] = false;
    south[0][3] = true;
    east[0][3] = false;
    west[0][3] = true;

    /***** Row 2 *****/
    /***** Room 5 *****/
    roomName[1][0] = "Dallas";
    roomDescription[1][0] = "you fly into Dallas and begin gaining back full control of the area from invading forces located in their largest alien operating base.";
    roomDirection[1][0] = "\nFrom here, you may only travel [north] or [east]\nPlease enter your next location: ";
    north[1][0] = true;
    south[1][0] = false;
    east[1][0] = true;
    west[1][0] = false;

    /***** Room 6 *****/
    roomName[1][1] = "Hospital";
    roomDescription[1][1] = "After fighting off invading forces in the previous locations, you stumble a pond a hospital to recover from any injuries during battle.";
    roomDirection[1][1] = "\nFrom here, you may travel in any direction [north] [south] [east] or [west]\nPlease enter your next location: ";
    north[1][1] = true;
    south[1][1] = true;
    east[1][1] = true;
    west[1][1] = true;

    /***** Room 7 *****/
    roomName[1][2] = "Armory";
    roomDescription[1][2] = "You found an unoccupied abandon armory full of weapons ready for restock. unfortunately, you had to fight off alien invaders protecting the area. After receiving loads of ammunition and gear, you pull out your map and begin planning your next location.";
    roomDirection[1][2] = "\nFrom here, you may only travel [east] or [west]\nPlease enter your next location: ";
    north[1][2] = false;
    south[1][2] = false;
    east[1][2] = true;
    west[1][2] = true;

    /***** Room 8 *****/
    roomName[1][3] = "Retreat";
    roomDescription[1][3] = "You managed to fly right into a large fleet of invading alien forces and was forced to immediately retreat in hopes of escaping the overwhelming attacks. After a tragic retreat, you begin to plan your next location.";
    roomDirection[1][3] = "\nFrom here, you may only travel [north] [south] or [west]\nPlease enter your next location: ";
    north[1][3] = true;
    south[1][3] = true;
    east[1][3] = false;
    west[1][3] = true;

    /***** Row 3 *****/
    /***** Room 9 *****/
    roomName[2][0] = "Blank Room";
    roomDescription[2][0] = "Blank Room";
    roomDirection[2][0] = "\nThis is a blank room, you may not enter";
    north[2][0] = false;
    south[2][0] = false;
    east[2][0] = false;
    west[2][0] = false;

    /***** Room 10 *****/
    roomName[2][1] = "Battle of Central America";
    roomDescription[2][1] = "You along with some refugees, prepare for the biggest battle of history and head right into a swarm of invading alien forced hyper-jumping right into the heart of America. After a long successful battle, you begin to decide where to travel next.";
    roomDirection[2][1] = "\nFrom here, you may only travel [north] or [south]\nPlease enter your next location: ";
    north[2][1] = true;
    south[2][1] = true;
    east[2][1] = false;
    west[2][1] = false;

    /***** Room 11 *****/
    roomName[2][2] = "Blank Room";
    roomDescription[2][2] = "Blank Room";
    roomDirection[2][2] = "This is a blank room, you may not enter";
    north[2][2] = false;
    south[2][2] = false;
    east[2][2] = false;
    west[2][2] = false;

    /***** Room 12 *****/
    roomName[2][3] = "Refugee Camp";
    roomDescription[2][3] = "While on your way to your next battle location. You managed to spot a refugee camps off in the distance. After scouting the area, you've successfully discovered refugees sheltered from adjacent alien forces.";
    roomDirection[2][3] = "From here, you may only travel [north] or [south]\nPlease enter your next location: ";
    north[2][3] = true;
    south[2][3] = true;
    east[2][3] = false;
    west[2][3] = false;

    /***** Row 4 *****/
    /***** Room 13 *****/
    roomName[3][0] = "Hangar";
    roomDescription[3][0] = "After long encounters and deadly blows to your ship, you spot an aircraft hangar not too far from your location. after scouting the abandoned area, you managed to find an unoccupied spaceship with double the capabilities of your previous ship.";
    roomDirection[3][0] = "From here, you may only travel back [east]\nPlease enter your next location: ";
    north[3][0] = false;
    south[3][0] = false;
    east[3][0] = true;
    west[3][0] = false;

    /***** Room 14 *****/
    roomName[3][1] = "Camp Klan";
    roomDescription[3][1] = "You find a friendly camp awaiting your arrival for refuel and recharge. You've received max health and max ammunition from friendly forces along with extra manpower for your ship.";
    roomDirection[3][1] = "From here, you may only travel [north] [west] or [east]\nPlease enter your next location: ";
    north[3][1] = true;
    south[3][1] = false;
    east[3][1] = true;
    west[3][1] = true;

    /***** Room 15 *****/
    roomName[3][2] = "Escort";
    roomDescription[3][2] = "After flying over a camp with potential friendlies, you turn around and result to escorting thousands of friendly refugees back to Camp Klan. your bravery has granted you extra support on your mission against the invading aliens";
    roomDirection[3][2] = "From here, you may only travel [east] or [west]\nPlease enter your next location: ";
    north[3][2] = false;
    south[3][2] = false;
    east[3][2] = true;
    west[3][2] = true;

    /***** Room 16 *****/
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

void PlayGame()
{
    bool donePlaying = false;                   // End Game Loop Variable
    while (!donePlaying){                       // Game Loop
        int choice = 0;                         // Varaibels for the user input
        string command;

        int currentMapRow = 0;                  // Varables for the start location of the hero
        int currentMapColumn = 0;

        /***** Main Menu *****/
        do
        {

            /***** Main Menu Introduction *****/
            cout << "---------------------------------------------------------------------------------------------" << endl;
            cout << "As you finish preparing your equipment during your descent to planet Earth, You head over to" << endl;
            cout << "your command chair to access the ship controls...\n" << endl;

            cout << "***** Spaceship ZXZ 3000 *****" << endl;
            cout << "Main Menu..." << endl;
            cout << "Hello Master," << endl;
            cout << "Welcome to the main menu screen.\n" << endl;

            cout << "Please select from the following options..." << endl;
            cout << "  [shop] items in item shop" << endl;
            cout << "  [begin] adventure" << endl;
            cout << "  [end] game and exit spaceship without a helmet\n" << endl;

            cin >> command;

        } while (!(command == "shop" || command == "begin" || command == "end"));

        /***** Enter Item Shop *****/
        if (command == "shop")
        {
            bool doneShopping = false;                           // Exit Item Shop
            string shopCommand = "";                             // User input variable
            vector<string> inventory;                            // Inventory vector variable

            inventory.push_back("  simple spaceship");           // Add items to hero inventory
            inventory.push_back("  simple armor");
            inventory.push_back("  simple laser");

            /***** Item Shop Introduction *****/
            cout << "\n---------------------------------------------------------------------------------------------" << endl;
            cout << "As you scroll through the menu options to enter Earths atmposhpere, you realized you forgot, " << endl;
            cout << "some items to fully prepare yourself, so you scroll back up to select the item shop menu option.\n" << endl;

            cout << "Item Shop..." << endl;
            cout << "Welcome to the Item Shop Master\n" << endl;

            /***** Item Shop Main Menu *****/
            while (!doneShopping)
            {
                cout << "Please select from the following options..." << endl;

                cout << "  [list] of items in your inventory" << endl;
                cout << "  [purchase] an item from the item shop" << endl;
                cout << "  [exit] the item shop" << endl;
                cout << "  [end] game\n" << endl;

                cin >> shopCommand;

                if (shopCommand == "list" || shopCommand == "purchase" || shopCommand == "exit" || shopCommand == "end")
                {
                    /***** Displays a List of Items *****/
                    if (shopCommand == "list")
                    {
                        cout << "\n---------------------------------------------------------------------------------------------" << endl;
                        cout << "You have " << inventory.size() << " items in your inventory. Here is a list of your current items.\n" << endl;

                        for (unsigned int i = 0; i < inventory.size(); ++i)
                        {
                            cout << inventory[i] << endl;
                        }
                        cout << endl;
                    }
                    /***** View a list of item for purchase *****/
                    else if (shopCommand == "purchase")
                    {
                        string takeChoice;

                        cout << "\n---------------------------------------------------------------------------------------------" << endl;
                        cout << "\nHeres a list of items in the item shop:" << endl;
                        shopInventory.Print();

                        cout << "\nPlease enter the item name from which you would like to purchase:\n" << endl;
                        
                        cin >> takeChoice;

                        int itemValue = shopInventory.GetItemValue(takeChoice);
                        if (itemValue == 0)
                        {
                            cout << "\n---------------------------------------------------------------------------------------------" << endl;
                            cout << "The item you entered [" << takeChoice << "] does not appear in the shops inventory\n" << endl;
                        }
                        else if (itemValue <= theHero.GetGold())
                        {
                            theHero.TakeItem(takeChoice, &shopInventory);
                            theHero.SetGold(theHero.GetGold() - itemValue);
                        }
                        else
                            cout << "You do not have enough money to buy " << takeChoice << endl;
                    }
                    /***** Exit Item Shop *****/
                    else if (shopCommand == "exit")
                    {
                        doneShopping = true;
                    }
                    /***** End Game *****/
                    else if (shopCommand == "end")
                    {
                        cout << "\nThanks for playing, Goodbye!";
                        exit(0);
                    }
                    else {
                        cout << "Invalid option, please try again" << endl;
                        cin >> shopCommand;
                    }
                }
            }
        }
        /***** Begin Your Adventure *****/
        else if (command == "begin")
        {
            cout << "\nNow that you've accept this brave task, please select the route you wish to travel\n";
            cout << "Be careful, whatever path you choose can effect or even terminate your journey.\n\n";

            while (!donePlaying)
            {
                cout << "Curent Row = " << currentMapRow << " Curent Column = " << currentMapColumn << endl;
                dungeonMap[currentMapRow][currentMapColumn].PrintRoom();
                //choice = dungeonMap[currentMapRow][currentMapColumn].GetChoice();

                if (choice == 8)
                {
                    currentMapRow--;
                }
                else if (choice == 2)
                {
                    currentMapRow++;
                }
                else if (choice == 6)
                {
                    currentMapColumn++;
                }
                else if (choice == 4)
                {
                    currentMapColumn--;
                }
                else
                {
                    cout << "Invalid option, please try again" << endl;
                    cin >> choice;
                }
            }

        }
        /***** Exit Game *****/
        else if (command == "end")
        {
            cout << "\nThanks for playing, Goodbye!";
            donePlaying = true;
        }
    }
}

int main()
{
    IntroductionStory();
    initializeVars();
    PlayGame();

    return 0;
}