#include <string>
#include <iostream>

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