#include "ProteinDatabase.h"

namespace seneca {

	ProteinDatabase::ProteinDatabase() : proteins(nullptr), numProteins(0) {}

	ProteinDatabase::ProteinDatabase(string fileName) : proteins(nullptr), numProteins(0) {
		
		std::ifstream file(fileName);
		if (file.good()) {
			string ln;
			size_t count = 0;
			while (std::getline(file, ln)) if (ln[0] == '>') count++;
			
			numProteins = count;
			proteins = new string[numProteins];

			file.clear();
			file.seekg(0);

			count = 0;
			string currProtein;

			while (std::getline(file, ln)) {
				if (ln[0] == '>') {
					if (!currProtein.empty()) {
						proteins[count++] = currProtein;
						currProtein.clear();
					}
				}
				else {
					currProtein += ln;
				}
			}

			if (!currProtein.empty() && count < numProteins) {
				proteins[count] = currProtein;
			}
		}
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src) : proteins(nullptr), numProteins(0) {
		if (this != &src) {
			numProteins = src.size();
			proteins = new string[numProteins];
			for (int i = 0; i < (int)numProteins; i++) proteins[i] = src.proteins[i];
		}
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src) noexcept : proteins(src.proteins), numProteins(src.numProteins) {
		std::cout << "MOVE CONSTRUCTOR CALLED" << std::endl;

		src.numProteins = 0;
		src.proteins = nullptr;
	}

	ProteinDatabase& ProteinDatabase::operator= (const ProteinDatabase& src) {
		if (this != &src) {
			deallocMem();

			numProteins = src.size();
			proteins = new string[numProteins];
			for (int i = 0; i < (int)numProteins; i++) proteins[i] = src.proteins[i];
		}
		return *this;
	}

	ProteinDatabase::~ProteinDatabase() {
		deallocMem();
	}

	size_t ProteinDatabase::size() const {
		return numProteins;
	}

	string ProteinDatabase::operator[] (size_t index) const {
		if (index < numProteins) return proteins[index];
		else return "";
	}

	void ProteinDatabase::deallocMem() {
		delete[] proteins;
		proteins = nullptr;
	}
}