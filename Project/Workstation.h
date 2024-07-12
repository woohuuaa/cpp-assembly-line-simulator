#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H
#include <deque>
#include <iostream>
#include "CustomerOrder.h"
#include "Workstation.h"
namespace seneca {
	extern std::deque<CustomerOrder> g_pending;		// the orders to be placed onto the assembly line at the first station.
	extern std::deque<CustomerOrder> g_completed;	// the orders that have been removed from the last station and have been completely filled.
	extern std::deque<CustomerOrder> g_incomplete;	// the orders that have been removed from the last station and could not be filled completely.

	class Workstation : public Station
	{	// entering the back and exiting the front
		std::deque<CustomerOrder> m_orders{};	// orders that have been placed on this station to receive service
		Workstation* m_pNextStation{};
	public:
		Workstation(const Workstation& src) = delete;				// copy constructor
		Workstation& operator=(const Workstation& src) = delete;	// copy assignment
		Workstation(Workstation&& src) = delete;					// move constructor
		Workstation& operator=(Workstation&& src) = delete;			// move assignment

		Workstation(const std::string& str);		
		void fill(std::ostream& os);				// fills the order at the front of the queue
		bool attemptToMoveOrder();					// move the order order at the front of the queue to the next station in the assembly line
		void setNextStation(Workstation* station);	// stores the address of Workstation to m_pNextStation
		Workstation* getNextStation() const;		// returns the address of next Workstation
		void display(std::ostream& os) const;		// display the name of the Item for which the current object is responsible
		Workstation& operator+=(CustomerOrder&& newOrder);	// moves the newOrder to the back of the queue
	};
}
#endif // !SENECA_WORKSTATION_H

