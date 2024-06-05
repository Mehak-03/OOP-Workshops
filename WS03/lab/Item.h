/*
Name - Mehakdeep Kaur
Email - m78@myseneca.ca
Id - 171544216
Date - 1 - 06 - 24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SENECA_ITEM_H_
#define SENECA_ITEM_H_
namespace seneca {
   class Item {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SENECA_SUBJECT_H
