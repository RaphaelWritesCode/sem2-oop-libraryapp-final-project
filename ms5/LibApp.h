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

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include <iostream>
#include "Menu.h"
#include "Book.h"

namespace sdds {
   class LibApp {
   public:
	   bool m_changed;
	   Menu m_mainMenu;
	   Menu m_exitMenu;
	   char m_filename[256]; // holds publication data name name
	   Publication* m_PPA[SDDS_LIBRARY_CAPACITY]; // Arr will be populated with records of the data publication data file
												// when LipApp is instantiated
	   int m_NOLP; // holds num of publications loaded into PPA
	   int m_LLRN; // holds the last library reference number read from the dada file
	   Menu m_pubTypeMenu;

	   // DOES: Constructs a new instance of the LibApp class.
	   //        Initializes the member variables m_changed, m_mainMenu, and m_exitMenu, m_pubTypeMenu, calls load();
       // PARAMETERS: None.
       // RETURNS: None.
	   LibApp(const char* filename = nullptr);

	   ~LibApp();

	   // DOES: Runs the library application.
       // PARAMETERS: None.
       // RETURNS: None.
	   void run();

   private:
	   // DOES: Asks the user for confirmation with a given message.
	   // PARAMETERS: message - The message to display for confirmation.
	   // RETURNS: true if the user confirms, false otherwise.
	   bool confirm(const char* message);

	   // DOES: Loads data for the library application.
	   // PARAMETERS: None.
	   // RETURNS: None.
	   void load();

	   // DOES: Saves data for the library application.
	   // PARAMETERS: None.
	   // RETURNS: None.
	   void save();

	   // DOES: Performs a publication search.
	   // PARAMETERS: Mode of search function.
	   // 1. Search all
	   // 2. Search Checkout Items Search only those publications which are on loan by library members
	   // 3. Search Available Items Search only those publications which are not on loan
	   // RETURNS: LibRef number.
	   int search(int mode);

	   // DOES: Performs the return of a publication.
	   // PARAMETERS: None.
	   // RETURNS: None.
	   void returnPub();

	   // DOES: Adds a new publication to the library.
	   // PARAMETERS: None.
	   // RETURNS: None.
	   void newPublication();

	   // DOES: Removes a publication from the library.
	   // PARAMETERS: None.
	   // RETURNS: None.
	   void removePublication();

	   // DOES: Performs the checkout of a publication.
	   // PARAMETERS: None.
	   // RETURNS: None.
	   void checkOutPub();

	   // Searches for a Publication object in PPA that matches the given LibRef parameter.
	   // @param libRef The LibRef number to search.
	   // @return Address of Publication obj in PPA that matches LibRef param.
	   Publication* getPub(int libRef);
   };
}
#endif // !SDDS_LIBAPP_H



