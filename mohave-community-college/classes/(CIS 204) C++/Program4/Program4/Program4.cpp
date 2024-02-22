#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 

***** Innvasion of the Alein Race *****
    
		Dungeon Map of the globe
    The map for this prgram is a 4x4 square that begins in the upper left corner and
    ends at the bottom right corner. The Goals is to make it through the maze without
		losing.

                 Column 0           Column 1          Column 2          Column 3
            --------------------------------------------------------------------------
    Row 0   |  North America  |  New York City  |   Blank Room    | Storage Facility |
            --------------------------------------------------------------------------
    Row 1   |     Dallas      |    Hospital     |      Armory     |     Retreat      |
            --------------------------------------------------------------------------
    Row 2   |   Blank Room    |   Great Battle  |   Blank Room    |   Refugee Camp   |
            --------------------------------------------------------------------------
    Row 3   |     Hangar      |     Cap Klan    |     Escort      |      Echelon     |
            --------------------------------------------------------------------------

Things that need work:
	TODO Exit Purchase to enter Item Shop
	TODO Exit Item Shop to enter Main Menu
	TODO Add Alien monesters to two rooms
	TODO Add Gold and Items in Armory room
	TODO Add New spaceship to Hanger Room

*/

class Item {

public:
	Item() {

		// If a blank item is created item() starts by having an invalid name until SetName() is called
		name = BLANK_NAME;
		value = 0;
		type = WEAPON_TYPE;
		damage = 0;
	}

	Item(string n, int v, string t, int d) {

		name = n;
		value = v;
		type = t;
		damage = d;
	}

	void Print() {

		cout << "[" << name << "] - worth: " << value << ",  type: " << type << ",  damage: " << damage;
	}

	string GetName() {

		return name;
	}

	int GetValue() {

		return value;
	}

	string GetType() {

		return type;
	}

	int GetDamage() {

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
class Inventory {
	
public:
	Inventory()
	{
		name = "**Blank Inventory Name**";
	}

	Inventory(string n)
	{
		name = n;
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
			cout << endl;
		}

		cout << endl;
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

	void SetName(string n)
	{
		name = n;
	}

	string GetName()
	{
		return name;
	}

	int Size()
	{
		return itemList.size();
	}

	static const string BLANK_NAME;

private:
	vector <Item> itemList;
	string name;
};
class Monster
{
public:
	Monster()
	{
		name = BLANK_NAME;
		description = "**None**";
		gold = 0;
		damage = 0;
		life = 0;
		instantAgro = false;
	}

	Monster(string n, string d, int g, int dam, int l)
	{
		name = n;
		description = d;
		gold = g;
		damage = dam;
		life = l;
		instantAgro = false;
		myInventory.SetName(n + "'s bag");
	}

	string GetName()
	{
		return name;
	}

	string GetDescription()
	{
		return description;
	}

	int GetLife()
	{
		return life;
	}

	int TakeDamage(int incomingDmg)
	{
		life -= incomingDmg;
		return incomingDmg;
	}

	int CauseDamage()
	{
		return damage;
	}

	void SetInstantAgro(bool a)
	{
		instantAgro = a;
	}

	bool InstantAgro()
	{
		return instantAgro;
	}

	static const string BLANK_NAME;
	Inventory myInventory;

private:
	string name;
	string description;
	int gold;
	int damage;
	int life;
	bool instantAgro;
};
class Hero
{
public:
	Hero()
	{
		name = "**Blank Hero Name**";
		gold = 0;
		life = 50;
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

	void InventoryMenu()
	{
		bool inInventory = true;
		cout << "**  Hero Inventory:  " << name << " has " << life << " life points, does " << myWeapon.GetDamage() << " damage, and absorbs " << myArmor.GetDamage() << " damage" << endl;

		while (inInventory)
		{
			string menuChoice;
			cout << "**  Hero inventory menu: [list] hero's inventory, [equip] item, [show] equipped items, [end] menu." << endl;
			cout << "**  Hero Inventory:  What would you like to do? ";
			cin >> menuChoice;

			if (menuChoice == "list")
			{
				cout << endl << "**  Hero Inventory:  The Hero opens inventory and finds... ";
				heroInventory.Print();
			}

			else if (menuChoice == "equip")
			{
				cout << "**  Hero Inventory:  Which item from your inventory would you like to equip? ";
				string equipChoice;
				cin >> equipChoice;

				Item oldEquipItem;
				Item newEquipItem = heroInventory.Remove(equipChoice);
				if (newEquipItem.GetName() == Item::BLANK_NAME)
				{
					cout << "**  Invalid equip choice " << equipChoice << ". That not in the hero's inventory.**" << endl;
				}

				else
				{
					if (newEquipItem.GetType() == Item::ARMOR_TYPE)
					{
						oldEquipItem = myArmor;
						myArmor = newEquipItem;
						if (oldEquipItem.GetName() != Item::BLANK_NAME)
							heroInventory.Add(oldEquipItem);

						cout << "**  Hero Inventory:  " << name << " unequips " << oldEquipItem.GetName() << endl;
						cout << "**  Hero Inventory:  " << name << " equips " << newEquipItem.GetName() << " in the armor slot." << endl;
					}

					if (newEquipItem.GetType() == Item::WEAPON_TYPE)
					{
						oldEquipItem = myWeapon;
						myWeapon = newEquipItem;
						if (oldEquipItem.GetName() != Item::BLANK_NAME)
							heroInventory.Add(oldEquipItem);

						cout << "**  Hero Inventory:  " << name << " un-equips " << oldEquipItem.GetName() << endl;
						cout << "**  Hero Inventory:  " << name << " equips " << newEquipItem.GetName() << " in the weapon slot." << endl;
					}

				}
			}

			else if (menuChoice == "show")
			{
				cout << "**  Hero Inventory:  weapon equipped {"; myWeapon.Print(); cout << "}" << endl;
				cout << "**  Hero Inventory:  armor equipped  {"; myArmor.Print(); cout << "}" << endl << endl;
			}

			else if (menuChoice == "end")
			{
				inInventory = false;
			}

			else
				cout << "**  Hero Inventory:  **Invalid menu choice**" << endl;
		}
	}

	void ProcessEncounter(Monster* theMonster)
	{
		if (theMonster == NULL)
		{
			cout << "** Error, null monster in ProcessEncounter leaving function " << endl;
			return;
		}

		cout << endl << "*****************************************************************" << endl;
		cout << "**  You encouther " << theMonster->GetName() << endl;
		cout << "**  Description: " << theMonster->GetDescription() << endl;
		cout << "*****************************************************************" << endl;

		// Battle the monster until one of you is dead
		while (theMonster->GetLife() > 0 && life > 0)
		{
			cout << "**  Battle:   " << name << " attacks " << theMonster->GetName() << " and does " << theMonster->TakeDamage(this->CauseDamage()) << " damage." << endl;
			cout << "**  Battle:   " << theMonster->GetName() << " attacks " << name << " and does " << this->TakeDamage(theMonster->CauseDamage()) << " damage." << endl;
		}

		if (Dead())
			cout << "Battle:  You have lost the battle and taken lethal damage!" << endl;
		if (theMonster->GetLife() <= 0)
			cout << "Battle:  Battle done, Success! " << theMonster->GetName() << endl;

		// After the battle look at the inventory and allow the hero to take what they want
		if (theMonster->myInventory.Size() > 0)
		{
			string takeChoice;
			while (takeChoice != "leave" && theMonster->myInventory.Size() > 0)
			{
				cout << endl << "You look into " << theMonster->GetName() << "'s inventory.";
				theMonster->myInventory.Print();

				cout << "Type the name of item you want to keep or [leave] to end the inventory menu:  ";
				cin >> takeChoice;
				cout << endl;

				if (takeChoice != "leave")
					this->TakeItem(takeChoice, &theMonster->myInventory);
			}
		}
	}

	void SetName(string n)
	{
		name = n;
		heroInventory.SetName(n);
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

	int CauseDamage()
	{
		return myWeapon.GetDamage();
	}

	int TakeDamage(int incomingDmg)
	{
		int totalDmg = incomingDmg - myArmor.GetDamage();
		if (totalDmg > 0)
		{
			life -= totalDmg;
			return totalDmg;
		}
		else
			return 0;
	}

	bool Dead()
	{
		if (life > 0)
			return false;
		else
			return true;
	}

private:
	string name;
	int gold;
	int life;
	Inventory heroInventory;
	Item myWeapon;
	Item myArmor;
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
		cout << name << ":" << endl;
		cout << description << endl;
	}

	string GetChoice()
	{
		bool validChoice = false;
		string myChoice = "";

		cout << directions << endl;

		cout << "Please select from the following options..." << endl;
		cout << "  [north]" << endl;
		cout << "  [south]" << endl;
		cout << "  [east]" << endl;
		cout << "  [west]" << endl;
		cout << "  [quit]\n" << endl;
		cin >> myChoice;

		do
		{
			if (myChoice == "north" && north == true)
			{
				validChoice = true;
				cout << "-----------------------------------------------------------------------------------------------\n" << endl;
			}
			else if (myChoice == "south" && south == true)
			{
				validChoice = true;
				cout << "-----------------------------------------------------------------------------------------------\n" << endl;
			}
			else if (myChoice == "east" && east == true)
			{
				validChoice = true;
				cout << "-----------------------------------------------------------------------------------------------\n" << endl;
			}
			else if (myChoice == "west" && west == true)
			{
				validChoice = true;
				cout << "-----------------------------------------------------------------------------------------------\n" << endl;
			}
			else if (myChoice == "quit") {
				cout << "-----------------------------------------------------------------------------------------------\n" << endl;
				cout << "Thanks for playing, Goodbye!\n";
				exit(0);
			}
			else
			{
				cout << "\n************** ERROR! **************" << endl;
				cout << "*                                  *" << endl;
				cout << "* Invalid option, please try again *" << endl;
				cout << "*                                  *" << endl;
				cout << "************************************\n" << endl;
				cin >> myChoice;
			}
				

		} while (!validChoice);

		return myChoice;
	}

	void SetOccupant(Monster m)
	{
		myOccupant = m;
	}

	Monster GetOccupant()
	{
		return myOccupant;
	}

private:
	string name;
	string description;
	string directions;
	Monster myOccupant;
	bool north, south, east, west;
};

/***** Global Variables *****/
Room dungeonMap[4][4];                          // Map Of the Globe filled with 16 rooms
Inventory shopInventory;                        // Shop inventory with items
Hero theHero;                                   // Hero class with hero storage

/***** Variables for blank items *****/
const string Monster::BLANK_NAME = "**Blank Monster**";
const string Inventory::BLANK_NAME = "**Blank Inventory**";
const string Item::BLANK_NAME = "**Blank Item**";
const string Item::ARMOR_TYPE = "Armor";
const string Item::WEAPON_TYPE = "Weapon";

void initializeVars()
{
    /***** hero data *****/
    string heroName;
	bool notValid = false;
	cout << "Please Enter your Hero's name: ";
    cin >> heroName;
    theHero.SetName(heroName);
    theHero.SetGold(100000);
	cout << endl;

    /**** Adding items to item shop ****/
    shopInventory.Add(Item("cannon", 15000, Item::WEAPON_TYPE, 300));
    shopInventory.Add(Item("sheild", 35000, Item::WEAPON_TYPE, 0));
    shopInventory.Add(Item("boosters", 60000, Item::WEAPON_TYPE, 50));

	/***** Temporary Varables for the differnt rooms *****/
	string roomName[4][4];
	string roomDescription[4][4];
	string roomDirection[4][4];
	bool north[4][4];
	bool south[4][4];
	bool east[4][4];
	bool west[4][4];

    /***** Row 0 *****/
    /***** Room 0 *****/
    roomName[0][0] = "North America";
    roomDescription[0][0] = "You enter the atmosphere of North America and begin to decide what location to take back.";
    roomDirection[0][0] = "From here, you may only travel [south] or [east]";
    north[0][0] = false;
    south[0][0] = true;
    east[0][0] = true;
    west[0][0] = false;

    /***** Room 1 *****/
    roomName[0][1] = "New York City";
    roomDescription[0][1] = "You fly into New York City and fight off thousands of alien forces. You managed to help\nestablish a defense stronghold to help fend off the rest of the invading forces located here.";
    roomDirection[0][1] = "From here, you may only travel [south]";
    north[0][1] = false;
    south[0][1] = true;
    east[0][1] = false;
    west[0][1] = false;

    /***** Room 2 *****/
    roomName[0][2] = "Blank Room";
    roomDescription[0][2] = "Blank Room";
    roomDirection[0][2] = "This is a blank room, you may not enter";
    north[0][2] = false;
    south[0][2] = false;
    east[0][2] = false;
    west[0][2] = false;

    /***** Room 3 *****/
    roomName[0][3] = "Storage Facility";
    roomDescription[0][3] = "You find a storage facility to store and house your gear or other materials found along the\nway. You stock up your gear and venture back into the invasion of the alien race.";
    roomDirection[0][3] = "From here, you may only travel [south]";
    north[0][3] = false;
    south[0][3] = true;
    east[0][3] = false;
    west[0][3] = false;

    /***** Row 1 *****/
    /***** Room 4 *****/
    roomName[1][0] = "Dallas";
    roomDescription[1][0] = "you fly into Dallas and begin gaining back full control of the area from invading forces\nlocated in their largest alien operating base.";
    roomDirection[1][0] = "From here, you may only travel [east]";
    north[1][0] = false;
    south[1][0] = false;
    east[1][0] = true;
    west[1][0] = false;

    /***** Room 5 *****/
    roomName[1][1] = "Hospital";
    roomDescription[1][1] = "After fighting off invading forces in the previous locations, you stumble a pond a hospital to\nrecover from any injuries during battle.";
    roomDirection[1][1] = "From here, you may only travel [south] or [east]";
    north[1][1] = false;
    south[1][1] = true;
    east[1][1] = true;
    west[1][1] = false;

    /***** Room 6 *****/
    roomName[1][2] = "Armory";
    roomDescription[1][2] = "You found an unoccupied abandon armory full of weapons ready for restock. unfortunately, you\nhad to fight off alien invaders protecting the area. After receiving loads of ammunition and\ngear, you pull out your map and begin planning your next location.";
    roomDirection[1][2] = "From here, you may only travel [east]";
    north[1][2] = false;
    south[1][2] = false;
    east[1][2] = true;
    west[1][2] = false;

    /***** Room 7 *****/
    roomName[1][3] = "Retreat";
    roomDescription[1][3] = "You managed to fly right into a large fleet of invading alien forces and was forced to\nimmediately retreat in hopes of escaping the overwhelming attacks. After a tragic retreat, you\nbegin to plan your next location.";
    roomDirection[1][3] = "From here, you may only travel [north] or [south]";
    north[1][3] = true;
    south[1][3] = true;
    east[1][3] = false;
    west[1][3] = false;

    /***** Row 2 *****/
    /***** Room 8 *****/
    roomName[2][0] = "Blank Room";
    roomDescription[2][0] = "Blank Room";
    roomDirection[2][0] = "This is a blank room, you may not enter";
    north[2][0] = false;
    south[2][0] = false;
    east[2][0] = false;
    west[2][0] = false;

    /***** Room 9 *****/
    roomName[2][1] = "Battle of Central America";
    roomDescription[2][1] = "You along with some refugees, prepare for the biggest battle of history and head right into a\nswarm of invading alien forced hyper-jumping right into the heart of America. After a lon\nsuccessful battle, you begin to decide where to travel next.";
    roomDirection[2][1] = "From here, you may only travel [south]";
    north[2][1] = false;
    south[2][1] = true;
    east[2][1] = false;
    west[2][1] = false;

    /***** Room 10 *****/
    roomName[2][2] = "Blank Room";
    roomDescription[2][2] = "Blank Room";
    roomDirection[2][2] = "This is a blank room, you may not enter";
    north[2][2] = false;
    south[2][2] = false;
    east[2][2] = false;
    west[2][2] = false;

    /***** Room 11 *****/
    roomName[2][3] = "Refugee Camp";
    roomDescription[2][3] = "While on your way to your next battle location. You managed to spot a refugee camps off in the\ndistance. After scouting the area, you've successfully discovered refugees sheltered from\nadjacent alien forces.";
    roomDirection[2][3] = "From here, you may only travel [south]";
    north[2][3] = false;
    south[2][3] = true;
    east[2][3] = false;
    west[2][3] = false;

    /***** Row 3 *****/
    /***** Room 12 *****/
    roomName[3][0] = "Hangar";
    roomDescription[3][0] = "After long encounters and deadly blows to your ship, you spot an aircraft hangar not too far\nfrom your location. after scouting the abandoned area, you managed to find an unoccupied spaceship with double the capabilities of your previous ship.";
    roomDirection[3][0] = "From here, you may only travel back [east]";
    north[3][0] = false;
    south[3][0] = false;
    east[3][0] = true;
    west[3][0] = false;

    /***** Room 13 *****/
    roomName[3][1] = "Camp Klan";
    roomDescription[3][1] = "You find a friendly camp awaiting your arrival for refuel and recharge. You've received max\nhealth and max ammunition from friendly forces along with extra manpower for your ship.";
    roomDirection[3][1] = "From here, you may only travel [east]\n";
    north[3][1] = false;
    south[3][1] = false;
    east[3][1] = true;
    west[3][1] = false;

    /***** Room 14 *****/
    roomName[3][2] = "Escort";
    roomDescription[3][2] = "After flying over a camp with potential friendlies, you turn around and result to escorting\nthousands of friendly refugees back to Camp Klan. your bravery has granted you extra support on your mission against the invading aliens";
    roomDirection[3][2] = "From here, you may only travel [east]\n";
    north[3][2] = false;
    south[3][2] = false;
    east[3][2] = true;
    west[3][2] = false;

    /***** Room 15 *****/
    roomName[3][3] = "Echelon";
	roomDescription[3][3] = "After successfully surviving your adventure, you travel back to your space station to receive\nfather guidance from higher authorities.";
    roomDirection[3][3] = "Congratulations, you've successfully taken back planet earth.\n\nUnited States Government:\n\n***Warning!***\nPlease [exit] the atmosphere, we will engage in deadly forces to remove you from the premises!";
    north[3][3] = false;
    south[3][3] = false;
    east[3][3] = false;
    west[3][3] = false;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            dungeonMap[i][j] = Room(roomName[i][j], roomDescription[i][j], roomDirection[i][j], north[i][j], south[i][j], east[i][j], west[i][j]);
}
void IntroductionStory() {

	/************************************* Game Introduction ******************************************/
	cout << "Once during an unusual time, there was a broken and dark planet called" << endl;
	cout << "Earth. Earth was invaded and overrun by a different species not from this" << endl;
	cout << "universe. While the humans fought bravely, the invading alien race fought" << endl;
	cout << "harder. During this long and violent battle against the alien race, the humans" << endl;
	cout << "eventually became overwhelmed, imprisoned, and now rely on hope or some other" << endl;
	cout << "entity to save them from this unprepared alien invasion. It is up to you hero to" << endl;
	cout << "turn the tide of this war. Will you accept this journey to save the humans from" << endl;
	cout << "their imprisonment?\n" << endl;
	cout << "To play the game, use the keyboard to [enter] in the different menu options" << endl;
	cout << "along the way. Be careful though, some of the paths your required to take may" << endl;
	cout << "result in altering your journey, or possibly lose the game entirely. to win" << endl;
	cout << "the game, you must make it to the end of the selection path without losing" << endl;
	cout << "the game. you may exit the game by entering [quit] during any of the" << endl;
	cout << "selection paths. Good luck on your journey to take back planet Earth.\n" << endl;
	/**************************************************************************************************/

}
void PlayGame() {

  bool donePlaying = false;               // End Game Loop Variable
	string choice;							            // Varaibels for the user input
	string command;													// 
	int currentMapRow = 0;                  // Varables for the start location of the hero
	int currentMapColumn = 0;

	/************************************************* Ship Introduction *************************************************/
	cout << "\n-----------------------------------------------------------------------------------------------\n" << endl;
	cout << "As you finish preparing your equipment during your descent to planet Earth, You head over to" << endl;
	cout << "your command chair to access the ship controls...\n" << endl;
	cout << "                                ***** Spaceship ZXZ 3000 *****" << endl;
	cout << "                                ******** Hello Master ********" << endl;
	cout << "\n-----------------------------------------------------------------------------------------------\n" << endl;
	/*********************************************************************************************************************/

	/***** Game Loop *****/
    while (!donePlaying) {
		/********************* Main Menu Introduction *********************/
		cout << "Accessing Data...\n" << endl;
		cout << "Main Menu:" << endl;
		cout << "Welcome to the main menu screen.\n" << endl;
		cout << "Please [enter] from the following options..." << endl;
		cout << "  [shop] items in item shop" << endl;
		cout << "  [begin] adventure" << endl;
		cout << "  [quit] game and exit spaceship without helmet\n" << endl;
		cin >> command;
		/******************************************************************/

		if (command == "shop" || command == "begin" || command == "quit") {

			if (command == "shop") {								 // Enter Item Shop

				bool doneShopping = false;                           // Exit Item Shop Variable
				string shopCommand = "";                             // User input variable
				vector<string> inventory;                            // Inventory vector variable
				inventory.push_back("  simple spaceship");           // Add items to hero inventory
				inventory.push_back("  simple armor");
				inventory.push_back("  simple laser");

				/***************************************** Item Shop Introduction *****************************************/
				cout << "\n-----------------------------------------------------------------------------------------------\n" << endl;
				cout << "Accessing Data...\n" << endl;
				cout << "As you scroll through the menu options to enter Earths atmosphere, you realized you forgot, " << endl;
				cout << "some items to fully prepare yourself, so you scroll back up to select the item shop menu option.\n" << endl;
				cout << "Item Shop:" << endl;
				cout << "Welcome to the Item Shop Master\n" << endl;
				cout << "Please [enter] from the following options..." << endl;
				cout << "  [list] of items in your inventory" << endl;
				cout << "  [purchase] an item from the item shop" << endl;
				cout << "  [exit] the item shop" << endl;
				cout << "  [quit] game and exit spaceship without helmet\n" << endl;
				cin >> shopCommand;
				/**********************************************************************************************************/

				while (!doneShopping) {				// Item Shop Main Menu
				
					if (shopCommand == "list" || shopCommand == "purchase" || shopCommand == "exit" || shopCommand == "quit") {
					
						if (shopCommand == "list") {			// List of Items
						
							/************************************************* List Introduction *************************************************/
							cout << "\n-----------------------------------------------------------------------------------------------\n" << endl;
							cout << "Accessing Data...\n" << endl;
							cout << "List:" << endl;
							cout << "You have " << inventory.size() << " items in your inventory. Here is a list of your current items:" << endl;

							for (unsigned int i = 0; i < inventory.size(); ++i) {
								cout << inventory[i] << endl;
							}
							cout << "\nPlease [enter] from the following options..." << endl;
							cout << "  [list] of items in your inventory" << endl;
							cout << "  [purchase] an item from the item shop" << endl;
							cout << "  [exit] the item shop" << endl;
							cout << "  [quit] game and exit spaceship without helmet\n" << endl;
							cin >> shopCommand;
							/*********************************************************************************************************************/
						}
						else if (shopCommand == "purchase") {			// Purchase Item

							bool validchoice = true;
							string takeChoice;
							
							/************************************************************ Purchase Introducation ************************************************************/
							cout << "\n-----------------------------------------------------------------------------------------------\n" << endl;
							cout << "Accessing Data...\n" << endl;
							cout << "Purchase:" << endl;
							cout << "Please [enter] the item from the list for which you would like to purchase. You can also [enter]\nfrom the following options..." << endl;
							//cout << "  [exit] the item shop" << endl;
							//cout << "  [quit] game and exit spaceship without helmet" << endl;
							shopInventory.Print();
							cin >> takeChoice;
							cout << "\n-----------------------------------------------------------------------------------------------\n" << endl;
							/************************************************************************************************************************************************/

							//if (takeChoice == "exit") {																																// Exit purchase needs fixing
							//	cout << "\n---------------------------------------------------------------------------------------------\n" << endl;
							//	cout << "Exiting Item Shop...\n" << endl;
							//	doneShopping = false;
							//}
							//else if (takeChoice == "quit") {																															// exit item shop needs fixing
							//	cout << "\n---------------------------------------------------------------------------------------------\n" << endl;
							//	cout << "Thanks for playing, Goodbye!\n";
							//	doneShopping = false;
							//	donePlaying = false;
							//}

							int itemValue = shopInventory.GetItemValue(takeChoice);
							if (itemValue == 0) {
								
								cout << "\n************** ERROR! **************" << endl;
								cout << "*                                  *" << endl;
								cout << "* Invalid option, please try again *" << endl;
								cout << "*                                  *" << endl;
								cout << "************************************\n" << endl;
								cout << "  [exit] the item shop" << endl;
								cout << "  [quit] game and exit spaceship without helmet" << endl;
								shopInventory.Print();
								cin >> takeChoice;
							}
							else if(itemValue <= theHero.GetGold()) {
								
								theHero.TakeItem(takeChoice, &shopInventory);
								theHero.SetGold(theHero.GetGold() - itemValue);
							}
							else
								
								cout << "You do not have enough money to buy " << takeChoice << endl;
						}
						/******************** Exit ********************/
						else if (shopCommand == "exit") {
							cout << "\n---------------------------------------------------------------------------------------------\n" << endl;
							cout << "Exiting Item Shop...\n" << endl;
							doneShopping = true;
						}
						/******************** Exit ********************/

						/******************** End *********************/
						else if (shopCommand == "quit") {
							cout << "\n---------------------------------------------------------------------------------------------\n" << endl;
							cout << "Thanks for playing, Goodbye!\n";
							doneShopping = true;
							donePlaying = true;
						}
						/******************** End *********************/
					}
					else {
						cout << "\n************** ERROR! **************" << endl;
						cout << "*                                  *" << endl;
						cout << "* Invalid option, please try again *" << endl;
						cout << "*                                  *" << endl;
						cout << "************************************\n" << endl;
						cin >> shopCommand;
					}
				}
			}
			else if (command == "begin") {				// Begin Game
				bool doneAdventuring = false;			// End Game Variable

				cout << "-----------------------------------------------------------------------------------------------\n" << endl;
				cout << "Now that you've accept this brave task, please select the route you wish to travel. Be careful," << endl;
				cout << "whatever path you choose can effect or even terminate your journey.\n" << endl;

				do {

					dungeonMap[currentMapRow][currentMapColumn].PrintRoom();
					cout << "Curent Row = " << currentMapRow << " Curent Column = " << currentMapColumn << endl;
					cout << "" << endl;
					choice = dungeonMap[currentMapRow][currentMapColumn].GetChoice();

					if (choice == "north" || choice == "south" || choice == "east" || choice == "west" || choice == "exit" || choice == "quit") {
						if (choice == "north")
							currentMapRow--;
						else if (choice == "south")
							currentMapRow++;
						else if (choice == "east")
							currentMapColumn++;
						else if (choice == "west")
							currentMapColumn--;
					}
				} while (!doneAdventuring);

			}
			else if (command == "quit"){			// Quit Game
			cout << "-----------------------------------------------------------------------------------------------\n" << endl;
				cout << "Thanks for playing, Goodbye!\n";
				donePlaying = true;
			}
		}
		else {
			cout << "\n************** ERROR! **************" << endl;
			cout << "*                                  *" << endl;
			cout << "* Invalid option, please try again *" << endl;
			cout << "*                                  *" << endl;
			cout << "************************************\n" << endl;
			cin >> command;
		}
    }
}
int main(){
    
	IntroductionStory();
  initializeVars();
  PlayGame();

  return 0;
}