/*
Name - Mehakdeep Kaur
Email - m78@myseneca.ca
Id - 171544216
Date - 1 - 06 - 24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca {

    void Item::setName(const char* name) {
        strncpy(m_itemName, name, 20);
        m_itemName[20] = '\0';
    }

    void Item::setEmpty() {
        m_price = 0.0;
        m_taxed = false;
        m_itemName[0] = '\0';
    }

    void Item::set(const char* name, double price, bool taxed) {
        if (name == nullptr || price < 0) {
            setEmpty();
        }
        else {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    void Item::display() const {
        if (isValid()) {
            std::cout << "| " << std::left << std::setw(20) << std::setfill('.') << m_itemName
                << " | " << std::right << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(2) << m_price
                << " | " << (m_taxed ? "Yes " : "No  ") << "|" << std::endl;
        }
        else {
            std::cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << std::endl;
        }
    }



    bool Item::isValid() const {
        return m_itemName[0] != '\0';
    }

    double Item::price() const {
        return m_price;
    }

    double Item::tax() const {
        if (m_taxed)
            return m_price * 0.13;
        else
            return 0.0;
    }

} // namespace seneca
