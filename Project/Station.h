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
		int m_id{};						// id of the station
		std::string m_itemName{};		// name of the item handled by the station
		std::string m_description{};	// description of the station
		size_t m_nextNo{};				// next serial number to be assigned to an item at this station
		size_t m_stock{};				// number of items currently in stock
		static size_t m_widthField;		// the maximum number of characters required to print to the screen the item name
		static int id_generator;		// generate IDs for new instances of type Station
	public:
		Station(const std::string& line);			// Create a station object from single record
		const std::string& getItemName() const;		// returns the name of the current Station
		size_t getNextSerialNumber();				// returns the next serial number to be used
		size_t getQuantity() const;					// returns the remaining quantity of items in the Station
		void updateQuantity();						// subtracts 1 from the available quantity
		void display(std::ostream& os, bool full) const;	// display station information
	};
}
#endif // !SENECA_STATION_H

