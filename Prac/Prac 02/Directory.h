#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H
#include "File.h"
#include <vector>
#include <exception>
#include <iomanip>


namespace seneca {

	class Directory : public Resource {
		std::vector<Resource*> m_contents;

	public:
		Directory(const std::string& name);
		~Directory() override;
		void update_parent_path(const std::string& path) override;
		NodeType type() const override;
		std::string path() const override;
		std::string name() const override;
		int count() const override;
		size_t size() const override;
		Directory& operator+=(Resource*);
		Resource* find(const std::string&, const std::vector<OpFlags>&);
		void remove(const std::string&, const std::vector<OpFlags>&);
		void display(std::ostream&, const std::vector<FormatFlags>&) const;

		void clear_directory();
		Directory* parent_directory(const std::string&);

		Directory(const Directory&) = delete;
		Directory(Directory&&) = delete;
		Directory& operator = (const Directory&) = delete;
		Directory& operator = (Directory&&) = delete;
	};
}


#endif