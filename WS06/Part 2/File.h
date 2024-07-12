#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include "Resource.h"


namespace seneca {
	
	class File : public Resource {
	private:
		std::string m_contents;

	public:
		File(const std::string& fileName, const std::string& contents = "");
		void updateContents(const std::string& contents);
		void update_parent_path(const std::string& path) override;
		NodeType type() const override;
		std::string path() const override;
		std::string name() const override;
		int count() const override;
		size_t size() const override;
	};
}

#endif