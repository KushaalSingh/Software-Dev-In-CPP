/*
Citation and Sources...
Final Project Milestone 1
Module: TriagePatient
Filename: TriagePatient.h
Version  1.0
Author   Kushaal Singh
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SENECA_TRIAGE_PATIENT_H
#define SENECA_TRIAGE_PATIENT_H

#include "Patient.h"

namespace seneca {

	const int SYM_LEN = 512;

	class TriagePatient : public Patient {
	private:
		char* m_symptoms;
		void deleteSymp();

	public:
		TriagePatient();
		TriagePatient(const TriagePatient& src);
		TriagePatient& operator= (const TriagePatient& src);
		~TriagePatient();
		char type() const override;
		std::ostream& write(std::ostream& out) const override;
		std::istream& read(std::istream& in) override;

	protected:
		const char* symptoms() const;
	};

	extern int nextTriageTicket;
}

#endif