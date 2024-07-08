#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H
#include <iostream>
#include "Resource.h"
#include "Directory.h"
#include "File.h"
namespace seneca {
	class Filesystem
	{
		// a pointer to the root directory of the filesystem
		Directory* m_root{};
		Directory* m_current{};
		std::string& trim(std::string& src);
		void createDirAndFile(const std::string& path, const std::string& content = "");
	public:
		// a custom constructor that receives the name of a file as its first argument, 
		// and an optional string containing the name of the root directory (defaults to an empty string).
		Filesystem(std::string filename, std::string rootDir = "");
		// this module does not allow copy operations. Make sure they are deleted.
		Filesystem(const Filesystem& src) = delete;
		Filesystem& operator=(const Filesystem& src) = delete;

		// move
		Filesystem(Filesystem&& src) noexcept;
		Filesystem& operator=(Filesystem&& src) noexcept;

		// adds a resource to the current directory
		Filesystem& operator+=(Resource* src);
		// changes the current directory to the directory (located in the current directory) whose name matches argument
		Directory* change_directory(const std::string& name = "");
		// a query that returns the current directory
		Directory* get_current_directory() const;
		// destructor 
		virtual ~Filesystem();
	};
}
#endif // !SENECA_FILESYSTEM_H

