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
		int id{};
		std::string itemName{};
		std::string description{};
		size_t nextNo{};
		size_t stock{};
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
	static size_t m_widthField{0};
	static int id_generator{0};
}
#endif // !SENECA_STATION_H

