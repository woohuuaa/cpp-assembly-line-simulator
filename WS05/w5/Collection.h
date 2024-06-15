////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-06-13							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
namespace seneca {
	template<typename T>
	class Collection
	{
		std::string m_name{};
		T* m_items{};
		unsigned m_size{};
		// a pointer to a function that returns void and receives two parameters 
		// of type const Collection<T>& and const T& in that order.
		void (*observer)(const Collection<T>&, const T&) {};
		void resize(size_t newSize)
		{
			T* tmpItems = new T[newSize];
			for (size_t i = 0; i < m_size; ++i)
			{
				tmpItems[i] = m_items[i];
			}
			delete[] m_items;
			m_items = tmpItems;
		}
	public:
		Collection(const std::string& name) : m_name(name) { }
		~Collection()
		{
			delete[] m_items;
		}

		const std::string& name() const
		{
			return m_name;
		}

		size_t size() const
		{
			return m_size;
		}
		/// <summary>
		/// stores the address of the callback function (observer) into an attribute
		/// </summary>
		/// <param name="observer">a pointer to a function that returns void and accepts two parameters: 
		/// a collection and an item that has just been added to the collection.</param>
		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			this->observer = observer;
		}
		/// <summary>
		/// adds a copy of item to the collection, only if the collection doesn't contain 
		/// an item with the same title.
		/// </summary>
		/// <param name="item">an item</param>
		/// <returns></returns>
		Collection<T>& operator+=(const T& item)
		{
			bool found{};
			if (!item.title().empty())
			{
				for (size_t i = 0; i < m_size && !found; ++i)
				{
					if (m_items[i].title() == item.title())
					{
						found = true;
					}
				}
				if (!found)
				{
					resize(m_size + 1);
					m_items[m_size++] = item;
					if (observer)
					{
						observer(*this, item);
					}
				}
			}
			return *this;
		}
		/// <summary>
		/// returns the item at index idx
		/// if the index is out of range, this operator throws an exception of type std::out_of_range with the message 
		/// Bad index [IDX]. Collection has [SIZE] items.. Use operator + to concatenate strings.
		/// </summary>
		/// <param name="idx">index of the item</param>
		/// <returns>item at index idx</returns>
		T& operator[](size_t idx) const
		{
			if (idx >= m_size) 
			{
				std::string msg = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
				throw std::out_of_range(msg);
			}
			return m_items[idx];
		}
		/// <summary>
		/// returns the address of the item with the title "title" 
		/// (type T has a member function called title() that returns the title of the item).
		/// If no such item exists, this function returns nullptr.
		/// </summary>
		/// <param name="title">title to match</param>
		/// <returns>the address of the item with the title</returns>
		T* operator[](const std::string& title) const
		{
			if (!title.empty())
			{
				for (size_t i = 0; i < m_size; ++i)
				{
					if (m_items[i].title() == title)
					{
						return &m_items[i];
					}
				}
			}
			return nullptr;
		}
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& o, const Collection<T>& c)
	{
		for (size_t i = 0; i < c.size(); ++i) {
			o << c[i];
		}
		return o;
	}
}
#endif // !SENECA_COLLECTION_H

