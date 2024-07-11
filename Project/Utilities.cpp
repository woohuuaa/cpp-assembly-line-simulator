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
		size_t end = str.find(m_delimiter, next_pos);
		std::string token = trim(str.substr(next_pos, end - next_pos));
		// if the delimiter is found
		if (end != std::string::npos) {
			next_pos = end + 1;
			more = true;
		}
		else { // if not found, should be the end of string
			next_pos = str.size();
			more = false;
		}
		if (token.empty())
		{
			more = false;
			throw "No Token.";
		}
		if (str[next_pos] == m_delimiter) {
			throw "Invalid next position.";
		}
		m_widthField = m_widthField < token.size() ? token.size() : m_widthField;
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
