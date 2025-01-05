#include "File.h"

namespace seneca {

	File::File(const std::string& name, const std::string& contents) : m_contents(contents) {
		m_name = name;
	}

	void File::update_parent_path(const std::string& path) {
		m_parent_path = path;
	}
}