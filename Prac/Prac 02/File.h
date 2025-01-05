#ifndef SENECA_FILE_H
#define SENECA_FILE_H
#include "Resource.h"

namespace seneca {

	class File : public Resource {
		std::string m_contents { "" };

	public:
		File(const std::string& name, const std::string& contents = "");
		~File() override = default;
		void update_parent_path(const std::string&) override;
		NodeType type() const override;
		std::string path() const override;
		std::string name() const override;
		int count() const override;
		size_t size() const override;
	};


}

#endif