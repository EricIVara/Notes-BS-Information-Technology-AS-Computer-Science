#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() : name_(""), price_(0), quantity_(0) {}

ItemToPurchase::ItemToPurchase(string &name, int price, int quantity)
    : name_(name), price_(price), quantity_(quantity) {}

void ItemToPurchase::SetName(string &name) { name_ = name; }

void ItemToPurchase::SetPrice(int price) { price_ = price; }

void ItemToPurchase::SetQuantity(int quantity) { quantity_ = quantity; }

const std::string &ItemToPurchase::GetName() const { return name_; }

int ItemToPurchase::GetPrice() const { return price_; }

int ItemToPurchase::GetQuantity() const { return quantity_; }
