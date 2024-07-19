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
	public:
		Filesystem(const std::string& file_name, const std::string& root_dirName = "");
		Filesystem(const Filesystem&) = delete;
		Filesystem& operator=(const Filesystem&) = delete;
		Filesystem(Filesystem&& src) noexcept;
		Filesystem& operator=(Filesystem&& src) noexcept;
		Filesystem& operator+=(Resource* src);
		Directory* change_directory(const std::string& dir = "");
		Directory* get_current_directory() const;
		~Filesystem();
	};

	std::string trim(const std::string& str);
}

#endif 