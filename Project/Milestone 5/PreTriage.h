#ifndef SENECA_PRE_TRIAGE_H
#define SENECA_PRE_TRIAGE_H

#include <fstream>
#include "Menu.h"
#include "TestPatient.h"
#include "TriagePatient.h"

namespace seneca {

	const int MAX_PATIENTS = 100;

	class PreTriage {
	private:
		Time m_avgContaigenTime;
		Time m_avgTriageTime;
		Patient* m_patients[MAX_PATIENTS]{};
		char* m_dataFile;
		int m_numPatients;

		Time getWaitTime(const Patient& src) const;
		void setAverageWaitTime(const Patient& src);
		int indexOfFirstInLine(char type);
		void load();
		void save();
		void Register();
		void admit();
		void lineup() const;

	public:
		PreTriage(const char* file);
		~PreTriage();
		void run();
	};
	// Can't put it in Utils module. Getting error LNK2019.
	template <typename type>
	void removeDynamicElement(type* array[], int index, int& size);
}
#endif
