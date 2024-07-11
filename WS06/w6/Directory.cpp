#include <iomanip>
#include "Directory.h"
namespace seneca {
	bool Directory::checkFlag(const std::vector<OpFlags>& flags)
	{
		for (const auto& flag : flags) {
			if (flag == OpFlags::RECURSIVE) {
				return true;
			}
		}
		return false;
	}
	seneca::Directory::Directory(std::string dirname)
	{
		m_name = dirname;
	}
	void Directory::update_parent_path(const std::string& pPath)
	{	// +=?
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
				throw;
			}
		}
		m_content.push_back(src);
		src->update_parent_path(path());
		return *this;
	}
	Resource* Directory::find(const std::string& filename, const std::vector<OpFlags>& flags)
	{
		bool recur = false;
		for (const auto& res : m_content) {
			if (res->name() == filename) {
				return res;
			}
		}
		if (checkFlag(flags))
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
	void Directory::remove(const std::string& name, const std::vector<OpFlags>& flags)
	{
		Resource* found = find(name, flags);
		if (found)
		{
			if ((found->type() == NodeType::DIR) && !checkFlag(flags))	{
				throw std::invalid_argument(name + "is a directory. Pass the recursive flag to delete directories");
			}
			// find index of the found file
			size_t index{};
			for (const auto& content : m_content) {
				if (content->name() == name) {
					break;
				}
				index++;
			}
			delete found;
			m_content.erase(m_content.begin() + index);
		}
		else
		{
			throw std::string(name + "does not exist in" + path());
		}
	}
	void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flags) const
	{
		os << "Total size: " + std::to_string(size()) + " bytes" << std::endl;
		bool tagLong{};
		for (const auto& flag : flags) {
			if (flag == FormatFlags::LONG) {
				tagLong = true;
			}
		}
		for (auto& res : m_content) {
			if (res->type() == NodeType::DIR) {
				os << "D | " << std::left << std::setw(15) << res->name() << " |";
				if (tagLong)
				{
					os << std::right << std::setw(2) << std::to_string(res->count()) << " | "
						<< std::right << std::setw(10) << std::to_string(res->size()) + " bytes";
				}
			}
			else {
				os << "F | " << std::left << std::setw(15) << res->name() << " |";
				if (tagLong)
				{
					os << std::right << std::setw(2) << "   | "
						<< std::right << std::setw(10) << std::to_string(res->size()) + " bytes";
				}
			}
			os << std::endl;
		}
	}
}
