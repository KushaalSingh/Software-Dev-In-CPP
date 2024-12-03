/*
Citation and Sources...
Final Project Milestone 1
Module: TestPatient
Filename: TestPatient.cpp
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
#include "TestPatient.h"

namespace seneca {

	int nextTestTicket = 1;

	TestPatient::TestPatient() : Patient(nextTestTicket++) {}

	char TestPatient::type() const {
		return 'C';
	}

	std::ostream& TestPatient::write(std::ostream& out) const {
		if (&out == &std::cout) out << "Contagion TEST" << std::endl;
		Patient::write(out);
		return out;
	}

	std::istream& TestPatient::read(std::istream& in) {
		Patient::read(in);
		if (&in != &std::cin) nextTestTicket = number() + 1;
		return in;
	}

}