#include "Directory.h"

namespace seneca {

	Directory::Directory(const std::string& name) {
		m_name = name;
	}

	Directory::~Directory() {

	}

	void Directory::update_parent_path(const std::string& newpath) {
		m_parent_path = newpath;

		for (auto& resource : m_contents) {
			resource->update_parent_path(path());
		}
	}

	NodeType Directory::type() const {
		return NodeType::DIR;
	}

	std::string Directory::path() const {
		return (m_parent_path + m_name);
	}
	
	std::string Directory::name() const {
		return m_name;
	}

	int Directory::count() const {
		return static_cast<int>(m_contents.size());
	}

	size_t Directory::size() const {
		size_t total_size = 0;
		for (auto& resource : m_contents) total_size += resource->size();
		return total_size;
	}

	Directory& Directory::operator += (Resource* res) {
		if (!res) throw std::invalid_argument("Cannot add a null resource.");
		for (auto& resource : m_contents) if (resource->name() == res->name()) throw std::runtime_error("A resource with the same name already exists.");
		res->update_parent_path(path());
		m_contents.push_back(res);
		return *this;
	}

	Resource* Directory::find(const std::string& res_name, const std::vector<OpFlags>& flag) {
		for (auto* res : m_contents) if (res->name() == res_name) return res;

		if (std::find(flag.begin(), flag.end(), OpFlags::RECURSIVE) != flag.end()) {
			for (auto* res : m_contents) {
				if (res->type() == NodeType::DIR) {
					Resource* found = dynamic_cast<Directory*>(res)->find(res_name, flag);
					if (found) return found;
				}
			}
		}
		return nullptr;
	}

	void Directory::remove(const std::string& res_name, const std::vector<OpFlags>& flag) {
		bool recursive = std::find(flag.begin(), flag.end(), OpFlags::RECURSIVE) != flag.end();
		Resource* resource = find(res_name, { OpFlags::RECURSIVE });

		if (!resource) throw std::invalid_argument("Resource does not exist");
		if (resource->type() == NodeType::DIR) {
			if (!recursive) throw std::invalid_argument("NAME is a directory. Pass the recursive flag to delete directories.");
			else dynamic_cast<Directory*>(resource)->clear_directory();
		}

		Directory* parent = parent_directory(res_name);
		if (parent) {
			auto it = std::find_if(parent->m_contents.begin(), parent->m_contents.end(), [&res_name](Resource* r) {
				return r->name() == res_name;
			});
			if (it != parent->m_contents.end()) parent->m_contents.erase(it);
		}
		delete resource;
	}

	void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flag) const {
		os << "Total size: " << size() << " bytes" << std::endl;

		for (auto* resource : m_contents) {
			os << (resource->type() == NodeType::DIR ? "D | " : "F | ");
			os << std::left << std::setw(15) << resource->name() << " | ";
			os << std::setw(2);
			if (resource->type() == NodeType::DIR && flag.back() == FormatFlags::LONG)
				os << std::right << resource->count();
			os << " | " << std::right << std::setw(10) << resource->size() << " bytes |" << std::endl;
		}
	}


	void Directory::clear_directory() {
		for (auto* resource : m_contents) {
			if (resource->type() == NodeType::DIR) dynamic_cast<Directory*>(resource)->clear_directory();
			delete resource;
		}
		m_contents.clear();
	}

	Directory* Directory::parent_directory(const std::string& res_name) {
		for (auto* res : m_contents) if (res->name() == res_name) return this;

		for (auto* resource : m_contents) {
			if (resource->type() == NodeType::DIR) {
				Directory* pdir = dynamic_cast<Directory*>(resource)->parent_directory(res_name);
				if (pdir) return pdir;
			}
		}
		return nullptr;
	}
}