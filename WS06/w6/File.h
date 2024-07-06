#ifndef SENECA_FILE_H
#define SENECA_FILE_H
#include <iostream>
#include "Resource.h"
namespace seneca {
	class File : public Resource
	{
		// stores the contents of a file
		std::string m_content{};
	public:
		/// <summary>
		/// custom constructor
		/// </summary>
		/// <param name="filename">the name of the file</param>
		/// <param name="content">a text representation of the contents of a file(optional)</param>
		File(std::string filename, std::string content = "");
		// sets the parent path to the parameter
		void update_parent_path(const std::string&);
		// a query that returns Flags::FILE
		NodeType type() const;
		// a query that returns the full absolute path of the file 
		// (concatenates the absolute path location and the file name)
		std::string path() const;
		// a query that returns the name of the file
		std::string name() const;
		// a query that returns -1
		int count() const;
		// a query that returns the size of the file in bytes. For simplicity, 
		// this is the number of characters in m_contents attribut
		size_t size() const;

		// add other functions only private allowed
	};
}
#endif // !SENECA_FILE_H
