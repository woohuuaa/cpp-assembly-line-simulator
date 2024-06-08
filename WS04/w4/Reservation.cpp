////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-06-05							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
#include "Reservation.h"
#include <string>
#include <iomanip>
namespace seneca {

	void Reservation::trimStr(std::string& res)
	{
		// Remove leading spaces
		while (res.front() == ' ' || res.front() == '\t')
		{
			res.erase(0, 1);
		}
		// Remove trailing spaces
		while (res.back() == ' ' || res.front() == '\t')
		{
			res.erase(res.length() - 1);
		}
	}
	Reservation::Reservation() { }
	void Reservation::update(int day, int time)
	{
		m_day = day;
		m_hour = time;
	}
	Reservation::Reservation(const std::string& res)
	{
		int start = 0;
		int end = res.find(':');

		m_id = res.substr(start, end - start);
		trimStr(m_id);

		start = end + 1;
		end = res.find(',', start);
		m_name = res.substr(start, end - start);
		trimStr(m_name);

		start = end + 1;
		end = res.find(',', start);
		m_email = res.substr(start, end - start);
		trimStr(m_email);

		start = end + 1;
		end = res.find(',', start);
		m_numOfPeople = std::stoi(res.substr(start, end - start));

		start = end + 1;
		end = res.find(',', start);
		m_day = std::stoi(res.substr(start, end - start));

		start = end + 1;
		m_hour = std::stoi(res.substr(start));
	}

	Reservation::operator bool() const
	{
		return !m_id.empty();
	}

	std::ostream& operator<<(std::ostream& o, const Reservation& r)
	{
		o << "Reservation "
			<< std::right << std::setw(10) << r.m_id << ": "
			<< std::right << std::setw(20) << r.m_name << "  "
			<< std::left << std::setw(20) << "<" + r.m_email + ">"
			<< "    ";

		if (r.m_hour >= 6 && r.m_hour <= 9) {
			o << "Breakfast";
		}
		else if (r.m_hour >= 11 && r.m_hour <= 15) {
			o << "Lunch";
		}
		else if (r.m_hour >= 17 && r.m_hour <= 21) {
			o << "Dinner";
		}
		else {
			o << "Drinks";
		}

		o << " on day " << r.m_day << " @ " << r.m_hour << ":00 for "
			<< r.m_numOfPeople;

		if (r.m_numOfPeople == 1) {
			o << " person." << std::endl;
		}
		else {
			o << " people." << std::endl;
		}

		return o;
	}
}
