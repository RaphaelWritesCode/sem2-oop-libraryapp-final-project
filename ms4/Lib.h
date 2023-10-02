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
#ifndef SDDS_LIB_H
#define SDDS_LIB_H

namespace sdds {

    // maximum number of day a publication can be borrowed with no penalty
    const int SDDS_MAX_LOAN_DAYS = 15;

    // The width in which the title of a publication should be printed on the console
    const int SDDS_TITLE_WIDTH = 30;

    // The width in which the author name of a book should be printed on the console
    const int SDDS_AUTHOR_WIDTH = 15;

    // The width in which the shelf id of a publication should be printed on the console
    const int SDDS_SHELF_ID_LEN = 4;

    // Maximum number of publications the library can hold.
    const int SDDS_LIBRARY_CAPACITY = 5000;

    // Max title length for input
    const int SDDS_MAX_TITLE_LEN = 255;

    // Max author length for input
    const int SDDS_MAX_AUTHOR_LEN = 256;
}

#endif