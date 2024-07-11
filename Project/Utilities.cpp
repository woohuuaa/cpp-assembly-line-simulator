// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
namespace seneca {
	char Utilities::m_delimiter = ',';

	std::string Utilities::trim(const std::string& src)
	{
		size_t first = src.find_first_not_of(' ');
		size_t last = src.find_last_not_of(' ');
		// if non-space char is not found, return empty string
		// otherwise return sub string without leading and trailing spaces
		return (first == std::string::npos || last == std::string::npos) ? "" : src.substr(first, last - first + 1);
	}
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		// reports an exception if a delimiter is found at next_pos
		if (str[next_pos] == m_delimiter) {
			more = false;
			throw "No Token Found.";
		}
		// uses the delimiter to extract the next token from str starting at position next_pos
		size_t end = str.find(m_delimiter, next_pos);
		std::string token = trim(str.substr(next_pos, end - next_pos));
		// if the delimiter is found
		if (end != std::string::npos) {
			next_pos = end + 1;
			more = true;
		}
		else { // if no delimiter found, reached the end of the string
			next_pos = str.size();
			more = false;
		}
		// set the width if token size is larger than stored m_widthField
		if (m_widthField < token.size())
		{
			m_widthField = token.size();
		}
		return token;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}
