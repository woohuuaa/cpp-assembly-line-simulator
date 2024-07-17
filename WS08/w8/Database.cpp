////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-07-14							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <string>
#include <iomanip>
#include "Database.h"
namespace seneca {
	std::shared_ptr<Database> Database::c_databaseAdd = nullptr;

	std::shared_ptr<Database> Database::getInstance(const std::string& filename)
	{
		if (!c_databaseAdd)
		{	// creates an instance of type Database
			c_databaseAdd = static_cast<std::shared_ptr<Database>>(new Database(filename));
		}
		return c_databaseAdd;
	}
	Err_Status Database::GetValue(const std::string& key, std::string& value)
	{
		for (size_t i = 0; i < MAX_SIZE; ++i)
		{
			if (m_keys[i] == key)
			{	// store in the second parameter the corresponding value from the array of values
				value = m_values[i];
				return Err_Status::Err_Success;
			}
		}
		return Err_Status::Err_NotFound;
	}
	Err_Status Database::SetValue(const std::string& key, const std::string& value)
	{
		int count{};
		for (size_t i = 0; i < MAX_SIZE; ++i)
		{
			if (!(m_keys[i].empty() && m_values[i].empty()))
			{
				count++;
			}
		}
		if (count < MAX_SIZE)
		{
			m_keys[count] = key;
			m_values[count] = value;
			return Err_Status::Err_Success;
		}
		return Err_Status::Err_OutOfMemory;
	}
	std::string Database::trim(const std::string& src)
	{
		size_t first = src.find_first_not_of(' ');
		size_t last = src.find_last_not_of(' ');
		// if non-space char is not found, return empty string
		// otherwise return sub string without leading and trailing spaces
		return (first == std::string::npos || last == std::string::npos) ? "" : src.substr(first, last - first + 1);
	}

	Database::Database(const std::string& filename)
	{
		std::string line{};
		size_t count{};
		// prints to the screen the address of the current instance and the prototype of the constructor 
		std::cout << "[" << std::hex << this << "] Database(const std::string&)" << std::endl;
		// opens the file and read the key/value pairs into the attributes
		std::ifstream f(filename);
		while (std::getline(f, line))
		{
			size_t start = 0, pos = 0;
			size_t end = line.find('$');
			// extract key information from a line
			std::string key = trim(line.substr(start, end - start));
			// replace "_" with " "
			pos = key.find('_', 0);
			key.replace(pos, 1, " ");
			// extract value from a line
			start = end;
			std::string value = trim(line.substr(start)); 
			// store key and value in array
			m_keys[count] = key;
			m_values[count++] = value;
		}
		f.close();
		m_count++;
	}

	Database::~Database()
	{
		std::cout << "[" << c_databaseAdd << "] ~Database()" << std::endl;
		std::ofstream f(m_filename + ".bkp.txt");
		for (size_t i = 0; i < MAX_SIZE; ++i)
		{
			f << std::left << std::setw(25) << m_keys[i] << " -> " << m_values[i] << "\n";
		}
	}
}
