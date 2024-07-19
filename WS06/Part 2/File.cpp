#include "File.h"

namespace seneca {

	File::File(const std::string& fileName, const std::string& contents) : m_contents(contents) {
		m_name = fileName;
	}

	void File::updateContents(const std::string& contents) {
		m_contents = contents;
	}

	void File::update_parent_path(const std::string& path) {
		if (std::count(path.begin(), path.end(), '/') == 1) m_parent_path = path.substr(1);
		else m_parent_path = path;
	}
	
	NodeType File::type() const {
		return NodeType::FILE;
	}

	std::string File::path() const {
		return m_parent_path;
	}

	std::string File::name() const {
		return m_name;
	}

	int File::count() const {
		return -1;
	}

	size_t File::size() const {
		return m_contents.size();
	}
}