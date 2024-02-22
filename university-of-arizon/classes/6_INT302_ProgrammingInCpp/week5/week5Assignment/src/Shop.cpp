#include "Shop.h"

Shop::Shop() {}

void Shop::AddItem(const ItemToPurchase &item) { items_.push_back(item); }

void Shop::DeleteItem(string &itemName) {
  for (auto it = items_.begin(); it != items_.end(); ++it) {
    if (it->GetName() == itemName) {
      items_.erase(it);
      break;
    }
  }
}

vector<ItemToPurchase> Shop::GetItems() const { return items_; }
