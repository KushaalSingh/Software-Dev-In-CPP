#include "Filesystem.h"

namespace seneca {

	Filesystem::Filesystem(const std::string& filename, const std::string& root) : m_root(new Directory (root.back() == '/' ? root : root + "/")), m_current(m_root) {
		std::ifstream file(filename);

		if (!file.is_open()) throw std::invalid_argument("Invalid File name. File does not exist.");

		std::string ln = "";
		while (std::getline(file, ln)) {
			create_resource(ln);

			auto separator = ln.find('|');
			if (separator == std::string::npos) create_resource(ln);
			else create_resource(ln.substr(0, separator + 1));
		}
	}

	Resource* Filesystem::create_resource(const std::string& line) {
		auto separator = line.find('|');
		if (separator == std::string::npos) {
			
		}
	}

	Directory* Filesystem::create_directory(const std::string& path) {

	}

	std::string& trim(const std::string& str) {
		size_t first = str.find_first_not_of(" ");
		size_t last = str.find_last_not_of(" ");
		
		std::string trimed = str.substr(first, last - first + 1);
		return trimed;
	}
}