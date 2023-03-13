#include <iostream>
#include <String>
using namespace std;

class Restaurant {
    public:
        void SetName(string restaurantName){
            name = restaurantName;
        }
        void SetRating(int userRating) {
            rating = userRating;
        }
        void Print();

    private:
        string name;
        int rating;
};

void Restaurant::Print() {
    cout << name << " -- " << rating << endl;
}

int main() {
    Restaurant favLunchPlace;
    Restaurant favDinnerPlace;

    favLunchPlace.SetName("In N' Out");
    favLunchPlace.SetRating(5);

    favDinnerPlace.SetName("In N' Out");
    favDinnerPlace.SetRating(5);

    cout << "My favorite Resauant is: " << endl;
    favLunchPlace.Print();
    favDinnerPlace.Print();

    return 0;
}