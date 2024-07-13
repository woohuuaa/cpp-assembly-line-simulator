// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <fstream>
#include "LineManager.h"
#include "Utilities.h"
namespace seneca {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{

		std::ifstream f(file);

		Utilities u;
		size_t nextPo{ 0u };
		bool more{ true };
		std::string str{};
		// extract name of the item, starting serial number, quantity in stock, description
		// using extractToken function
		m_itemName = u.extractToken(str, nextPo, more);
		m_nextNo = std::stoi(u.extractToken(str, nextPo, more));
	}
}
