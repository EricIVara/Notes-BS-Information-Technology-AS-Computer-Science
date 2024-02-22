// Invasion of the Alien Race

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string hero;
    int userBegins, option;

    cout << "Welcome to my game Invasion of the Alien Race\n\n";
    cout << "Please Enter Your Name\n"; // user entes name
    cin >> hero;
    cout << "\nOnce during an unusual time, there was a broken and dark planet called\n"; // intorduction
    cout << "Earth. Earth was invaded and overrun by a different species not from this\n";
    cout << "universe. While the humans fought bravely, the invading alien race fought\n";
    cout << "harder. During this long and violent battle against the alien race, the humans\n";
    cout << "eventually became overwhelmed, imprisoned, and now rely on hope or some other\n";
    cout << "entity to save them from this unprepared alien invasion. It is up to you hero to\n";
    cout << "turn the tide of this war. Will you accept this journey to save the humans from\n";
    cout << "their imprisonment?\n\n";

    cout << "Please chose from the following if you wish to continue:\n"; // menu option user selection
    cout << "  1) Item shop\n  2) Exit the game\n  3) Begin your adventure\n";
    cin >> userBegins;
    if (userBegins == 1)
    {
        cout << "Weclcome to the item shop"; // Enter item Shop
    }
    if (userBegins == 2)
    {
        cout << "Thanks for playing, Goodbye!"; // exit game
        exit(0);
    }
    if (userBegins == 3) // begin journey
    {
        cout << "welcome to Earth!";
    }
    return 0;
}