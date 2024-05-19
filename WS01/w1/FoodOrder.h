////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-05-19							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
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
		char* m_foodDesc{};
		double m_price{};
		char m_dailySpecial{};
		void setfoodDesc(char*& des, const char* src);
	public:
		FoodOrder();
		// apply rule of three
		FoodOrder(const FoodOrder& rhs);
		FoodOrder& operator=(const FoodOrder& rhs);
		~FoodOrder();

		std::istream& read(std::istream& istr);
		// getline, delimeter, ignore
		std::ostream& display(std::ostream& ostr = std::cout) const;
	};
}
#endif