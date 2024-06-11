#ifndef SENECA_PROTEIN_DATABASE
#define SENECA_PROTEIN_DATABASE

#include "TimedTask.h"

namespace seneca {

	class ProteinDatabase {
	private:
		string* strings;
		size_t numStrings;
		
	public:
		ProteinDatabase();
		ProteinDatabase(string fileName);
		size_t size();
		string operator[](size_t index) const;
	};


}


#endif