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
#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H
#include "Collection.h"
namespace seneca {
	template<typename T>
	class OrderedCollection : public Collection<T, sizeL>
	{
		void bubbleSort()
		{
			T tmp{};
			size_t size = this->size();
			for (size_t i = 0; i < size - 1; i++)
			{
				for (size_t j = 0; j < size - i - 1; j++)
				{
					if (this->operator[](j) > this->operator[](j + 1))
					{
						tmp = this->operator[](j);
						this->operator[](j) = this->operator[](j + 1);
						this->operator[](j + 1) = tmp;
					}
				}
			}
		}
	public:
		// to place or insert the received item into the array m_items at an appropriate 
		// index to ensure that the elements are in ascending order after insertion.
		bool operator+=(const T& t)
		{
			size_t size = this->size();
			if (size < this->capacity())
			{
				this->setSmallestItem(t);
				this->setLargestItem(t);
				this->incrSize();
				this->operator[](size) = t;
				// use bubble sort to sort the m_items array
				bubbleSort();
				return true;
			}
			else
			{
				return false;
			}
		}
	};
}
#endif 
