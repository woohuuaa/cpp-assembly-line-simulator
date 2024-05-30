#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include "Book.h"
namespace seneca {
	template<typename T, unsigned int C>
	class Collection
	{
		T m_items[C]{};
		unsigned int m_capacity{C};
		unsigned int m_size{0};
		// class member: 
		// keeps track of the smallest item and 
		// largest item across all the class objects 
		static T m_smallestItem;
		static T m_largestItem;
	protected:
		void setSmallestItem(const T& src);
		void setLargestItem(const T& src);
	public:
		// default constructor
		Collection();
		// Public Class Members
		static T getSmallestItem();
		static T getLargestItem();
		unsigned int size() const;
		unsigned int capacity() const;
		bool operator+=(const T& t);
		void print(std::ostream& ostr) const;
	};

	//  trying different syntax for initialization
	template<typename T, unsigned int C>
	T Collection<T, C>::m_smallestItem{ 9999 };

	template<typename T, unsigned int C>
	T Collection<T, C>::m_largestItem = static_cast<T>(-9999);

	template<typename T, unsigned int C>
	void Collection<T, C>::setSmallestItem(const T& src)
	{
		if (src < m_smallestItem)
		{
			m_smallestItem = src;
		}
	}

	template<typename T, unsigned int C>
	void Collection<T, C>::setLargestItem(const T& src)
	{
		if (src > m_largestItem)
		{
			m_largestItem = src;
		}
	}

	template<typename T, unsigned int C>
	Collection<T, C>::Collection() { }

	template<typename T, unsigned int C>
	T Collection<T, C>::getSmallestItem()
	{
		return Collection<T, C>::m_smallestItem;
	}

	template<typename T, unsigned int C>
	T Collection<T, C>::getLargestItem()
	{
		return Collection<T, C>::m_largestItem;
	}

	template<typename T, unsigned int C>
	unsigned int Collection<T, C>::size() const
	{
		return m_size;
	}

	template<typename T, unsigned int C>
	unsigned int Collection<T, C>::capacity() const
	{
		return m_capacity;
	}

	template<typename T, unsigned int C>
	bool Collection<T, C>::operator+=(const T& t)
	{
		if (m_size < m_capacity)
		{
			setSmallestItem(t);
			setLargestItem(t);
			m_items[m_size++] = t;
			return true;
		}
		else 
		{
			return false;
		}
	}

	template<typename T, unsigned int C>
	void Collection<T, C>::print(std::ostream& ostr) const
	{
		ostr << "[" ;
		for (size_t i = 0; i < m_size; i++)
		{
			ostr << m_items[i];
			if (i < m_size - 1)
			{
				ostr << ",";
			}
		}
		ostr << "]\n";
	}

	// Template Specializations
	//template<>
	//Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

	template<>
	Book Collection<Book, 10>::m_smallestItem{ "", 1, 10000 };

	template<>
	Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);
}
#endif // !SENECA_COLLECTION_H

