// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
namespace seneca {
	std::string Utilities::trim(const std::string& src)
	{
		size_t first = src.find_first_not_of(' ');
		size_t last = src.find_last_not_of(' ');
		return src.substr(first, (last - first + 1));
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
		if (next_pos == m_delimiter) {
			throw "Invalid position.";
		}
		std::string token{};
		size_t end = str.find(m_delimiter, next_pos);
		if (end != std::string::npos) {
			token = trim(str.substr(next_pos, end));
			next_pos = end + 1;
			more = true;
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
