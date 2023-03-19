#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

using namespace std;

#include <string>

class ItemToPurchase {
public:
  ItemToPurchase();
  ItemToPurchase(string &name, int price, int quantity);

  void SetName(string &name);
  void SetPrice(int price);
  void SetQuantity(int quantity);

  const string &GetName() const;
  int GetPrice() const;
  int GetQuantity() const;

private:
  string name_;
  int price_;
  int quantity_;
};

#endif // ITEM_TO_PURCHASE_H
