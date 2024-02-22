#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<double> peopleWeights(5);

    // Prompt the user to enter five numbers. Store the numbers in a vector of doubles
    for(int i = 0; i < peopleWeights.size(); ++i) {
        cout << "Enter weight "<< i + 1 << ":" << endl;
        cin >> peopleWeights.at(i);
    }

    // Output the vector's numbers on one line, each number followed by one space.
    cout << "You entered: ";
    for(int i= 0; i < peopleWeights.size(); ++i) {
        cout << peopleWeights.at(i) << " ";
    }

    cout << endl<< endl;

    // Output the total weight, by summing the vector's elements.
    double sumVal = 0.00;
    for(int i= 0; i < peopleWeights.size(); ++i) {
        sumVal += peopleWeights.at(i);

    }
    cout << "Total weight: " << sumVal << endl;

    // Output the average of the vector's elements.
    double avgVal = sumVal / peopleWeights.size();
    cout << "Average weight: " << avgVal << endl;
    
    // Output the max vector element.
    double maxVal = 0.00;
    for(int i= 0; i < peopleWeights.size(); ++i) {
        if(peopleWeights.at(i) > maxVal) {
            maxVal = peopleWeights.at(i);
        }
    }
    cout << "Max weight: " << maxVal << endl;

    return 0;
}