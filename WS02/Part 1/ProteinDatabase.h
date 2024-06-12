#ifndef SENECA_PROTEIN_DATABASE
#define SENECA_PROTEIN_DATABASE

#include "TimedTask.h"
#include <fstream>

namespace seneca {

	class ProteinDatabase {
	private:
		string* proteins;
		size_t numProteins;
		
	public:
		ProteinDatabase();
		ProteinDatabase(string fileName);
		~ProteinDatabase();
		size_t size();
		string operator[](size_t index) const;
	};
}


#endif