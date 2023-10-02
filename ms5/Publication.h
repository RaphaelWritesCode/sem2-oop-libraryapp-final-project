/*/////////////////////////////////////////////////////////////////////////
                                OOP224 MS4
Full Name  : Raphael Antioquia
Student ID#: 031379126
Email      : rtantioquia@myseneca.ca
Section    : NEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include <iostream>
#include "Streamable.h"
#include "Lib.h"
#include "Date.h"
namespace sdds {

    class Publication : public Streamable {
       
        char* m_title; // holds dynamic title for publication
        char m_shelfId[5]; // c-string that is exactly 4 characters long
        int m_membership; // holds 5 digit membership number of members of the library
                          // 0 means publication is available
        int m_libRef; // uniquely identifies each publication in system, default = -1
        Date m_date; // holds publication date of an item, also used to track date book was borrowed

    public:
        //RULE OF THREES
        
        // sets all attributes to their default values
        Publication();

        // copy constructor
        Publication(const Publication& other);

        // assignment operator
        Publication& operator=(const Publication& other);
        virtual ~Publication();


        //MODIFIERS
        
        // Sets the membership attribute to either zero or a five-digit integer.
        virtual void set(int member_id);

        // Sets the **libRef** attribute value
        void setRef(int value);

        // Sets the date to the current date of the system.
        void resetDate();


        // QUERIES

        //Returns the character 'P' to identify this object as a "Publication object"
        virtual char type()const;

        //Returns true is the publication is checkout (membership is non-zero)
        bool onLoan()const;

        //Returns the date attribute
        Date checkoutDate()const;

        //Returns true if the argument title appears anywhere in the title of the 
        //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        bool operator==(const char* title)const;

        //Returns the title attribute
        operator const char* ()const;

        // returns the libref attribute
        int getRef()const;
        

        // STREAMABLE PURE VIRTUAL FUNCTION IMPLEMENTATIONS

        // returns true if the address of the io obj is the same as
        // the address of either the cin obj or cout object
        bool conIO(std::ios& io) const;

        // if os argument is a console IO obj (conIO), prints: shielfID, title, membership, and date
        // otherwise, prints type(), libRef, shelfID, title, membership, and dates
        std::ostream& write(std::ostream& os) const;

        // reads all the values in local variables before setting the attributes to any values
        std::istream& read(std::istream& is);

        // returns true if title or shelfID attributes is null or empty,
        // else returns false
        operator bool() const;
    };
}
#endif
