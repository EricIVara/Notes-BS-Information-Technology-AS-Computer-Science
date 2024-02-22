#include <iostream>
#include <string>
#include "ItemToPurchase.h"
using namespace std;

int main() {
   ItemToPurchase item1, item2;
   string name;
   int price, quantity, totalCost;

   // Get user input for first item
   cout << "Item 1" << endl;
   cout << "Enter the item name:" << endl;
   getline(cin, name);
   item1.SetName(name);
   cout << "Enter the item price:" << endl;
   cin >> price;
   item1.SetPrice(price);
   cout << "Enter the item quantity:" << endl;
   cin >> quantity;
   item1.SetQuantity(quantity);
   cin.ignore();  // Ignore newline character in input buffer

   // Get user input for second item
   cout << endl << "Item 2" << endl;
   cout << "Enter the item name:" << endl;
   getline(cin, name);
   item2.SetName(name);
   cout << "Enter the item price:" << endl;
   cin >> price;
   item2.SetPrice(price);
   cout << "Enter the item quantity:" << endl;
   cin >> quantity;
   item2.SetQuantity(quantity);

   // Calculate total cost and output item details
   totalCost = (item1.GetPrice() * item1.GetQuantity()) + (item2.GetPrice() * item2.GetQuantity());
   cout << endl << "TOTAL COST" << endl;
   cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << (item1.GetPrice() * item1.GetQuantity()) << endl;
   cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << (item2.GetPrice() * item2.GetQuantity()) << endl;
   cout << endl << "Total: $" << totalCost << endl;

   return 0;
}