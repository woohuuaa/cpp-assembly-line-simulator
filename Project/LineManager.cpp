// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-31
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <fstream>
#include <string>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"
namespace seneca {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::ifstream f(file);
		if (!f.is_open())
		{
			throw "File not found";
		}
		// read data from file
		// use Utilities to extract station information from each line read
		std::string line{};
		Utilities u;
		while (std::getline(f, line))
		{
			bool more{ true };
			size_t nextPo{ 0u };

			// extract station | next station using extractToken function
			std::string station = u.extractToken(line, nextPo, more);
			std::string nextStation = u.extractToken(line, nextPo, more);

			// copy the found station into m_activeLine vector
			std::copy_if(stations.begin(), stations.end(), std::back_inserter(m_activeLine), [&](Workstation* s1) 
			{
				if (s1->getItemName() == station) 
				{	
					// loop to find the next station and setNextStation of current station
					auto itr = std::find_if(stations.begin(), stations.end(), [&](const Workstation* s2) {
						return s2->getItemName() == nextStation;
					});
					if (itr != stations.end())
					{
						s1->setNextStation(*itr);
					}
					return true;
				}
				return false;
			});
		}
		// identifies the first station in the assembly line
		auto firstIt = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* s1) 
		{
			return std::none_of(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* s2) 
			{
				return s2->getNextStation() && s2->getNextStation()->getItemName() == s1->getItemName();
			});
		});
		// set first station
		if (firstIt != m_activeLine.end()) 
		{
			m_firstStation = *firstIt;
		}
		// updates the attribute that holds the total number of orders in the g_pending
		m_cntCustomerOrder = g_pending.size();
	}

	void LineManager::reorderStations()
	{
		std::vector<Workstation*> newLine;
		// set first station
		Workstation* sPtr = m_firstStation;
		// push station to new array and get next station
		while (sPtr) 
		{
			newLine.push_back(sPtr);
			sPtr = sPtr->getNextStation();
		}
		m_activeLine = newLine;
	}

	bool LineManager::run(std::ostream& os)
	{
		static int counter = 0;	// current iteration number
		// iteration number (how many times this function has been called by the client)
		os << "Line Manager Iteration:" << ++counter << std::endl;
		if (g_pending.size()) {
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}

		for (auto& w : m_activeLine) {
			w->fill(os);
		}

		for (auto& w : m_activeLine) {
			w->attemptToMoveOrder();
		}

		if ((g_completed.size() + g_incomplete.size()) == m_cntCustomerOrder)
		{
			return true;
		}
		return false;
	}

	void LineManager::display(std::ostream& os) const
	{
		// displays all active stations on the assembly line in their current order 
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* s) {
			return s->display(os);
		});
	}
}
