#ifndef SENECA_DIRECTORY_CPP
#define SENECA_DIRECTORY_CPP

#include "Resource.h"
#include "Flags.h"
#include <vector>
#include <algorithm>
#include <iomanip>

namespace seneca {

	class Directory : public Resource {
	private:
		std::vector<Resource*> m_contents;

	public:
		Directory(const std::string& name);
		~Directory();
		void update_parent_path(const std::string& path) override;
		void constructPath(const std::string& path);
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

		void remove(const std::string& name, const std::vector<OpFlags>& flags = {}) {
			auto it = std::find_if(m_contents.begin(), m_contents.end(), [&](Resource* resource) {
				return resource->name() == name;
				});

			if (it == m_contents.end()) {
				throw std::string(name + " does not exist in " + m_name);
			}

			Resource* resource = *it;
			if (resource->type() == NodeType::DIR) {
				if (std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) == flags.end()) {
					throw std::invalid_argument(name + " is a directory. Pass the recursive flag to delete directories.");
				}
			}

			delete resource;
			m_contents.erase(it);
		}

		void display(std::ostream& os, const std::vector<FormatFlags>& flags = {}) const {
			os << "Total size: " << size() << " bytes\n";

			for (const Resource* resource : m_contents) {
				os << (resource->type() == NodeType::DIR ? "D | " : "F | ")
					<< std::left << std::setw(15) << resource->name() << " | ";

				if (std::find(flags.begin(), flags.end(), FormatFlags::LONG) != flags.end()) {
					if (resource->type() == NodeType::DIR) {
						os << std::right << std::setw(2) << resource->count() << " | "
							<< std::right << std::setw(10) << resource->size() << " bytes |";
					}
					else {
						os << std::right << std::setw(10) << resource->size() << " bytes |";
					}
				}
				os << "\n";
			}
		}

	};

}

#endif