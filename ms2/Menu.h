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
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

#include <iostream>

namespace sdds {
	const unsigned  int MAX_MENU_ITEMS = 20;

	class Menu;

	class MenuItem {
	private:
		char* m_item;

		// DOES: Creates a MenuItem object with an optional item content.
		// PARAMETERS: item - C-style string representing the item content (defaulted to an empty string).
		MenuItem(const char* item = "");

		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;

		// DOES: Destroys the MenuItem object and frees the dynamically allocated memory.
		~MenuItem();

		// DOES: Converts the MenuItem to a boolean value.
		// RETURNS: True if the MenuItem has valid content, false otherwise.
		operator bool()const;

		// DOES: Converts the MenuItem to a const char*.
		// RETURNS: Pointer to the item content.
		operator const char* ()const;

		// DOES: Displays the MenuItem content on the output stream (defaulted to std::cout).
		// PARAMETERS: os - The output stream to display the content on (defaulted to std::cout).
		// RETURNS: Reference to the output stream after displaying the content.
		std::ostream& display(std::ostream& os = std::cout)const;

		friend class Menu;
	};

	class Menu {
	public:
		char* m_title;
		MenuItem* m_menuItem[MAX_MENU_ITEMS];
		int m_noOfItems;

		// DOES: Creates a Menu object without a title and initializes the menu items.
		// PARAMETERS: None.
		Menu();

		// DOES: Creates a Menu object with a specified title and initializes the menu items.
		// PARAMETERS: title - C-style string representing the menu title.
		Menu(const char* title);

		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;

		// DOES: Destroys the Menu object and frees the dynamically allocated memory.
		~Menu();

		// DOES: Displays the title of the Menu on the output stream (defaulted to std::cout).
		// PARAMETERS: os - The output stream to display the title on (defaulted to std::cout).
		// RETURNS: None.
		void displayTitle(std::ostream& os = std::cout)const;

		// DOES: Displays the entire Menu on the output stream (defaulted to std::cout).
		// PARAMETERS: os - The output stream to display the Menu on (defaulted to std::cout).
		// RETURNS: None.
		void displayMenu(std::ostream& os = std::cout)const;

		// DOES: Displays the Menu and gets the user's selection.
		// Validates the selection and returns it.
		// PARAMETERS: None.
		// RETURNS: Unsigned integer representing the user's selection.
		unsigned int run();

		// DOES: Same functionality as run() function.
		// Displays the Menu and gets the user's selection.
		// Validates the selection and returns it.
		// PARAMETERS: None.
		// RETURNS: Unsigned integer representing the user's selection.
		unsigned int operator~();

		// DOES: Adds a MenuItem to the Menu.
		// PARAMETERS: menuitemContent - C-style string representing the content of the MenuItem.
		// RETURNS: Reference to the Menu object after adding the MenuItem.
		Menu& operator<<(const char* menuitemConent);

		// DOES: Converts the Menu to an unsigned int.
		// RETURNS: The number of MenuItems in the Menu.
		operator unsigned int()const;

		// DOES: Converts the Menu to an int.
		// RETURNS: The number of MenuItems in the Menu.
		operator int()const;

		// DOES: Converts the Menu to a boolean value.
		// RETURNS: True if the Menu has one or more MenuItems, false otherwise.
		operator bool()const;

		// DOES: Returns the const char* cast of the corresponding MenuItem content in the Menu.
		// PARAMETERS: index - Index of the MenuItem to access.
		// RETURNS: Pointer to the MenuItem content.
		const char* operator[](int)const;

	};

	// DOES: Writes the Menu title to the output stream.
	// PARAMETERS: os - The output stream to write to.
	// item - The Menu object to write.
	// RETURNS: Reference to the output stream after writing the Menu title.
	std::ostream& operator<<(std::ostream& os, const Menu& item);

}
#endif


