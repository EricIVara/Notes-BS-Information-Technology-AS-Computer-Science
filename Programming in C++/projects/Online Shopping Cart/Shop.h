#ifndef SHOP_H
#define SHOP_H

#include "ItemToPurchase.h"
#include <string>
#include <vector>

using namespace std;

class Shop {
public:
  Shop();

  void AddItem(const ItemToPurchase &item);
  void DeleteItem(string &itemName);
  vector<ItemToPurchase> GetItems() const;

private:
  vector<ItemToPurchase> items_;
};

#endif // SHOP_H
