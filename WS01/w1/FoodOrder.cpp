#define _CRT_SECURE_NO_WARNINGS
#include "FoodOrder.h"
#include <iostream>
#include <cstring>
#include <string> //std::string
using namespace std;
double g_taxrate{};
double g_dailydiscount{};
namespace seneca
{
	FoodOrder::FoodOrder() {}

	std::istream& seneca::FoodOrder::read(std::istream& istr)
	{
		// TODO: insert return statement here
		if (!std::cin.fail())
		{
			char tmpName[11]{};
			char tmpDesc[26]{};
			double tmpPrice{};
			char tmpSpecial{};
			istr.getline(tmpName, 10, ',');
			strcpy(m_customerName, tmpName);

			istr.getline(tmpDesc, 25, ',');
			strcpy(m_foodDesc, tmpDesc);

			istr >> tmpPrice;
			istr.ignore();
			m_price = tmpPrice;

			istr >> tmpSpecial;
			m_dailySpecial = tmpSpecial;
			istr.ignore();
		}
		return istr;
	}

	std::ostream& seneca::FoodOrder::display(std::ostream& ostr) const
	{
		static int counter{};
		// TODO: insert return statement here
		counter++;
		ostr.width(2);
		ostr.setf(ios::left);
		ostr << counter << ". ";
		if (strlen(m_customerName)) {
			ostr.setf(ios::left);
			ostr.width(10);
			ostr << m_customerName <<  '|' ;

			ostr.width(25);
			ostr << m_foodDesc << '|';

			ostr.setf(ios::fixed);
			ostr.width(12);
			ostr.precision(2);
			ostr << m_price * (1 + g_taxrate) << '|';

			if (m_dailySpecial == 'Y')
			{
				ostr.setf(ios::right);
				ostr.width(13);
				ostr.precision(2);
				ostr << m_price * (1 + g_taxrate) - g_dailydiscount;
				ostr.unsetf(ios::right);
			}
			ostr.unsetf(ios::fixed);
			ostr << endl;
		}
		else {
			ostr << "No Order" << endl;
		}
		return ostr;
	}
}
