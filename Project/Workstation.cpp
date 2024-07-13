// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Workstation.h"
namespace seneca {
	Workstation::Workstation(const std::string& str) : Station(str) {
	}

	void Workstation::fill(std::ostream& os) 
	{
		if (!m_orders.empty())
		{
			m_orders.front().fillItem(*this, os);	// fills the order at the front of the queue
		}
	}
	bool Workstation::attemptToMoveOrder() 
	{	// if the order requires no more service at this station or cannot be filled (not enough inventory)
		if (m_orders.front().isOrderFilled() || !getQuantity())
		{	// move it to the next station
			if (m_pNextStation)
			{
				m_pNextStation->m_orders.push_back(m_orders.front());
			}
			else // if there is no next station in the assembly line
			{
				if (m_orders.front().isOrderFilled())
				{
					g_completed.push_front(m_orders.front());
				}
				else
				{
					g_incomplete.push_front(m_orders.front());
				}
			}
			m_orders.pop_front();
			return true;
		}
		return false;
	}
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation)
		{
			os << getItemName() << " --> " << m_pNextStation->getItemName() << '\n';
		}
		else
		{
			os << getItemName() << " --> End of Line" << '\n';
		}
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(newOrder);
		return *this;
	}
}