#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include "Resource.h"


namespace seneca {
	
	class File : public Resource {
	private:
		std::string m_contents;

	public:
		File(const std::string& fileName, const std::string& contents = "");
		void update_parent_path(const std::string& path) override;

	};
}

#endif