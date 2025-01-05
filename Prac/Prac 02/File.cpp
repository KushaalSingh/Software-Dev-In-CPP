#include "File.h"

namespace seneca {

	File::File(const std::string& name, const std::string& contents) : m_contents(contents) {
		m_name = name;
	}

}