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
	void FoodOrder::setfoodDesc(char*& des, const char* src)
	{
		delete[] des;
		if (src) {
			des = new char[strlen(src) + 1];
			strcpy(des, src);
		}
	}
	FoodOrder::FoodOrder() {}

	FoodOrder::FoodOrder(const FoodOrder& rhs)
	{
		operator=(rhs);
	}

	FoodOrder& FoodOrder::operator=(const FoodOrder& rhs)
	{
		// TODO: insert return statement here
		if (this != &rhs)
		{
			strcpy(m_customerName, rhs.m_customerName);
			setfoodDesc(m_foodDesc, rhs.m_foodDesc);
			m_price = rhs.m_price;
			m_dailySpecial = rhs.m_dailySpecial;
		}
		return *this;
	}

	FoodOrder::~FoodOrder()
	{
		delete[] m_foodDesc;
	}

	std::istream& seneca::FoodOrder::read(std::istream& istr)
	{
		// TODO: insert return statement here
		if (istr.good())
		{
			char tmpName[11]{};
			string tmpDesc{};
			double tmpPrice{};
			char tmpSpecial{};
			istr.getline(tmpName, 10, ',');
			strcpy(m_customerName, tmpName);

			getline(istr, tmpDesc, ',');
			if (!m_foodDesc)
			{
				m_foodDesc = new char[tmpDesc.length() + 1];
			}
			else if (tmpDesc.length() > strlen(m_foodDesc)) {
				delete[] m_foodDesc;
				m_foodDesc = new char[tmpDesc.length() + 1];
			}
			strcpy(m_foodDesc, tmpDesc.c_str());

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
