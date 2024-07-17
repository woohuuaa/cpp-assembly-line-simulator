// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
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
		size_t nextPo{ 0u };
		bool more{ true };
		while (std::getline(f, line) && more)
		{
			// extract station | next station using extractToken function
			std::string station = u.extractToken(line, nextPo, more);
			std::string nextStation = u.extractToken(line, nextPo, more);
			// copy the found station into m_activeLine vector
			std::copy_if(stations.begin(), stations.end(), std::back_inserter(m_activeLine), [=](const Workstation*& s) {
					return s->getItemName() == station;
			});
			// set the next station for found station
			const auto itr = std::find_if(stations.begin(), stations.end(), [=](const Workstation*& s) {
					return s->getItemName() == nextStation;
			});
			m_activeLine.back()->setNextStation(*itr);
		}
		// identifies the first station in the assembly line
		m_firstStation = m_activeLine.front();
		// updates the attribute that holds the total number of orders in the g_pending
		m_cntCustomerOrder = g_pending.size();
	}
	void LineManager::reorderStations()
	{
		std::sort(m_activeLine.begin(), m_activeLine.end(), [=](const Workstation*& s1, const Workstation*& s2) {
			return s1->getNextStation()->getItemName() == s2->getItemName();
		});
	}
	bool LineManager::run(std::ostream& os)
	{
		int count{};	// current iteration number
		os << "Line Manager Iteration:" << count << std::endl;
		m_firstStation. = g_pending.front();
		g_pending.pop_front();
		return false;
	}
	void LineManager::display(std::ostream& os) const
	{
		// displays all active stations on the assembly line in their current order 
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation*& s) {
			return s->display(os);
		});
	}
}
