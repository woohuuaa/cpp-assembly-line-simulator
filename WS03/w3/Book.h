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
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
namespace seneca {
	class Book
	{
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};
		double m_pageToChap{};
	public:
		Book();
		Book(const std::string& title, unsigned nChapters, unsigned nPages);

		// TODO: In completing Part 1, add here the missing 
		// member prototypes that would be necessary for the 
		// Collection module code and tester module w3_p1.cpp 
		// to manage Book-type objects. 
		/// <summary>
		/// check if the book object is in valid state
		/// </summary>
		operator bool() const;
		// In completing Part 2, add here the missing 
		// member prototypes that would be necessary for 
		// OrderedCollection module code and tester module 
		// w3_p2.cpp to manage Book-type object. 
		//
		Book& operator=(const Book& src);
		bool operator>(const Book& src) const;
		bool operator<(const Book& src) const;
		//bool operator==(const Book& src) const;
		//
		// Write the implementations of these functions 
		// in Book.cpp file
		
		std::ostream& print(std::ostream& os) const;

	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);
}
#endif // !SENECA_BOOK_H