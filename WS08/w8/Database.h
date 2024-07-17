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
namespace seneca {
	constexpr size_t MAX_SIZE = 20;

	enum class Err_Status
	{
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	class Database
	{
		int m_count{};									// the number of entries in the database
		std::string m_keys[MAX_SIZE]{};					// array of strings representing the keys
		std::string m_values[MAX_SIZE]{};				// array of strings representing the values
		std::string m_filename{};						// representing the database file name
		static std::shared_ptr<Database> c_databaseAdd;	// store the address of the one and only instance of type Database

		std::string trim(const std::string& src);
		/// <summary>
		/// private constructor: opens the file and read the key/value pairs into the attributes
		/// </summary>
		/// <param name="filename">file to be opened</param>
		Database(const std::string& filename);

		//void encryptDecrypt(T& value);
	public:
		/// <summary>
		/// creates an instance of type Database (using the private constructor) and stores it in the static attribute
		/// </summary>
		/// <param name="filename">a string representing the filename of the database file</param>
		/// <returns>the static attribute to the client</returns>
		static std::shared_ptr<Database> getInstance(const std::string& filename);
		// a query that searches in the array of keys for a the first parameter
		Err_Status GetValue(const std::string& key, std::string& value);
		// a modifier that receives as parameters a key and a value
		Err_Status SetValue(const std::string& key, const std::string& value);
		// a destructor that prints to the screen the address of the current instance and the prototype of the destructor
		~Database();

	};

}
#endif // !SENECA_DATABASE_H
