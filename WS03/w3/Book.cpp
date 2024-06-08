////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-05-30							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"
namespace seneca {
	Book::Book() { }
	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) 
		: m_title(title), m_numChapters(nChapters), m_numPages(nPages), m_pageToChap{ static_cast<double>(m_numPages) / m_numChapters }
	{ }
	//Book& Book::operator=(const Book& src)
	//{
	//	if (this != &src && src)
	//	{
	//		m_title = src.m_title;
	//		m_numChapters = src.m_numChapters;
	//		m_numPages = src.m_numPages;
	//		m_pageToChap = src.m_pageToChap;
	//	}
	//	return *this;
	//}

	bool Book::operator>(const Book& src) const
	{
		return m_pageToChap > src.m_pageToChap;
	}

	bool Book::operator<(const Book& src) const
	{
		return m_pageToChap < src.m_pageToChap;
	}

	Book::operator bool() const
	{
		return m_title.length();
	}
	std::ostream& Book::print(std::ostream& os) const
	{
		if (*this)
		{
			os << std::right << std::setw(56) 
				<< (m_title + ',' + std::to_string(m_numChapters) + ',' + std::to_string(m_numPages))
				<< " | " << std::left << std::setw(15)
				<< '(' + std::to_string(m_pageToChap) + ')';
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