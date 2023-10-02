/*/////////////////////////////////////////////////////////////////////////
                          OOP224 MS1
Full Name  : Raphael Antioquia
Student ID#: 031379126
Email      : rtantioquia@myseneca.ca
Section    : NEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <limits>
#include <cstring>
using namespace std;
#include "Menu.h"

namespace sdds {
    MenuItem::MenuItem(const char* item) {
        if (item) {
            m_item = new char[strlen(item) + 1];
            strcpy(m_item, item);
        }
        else {
            m_item = nullptr;
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_item;
        m_item = nullptr;
    }

    MenuItem::operator bool() const {
        return m_item != nullptr;
    }

    MenuItem::operator const char* () const {
        return m_item;
    }

    std::ostream& MenuItem::display(std::ostream& os) const {
        if (m_item) {
            os << m_item;
        }
        return os;
    }

    Menu::Menu() {
        m_title = nullptr;
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            m_menuItem[i] = nullptr;
        }
        m_noOfItems = 0;
    }


    Menu::Menu(const char* title) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);

        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            m_menuItem[i] = nullptr;
        }

        m_noOfItems = 0;
    }

    Menu::~Menu() {
        delete[] m_title;
        m_title = nullptr;

        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            delete m_menuItem[i];
            m_menuItem[i] = nullptr;
        }
    }

    void Menu::displayTitle(std::ostream& os) const {
        if (m_title) {
            os << m_title;
        }
    }

    void Menu::displayMenu(std::ostream& os) const {
        displayTitle();
	
	    if (m_title) {
                os << ":" << endl;
            }
	
        for (int i = 0; i < static_cast<int>(m_noOfItems); ++i) {
            os << setw(2) << right << i + 1 << "- " << m_menuItem[i]->m_item << endl;
        }
        os << " 0- Exit" << endl;
        os << "> ";
    }

    unsigned int Menu::run() {
        displayMenu();

        unsigned int choice;
        bool isValid = false;

        do {
            cin >> choice;

            if (cin.fail() || choice < 0 || choice > static_cast<unsigned int>(m_noOfItems)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Selection, try again: ";
            }
            else {
                isValid = true;
            }
        } while (!isValid);

        return choice;
    }


    unsigned int Menu::operator~() {
        return run();
    }

    Menu& Menu::operator<<(const char* menuItemContent) {
       if (static_cast<unsigned int>(m_noOfItems) < MAX_MENU_ITEMS) {
            m_menuItem[m_noOfItems] = new MenuItem(menuItemContent);
            m_noOfItems++;
        }
        return *this;
    }

    Menu::operator unsigned int() const {
        return m_noOfItems;
    }

    Menu::operator int() const {
        return static_cast<int>(m_noOfItems);
    }

    Menu::operator bool() const {
        return (m_noOfItems > 0);
    }

    std::ostream& operator<<(std::ostream& os, const Menu& menu) {
        menu.displayTitle();
        return os;
    }

    const char* Menu::operator[](int index) const {
        if (m_noOfItems > 0) {
            index %= m_noOfItems;  // Loop back to the beginning if index exceeds the number of MenuItems
            return static_cast<const char*>(*m_menuItem[index]);
        }
        return nullptr;
    }

}