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
#include <fstream>
#include <limits>
#include <iomanip>
#include <cstring>
#include "LibApp.h"
#include "PublicationSelector.h"
using namespace std;

namespace sdds {
	LibApp::LibApp(const char* filename) : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_pubTypeMenu("Choose the type of publication:") {
		if (filename != nullptr) {
			strcpy(m_filename, filename);
		}

		m_NOLP = 0;
		m_LLRN = 0;
		
		m_mainMenu << "Add New Publication"
			<< "Remove Publication"
			<< "Checkout publication from library"
			<< "Return publication to library";

			m_exitMenu << "Save changes and exit"
				<< "Cancel and go back to the main menu";

			m_pubTypeMenu << "Book"
				<< "Publication";

			load();
	}

	LibApp::~LibApp() {
		for (int i = 0; i < m_NOLP; i++) {
			delete m_PPA[i];
			m_PPA[i] = nullptr;
		}
	}

	bool LibApp::confirm(const char* message) {
		Menu confirm(message);
		confirm << "Yes";

		unsigned int choice = confirm.run();
		return (choice == 1);
	}

	void LibApp::load() {
		cout << "Loading Data" << endl;

		ifstream infile(m_filename);

		if (infile.is_open()) {
			char type{};
			int i;

			for (i = 0; infile && i < SDDS_LIBRARY_CAPACITY; i++) {
				infile >> type;
				infile.ignore();

				if (infile) {
					if (type == 'P') {
						m_PPA[i] = new Publication;
					}
					else if (type == 'B') {
						m_PPA[i] = new Book;
					}
					else {
						cerr << "Invalid publication type";
					}
					if (m_PPA[i]) {
						infile >> *m_PPA[i];
						m_NOLP++;
						// sets LLRN to libRef of last pub read
						m_LLRN = m_PPA[i]->getRef();
					}
				}
			}
			infile.close();
		}
		else {
			cerr << "LipApp Load Funtion: File could not be opened";
		}

	}

	void LibApp::save() {
		cout << "Saving Data" << endl;

		ofstream outfile(m_filename);

		if (outfile.is_open()) {
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->getRef() != 0) {
					outfile << *m_PPA[i];
				}
			}
			outfile.close();
		}
		else {
			cerr << "LipApp Save Funtion: File could not be opened";
		}

	}

	int LibApp::search(int mode) {
		char pubTitle[257];
		char pubType{};
		int psLibRef = 0;
		PublicationSelector pubSelect("Select one of the following found matches:", 15);
		int selection = m_pubTypeMenu.run();

		if (selection == 1) {
			pubType = 'B';
		}
		else if (selection == 2) {
			pubType = 'P';
		}

		cout << "Publication Title: ";
		cin.ignore();
		cin.getline(pubTitle, 256);
		// Search Modes
		// 1. Search all
		// 2. Search Checkout Items Search only those publications which are on loan by library members
		// 3. Search Available Items Search only those publications which are not on loan

		if (mode == 1) {
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->type() == pubType && m_PPA[i]->operator==(pubTitle) && m_PPA[i]->getRef() > 0) {
					pubSelect << m_PPA[i];
				}
			}
		}
		else if (mode == 2) {
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->type() == pubType && m_PPA[i]->operator==(pubTitle) && m_PPA[i]->getRef() > 0 && m_PPA[i]->onLoan()) {
					pubSelect << m_PPA[i];
				}
			}
		}
		else if (mode == 3) {
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->type() == pubType && m_PPA[i]->operator==(pubTitle) && m_PPA[i]->getRef() > 0 && !m_PPA[i]->onLoan()) {
					pubSelect << m_PPA[i];
				}
			}
		}
		else {
			cerr << "LibApp Search Function: Inappropriate Search Type";
		}

		if (pubSelect) {
			// sorts matched pubs
			pubSelect.sort();
			// create menu of matched pubs & return their libRef
			psLibRef = pubSelect.run();

			if (psLibRef > 0) {
				cout << *getPub(psLibRef) << endl;
			}
			else {
				cout << "Aborted!" << endl;
			}
		}
		else {
			cout << "No matches found!" << endl;
		}

		return psLibRef;

	}

	void LibApp::returnPub() {
		cout << "Return publication to the library" << endl;
		// search for "on loan" pubs only
		int libRef = search(2);

		// if any matches are found
		if (libRef > 0) {
			bool confirmed = confirm("Return Publication?");

			if (confirmed) {
				int daysLoaned = Date() - getPub(libRef)->checkoutDate();

				if (daysLoaned > SDDS_MAX_LOAN_DAYS) {
					int daysLate = daysLoaned - SDDS_MAX_LOAN_DAYS;
					double penaltyFee = daysLate * .50;

					cout << "Please pay $" << fixed << setprecision(2) << penaltyFee
						<< " penalty for being " << daysLate << " days late!" << endl;
				}

				// set membership to 0, to indicate pub is available to be checked out now
				getPub(libRef)->set(0);
				m_changed = true;
				cout << "Publication returned" << endl;
			}
		}
		
	}

	void LibApp::newPublication() {
		bool shouldExit = false;

		// Check if the library is at max capacity
		if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl;
			shouldExit = true;
		}

		Publication* newPub = nullptr;

		if (!shouldExit) {
			cout << "Adding new publication to the library" << endl;

			int selection = m_pubTypeMenu.run();
			cin.ignore(1000, '\n');

			// If user chooses to exit
			if (selection == 0) {
				cout << "Aborted!" << endl;
				shouldExit = true;
			}
			else {
				// Create publication based on selection
				if (selection == 1) {
					newPub = new Book;
				}
				else if (selection == 2) {
					newPub = new Publication;
				}
				cin >> *newPub;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					delete newPub;
					cout << "Input error! Aborted!" << endl;
					shouldExit = true;
				}
			}
		}

		if (!shouldExit) {
			bool confirmed = confirm("Add this publication to the library?");
			if (!confirmed) {
				delete newPub;
				cout << "Aborted!" << endl;
				shouldExit = true;
			}
		}

		if (!shouldExit) {
			m_LLRN++;
			newPub->setRef(m_LLRN);
			m_PPA[m_NOLP++] = newPub;
			m_changed = true;
			cout << "Publication added" << endl;
		}

		return;
	}



	void LibApp::removePublication() {
		cout << "Removing publication from the library" << endl;

		// searches through all publications & returns libRef of pub obj
		int libRef = search(1);

		if (libRef > 0) {
			bool confirmed = confirm("Remove this publication from the library?");

			if (confirmed) {
				// sets libRef of selected pub to 0
				getPub(libRef)->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
		
	}

	void LibApp::checkOutPub() {
		cout << "Checkout publication from the library" << endl;
		// serach available pubs
		int libRef = search(3);

		// run only if match is found
		if (libRef > 0) {
			bool confirmed = confirm("Check out publication?");
			if (confirmed) {
				int membership = 0;

				cout << "Enter Membership number: ";
				do {
					cin >> membership;

					if (membership < 10000 || membership > 99999) {
						cout << "Invalid membership number, try again: ";
					}
					else {
						getPub(libRef)->set(membership);
						m_changed = true;
						cout << "Publication checked out" << endl;
					}
				} while (membership < 10000 || membership > 99999);
			}
		}

		
	}

	void LibApp::run() {
		bool exit = false;

		while (!exit) {
			unsigned int selection = m_mainMenu.run();

			switch (selection) {
			case 1:
				newPublication();
				cout << endl;
				break;
			case 2:
				removePublication();
				cout << endl;
				break;
			case 3:
				checkOutPub();
				cout << endl;
				break;
			case 4:
				returnPub();
				cout << endl;
				break;
			case 0:
				if (m_changed) {
					unsigned int exitSelection = m_exitMenu.run();

					switch (exitSelection) {
					case 1:
						save();
						exit = true;
						break;
					case 2:
						break;
					default:
						bool confirmed = confirm("This will discard all the changes are you sure?");

						if (confirmed) {
							exit = true;
						}
						break;
					}
					cout << endl;
				}
				else {
					cout << endl;
					exit = true;
					break;
				}
			}
		}
		
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

	Publication* LibApp::getPub(int libRef) {
		Publication* result = nullptr;
		bool keepSearching = true;

		for (int i = 0; i < m_NOLP && keepSearching; i++) {
			if (m_PPA[i]->getRef() == libRef) {
				result = m_PPA[i]; // Assign the address of the found Publication object
				keepSearching = false;
			}
		}

		return result; // Return the pointer to the found Publication object
	}
	

}


