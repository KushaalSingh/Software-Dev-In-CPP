#include "Directory.h"

namespace seneca {

	Directory::Directory(const std::string& name) {
		m_name = name;
	}

	void Directory::update_parent_path(const std::string& path) {
		m_parent_path = path;
		for (auto& resource : m_contents) resource->update_parent_path(m_parent_path + m_name);
	}

	NodeType Directory::type() const {
		return NodeType::DIR;
	}

	std::string Directory::path() const {
		return m_parent_path;
	}

	std::string Directory::name() const {
		return m_name;
	}

	int Directory::count() const {
		return static_cast<int>(m_contents.size());
	}

	size_t Directory::size() const {
		size_t totalSize = 0u;
		for (const auto& resource : m_contents) totalSize += resource->size();
		return totalSize;
	}

	Directory& Directory::operator+=(Resource* src) {
		for (auto& resources : m_contents) if (resources->name() == src->name()) throw std::runtime_error("Resource with same name found");
		m_contents.push_back(src);
		src->update_parent_path(m_parent_path + src->name());
		return *this;
	}

	Resource* Directory::find(const std::string& src, const std::vector<OpFlags>& flag) {
		for (Resource* resource : m_contents) if (resource->name() == src) return resource;

		if (std::find(flag.begin(), flag.end(), OpFlags::RECURSIVE) != flag.end()) {
			for (Resource* resource : m_contents) {
				if (resource->type() == NodeType::DIR) {
					Directory* dir = dynamic_cast<Directory*>(resource);
					if (dir) {
						Resource* res = dir->find(src, flag);
						if (res != nullptr) return res;
					}
				}
 			}
		}
		return nullptr;
	}

	Directory::~Directory() {
		for (Resource* resource : m_contents) delete resource;
	}

	void Directory::remove(const std::string& name, const std::vector<OpFlags>& flags = {}) {
		auto it = std::find_if(m_contents.begin(), m_contents.end(), [&](Resource* resource) {
			return resource->name() == name;
		});

		if (it == m_contents.end()) {
			throw std::string(name + " does not exist in " + m_name);
		}

		Resource* resource = *it;
		if (resource->type() == NodeType::DIR) {
			if (std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) == flags.end()) {
				throw std::invalid_argument(name + " is a directory. Pass the recursive flag to delete directories.");
			}
		}

		delete resource;
		m_contents.erase(it);
	}

	NodeType resourceType(const std::string& res) {
		if (res[res.length() - 1] == '/' && std::count(res.begin(), res.end(), '/') == 1) return NodeType::DIR;
		else if (res.find('/') == std::string::npos) return NodeType::FILE;
		else return NodeType::PATH;
	}
}