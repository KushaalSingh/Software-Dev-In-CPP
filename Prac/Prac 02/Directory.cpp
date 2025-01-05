#include "Directory.h"

namespace seneca {

	Directory::Directory(const std::string& name) {
		m_name = name;
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

	Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flag) {
		for (auto* res : m_contents) if (res->name() == name) return res;

		if (std::find(flag.begin(), flag.end(), OpFlags::RECURSIVE) != flag.end()) {
			for (auto* res : m_contents) {
				if (res->type() == NodeType::DIR) {
					Resource* found = dynamic_cast<Directory*>(res)->find(name, flag);
					if (found) return found;
				}
			}
		}
		return nullptr;
	}
}