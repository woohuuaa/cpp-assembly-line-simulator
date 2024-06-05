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
#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H
#include <iostream>
namespace seneca {
	constexpr int MAX_DAY = 28;
	constexpr int MAX_HOUR = 24;
	class Reservation
	{
		std::string m_id{};
		std::string m_name{};
		std::string m_email{};
		int m_numOfPeople{};
		int m_day{};
		int m_hour{};
		/// <summary>
		/// to trim the leading and trailing spaces
		/// </summary>
		/// <param name="res"></param>
		void trimStr(std::string& res);
	public:
		/// <summary>
		/// default constructor
		/// </summary>
		Reservation();
		/// <summary>
		/// updates the attributes with received new day and time for the reservation
		/// </summary>
		/// <param name="day"></param>
		/// <param name="time"></param>
		void update(int day, int time);
		/// <summary>
		/// responsible for extracting information about the reservation from the string 
		/// and storing the tokens in the instance's attributes.
		/// </summary>
		/// <param name="res"></param>
		Reservation(const std::string& res);

		// Friend Helpers
		/// <summary>
		/// if the hour is between 6AM and 9AM (inclusive), the kitchen serves breakfast
		/// if the hour is between 11AM and 3PM (inclusive), the kitchen serves lunch
		/// if the hour is between 5PM and 9PM (inclusive), the kitchen serves dinner
		/// </summary>
		/// <param name="o"></param>
		/// <param name="r"></param>
		/// <returns></returns>
		friend std::ostream& operator<<(std::ostream& o, const Reservation& r);
	};
}
#endif // !SENECA_RESERVATION_H

