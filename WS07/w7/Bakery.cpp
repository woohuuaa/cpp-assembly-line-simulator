////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-07-19							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
#include "Bakery.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>
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
		// declare size of each field
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
		// display each BakedGood in m_collection
		// can also use all_of / none_of
		std::for_each(m_collection.begin(), m_collection.end(), [&os](auto bg) { os << bg << '\n'; });
		
		// count and display total of BakedGood qty
		/////////////////////////// Question: why we need to use a const int& to accumulate 
		int totalStock = std::accumulate(m_collection.begin(), m_collection.end(), 0, [](const int& totalS, const BakedGood& b) {
			return totalS + b.qty; });
		os << "Total Stock: " << totalStock << std::endl;
		// count and display total of BakedGood price
		double totalPrice = std::accumulate(m_collection.begin(), m_collection.end(), 0.0, [](const double& totalP, const BakedGood& b) {
			return totalP + b.price; });
		os << "Total Price: " << std::fixed << std::setprecision(2) << totalPrice << std::endl;
	}

	void Bakery::sortBakery(const std::string& fieldName)
	{
		// sort Bakery in ascending order based on field
		if (fieldName == "Description") {
			std::sort(m_collection.begin(), m_collection.end(), [](const BakedGood& b1, const BakedGood& b2) {
				return b1.description < b2.description;
			});
		}
		else if (fieldName == "Shelf") {
			std::sort(m_collection.begin(), m_collection.end(), [](const BakedGood& b1, const BakedGood& b2) {
				return b1.shelfLife < b2.shelfLife;
			});
		}
		else if (fieldName == "Stock") {
			std::sort(m_collection.begin(), m_collection.end(), [](const BakedGood& b1, const BakedGood& b2) {
				return b1.qty < b2.qty;
			});
		}
		else if (fieldName == "Price") {
			std::sort(m_collection.begin(), m_collection.end(), [](const BakedGood& b1, const BakedGood& b2) {
				return b1.price < b2.price;
			});
		}
		else {
			throw "Invalid field name.";
		}
	}

	std::vector<BakedGood> Bakery::combine(Bakery& b)
	{
		int newSize = m_collection.size() + b.m_collection.size();
		std::vector<BakedGood> newCollect(newSize);
		sortBakery("Price");
		b.sortBakery("Price");
		// use merge sort to insert elements
		std::merge(m_collection.begin(), m_collection.end(), b.m_collection.begin(), b.m_collection.end(), 
			newCollect.begin(), [](const BakedGood& b1, const BakedGood& b2) {
				return b1.price < b2.price; 
			});
		return newCollect;
	}

	bool Bakery::inStock(const std::string& desc, BakedType type) const
	{
		// any_of / find
		return any_of(m_collection.begin(), m_collection.end(), [=](const BakedGood& b) {
				return b.description == desc;
			});
		;
	}

	std::list<BakedGood> Bakery::outOfStock(BakedType type) const
	{
		std::list<BakedGood> outOfStockList{};
		// Another version to create an out-of-stock array to return:
		// use count_if to count the size of new array
		//int newSize = count_if(m_collection.begin(), m_collection.end(), [=](const BakedGood& b) {
		//return b.type == type && b.qty == 0; });
		//
		//outOfStockList.resize(newSize);
		//
		//copy_if(m_collection.begin(), m_collection.end(), outOfStockList.begin(), [=](const BakedGood& b) {
		//return b.type == type && b.qty == 0;
		//});
		// 
		// algorithms do not change the memory size of cotainer
		std::copy_if(m_collection.begin(), m_collection.end(), std::back_inserter(outOfStockList), [=](const BakedGood& b) {
			return b.type == type && b.qty == 0;
			});
		return outOfStockList;
	}

	std::ostream& operator<<(std::ostream& out, const BakedGood& b)
	{
		out << "* " << std::left << std::setw(10) << (b.type == BakedType::BREAD ? "Bread" : "Pastry")
			<< " * " << std::setw(20) << b.description
			<< " * " << std::setw(5) << b.shelfLife
			<< " * " << std::setw(5) << b.qty
			<< " * " << std::right << std::fixed << std::setprecision(2) << std::setw(8) << b.price << " * ";
		return out;
	}

}
