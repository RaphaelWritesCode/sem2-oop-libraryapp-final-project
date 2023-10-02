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


#include "Streamable.h"

using namespace std;

namespace sdds {

    std::ostream& operator<<(std::ostream& os, const Streamable& obj) {
        if (obj) {
            obj.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& obj) {
        obj.read(is);
        return is;
    }
}