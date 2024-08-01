// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-31
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include <iostream>
#include "Station.h"
namespace seneca {
	
	struct Item
	{
		std::string m_itemName{};
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		std::string m_name{};		// the name of the customer
		std::string m_product{};	// the name of the product being assembled
		size_t m_cntItem{};			// a count of the number of items in the customer's order
		Item** m_lstItem{};			// a dynamically allocated array of pointers to dynamically allocated objects of type Item
		static size_t m_widthField;	// the maximum width of a field
		void setEmpty();			// deallocate memory
	public:
		CustomerOrder() {};
		CustomerOrder(const std::string& str);	// create CustomerOrder object from a string

		CustomerOrder(const CustomerOrder& src);	// copy constructor throws an exception if called 
		CustomerOrder& operator=(const CustomerOrder& src) = delete;

		CustomerOrder(CustomerOrder&& src) noexcept;			// move constructor
		CustomerOrder& operator=(CustomerOrder&& src) noexcept;	// move operator
		virtual ~CustomerOrder();								// descructor

		bool isOrderFilled() const;								// true if all the items in the order have been filled
		bool isItemFilled(const std::string& itemName) const;	// true if all items specified by itemName have been filled
		void fillItem(Station& station, std::ostream& os);		// fills one item in the current order that the specified Station
		void display(std::ostream& os) const;					// display CustomerOrder
	};
}
#endif // !SENECA_CUSTOMERORDER_H

