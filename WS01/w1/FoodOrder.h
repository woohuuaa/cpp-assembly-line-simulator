/////////////////////////////////////////////////////////////////////////
//	  																   //
//  I declare that this submission is the result of my own work and I  //
//  only copied the code that my professor provided to complete my     //
//  workshops and assignments. This submitted piece of work has not    //
//  been shared with any other student or 3rd party content provider.  //
//	 																   //
/////////////////////////////////////////////////////////////////////////

#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
#include <iostream>
// extern
// static
// dynamic string DMA
// 
extern double g_taxrate;
extern double g_dailydiscount;
namespace seneca {
	class FoodOrder
	{
		char m_customerName[11]{};
		// char* m_foodDesc{};
		char m_foodDesc[26]{};
		double m_price{};
		char m_dailySpecial{};
		// rule of three
	public:
		FoodOrder();
		std::istream& read(std::istream& istr);
		// getline, delimeter, ignore
		std::ostream& display(std::ostream& ostr = std::cout) const;
	};
}
#endif