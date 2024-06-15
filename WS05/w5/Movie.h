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
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <iostream>
namespace seneca {
	class Movie
	{
		std::string m_title{};
		unsigned m_year{};
		std::string m_desc{};
		void trim(std::string& str);
	public:
		Movie(){ }
		const std::string& title() const;
		/// <summary>
		/// receives the movie through a reference to a string. 
		/// This constructor extracts the information about the movie from the string and stores the tokens in the attributes.
		/// </summary>
		/// <param name="strMovie">a string contains movie information</param>
		Movie(const std::string& strMovie);
		/// <summary>
		/// a templated function. This function calls the overloaded operator() on instance spellChecker, 
		/// passing to it the movie title and description.
		/// type T must have an overload of the operator() that accepts a string as a parameter.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="spellChecker"></param>
		template<typename T>
		void fixSpelling(T& spellChecker) 
		{
			spellChecker(m_title);
			spellChecker(m_desc);
		}
		
		friend std::ostream& operator<<(std::ostream& o, const Movie& m);
	};
}
#endif // !SENECA_MOVIE_H

