#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
   public:
      // Default constructor
      ItemToPurchase();

      // Mutator functions
      void SetName(string name);
      void SetPrice(int price);
      void SetQuantity(int quantity);

      // Accessor functions
      string GetName() const;
      int GetPrice() const;
      int GetQuantity() const;

   private:
      string itemName;
      int itemPrice;
      int itemQuantity;
};

#endif  /* ITEMTOPURCHASE_H */