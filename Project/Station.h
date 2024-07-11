// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
namespace seneca {
	class Station
	{
		int m_id{};
		std::string m_itemName{};
		std::string m_description{};
		size_t m_nextNo{};
		size_t m_stock{};
		static size_t m_widthField;
		static int id_generator;
	public:
		Station(const std::string& line);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !SENECA_STATION_H

