#include "FileSystem.h"

namespace seneca {

	Filesystem::Filesystem(const std::string& file_name, const std::string& root_name) {
		m_root = new Directory(root_name.empty() ? "" : root_name + "/");
		m_current = m_root;

		std::ifstream file(file_name);
		if (!file.is_open()) throw std::runtime_error("Failed to open file");
		
		std::string line;
		while (std::getline(file, line)) {
			size_t delim = line.find('|');
			auto path = trim(line.substr(0, delim));
			auto comment = trim(line.substr(delim + 1, line.length() - delim));
			Resource* res = createResource(path, m_root);
			if (res && res->type() == NodeType::FILE) {
				dynamic_cast<File*>(res)->updateContents(comment);
			}
		}

	}

	Filesystem::Filesystem(Filesystem&& src) noexcept : m_root(src.m_root), m_current(src.m_current) {
		src.m_root = nullptr;
		src.m_current = nullptr;
	}

	Filesystem& Filesystem::operator=(Filesystem&& src) noexcept {
		if (this != &src) {
			delete[] m_root;
			m_root = src.m_root;
			m_current = src.m_current;
			src.m_root = nullptr;
			src.m_current = nullptr;
		}
		return *this;
	}

	Filesystem& Filesystem::operator+=(Resource* src) {
		*m_current += src;
		return *this;
	}

	Filesystem::~Filesystem() {
		delete m_root;
	}

	Directory* Filesystem::change_directory(const std::string& dir) {
		if (dir.empty()) m_current = m_root;
		else {
			auto found = m_current->find(dir);
			if (found) {
				m_current = dynamic_cast<Directory*>(found);
			}
			else throw std::invalid_argument("Cannot change directory! " + dir + " not found!");
		}
		return m_current;
	}

	Directory* Filesystem::get_current_directory() const {
		return m_current;
	}

	Resource* Filesystem::createResource(const std::string& path, Directory* base) {
		size_t p1 = 0, p2 = 0;

		if (resourceType(path) == NodeType::PATH) {
			for (size_t i = 0; i < path.length() && !path.empty(); i++) {
				if (path[i] == '/') {
					p2 = i;
					Resource* curr = base->find(path.substr(p1, p2 - p1 + 1));
					if (curr) {
						p1 = p2 + 1;
						return createResource(path.substr(p1), dynamic_cast<Directory*>(curr));
					}
					else {
						Resource* temp = new Directory(path.substr(p1, p2 + 1));
						*base += temp;
						p1 = p2 + 1;
						return createResource(path.substr(p1), dynamic_cast<Directory*>(temp));
					}
				}
			}

		}
		else if (resourceType(path) == NodeType::DIR) {
			Resource* temp = new Directory(path);
			*base += temp;
		}
		else if (resourceType(path) == NodeType::FILE) {
			Resource* temp = new File(path);
			*base += temp;
			return temp;
		}
		return nullptr;
	}

	std::string trim(const std::string& str) {
		size_t first = str.find_first_not_of(' ');
		size_t last = str.find_last_not_of(' ');
		return str.substr(first, last - first + 1);
	}
}