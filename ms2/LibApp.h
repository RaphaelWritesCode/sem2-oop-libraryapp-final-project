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

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include <iostream>
#include "Menu.h"

namespace sdds {
   class LibApp {
   public:
	   bool m_changed;
	   Menu m_mainMenu;
	   Menu m_exitMenu;

	   // DOES: Constructs a new instance of the LibApp class.
	   //        Initializes the member variables m_changed, m_mainMenu, and m_exitMenu, calls load();
       // PARAMETERS: None.
       // RETURNS: None.
	   LibApp();

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
	   // PARAMETERS: None.
	   // RETURNS: None.
	   void search();

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
   };
}
#endif // !SDDS_LIBAPP_H



