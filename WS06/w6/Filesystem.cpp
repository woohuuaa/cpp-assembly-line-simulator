#include "Filesystem.h"
namespace seneca {
	// a custom constructor that receives the name of a file as its first argument, 
	// and an optional string containing the name of the root directory (defaults to an empty string).
	Filesystem::Filesystem(std::string filename, std::string rootDir)
	{

	}
	Filesystem::Filesystem(Filesystem&& src)
	{
	}
	Filesystem& Filesystem::operator=(Filesystem&& src)
	{
		// TODO: insert return statement here
	}
	Filesystem& Filesystem::operator+=(Resource*)
	{
		// TODO: insert return statement here
	}
	Directory* Filesystem::change_directory(const std::string& name)
	{
		return nullptr;
	}
	Directory* Filesystem::get_current_directory() const
	{
		return nullptr;
	}
	Filesystem::~Filesystem()
	{

	}
}