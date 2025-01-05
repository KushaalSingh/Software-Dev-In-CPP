#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H
#include "File.h"
#include <vector>
#include <exception>


namespace seneca {

	class Directory : public Resource {
		std::vector<Resource*> m_contents;
	public:
		Directory(const std::string& name);
		void update_parent_path(const std::string& path) override;
		NodeType type() const override;
		std::string path() const override;
		std::string name() const override;
		int count() const override;
		size_t size() const override;
		Directory& operator+=(Resource*);
		Resource* find(const std::string&, const std::vector<OpFlags>&);
	};

}


#endif