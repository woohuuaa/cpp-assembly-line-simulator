// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-31
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"
namespace seneca {
	size_t CustomerOrder::m_widthField{};
	
	void CustomerOrder::setEmpty()
	{
		if (m_lstItem)
		{
			for (size_t i = 0; i < m_cntItem; ++i) {
				delete m_lstItem[i];
			}
		}
		delete[] m_lstItem;
	}

	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities u;
		size_t nextPo{ 0u };
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
		delete[] m_lstItem;
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
			setEmpty();
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
		setEmpty();
	}
	bool CustomerOrder::isOrderFilled() const
	{
		bool isFilled{true};
		for (size_t i = 0; i < m_cntItem && isFilled; ++i)
		{
			isFilled = m_lstItem[i]->m_isFilled ? true : false;
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
				isFilled = m_lstItem[i]->m_isFilled ? true : false;
			}
		}
		return isFilled;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		std::string itemName, sName = station.getItemName();
		// find if the station is for fulfilling items in m_lstItem
		for (size_t i = 0; i < m_cntItem ; ++i)
		{	//if the order contains items handled and item is not filled
			if (m_lstItem[i]->m_itemName == sName && !m_lstItem[i]->m_isFilled)
			{
				itemName = m_lstItem[i]->m_itemName;
				// fulfill the order if station qty is available
				if (station.getQuantity())
				{
					station.updateQuantity();	// subtracts 1 from the station inventory
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();	// updates Item::m_serialNumber
					m_lstItem[i]->m_isFilled = true;
					os << "    Filled " + m_name + ", " + m_product + " [" + itemName + "]" << std::endl;
					return;
				}
				else
				{
					os << "    Unable to fill " + m_name + ", " + m_product + " [" + itemName + "]" << std::endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << '\n';
		for (size_t i = 0; i < m_cntItem; ++i)
		{
			os << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ')
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
