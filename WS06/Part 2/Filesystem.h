#ifndef SENECA_FILE_SYSTEM_H
#define SENECA_FILE_SYSTEM_H

#include <fstream>
#include "Directory.h"
#include "File.h"
#include "Flags.h"

namespace seneca {

	class Filesystem {
	private:
		Directory* m_root;
		Directory* m_current;

		Resource* createResource(const std::string& path, Directory* base);
		NodeType resourceType(const std::string& res);
	public:
		Filesystem(const std::string& file_name, const std::string& root_dirName = "");
	};

	std::string trim(const std::string& str);
}

#endif 