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
