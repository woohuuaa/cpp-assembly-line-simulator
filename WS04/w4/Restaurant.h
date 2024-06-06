#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H
#include "Reservation.h"
namespace seneca {
	class Restaurant
	{
		Reservation** m_pReservations{};
		size_t m_numOfResv{};
		void setEmpty();	
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		//rule of 5
		Restaurant(const Restaurant& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant(Restaurant&& src);
		Restaurant& operator=(Restaurant&& src);
		virtual ~Restaurant();
		/// <summary>
		/// a query that returns the number of reservations in the system
		/// </summary>
		/// <returns></returns>
		size_t size();
		/// <summary>
		/// to insert the content of a Restaurant object into an ostream object
		/// </summary>
		/// <param name="o">ostream object</param>
		/// <param name="rest">Restaurant object</param>
		/// <returns></returns>
		friend std::ostream& operator<<(std::ostream& o, const Restaurant& rest);
	};	
}
#endif // !SENECA_RESTAURANT_H

