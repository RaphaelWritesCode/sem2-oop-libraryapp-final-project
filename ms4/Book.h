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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"

namespace sdds {

	class Book : public Publication {
	private:
		char* m_author;
	public:
		// Created empty by default, in a safe empty state
		Book();

		// Rule of three
		Book(const Book&);
		Book& operator=(const Book&);
		~Book();

		// Methods

		//Returns the character 'B' to identify this object as a "Publication object"
		char type()const override;

		// if os argument is a console IO obj (conIO), prints: shielfID, title, membership, and date
		// otherwise, prints type(), libRef, shelfID, title, membership, and dates
		std::ostream& write(std::ostream& os) const;

		// reads all the values in local variables before setting the attributes to any values
		std::istream& read(std::istream& istr);

		// Sets the membership attribute to either zero or a five-digit integer.
		void set(int member_id) override;

		// returns true if title or shelfID attributes is null or empty,
        // else returns false
		operator bool() const;
	};
}

#endif