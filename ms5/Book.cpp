/*/////////////////////////////////////////////////////////////////////////
								OOP224 MS5
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
#include <string>
#include <cstring>
#include <iomanip>
#include "Book.h"

namespace sdds {
	Book::Book() : Publication() {
		m_author = nullptr;
	}

	Book::Book(const Book& src) : Publication(src) {
		if (src.m_author) {
			m_author = new char[strlen(src.m_author) + 1];
			strcpy(m_author, src.m_author);
		}
		else {
			m_author = nullptr;
		}
	}

	Book& Book::operator=(const Book& src) {
		if (this != &src) {
			Publication::operator=(src);  // Copy base class parts

			delete[] m_author;  // Delete old m_author if it exists

			if (src.m_author) {  // If source has an m_author, allocate and copy
				m_author = new char[strlen(src.m_author) + 1];
				strcpy(m_author, src.m_author);
			}
			else {
				m_author = nullptr;
			}
		}
		return *this;
	}


	Book::~Book() {
		delete[] m_author;
		m_author = nullptr;
	}

	char Book::type()const {
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const {
		Publication::write(os);
		
		if (conIO(os)) {
			os << ' ' << std::setw(SDDS_AUTHOR_WIDTH);

			if (strlen(m_author) > SDDS_AUTHOR_WIDTH) {
				char author[SDDS_AUTHOR_WIDTH + 1];
				strncpy(author, m_author, SDDS_AUTHOR_WIDTH);
				author[SDDS_AUTHOR_WIDTH] = '\0';

				os << std::left << author;
			}
			else {				
				os << std::left << m_author;
			}

			os << " |";

		}
		else {
			os << '\t' << m_author << '\n';
		}

		return os;
	}

	std::istream& Book::read(std::istream& is) {
		char tempAuthor[SDDS_MAX_AUTHOR_LEN + 1] = "";

		Publication::read(is);

		delete[] m_author;  // Delete existing m_author safely. It's okay if it's nullptr.

		if (conIO(is)) {
			is.ignore();
			std::cout << "Author: ";
		}
		else {
			is.ignore();
		}

		is.get(tempAuthor, SDDS_MAX_AUTHOR_LEN + 1);

		if (!is.fail()) {
			m_author = new char[strlen(tempAuthor) + 1];
			strcpy(m_author, tempAuthor);
		}
		else {
			m_author = nullptr;  // Ensure m_author is null if input failed.
		}

		return is;
	}

		
	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool() const {
		return (m_author && m_author[0] != '\0' && Publication::operator bool());
	}

}