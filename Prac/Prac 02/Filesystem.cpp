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
		size_t separator = line.find('|');
		size_t lchar = 0;
		Directory* base = m_root;

		if (separator == std::string::npos) {	// if line has only directory(s).
			auto trim_str = trim(line);

			for (size_t i = 0; i < trim_str.size(); i++) {
				if (trim_str[i] == '/') {
					base = create_directory(trim_str.substr(lchar, i - lchar + 1), base);
					lchar = i + 1;
				}
			}
		}
		else {	// if line includes directory(s) and file(s).
			auto trim_str = trim(line.substr(0, separator));
			auto trim_cont = trim(line.substr(separator + 1));
			size_t lslash = trim_str.find_last_of('/');

			if (lslash == std::string::npos) {
				File* file = create_file(trim_str, base);
				file->update_contents(trim_cont);
			}

			else {
				for (size_t i = 0; i < trim_str.size(); i++) {

					if (i == lslash) {

					}

					if (trim_str[i] == '/') {

					}
				}
			}

			for (size_t i = 0; i < trim_str.size(); i++) {
				if (trim_str[i] == '/') {
					base = create_directory(trim_str.substr(lchar, i - lchar + 1), base);
					lchar = i + 1;
				}
			}
		}
	}

	Directory* Filesystem::create_directory(const std::string& name, Directory* base) {
		Resource* found = base->find(name, { });
		if (found) return dynamic_cast<Directory*>(found);
		
		Directory* directory = new Directory(name);
		*base += directory;
		return directory;
	}

	File* Filesystem::create_file(const std::string& name, Directory* base) {
		Resource* found = base->find(name, { });
		if (found) return dynamic_cast<File*>(found);

		File* file = new File(name);
		*base += file;
		return file;
	}

	std::string& trim(const std::string& str) {
		size_t first = str.find_first_not_of(" ");
		size_t last = str.find_last_not_of(" ");
		
		std::string trimed = str.substr(first, last - first + 1);
		return trimed;
	}
}