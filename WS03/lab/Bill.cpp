/*
Name - Mehakdeep Kaur
Email - m78@myseneca.ca
Id - 171544216
Date - 1 - 06 - 24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "Bill.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca {

    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
    }

    bool Bill::isValid() const {
        if (m_title[0] == '\0' || m_items == nullptr)
            return false;

        for (int i = 0; i < m_noOfItems; ++i) {
            if (!m_items[i].isValid())
                return false;
        }

        return true;
    }

    double Bill::totalTax() const {
        double tax = 0.0;
        for (int i = 0; i < m_noOfItems; ++i) {
            tax += m_items[i].tax();
        }
        return tax;
    }

    double Bill::totalPrice() const {
        double totalPrice = 0.0;
        for (int i = 0; i < m_noOfItems; ++i) {
            totalPrice += m_items[i].price();
        }
        return totalPrice;
    }

    void Bill::Title() const {
        std::cout << "+--------------------------------------+" << std::endl;
        if (isValid()) {
            std::cout << "| " << std::left << std::setw(36) << m_title << " |" << std::endl;
        }
        else {
            std::cout << "| Invalid Bill                         |" << std::endl;
        }
        std::cout << "+----------------------+---------+-----+" << std::endl;
        std::cout << "| Item Name            | Price   + Tax |" << std::endl;
        std::cout << "+----------------------+---------+-----+" << std::endl;
    }

    void Bill::footer() const {
        std::cout << "+----------------------+---------+-----+" << std::endl;
        if (isValid()) {
            std::cout << "|                Total Tax: " << std::right << std::setw(10) << std::fixed << std::setprecision(2) << totalTax() << " |" << std::endl;
            std::cout << "|              Total Price: " << std::right << std::setw(10) << std::fixed << std::setprecision(2) << totalPrice() << " |" << std::endl;
            std::cout << "|          Total After Tax: " << std::right << std::setw(10) << std::fixed << std::setprecision(2) << totalTax() + totalPrice() << " |" << std::endl;
        }
        else {
            std::cout << "| Invalid Bill                         |" << std::endl;
        }
        std::cout << "+--------------------------------------+" << std::endl;
    }

    void Bill::init(const char* title, int noOfItems) {
        if (title == nullptr || noOfItems <= 0) {
            setEmpty();
            return;
        }

        m_noOfItems = noOfItems;
        m_itemsAdded = 0;
        strncpy(m_title, title, 36);
        m_title[36] = '\0';

        m_items = new Item[m_noOfItems];
        for (int i = 0; i < m_noOfItems; ++i) {
            m_items[i].setEmpty();
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            ++m_itemsAdded;
            return true;
        }
        else {
            return false;
        }
    }

    void Bill::display() const {
        Title();
        for (int i = 0; i < m_noOfItems; ++i) {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }

} // namespace seneca
