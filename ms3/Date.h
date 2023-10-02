/*/////////////////////////////////////////////////////////////////////////
                          OOP224 MS3
Full Name  : Raphael Antioquia
Student ID#: 031379126
Email      : rtantioquia@myseneca.ca
Section    : NEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// Final Project Milestone 1 
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include <iostream>
namespace sdds {
   const int NO_ERROR = 0;
   const int CIN_FAILED = 1;
   const int YEAR_ERROR = 2;
   const int MON_ERROR = 3;
   const int  DAY_ERROR = 4;
   const char DATE_ERROR[5][16] = {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
   };
   const int  MIN_YEAR = 1500;
   class Date {
   private:
      int m_year;
      int m_mon;
      int m_day;
      int m_ErrorCode;
      int m_CUR_YEAR;
      int daysSince0001_1_1()const; // returns number of days passed since the date 0001/1/1
      bool validate();             /* validates the date setting the error code and then returning the result 
                                    true, if valid, and false if invalid.*/
      void errCode(int);           // sets the error code
      int systemYear()const;       // returns the current system year
      bool bad()const;             // return true if
      int mdays()const;            // returns the number of days in current month
      void setToToday();           // sets the date to the current date (system date)

     
   public:
      Date();                      // creates a date with current date
      Date(int year, int mon, int day); /* create a date with assigned values
                                         then validates the date and sets the 
                                         error code accordingly */
      int errCode()const;         // returns the error code or zero if date is valid
      const char* dateStatus()const;  // returns a string corresponding the current status of the date
      int currentYear()const;         // returns the m_CUR_YEAR value;

      // DOES: Reads a date from the input stream (defaulted to std::cin).
      // PARAMETERS: is - The input stream to read from (defaulted to std::cin).
      // RETURNS: Reference to the input stream after reading the date.
      std::istream& read(std::istream& is = std::cin);

      // DOES: Writes the date to the output stream(defaulted to std::cout).
      // PARAMETERS: os - The output stream to write to (defaulted to std::cout).
      // RETURNS: Reference to the output stream after writing the date.
      std::ostream& write(std::ostream& os = std::cout)const;

      // DOES: Checks if the date is equal to the other date.
      // PARAMETERS: other - The other Date object to compare with.
      // RETURNS: True if the dates are equal, false otherwise.
      bool operator==(const Date& other)const;

      // DOES: Checks if the date is not equal to the other date.
      // PARAMETERS: other - The other Date object to compare with.
      // RETURNS: True if the dates are not equal, false otherwise.
      bool operator!=(const Date& other)const;

      // DOES: Checks if the date is greater than or equal to the other date.
      // PARAMETERS: other - The other Date object to compare with.
      // RETURNS: True if the date is greater than or equal to the other date, false otherwise.
      bool operator>=(const Date& other)const;

      // DOES: Checks if the date is less than or equal to the other date.
      // PARAMETERS: other - The other Date object to compare with.
      // RETURNS: True if the date is less than or equal to the other date, false otherwise.
      bool operator<=(const Date& other)const;

      //DOES: Checks if the date is less than the other date.
      // PARAMETERS: other - The other Date object to compare with.
      // RETURNS: True if the date is less than the other date, false otherwise.
      bool operator<(const Date& other)const;

      // DOES: Checks if the date is greater than the other date.
      // PARAMETERS: other - The other Date object to compare with.
      // RETURNS: True if the date is greater than the other date, false otherwise.
      bool operator>(const Date& other)const;
       
      // DOES: Calculates the difference in days between the date and the other date.
      // PARAMETERS: other - The other Date object to calculate the difference with.
      // RETURNS: The difference in days as an integer.
      int operator-(const Date& other)const;

      // DOES: Converts the date to a boolean value.
      // RETURNS: True if the date is valid, false otherwise.
      operator bool()const;
      
   };

   // DOES: Writes the date to the output stream.
   // PARAMETERS: os - The output stream to write to.
   // RO - The Date object to write.
   // RETURNS: Reference to the output stream after writing the date.
   std::ostream& operator<<(std::ostream& os, const Date& RO);

   // DOES: Reads the date from the input stream.
   // PARAMETERS: is - The input stream to read from.
   // RO - The Date object to store the read date.
   // RETURNS: Reference to the input stream after reading the date.
   std::istream& operator>>(std::istream& is, Date& RO);

   extern bool sdds_test;
   extern int sdds_year;
   extern int sdds_mon;
   extern int sdds_day;
}
#endif