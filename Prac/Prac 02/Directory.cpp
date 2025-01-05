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


	std::string Directory::path() const {
		return (m_parent_path + m_name);
	}
	
}