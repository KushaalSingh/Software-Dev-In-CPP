#ifndef SENECA_PROTEIN_DATABASE
#define SENECA_PROTEIN_DATABASE

#include "TimedTask.h"
#include <fstream>

namespace seneca {

	class ProteinDatabase {
	private:
		string* proteins;
		size_t numProteins;
		void deallocMem();

	public:
		ProteinDatabase();
		ProteinDatabase(string fileName);
		ProteinDatabase(const ProteinDatabase& src);
		ProteinDatabase(ProteinDatabase&& src) noexcept;
		~ProteinDatabase();
		ProteinDatabase& operator= (const ProteinDatabase& src);
		size_t size() const;
		string operator[](size_t index) const;
	};
}


#endif