// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"
namespace seneca {
	size_t CustomerOrder::m_widthField{};
	
	void CustomerOrder::addListItem(const std::string& itemName)
	{
		// allocate memory for a new Item* array based on number of item
		Item** tmpList = new Item*[m_cntItem];
		// if new array size > 1, copy the m_lstItem into new array
		for (size_t i = 0; i < m_cntItem - 1 && m_cntItem > 1; ++i)
		{
			tmpList[i] = m_lstItem[i];
		}
		// add new item to new Item* array
		Item i(itemName);
		tmpList[m_cntItem - 1] = &i;
		delete[] m_lstItem;
		// m_lstItem get the new size Item* array
		m_lstItem = tmpList;
		tmpList = nullptr;
	}
	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities u;
		size_t nextPo{ 0u }, countI{};
		bool more{ true };
		std::string token{};
		std::vector<Item*> itemList{};
		// extract name and product
		m_name = u.extractToken(str, nextPo, more);
		m_product = u.extractToken(str, nextPo, more);
		// extract items
		while (more) {
			token = u.extractToken(str, nextPo, more);
			// allocate new item and push into itemList array
			Item* i = new Item(token);
			itemList.push_back(i);
			m_cntItem++;
		}

		// allocate memory for m_lstItem and copy the item pointers (itemList) into m_lstItem
		m_lstItem = new Item*[m_cntItem];
		for (size_t i = 0; i < m_cntItem; ++i) {
			m_lstItem[i] = itemList[i];
		}
		// update m_widthField with maximun FieldWidth
		if (u.getFieldWidth() > m_widthField) {
			m_widthField = u.getFieldWidth();
		}
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw "Should not use copy constructor.";
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src)
		{
			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;
			src.m_lstItem = nullptr;
		}
		return *this;
	}
	CustomerOrder::~CustomerOrder()
	{
		delete[] m_lstItem;
	}
	bool CustomerOrder::isOrderFilled() const
	{
		bool isFilled{true};
		for (size_t i = 0; i < m_cntItem && isFilled; ++i)
		{
			if (!m_lstItem[i]->m_isFilled) 
			{
				isFilled = false;
			}
		}
		return isFilled;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool isFilled{ true };
		for (size_t i = 0; i < m_cntItem; ++i)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				isFilled = !(m_lstItem[i]->m_isFilled) ? false : true;
			}
		}
		return isFilled;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		bool found{};
		size_t index{};
		std::string itemName{};
		// find if the station is for fulfilling items in m_lstItem
		for (size_t i = 0; i < m_cntItem && !found; ++i)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName())
			{
				itemName = m_lstItem[i]->m_itemName;
				index = i;
				found = true;
			}
		}
		// fulfill the order if item found and station qty is available
		if (found && station.getQuantity())
		{
			station.updateQuantity();	// subtracts 1 from the station inventory
			m_lstItem[index]->m_serialNumber = station.getNextSerialNumber();	// updates Item::m_serialNumber
			m_lstItem[index]->m_isFilled = true;
			os << "    Filled " + m_name + ", " + m_product + "[" + itemName + "]" << std::endl;
		}
		// if the order contains items handled but unfilled, and the inventory is empty
		else if (!m_lstItem[index]->m_isFilled && !station.getQuantity())
		{
			os << "    Unable to fill " + m_name + ", PRODUCT [" + itemName + "]" << std::endl;
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << '\n';
		for (size_t i = 0; i < m_cntItem; ++i)
		{
			os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ')
				<< std::left << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled)
			{
				os << "FILLED";
			}
			else {
				os << "TO BE FILLED";
			}
			os << std::endl;
		}
	}

}
