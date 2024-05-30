#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"
namespace seneca {
	Book::Book() { }
	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
	{
		m_title = title;
		m_numChapters = nChapters;
		m_numPages = nPages;
	}
	//bool Book::operator=(const Book& src)
	//{
	//	if (src)
	//	{
	//		m_title = src.m_title;
	//		m_numChapters = src.m_numChapters;
	//		m_numPages = src.m_numPages;
	//		return true;
	//	}
	//	return false;
	//}

	//bool Book::operator>(const Book& src)
	//{
	//	if (src && ((m_title > src.m_title) || (m_numChapters > src.m_numChapters) || (m_numPages > src.m_numPages)))
	//	{
	//		return true;
	//	}
	//	return false;
	//}

	//bool Book::operator<(const Book& src)
	//{
	//	if (src && ((m_title < src.m_title) || (m_numChapters < src.m_numChapters) || (m_numPages < src.m_numPages)))
	//	{
	//		return true;
	//	}
	//	return false;
	//}

	//bool Book::operator==(const Book& src)
	//{
	//	if (src && (m_title == src.m_title) && (m_numChapters == src.m_numChapters) && (m_numPages == src.m_numPages))
	//	{
	//		return true;
	//	}
	//	return false;
	//}

	Book::operator bool() const
	{
		return (m_title.length() && m_numChapters && m_numPages);
	}
	std::ostream& Book::print(std::ostream& os) const
	{
		if (*this)
		{
			os << std::right << std::setw(56) 
				<< (m_title + ',' + std::to_string(m_numChapters) + ',' + std::to_string(m_numPages))
				<< std::left << std::setw(15) 
				<< " | (" + std::to_string(static_cast<double>(m_numPages) / m_numChapters) + ')';
		}
		else
		{
			os << "| Invalid book data";
		}
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Book& bk)
	{ 
		return bk.print(os);
	}
}