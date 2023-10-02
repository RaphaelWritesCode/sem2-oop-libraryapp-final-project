/*/////////////////////////////////////////////////////////////////////////
                          OOP224 MS3
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
#include <cstring>
#include "Publication.h"

namespace sdds {
    Publication::Publication() {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();
    }

    Publication::Publication(const Publication& other)
        : m_membership(other.m_membership), m_libRef(other.m_libRef), m_date(other.m_date) {
        if (other.m_title) {
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
        }
        strncpy(m_shelfId, other.m_shelfId, 4);
        m_shelfId[4] = '\0';
    }

    Publication& Publication::operator=(const Publication& other) {
        if (this != &other) {
            delete[] m_title;

            if (other.m_title) {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
            else {
                m_title = nullptr;
            }

            strncpy(m_shelfId, other.m_shelfId, 4);
            m_shelfId[4] = '\0';

            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
        }
        return *this;
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    // Modifiers
    void Publication::set(int member_id) {
        if (member_id >= 10000 && member_id <= 99999) {
            m_membership = member_id;
        }
        else {
            m_membership = 0;
        }
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    // Queries
    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return (m_membership != 0);
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        return (strstr(m_title, title) != nullptr);
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    // Streamable pure virtual function implementations
    bool Publication::conIO(std::ios& io)const {
        return (&io == &std::cin || &io == &std::cout);
    }

    std::ostream& Publication::write(std::ostream& os) const {
        if (conIO(os)) {
            os << "| " << std::setw(SDDS_SHELF_ID_LEN) << m_shelfId << " | "
                << std::left << std::setw(SDDS_TITLE_WIDTH) << std::setfill('.') << m_title << std::setfill(' ')
                << " | ";

            if (m_membership == 0) {
                os << std::setw(5) << " N/A";
            }
            else {
                os << std::setw(5) << m_membership;
            }
            os << " | " << m_date << " |";
        }
        else {
            // Print for non-console IO
            os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t'
                << m_membership << '\t' << m_date;
        }
        return os;
    }


    std::istream& Publication::read(std::istream& is) {
        char titleBuffer[MAX_TITLE + 1] = "";
        char shelfBuffer[SHELFID_LEN + 1] = "";

        // Clear existing data
        delete[] m_title;
        m_title = nullptr;
        strcpy(m_shelfId, "");
        m_membership = 0;
        m_libRef = -1;

        bool inputValid = true;  // Flag to track if the input is valid

        if (conIO(is)) {
            std::cout << "Shelf No: ";
            is.getline(shelfBuffer, SHELFID_LEN + 1);

            if (strlen(shelfBuffer) != SHELFID_LEN) {
                inputValid = false;
            }

            if (inputValid) {
                std::cout << "Title: ";
                is.getline(titleBuffer, MAX_TITLE + 1);

                std::cout << "Date: ";
                is >> m_date;
            }
        }
        else {
            is >> m_libRef;
            is.ignore();
            is.getline(shelfBuffer, SHELFID_LEN + 1, '\t');
            is.getline(titleBuffer, MAX_TITLE + 1, '\t');
            is >> m_membership;
            is.ignore();
            is >> m_date;
        }

        if (!m_date) {
            inputValid = false;
        }

        if (inputValid) {
            m_title = new char[strlen(titleBuffer) + 1];
            strcpy(m_title, titleBuffer);
            strcpy(m_shelfId, shelfBuffer);
        }
        else {
            is.setstate(std::ios::failbit);
        }

        return is;
    }

    Publication::operator bool() const {
        // Check if m_title is not null and not an empty string
        bool validTitle = m_title && strlen(m_title) > 0;

        // Check if m_shelfId is not an empty string
        bool validShelfId = m_shelfId[0] != '\0';

        return validTitle && validShelfId;
    }

}