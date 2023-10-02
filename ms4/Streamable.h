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

#pragma once
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>

namespace sdds {
	class Streamable {
	public:
        
        // This is not capable of modifying the Streamable object
        // Receives and returns a reference of an ostream object
        virtual std::ostream& write(std::ostream&) const = 0;

        // reads receives and returns a reference of an istream object
        virtual std::istream& read(std::istream&) = 0;

        // not capable of modifying the Streamable object
        // conIO receives a reference of an ios object and returns a Boolean
        // conIO determines if incoming ios object is a console IO obj or not
        virtual bool conIO(std::ios& io)const = 0;

        // returns if Streamble obj is VALID or not
        virtual operator bool() const = 0;

        // Empty virtual destructor
        virtual ~Streamable() {};

        // constant object of type Streamable can be written on an ostream object,
        // only if the  Streamable obj is in a valid state, otherwise does nothing
        friend std::ostream& operator<<(std::ostream& os, const Streamable& obj);

        // obj type Streamable can be read from istream obj
        friend std::istream& operator>>(std::istream& is, Streamable& obj);
	};

   
}

#endif // !SDDS_STREAMABLE_H
