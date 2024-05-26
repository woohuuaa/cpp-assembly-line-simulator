#include "ProteinDatabase.h"
namespace seneca {
	seneca::ProteinDatabase::ProteinDatabase(){}
	seneca::ProteinDatabase::ProteinDatabase(std::string filename)
	{
		size_t numSequence{}, i{};
		std::string buffer;
		std::ifstream file(filename);
		while (file)
		{
			char x = file.get();
			if (x == '>')
			{
				numSequence++;
			}
		}
		// allocates memory for that number of protein sequences in the array
		m_proteinSequence = new std::string[numSequence];

		// re-reads the file
		file.clear();
		file.seekg(0);

		// loads the protein sequences
		while (std::getline(file, buffer))
		{
			if (buffer[0] == '>')
			{
				if (m_proteinSequence[i].length() != 0)
				{
					i++;
					buffer = '\0';
				}
			}
			else
			{
				m_proteinSequence[i] += buffer;
			}
		}
		m_size = numSequence;
	}
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src)
	{
		operator=(src);
	}
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src)
	{
		if (this != &src)
		{
			if (src)
			{
				delete[] m_proteinSequence;
				m_proteinSequence = nullptr;
				m_size = src.m_size;
				m_proteinSequence = new std::string[src.m_size];
				for (size_t i = 0; i < src.m_size; i++)
				{
					m_proteinSequence[i] = src.m_proteinSequence[i];
				}
			}
			else
			{
				delete[] m_proteinSequence;
				m_proteinSequence = nullptr;
				m_size = 0;
			}
		}
		return *this;
	}
	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src) /*: m_proteinSequence(std::move(src.m_proteinSequence)), m_size(src.m_size)*/
	{
		*this = std::move(src);
		//src.m_proteinSequence = nullptr;
		//src.m_size = 0;
	}
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src)
	{
		if (this != &src)
		{
			// 1. check for self-assignment
			if (src)
			{
				// 2. clean-up the resource used by the current instance
				delete[] m_proteinSequence;
				m_proteinSequence = nullptr;
				// 3. shallow copy
				m_size = src.m_size;
				// 4. move the resource from parameter into current instance
				// copy address to current object
				m_proteinSequence = src.m_proteinSequence;

				src.m_proteinSequence = nullptr;
				src.m_size = 0;
			}
			else
			{
				delete[] m_proteinSequence;
				m_proteinSequence = nullptr;
				m_size = 0;
			}
		}
		return *this;
	}
	ProteinDatabase::~ProteinDatabase()
	{
		delete[] m_proteinSequence;
	}
	ProteinDatabase::operator bool() const
	{
		return (m_size > 0 && m_proteinSequence != nullptr);
	}
	size_t seneca::ProteinDatabase::size() const
	{
		return m_size;
	}
	std::string seneca::ProteinDatabase::operator[](size_t index)
	{
		std::string copy{};
		if (index < m_size)
		{
			copy = m_proteinSequence[index];
		}
		return copy;
	}
}
