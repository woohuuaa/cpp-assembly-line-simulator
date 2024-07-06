#include "File.h"
namespace seneca {
	seneca::File::File(std::string filename, std::string content) : m_content(content)
	{
		m_name = filename;
	}
	void File::update_parent_path(const std::string& pPath)
	{
		m_parent_path = pPath;
	}
	NodeType File::type() const
	{
		return NodeType::FILE;
	}
	std::string File::path() const
	{
		return m_parent_path + m_name;
	}
	std::string File::name() const
	{
		return m_name;
	}
	int File::count() const
	{
		return -1;
	}
	size_t File::size() const
	{
		return m_content.size();
	}
}
