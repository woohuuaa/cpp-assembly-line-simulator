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
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#include <iostream>
namespace seneca {
	constexpr size_t MAX_SIZE = 6;
	class SpellChecker
	{
		std::string m_badWords[MAX_SIZE]{};
		std::string m_goodWords[MAX_SIZE]{};
		size_t m_count[MAX_SIZE]{};
		void trimTwoWordsFromLine(const std::string line, std::string& bad, std::string& good);
	public:
		/// <summary>
		/// receives the address of a C-style null-terminated string that holds 
		/// the name of the file that contains the misspelled words.
		/// </summary>
		/// <param name="filename"></param>
		SpellChecker(const char* filename);
		/// <summary>
		/// searches text and replaces any misspelled word with the correct version. 
		/// It should also count how many times each misspelled word has been replaced.
		/// </summary>
		/// <param name="text"></param>
		void operator()(std::string& text);
		/// <summary>
		/// inserts into the parameter how many times each misspelled word has been 
		/// replaced by the correct word using the current instance.
		/// </summary>
		/// <param name="out">ostream object</param>
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SENECA_SPELLCHECKER_H
