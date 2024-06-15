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
#include "SpellChecker.h"
#include <fstream>
#include <string>
#include <iomanip>
namespace seneca {
	void SpellChecker::trimTwoWordsFromLine(const std::string line, std::string& bad, std::string& good)
	{
		size_t start = line.find_first_not_of(' ');
		size_t end = line.find_first_of(' ');
		bad = line.substr(start, end - start);

		start = line.find_first_not_of(' ', end);
		good = line.substr(start);
	}
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			const char* msg("Bad file name!");
			throw msg;
		}
		std::string line{};
		size_t cnt{};
		while(std::getline(file, line))		// read one line at a time
		{
			if (!line.empty())
			{
				std::string badWord{}, goodWord{};
				trimTwoWordsFromLine(line, badWord, goodWord);		// extract bad word and good word from a line
				m_badWords[cnt] = badWord;			// load bad word into m_badWords array
				m_goodWords[cnt] = goodWord;		// load good word into m_badWords array
				cnt++;
			}
		} while (file);
	}
	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < MAX_SIZE; ++i)
		{
			size_t pos = text.find(m_badWords[i]);
			while (pos != std::string::npos)
			{
				text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
				m_count[i]++;
				pos = text.find(m_badWords[i], pos + m_goodWords[i].length());
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics\n";
		for (size_t i = 0; i < MAX_SIZE; ++i)
		{
			out << std::setw(15) << std::right << m_badWords[i] << ": "
				<< m_count[i] << " replacements" << std::endl;
		}
	}
}