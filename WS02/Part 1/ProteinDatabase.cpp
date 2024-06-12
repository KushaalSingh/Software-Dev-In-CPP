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

	ProteinDatabase::~ProteinDatabase() {
		delete[] proteins;
		proteins = nullptr;
	}

	size_t ProteinDatabase::size() {
		return numProteins;
	}

	string ProteinDatabase::operator[] (size_t index) const {
		if (index < numProteins) return proteins[index];
		else return "";
	}
}