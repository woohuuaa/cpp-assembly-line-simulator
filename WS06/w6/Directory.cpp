#include "Directory.h"
namespace seneca {
	seneca::Directory::Directory(std::string dirname)
	{
		m_name = dirname;
	}
	void Directory::update_parent_path(const std::string& pPath)
	{
		m_parent_path = pPath;
		for (auto& res : m_content) {
			res->update_parent_path(path());
		}
	}
	NodeType Directory::type() const
	{
		return NodeType::DIR;
	}
	std::string Directory::path() const
	{
		return m_parent_path + m_name;
	}
	std::string Directory::name() const
	{
		return m_name;
	}
	int Directory::count() const
	{
		return m_content.size();
	}
	size_t Directory::size() const
	{
		size_t sum{ 0u };
		if (!m_content.empty()) {
			for (auto& res : m_content) {
				sum += res->size();
			}
		}
		return sum;
	}
	Directory& Directory::operator+=(Resource* src)
	{
		for (const auto& res : m_content) {
			if (res->name() == src->name()) {
				throw std::runtime_error("Resource with the same name already exists in the directory");
			}
		}
		m_content.push_back(src);
		m_content[m_content.size() - 1]->update_parent_path(path());
		return *this;
	}
	Resource* Directory::find(const std::string& filename, const std::vector<OpFlags>& flags)
	{
		bool reccur = false;
		for (const auto& res : m_content) {
			if (res->name() == filename) {
				return res;
			}
		}
		for (const auto& flag : flags) {
			if (flag == OpFlags::RECURSIVE) {
				reccur = true;
			}
		}
		if (reccur)
		{
			for (const auto& res : m_content) {
				if (res->type() == NodeType::DIR) {
					Resource* resFound = dynamic_cast<Directory*>(res)->find(filename, flags);
					if (resFound)
					{
						return resFound;
					}
				}
			}
		}
		return nullptr;
	}
	Directory::~Directory()
	{
		for (auto& res : m_content) {
			delete res;
		}
	}
	//void Directory::remove(const std::string&, const std::vector<OpFlags>&)
	//{

	//}
	//void Directory::display(std::ostream&, const std::vector<FormatFlags>&) const
	//{

	//}
}
