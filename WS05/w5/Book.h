////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-06-12							  //
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
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		unsigned m_year{};
		double m_price{};
		std::string m_description{}; // a short summary of the book
		void trim(std::string& str);
	public:
		// default constructor
		Book() { };
		// a query that returns the title of the book
		const std::string& title() const;
		// a query that returns the publication country
		const std::string& country() const;
		// a query that returns the publication year
		const size_t& year() const;
		// returns the price by reference, allowing the client code to update the price
		double& price();
		/// <summary>
		/// constructor extracts the information about the book from the string by 
		//  parsing it and stores the tokens in the object's attributes.
		/// </summary>
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& o, const Book& book);
		/// <summary>
		/// calls the overloaded operator() on the instance spellChecker, 
		/// passing to it the book description.
		/// </summary>
		/// <param name="spellChecker"></param>
		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_description);
		}
	};
}
#endif // !SENECA_BOOK_H