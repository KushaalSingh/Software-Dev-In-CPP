#include "FileSystem.h"

namespace seneca {

	Filesystem::Filesystem(const std::string& file_name, const std::string& root_name) {
		m_root = new Directory(root_name.empty() ? "" : root_name + "/");
		m_current = m_root;

		std::ifstream file(file_name);
		if (!file.is_open()) throw std::runtime_error("Failed to open file");
		
		std::string line;
		while (std::getline(file, line)) {
			int p1 = 0, p2 = 0, count = 0, ls = 0;
			size_t delim = line.find('|');
			size_t slashCount = std::count(line.begin(), line.end(), '/');
			auto path = trim(line.substr(0, delim));
			auto comment = trim(line.substr(delim + 1, line.length() - delim));

			for (int i = 0; i < path.length(); i++) {
				if (path[i] == '/') {

				}
			}
		}

	}

	Resource* Filesystem::createResource(const std::string& path, Directory* base) {
		size_t p1 = 0, p2 = 0, count = 0;

		if (resourceType(path) == NodeType::PATH) {
			for (size_t i = 0; i < path.length() && !path.empty(); i++) {
				if (path[i] == '/') {
					p2 = i;
					Resource* curr = base->find(path.substr(p1, p2 - p1));
					p1 = p2 + 1;
					if (curr) {
						return createResource(path.substr(p1), dynamic_cast<Directory*>(curr));
					}
					else {
						Resource* temp = new Directory(path.substr(p1, p2 - p1));
						*base += temp;
						return createResource(path.substr(p1), dynamic_cast<Directory*>(temp));
					}
				}
			}

		}
		else if (resourceType(path) == NodeType::DIR) {
			Resource* temp = new Directory(path.substr(p1, p2 - p1));
			*base += temp;
			return nullptr;
		}
		else if (resourceType(path) == NodeType::FILE) {
			Resource* temp = new File(path);
			*base += temp;
			return temp;
		}
	}

	std::string trim(const std::string& str) {
		size_t first = str.find_first_not_of(' ');
		size_t last = str.find_last_not_of(' ');
		return str.substr(first, last - first + 1);
	}

	NodeType resourceType(const std::string& res) {
		if (res[res.length() - 1] == '/' && std::count(res.begin(), res.end(), '/') == 1) return NodeType::DIR;
		else if (res.find('/') == std::string::npos) return NodeType::FILE;
		else return NodeType::PATH;
	}
}