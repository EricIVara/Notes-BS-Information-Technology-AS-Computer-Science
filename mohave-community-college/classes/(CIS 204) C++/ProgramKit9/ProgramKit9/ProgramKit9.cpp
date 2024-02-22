// Invasion of the Alien Race

#include <iostream>
#include <string>
#include "Room.cpp"
using namespace std;

void introductionStory();
int mainMenu(int);

int main()
{
    int userMenuOption,
        userDecisionPath1;
    bool donePlaying = false;

    introductionStory();
    mainMenu(userMenuOption);

    while (!donePlaying) // game loop
    {
        if (userMenuOption == 3)
        {
            cout << "\nThanks for playing, Goodbye!"; // exit game
            donePlaying = true;
        }
        if (userMenuOption == 2)
        {
            cout << "Weclcome to the item shop"; // Enter item Shop
        }
        if (userMenuOption == 1) // begin adventure
        {
            cout << "\nNow that you've accept this brave task, please select the ship you wish to travel in\n";
            cout << "Be careful though, whatever userDecisionPath1 you chose may have an effect on your journey.\n\n";
            cout << "(1) Travel in C++400.\n"; // user begins playing the text based game
            cout << "(2) Travel in C#400.\n" << endl;
            cin >> userDecisionPath1;

            if (userDecisionPath1 == 1) // consequences of users options for selecting their first options
            {
                cout << "\nCongratulations, you've selected a ship that will speed up the rate it takes to conquer Earth back by 200%.";
            }
            if (userDecisionPath1 == 2)
            {
                cout << "\nUnfortunately, you've selected a ship that will slow the rate it takes to conquer Earth back by 100%";
            }
        }

        string beginningDescription = "Welcome to whats left of Earth...";
        string beginningDirection = "From here, you can choose where to go next.\n";
        Room start("the Atmosphere", beginningDescription, beginningDirection, 1, 1, 1, 1);

        string northDescription = "You've found a masive human refugee camp of allies.";
        string northDirection;
        Room north("North America", northDescription, northDirection, 0, 0, 0, 0);

        string southDescription = "You've were captured by an invading alien scout";
        string southDirection;
        Room south("South America", southDescription, southDirection, 0, 0, 0, 0);

        string eastDescription = "You've conquered back all of Eastern Europe, Good Job!";
        string eastDirection;
        Room east("Eastern Europe", eastDescription, eastDirection, 0, 0, 0, 0);

        string westDescription = "You've were captured by a alien drop ship";
        string westDirection;
        Room west("Oceania", westDescription, westDirection, 0, 0, 0, 0);

        start.PrintRoom();
        string choice = start.GetChoice();

        if (choice == "north")
        {
            north.PrintRoom();
            cout << "You travel back to your ship to recharge." << endl;
        }
        if (choice == "south")
        {
            south.PrintRoom();
            cout << "You've been lunched into space, Game Over!" << endl;
            donePlaying = true;
        }
        if (choice == "east")
        {
            east.PrintRoom();
            cout << "You travel back to your ship to recharge." << endl;
        }
        if (choice == "west")
        {
            west.PrintRoom();
            cout << "You've been enlisted into the alien invasion, Game Over!" << endl;
            donePlaying = true;
        }
    }

    { 
        string hero;
        
        cout << "\nOnce during an unusual time, there was a broken and dark planet called\n"; // intorduction
        cout << "Earth. Earth was invaded and overrun by a different species not from this\n";
        cout << "universe. While the humans fought bravely, the invading alien race fought\n";
        cout << "harder. During this long and violent battle against the alien race, the humans\n";
        cout << "eventually became overwhelmed, imprisoned, and now rely on hope or some other\n";
        cout << "entity to save them from this unprepared alien invasion. It is up to you hero to\n";
        cout << "turn the tide of this war. Will you accept this journey to save the humans from\n";
        cout << "their imprisonment?\n\n";
    }

    int mainMenu(int userInput);
    {
        cout << "Please chose from the following if you wish to continue:\n"; // menu userDecisionPath1 user selection
        cout << "  1) Begin your adventure\n  2) Item shop\n  3) Exit the game\n" << endl;
        cin >> userMenuOption;

        return userInput;
    }
    return 0;
}