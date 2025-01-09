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
			create_directory(trim(line), m_root);
		}
	}

	Directory* Filesystem::create_directory(const std::string& path, Directory* base) {
		size_t lchar = 0;
		for (size_t i = 0; i < path.size(); i++) {
			if (path[i] == '/') {
				std::string dirName = path.substr(lchar, i - lchar + 1);
				Resource* found = base->find(dirName, { });
				lchar = i + 1;

				if (!found) {
					Directory* newDir = new Directory(dirName);
					*base += newDir;
				}
				else if (path.size() >= lchar){
					create_directory(path.substr(lchar), dynamic_cast<Directory*>(found));
				}
			}
		}
	}

	std::string& trim(const std::string& str) {
		size_t first = str.find_first_not_of(" ");
		size_t last = str.find_last_not_of(" ");
		
		std::string trimed = str.substr(first, last - first + 1);
		return trimed;
	}
}