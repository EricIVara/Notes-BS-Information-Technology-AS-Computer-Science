
#include <iostream>
using namespace std;

int main() {
    double currentTemp;
    double desiredTemp;
    double currentHumidity;
    double isHot = (currentTemp > desiredTemp);
    double isReallyHot = (currentTemp > (desiredTemp + 5.0));
    double isHumid = (currentHumidity > 0.50);
    bool acOn;
    bool evapCoolerOn;
    
    if (isReallyHot) {
       // Use A/C and evaporative cooler
       acOn = true;
       evapCoolerOn = true;
    }
    if (isHot && isHumid) {
       // Use A/C
       acOn = true;
       evapCoolerOn = false;
    }
    else if (isHot && !isHumid) {
       // Use evaporative cooler
       acOn = false;
       evapCoolerOn = true;
    }
    else {
       acOn = false;
       evapCoolerOn = false;
    }
}