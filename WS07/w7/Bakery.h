#ifndef SENECA_BAKERY_H
#define SENECA_BAKERY_H
#include <iostream>
#include <vector>
namespace seneca {
	
	enum class BakedType
	{
		BREAD, PASTERY
	};

	struct BakedGood 
	{
		BakedType type{};
		std::string description{};
		size_t shelfLife{};
		size_t qty{};
		double price{};
		BakedGood(BakedType type, std::string desc, size_t sl, size_t qty, double price);
	};

	class Bakery
	{
		std::vector<BakedGood> m_collection{};
		std::string trim(const std::string& src);
	public:
		Bakery(std::string filename);
		void showGoods(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}
#endif // ! SENECA_BAKERY_H

