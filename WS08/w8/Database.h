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
#ifndef SENECA_DATABASE_H
#define SENECA_DATABASE_H
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <iomanip>
namespace seneca {
	constexpr size_t MAX_SIZE = 20;

	enum class Err_Status
	{
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	template<typename T>
	class Database
	{
		int m_count{};									// the number of entries in the database
		std::string m_keys[MAX_SIZE]{};					// array of strings representing the keys
		T m_values[MAX_SIZE]{};							// array of strings representing the values
		std::string m_filename{};						// representing the database file name
		static std::shared_ptr<Database> c_databaseAdd;	// store the address of the one and only instance of type Database

		/// <summary>
		/// private constructor: opens the file and read the key/value pairs into the attributes
		/// </summary>
		/// <param name="filename">file to be opened</param>
		Database(const std::string& filename)
		{
			std::string line{};
			size_t count{};
			// prints to the screen the address of the current instance and the prototype of the constructor 
			std::cout << "[" << std::hex << this << "] Database(const std::string&)" << std::dec << std::endl;
			// opens the file and read the key/value pairs into the attributes
			std::ifstream f(filename);
			while (!f.eof() && count < MAX_SIZE)
			{
				// extract key from a line
				std::string key{};
				f >> key;

				// replace "_" with " "
				size_t pos = key.find('_', 0);
				key.replace(pos, 1, " ");

				// store key and value in array
				m_keys[count] = key;

				// extract value from a line
				T value;
				f >> value;
				encryptDecrypt(value);
				m_values[count++] = value;
			}
			f.close();
			m_count++;
		}

		void encryptDecrypt(T& value) {	}
	public:
		/// <summary>
		/// creates an instance of type Database (using the private constructor) and stores it in the static attribute
		/// </summary>
		/// <param name="filename">a string representing the filename of the database file</param>
		/// <returns>the static attribute to the client</returns>
		static std::shared_ptr<Database> getInstance(const std::string& filename)
		{
			if (!c_databaseAdd)
			{	// creates an instance of type Database
				c_databaseAdd = static_cast<std::shared_ptr<Database>>(new Database(filename));
			}
			return c_databaseAdd;
		}
		// a query that searches in the array of keys for a the first parameter
		Err_Status GetValue(const std::string& key, T& value)
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
		// a modifier that receives as parameters a key and a value
		Err_Status SetValue(const std::string& key, const T& value)
		{
			for (size_t i = 0; i < MAX_SIZE; ++i) {
				if (m_keys[i].empty()) {
					m_keys[i] = key;
					m_values[i] = value;
					return Err_Status::Err_Success;
				}
			}
			return Err_Status::Err_OutOfMemory;
		}
		// a destructor that prints to the screen the address of the current instance and the prototype of the destructor
		~Database()
		{
			std::cout << "[" << c_databaseAdd << "] ~Database()" << std::endl;
			std::string backup = m_filename + ".bkp.txt";
			std::ofstream f(backup);
			for (size_t i = 0; i < m_count; ++i)
			{
				encryptDecrypt(m_values[i]);
				f << std::left << std::setw(25) << m_keys[i] << " -> " << m_values[i] << "\n";
			}
		}
	};
	// class variable initialization
	template<typename T>
	std::shared_ptr<Database<T>> Database<T>::c_databaseAdd = nullptr;

	// specialize the encryptDecrypt() for the type std::string
	template<>
	inline void Database<std::string>::encryptDecrypt(std::string& value) {
		const char secret[]{ "secret encryption key" };

		for (int i = 0; i < value.size(); ++i)
		{
			for (int j = 0; j < std::strlen(secret); ++j)
				value[i] ^= secret[j];
		}
	}

	// specialize the encryptDecrypt() for the type long long
	template<>
	inline void Database<long long>::encryptDecrypt(long long& value) {
		const char secret[]{ "super secret encryption key" };

		for (int i = 0; i < sizeof(value); ++i)
		{
			for (int j = 0; j < std::strlen(secret); ++j)
				reinterpret_cast<char*>(&value)[i] ^= secret[j];
		}
	}
}
#endif // !SENECA_DATABASE_H
