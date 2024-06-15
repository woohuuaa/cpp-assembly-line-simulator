////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-06-12							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
#include "Book.h"
#include <string>
#include <iomanip>
namespace seneca {
	void Book::trim(std::string& str)
	{
		// Remove leading spaces
		while (str.front() == ' ' || str.front() == '\t')
		{
			str.erase(0, 1);
		}
		// Remove trailing spaces
		while (str.back() == ' ' || str.front() == '\t')
		{
			str.erase(str.length() - 1);
		}
	}

	const std::string& seneca::Book::title() const
	{
		return m_title;
	}

	const std::string& seneca::Book::country() const
	{
		return m_country;
	}

	const size_t& seneca::Book::year() const
	{
		return m_year;
	}

	double& seneca::Book::price()
	{
		return m_price;
	}

	seneca::Book::Book(const std::string& strBook)
	{
		int start = 0;
		int end = strBook.find(',');

		m_author = strBook.substr(start, end - start);
		trim(m_author);

		start = end + 1;
		end = strBook.find(',', start);
		m_title = strBook.substr(start, end - start);
		trim(m_title);

		start = end + 1;
		end = strBook.find(',', start);
		m_country = strBook.substr(start, end - start);
		trim(m_country);

		start = end + 1;
		end = strBook.find(',', start);
		m_price = std::stod(strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.find(',', start);
		m_year = std::stoi(strBook.substr(start, end - start));

		start = end + 1;
		m_description = strBook.substr(start);
		trim(m_description);
	}
	std::ostream& operator<<(std::ostream& o, const Book& book)
	{
		o << std::setw(20) << book.m_author << " | "
			<< std::setw(22) << book.m_title << " | "
			<< std::setw(5) << book.m_country << " | "
			<< std::setw(4) << book.m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | " 
			<< book.m_description << std::endl;
		return o;
	}
}


