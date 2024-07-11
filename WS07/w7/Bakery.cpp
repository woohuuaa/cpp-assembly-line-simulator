#include "Bakery.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
namespace seneca {
	BakedGood::BakedGood(BakedType type, std::string desc, size_t sl, size_t qty, double price)
		: type(type), description(desc), shelfLife(sl), qty(qty), price(price) { }

	std::string Bakery::trim(const std::string& str)
	{
		size_t first = str.find_first_not_of(' ');
		size_t last = str.find_last_not_of(' ');
		return str.substr(first, (last - first + 1));
	}
	Bakery::Bakery(std::string filename)
	{
		std::ifstream f(filename);
		size_t typeSize = 8, descSize = 20, SLSize = 14, stockSize = 8, priceSize = 6;
		// throw exception if file name is not valid
		if (!f.is_open())
		{
			throw "File not found";
		}
		// read data from file
		std::string line{};
		while (std::getline(f, line))
		{
			size_t start = 0, end = typeSize;
			std::string type = trim(line.substr(start, typeSize));
			BakedType bType{};
			if (type == "Bread")
			{
				bType = BakedType::BREAD;
			}
			else
			{
				bType = BakedType::PASTERY;
			}
			start = typeSize;
			end = start + descSize;
			std::string desc = trim(line.substr(start, descSize));

			start = end;
			end = start + SLSize;
			int sl = std::stoi(trim(line.substr(start, SLSize)));

			start = end;
			end = start + stockSize;
			int qty = std::stoi(trim(line.substr(start, stockSize)));

			start = end;
			end = start + priceSize;
			double price = std::stod(trim(line.substr(start, priceSize)));

			BakedGood bg(bType, desc, sl, qty, price);
			m_collection.push_back(bg);
		}
		f.close();
	}

	void Bakery::showGoods(std::ostream& os) const
	{
		std::for_each(m_collection.begin(), m_collection.end(), [&](auto bg) { 
			os << bg;
		});
	}

	std::ostream& operator<<(std::ostream& out, const BakedGood& b)
	{
		out << "* " << std::left << std::setw(10) << (b.type == BakedType::BREAD ? "Bread" : "Pastry")
			<< " * " << std::setw(20) << b.description
			<< " * " << std::setw(5) << b.shelfLife
			<< " * " << std::setw(5) << b.qty
			<< " * " << std::right << std::fixed << std::setprecision(2) << std::setw(8) << b.price << " *" << std::endl;
		return out;
	}

}
