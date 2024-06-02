////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-05-30							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include "Book.h"
namespace seneca {
	constexpr size_t sizeS = 10;
	constexpr size_t sizeL = 72;

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
		/// <summary>
		/// a mutator operator to receive an array index and return corresponding element from m_items array.
		/// </summary>
		/// <param name="index">an array index</param>
		/// <returns>index corresponding element from m_items array</returns>
		T& operator[](size_t index);
		const T& operator[](size_t index) const;
		/// <summary>
		/// a mutator to increase by 1 the size count of elements stored in the collection
		/// </summary>
		void incrSize();
	public:
		// default constructor
		Collection();
		// Public Class Members
		static T getSmallestItem();
		static T getLargestItem();
		unsigned int size() const;
		unsigned int capacity() const;
		bool operator+=(const T& t);
		std::ostream& print(std::ostream& ostr) const;
	};

	//  trying different syntax for initialization
	template<typename T, unsigned int C>
	T Collection<T, C>::m_smallestItem{ 9999 };

	template<typename T, unsigned int C>
	T Collection<T, C>::m_largestItem{ -9999 };

	// Template Specializations
	//// part 1
	template<>
	Book Collection<Book, sizeS>::m_smallestItem{ "", 1, 10000 };

	template<>
	Book Collection<Book, sizeS>::m_largestItem{ "", 10000, 1 };

	// part 2
	template<>
	Book Collection<Book, sizeL>::m_smallestItem{ "", 1, 10000 };

	template<>
	Book Collection<Book, sizeL>::m_largestItem{ "", 10000, 1 };


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
	T& Collection<T, C>::operator[](size_t index)
	{
		return m_items[index];
	}

	template<typename T, unsigned int C>
	inline const T& Collection<T, C>::operator[](size_t index) const
	{
		return m_items[index];
	}

	template<typename T, unsigned int C>
	void Collection<T, C>::incrSize()
	{
		if (m_size < m_capacity)
		{
			m_size++;
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
	inline std::ostream& Collection<T, C>::print(std::ostream& ostr) const
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
		return ostr;
	}

	template<>
	inline std::ostream& Collection<Book, sizeS>::print(std::ostream& ostr) const
	{
		ostr << "| ---------------------------------------------------------------------------|\n";
		for (size_t i = 0; i < m_size; i++)
		{
			ostr << "| " << m_items[i];
			ostr << " |\n";
		}
		ostr << "| ---------------------------------------------------------------------------|\n";
		return ostr;
	}

	template<>
	inline std::ostream& Collection<Book, sizeL>::print(std::ostream& ostr) const
	{
		ostr << "| ---------------------------------------------------------------------------|\n";
		for (size_t i = 0; i < m_size; i++)
		{
			ostr << "| " << m_items[i];
			ostr << " |\n";
		}
		ostr << "| ---------------------------------------------------------------------------|\n";
		return ostr;
	}


}
#endif // !SENECA_COLLECTION_H

