#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H
#include "File.h"
#include <vector>

namespace seneca {

	class Directory : public Resource {
		std::vector<Resource*> m_contents;
	public:
		Directory(const std::string& name);
	};

}


#endif