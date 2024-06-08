#include "ConfirmationSender.h"
namespace seneca {
	void ConfirmationSender::setEmpty()
	{
		delete[] m_pReservations;
		m_pReservations = nullptr;
		m_numOfResv = 0;
	}
	void ConfirmationSender::resize(size_t newSize)
	{
		const Reservation** tmpResP = new const Reservation*[newSize];
		if (newSize > m_numOfResv)
		{
			for (size_t i = 0; i < m_numOfResv; ++i)
			{
				tmpResP[i] = m_pReservations[i];
			}
		}
		else 
		{
			for (size_t i = 0, index = 0; i < m_numOfResv; ++i)
			{
				if (m_pReservations[i])
				{
					tmpResP[index++] = m_pReservations[i];
				}
			}
		}
		delete[] m_pReservations;
		m_pReservations = tmpResP;
	}
	seneca::ConfirmationSender::ConfirmationSender() { }
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
	{
		*this = std::move(src);
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src)
		{
			setEmpty();
			if (src.m_pReservations)
			{
				m_numOfResv = src.m_numOfResv;
				m_pReservations = new const Reservation * [m_numOfResv];
				for (size_t i = 0; i < m_numOfResv; ++i) 
				{
					m_pReservations[i] = src.m_pReservations[i];
				}

			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		if (this != &src)
		{
			setEmpty();
			if (src.m_pReservations)
			{
				m_numOfResv = src.m_numOfResv;
				m_pReservations = src.m_pReservations;
				src.m_pReservations = nullptr;
			}
		}
		return *this;
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_pReservations;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		if (res)
		{
			bool found{ false };
			for (size_t i = 0; i < m_numOfResv && !found; ++i)
			{
				if (m_pReservations[i] == &res)
				{
					found = true;
				}
			}
			if (!found)
			{
				resize(m_numOfResv + 1);
				m_pReservations[m_numOfResv++] = &res;
			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		if (res)
		{
			bool found{ false };
			for (size_t i = 0; i < m_numOfResv && !found; ++i)
			{
				if (m_pReservations[i] == &res)
				{
					found = true;
					m_pReservations[i] = nullptr;
				}
			}
			if (found)
			{
				resize(m_numOfResv - 1);
				--m_numOfResv;
			}
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& o, const ConfirmationSender& cfms)
	{
		o << "--------------------------\nConfirmations to Send\n--------------------------\n";
		if (cfms.m_pReservations)
		{
			for (size_t i = 0; i < cfms.m_numOfResv; ++i)
			{
				o << *cfms.m_pReservations[i];
			}
		}
		else
		{
			o << "There are no confirmations to send!\n";
		}
		o << "--------------------------" << std::endl;
		return o;
	}
}
