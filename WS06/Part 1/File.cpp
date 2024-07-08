#include "File.h"

namespace seneca {

	File::File(const std::string& fileName, const std::string& contents = std::string()) : m_contents(contents) {
		m_name = fileName;
	}

	void File::update_parent_path(const std::string& path) {
		m_parent_path += path;
	}
	
}