// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
namespace seneca {
	
	size_t Station::m_widthField{ 0 };
	int Station::id_generator{ 0 };

	Station::Station(const std::string& line)
	{
		Utilities u;
		size_t nextPo{0u};
		bool more{true};
		m_itemName = u.extractToken(line, nextPo, more);
		m_nextNo = std::stoi(u.extractToken(line, nextPo, more));
		m_stock = std::stoi(u.extractToken(line, nextPo, more));
		if (u.getFieldWidth() > m_widthField) {
			m_widthField = u.getFieldWidth();
		}
		m_description = u.extractToken(line, nextPo, more);
		m_id = ++id_generator;
	}
	const std::string& Station::getItemName() const
	{
		return m_itemName;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_nextNo++;
	}
	size_t Station::getQuantity() const
	{
		return m_stock;
	}
	void Station::updateQuantity()
	{
		if (m_stock == 0)
		{
			throw "No enough stock";
		}
		m_stock -= 1;
	}
	void Station::display(std::ostream& os, bool full) const
	{
		os << std::setw(3) << std::setfill('0') << m_id << " | " << std::setfill(' ')
			<< std::setw(m_widthField) << m_itemName << " | "
			<< std::setw(6) << std::setfill('0') << m_nextNo << " | " << std::setfill(' ');
		if (full)
		{
			os << std::setw(4) << m_stock << " | " << m_description;
		}
		os << std::endl;
	}
}