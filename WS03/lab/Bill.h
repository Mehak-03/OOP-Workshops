/*
Name - Mehakdeep Kaur
Email - m78@myseneca.ca
Id - 171544216
Date - 1 - 06 - 24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SENECA_BILL_H_
#define SENECA_BILL_H_
#include "Item.h"
namespace seneca {
   class Bill {
      char m_title[37];
      Item* m_items;
      int m_noOfItems;
      int m_itemsAdded;
      double totalTax()const;
      double totalPrice()const;
      void Title()const;
      void footer()const;
      void setEmpty();
      bool isValid()const;
   public:
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const;
      void deallocate();
   };
}
#endif // !SENECA_TRANSCRIPT_H
