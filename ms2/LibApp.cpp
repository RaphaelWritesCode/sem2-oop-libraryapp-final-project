/*/////////////////////////////////////////////////////////////////////////
						  OOP224 MS2
Full Name  : Raphael Antioquia
Student ID#: 031379126
Email      : rtantioquia@myseneca.ca
Section    : NEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include "LibApp.h"
using namespace std;

namespace sdds {
	LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?") {
		m_mainMenu << "Add New Publication"
			<< "Remove Publication"
			<< "Checkout publication from library"
			<< "Return publication to library";

		m_exitMenu << "Save changes and exit"
			<< "Cancel and go back to the main menu";

		load();
	}

	bool LibApp::confirm(const char* message) {
		Menu confirm(message);
		confirm << "Yes";

		unsigned int choice = confirm.run();
		return (choice == 1);
	}

	void LibApp::load() {
		cout << "Loading Data" << endl;
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
	}

	void LibApp::search() {
		cout << "Searching for publication" << endl;
	}

	void LibApp::returnPub() {
		search();
		cout << "Returning publication" << endl
			<< "Publication returned" << endl;

		m_changed = true;
	}

	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		bool confirmed = confirm("Add this publication to library?");

		if (confirmed) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}

	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();
		bool confirmed = confirm("Remove this publication from the library?");

		if (confirmed) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}

	}

	void LibApp::checkOutPub() {
		search();
		bool confirmed = confirm("Check out publication?");

		if (confirmed) {
			m_changed = true;
			cout << "Publication checked out" << endl;
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

}


