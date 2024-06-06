#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H
#include "Reservation.h"
namespace seneca {
	class ConfirmationSender
	{
		const seneca::Reservation** m_pReservations{};
		size_t m_numOfResv{};
		void setEmpty();
		void resize(size_t newSize);
	public:
		ConfirmationSender();
		// rule of 5
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);
		virtual ~ConfirmationSender();
		/// <summary>
		/// adds the reservation res to the array by adding its address.
		/// </summary>
		/// <param name="res"></param>
		/// <returns></returns>
		ConfirmationSender& operator+=(const Reservation& res);
		/// <summary>
		/// removes the reservation res from the array by removing its address
		/// </summary>
		ConfirmationSender& operator-=(const Reservation& res);
		/// <summary>
		/// to insert the content of a ConfirmationSender object into an ostream object
		/// </summary>
		/// <param name="o"></param>
		/// <param name="cfms"></param>
		/// <returns></returns>
		friend std::ostream& operator<<(std::ostream& o, const ConfirmationSender& cfms);
	};
}
#endif // !SENECA_CONFIRMATIONSENDER_H



