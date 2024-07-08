#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H
#include <iostream>
#include <vector>
#include "Resource.h"
namespace seneca {
	class Directory : public Resource
	{
		std::vector<Resource*> m_content{};
		bool checkFlag(const std::vector<OpFlags>& flags);
	public:
		/// <summary>
		/// a custom constructor that receives the name of the directory as a string
		/// uses it to initialize the Directory object.
		/// assume all directory names end with a /.
		/// </summary>
		/// <param name="dirname">the name of the directory</param>
		Directory(std::string dirname);
		// sets the parent path to the parameter
		void update_parent_path(const std::string& pPath);
		// a query that returns Flags::DIR
		NodeType type() const;
		// a query that returns the full absolute path of the directory 
		// (a concatenation of the absolute path location and the directory name)
		std::string path() const;
		// a query that returns the name of the directory
		std::string name() const;
		// a query that returns the number of resources that this directory holds
		int count() const;
		// a query that returns the size of the directory in bytes
		size_t size() const;
		// adds a resource to the directory and returns a reference to the current directory
		Directory& operator+=(Resource*);
		// finds and returns the address of a resource in the directory whose name matches the given string 
		// or nullptr if a match is not found
		Resource* find(const std::string& filename, const std::vector<OpFlags>& flags = {});
		// a destructor that deallocates memory for each resource that this directory holds
		virtual ~Directory();
		// this class should not allow copy/move operations
		// copy
		Directory(const Directory& src) = delete;
		Directory& operator=(const Directory& src) = delete;
		// move
		Directory(Directory&& src) = delete;
		Directory& operator=(Directory&& src) = delete;

		// p2
		//deletes a resource from the directory whose name matches the first argument 
		//(removing it from its contents and deallocating memory for it)
		void remove(const std::string& name, const std::vector<OpFlags>& flags = {});
		void display(std::ostream& os, const std::vector<FormatFlags>& flags = {}) const;
	};
}
#endif // !SENECA_DIRECTORY_H

