#include "Shop.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Prompt the user to enter number of items.
  // Store the items in a vector of type ItemToPurchase.
  cout << "How many items would you like to put in your shop: ";
  int numItems;
  cin >> numItems;
  cin.ignore();

  Shop shop;
  for (int i = 0; i < numItems; ++i) {
    cout << "Item " << i + 1 << endl;

    // Get the name of the item
    cout << "Enter the name of the item: ";
    string itemName;
    getline(cin, itemName);

    // Get the price of the item
    cout << "Enter the price of the item: ";
    int itemPrice;
    cin >> itemPrice;

    // Get the quantity of the item
    cout << "Enter the quantity of the item: ";
    int itemQuantity;
    cin >> itemQuantity;
    cin.ignore();

    ItemToPurchase item(itemName, itemPrice, itemQuantity);
    shop.AddItem(item);
  }

  bool running = true;
  while (running) {
    // Prompt the user to select an action
    cout << "Select an action:\n";
    cout << "1. Delete an item\n";
    cout << "2. Add an item\n";
    cout << "3. View Items in Shop\n";
    cout << "4. Quit\n";

    int action;
    cin >> action;
    cin.ignore();

    switch (action) {
    case 1: {
      // Prompt the user to select an item to delete
      cout << "Enter the name of an item you would like to delete: ";
      string selectedItem;
      getline(cin, selectedItem);

      // Delete the selected item from the shop
      shop.DeleteItem(selectedItem);
      break;
    }
    case 2: {
      // Get the name of the item
      cout << "Enter the name of the item: ";
      string itemName;
      getline(cin, itemName);

      // Get the price of the item
      cout << "Enter the price of the item: ";
      int itemPrice;
      cin >> itemPrice;

      // Get the quantity of the item
      cout << "Enter the quantity of the item: ";
      int itemQuantity;
      cin >> itemQuantity;
      cin.ignore();

      ItemToPurchase item(itemName, itemPrice, itemQuantity);
      shop.AddItem(item);
      break;
    }
    case 3: {
      // Print out the remaining items in the shop
      cout << "Remaining items in the shop:\n";
      for (const auto &item : shop.GetItems()) {
        cout << item.GetName() << " - $" << item.GetPrice() << " - "
             << item.GetQuantity() << " in stock\n";
      }
      break;
    }
    case 4: {
      running = false;
      break;
    }
    default: {
      cout << "Invalid action. Please select a valid action.\n";
      break;
    }
    }
  }

  return 0;
}