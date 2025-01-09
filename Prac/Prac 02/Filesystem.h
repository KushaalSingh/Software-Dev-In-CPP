#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H
#include "Directory.h"
#include <fstream>

namespace seneca {

	class Filesystem {
		Directory* m_root;
		Directory* m_current;

		Resource* create_resource(const std::string&);
		Directory* create_directory(const std::string&, Directory*);
	public:
		Filesystem(const std::string&, const std::string& = "");
	};

	std::string& trim(const std::string&);
}


#endif