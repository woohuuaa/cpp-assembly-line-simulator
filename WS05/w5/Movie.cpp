////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-06-13							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
#include "Movie.h"
#include <string>
#include <iomanip>
namespace seneca {
	void Movie::trim(std::string& str)
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
	const std::string& Movie::title() const
	{
		return m_title;
	}
	Movie::Movie(const std::string& strMovie)
	{
		int start = 0;
		int end = strMovie.find(',');

		m_title = strMovie.substr(start, end - start);
		trim(m_title);

		start = end + 1;
		end = strMovie.find(',', start);
		m_year = std::stoi(strMovie.substr(start, end - start));

		start = end + 1;
		m_desc = strMovie.substr(start);
		trim(m_desc);
	}
	std::ostream& operator<<(std::ostream& o, const Movie& m)
	{
		o << std::setw(40) << m.m_title << " | "
			<< std::setw(4) << m.m_year << " | "
			<< m.m_desc << std::endl;
		return o;
	}
}
