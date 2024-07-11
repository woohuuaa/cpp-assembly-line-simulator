// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include "Utilities.h"
namespace seneca {
	Station::Station(const std::string& line)
	{
		Utilities u;
		size_t nextPo{};
		bool more{};
		u.extractToken(line, nextPo, more);
	}
}