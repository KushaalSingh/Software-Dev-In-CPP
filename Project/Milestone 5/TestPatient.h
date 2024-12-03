/*
Citation and Sources...
Final Project Milestone 1
Module: TestPatient
Filename: TestPatient
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
#ifndef SENECA_TEST_PATIENT_H
#define SENECA_TEST_PATIENT_H

#include "Patient.h"

namespace seneca {

	extern int nextTestTicket;
	
	class TestPatient : public Patient {
	public:
		TestPatient();
		char type() const override;
		std::ostream& write(std::ostream& out) const override;
		std::istream& read(std::istream& in) override;
	};



}


#endif
