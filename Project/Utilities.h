// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H
namespace seneca {
	class Utilities
	{
		size_t m_widthField{1};		// length of the token extracted
		static char m_delimiter;	// separates the tokens in any given std::string object
		std::string trim(const std::string& src);	// remove leading and trailing spaces of a string
	public:
		void setFieldWidth(size_t newWidth);	// sets the field width
		size_t getFieldWidth() const;	// returns the field width
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);	 // extracts a token from string str
		static void setDelimiter(char newDelimiter);	// sets the delimiter for this class
		static char getDelimiter();		// returns the delimiter for this class
	};
}
#endif // !SENECA_UTILITIES_H

