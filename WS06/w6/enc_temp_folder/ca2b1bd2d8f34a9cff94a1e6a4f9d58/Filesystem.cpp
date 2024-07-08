#include <fstream>
#include <string>
#include "Filesystem.h"
namespace seneca {
	std::string& Filesystem::trim(std::string& src)
	{
		// Remove leading spaces
		while (src.front() == ' ' || src.front() == '\t')
		{
			src.erase(0, 1);
		}
		// Remove trailing spaces
		while (src.back() == ' ' || src.front() == '\t')
		{
			src.erase(src.length() - 1);
		}
		return src;
	}

	void Filesystem::createDirAndFile(const std::string& path, const std::string& content)
	{
		std::string dir{};
		size_t start{0}, end = path.find('/');
		if (end != std::string::npos)
		{
			do {
				dir = path.substr(start, end);
				Directory* foundDir = dynamic_cast<Directory*>(m_current->find(dir));
				if (!foundDir) {
					Directory* newDir = new Directory(dir);
					// see if need to change
					newDir->update_parent_path((m_current->path() + dir));
					*this += newDir;
					m_current = newDir;
				}
				else
				{
					// change to newly created directly object
					m_current = foundDir;
				}
			} while ((start = end + 1) && (end = path.find('/', start)) && (end != std::string::npos));
		}
		if (!content.empty())
		{
			// create new file object
			std::string file = path.substr(start);
			File* newFile = new File(file, content);
			newFile->update_parent_path(path);
			*this += newFile;
		}
	}
	// a custom constructor that receives the name of a file as its first argument, 
	// and an optional string containing the name of the root directory (defaults to an empty string).
	Filesystem::Filesystem(std::string filename, std::string dirname)
	{
		m_root = new seneca::Directory(dirname);
		m_current = m_root;
		// loads the content of the file
		std::ifstream fin(filename);
		if (fin.is_open())
		{
			std::string line{};
			std::string path{};
			std::string content{};
			while (std::getline(fin, line))
			{
				m_current = m_root;
				size_t splitPos = line.find('|');
				// case FILE
				if (splitPos != std::string::npos)
				{
					// extract path and content from each line
					path = line.substr(0, splitPos);
					path = trim(path);
					content = line.substr(splitPos + 1);
					content = trim(content);

					createDirAndFile(path, content);
				}
				// case DIR
				else
				{
					path = trim(line);

					createDirAndFile(path);
				}
			}
			fin.close();
		}
		else
		{
			throw std::string("**EXPECTED EXCEPTION: File not found");
		}

	}
	Filesystem::Filesystem(Filesystem&& src) noexcept
	{
		*this = std::move(src);
	}
	Filesystem& Filesystem::operator=(Filesystem&& src) noexcept
	{
		if (this != &src)
		{
			delete m_root;
			m_current = nullptr;
			m_root = nullptr;
			m_root = src.m_root;
			m_current = src.m_current;
			src.m_root = nullptr;
			src.m_current = nullptr;
		}
		return *this;
	}
	Filesystem& Filesystem::operator+=(Resource* src)
	{
		*m_current += src;
		return *this;
	}
	Directory* Filesystem::change_directory(const std::string& name)
	{
		if (!name.empty())
		{
			Directory* resFound = dynamic_cast<Directory*>(m_current->find(name));
			if (resFound)
			{
				m_current = resFound;
			}
			else
			{
				throw std::invalid_argument("Cannot change directory! " + name + " not found!");
			}
		}
		else 
		{
			m_current = m_root;
		}
		return m_current;
	}
	Directory* Filesystem::get_current_directory() const
	{
		return m_current;
	}
	Filesystem::~Filesystem()
	{
		delete m_root;
	}
}