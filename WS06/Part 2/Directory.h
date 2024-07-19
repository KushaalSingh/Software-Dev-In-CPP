#ifndef SENECA_DIRECTORY_CPP
#define SENECA_DIRECTORY_CPP

#include "Resource.h"
#include "Flags.h"
#include <vector>
#include <algorithm>
#include <exception>
#include <iomanip>

namespace seneca {

	class Directory : public Resource {
	private:
		std::vector<Resource*> m_contents;

	public:
		Directory(const std::string& name);
		~Directory();
		void update_parent_path(const std::string& path) override;
		NodeType type() const override;
		std::string path() const override;
		std::string name() const override;
		int count() const override;
		size_t size() const override;
		Directory& operator+=(Resource* src);
		Resource* find(const std::string& src, const std::vector<OpFlags>& flag = {});

		Directory(const Directory&) = delete;
		Directory& operator=(const Directory&) = delete;
		Directory(Directory&&) = delete;
		Directory& operator=(Directory&&) = delete;

		void remove(const std::string& name, const std::vector<OpFlags>& flags = {});
		void display(std::ostream& os, const std::vector<FormatFlags>& flags = {}) const;
	};

	NodeType resourceType(const std::string& res);
}

#endif