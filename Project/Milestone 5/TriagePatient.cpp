/*
Citation and Sources...
Final Project Milestone 1
Module: TriagePatient
Filename: TriagePatient.cpp
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

#include "TriagePatient.h"

namespace seneca {

	int nextTriageTicket = 1;
	
	TriagePatient::TriagePatient() : Patient(nextTriageTicket++), m_symptoms(nullptr) {}

	char TriagePatient::type() const {
		return 'T';
	}

	TriagePatient::TriagePatient(const TriagePatient& src) : Patient(src), m_symptoms(nullptr) {
		U.allocStringCopy(m_symptoms, src.m_symptoms);
	}

	TriagePatient& TriagePatient::operator= (const TriagePatient& src) {
		deleteSymp();
		m_symptoms = new char[strlen(src.m_symptoms) + 1];
		strcpy(m_symptoms, src.m_symptoms);
		Patient::operator=(src);
		return *this;
	}

	std::ostream& TriagePatient::write(std::ostream& out) const {
		if (&out == &std::cout) {
			out << "TRIAGE" << std::endl;
			Patient::write(out) << "Symptoms: " << m_symptoms << std::endl;
		}
		else if (&out != &std::clog) {
			Patient::write(out) << "," << m_symptoms;
		}
		else Patient::write(out);
		return out;
	}

	std::istream& TriagePatient::read(std::istream& in) {
		Patient::read(in);
		char symptoms[SYM_LEN];
		deleteSymp();
		if (&in != &std::cin) {
			in.ignore();
			if (!in.get(symptoms, 511, '\n')) return in;
			U.allocStringCopy(m_symptoms, symptoms);
			nextTriageTicket = number() + 1;
		}
		else {
			char symptoms[SYM_LEN];
			std::cout << "Symptoms: ";
			if (!in.get(symptoms, (SYM_LEN - 1), '\n')) return in;
			U.allocStringCopy(m_symptoms, symptoms);
		}
		in.ignore();
		return in;
	}

	TriagePatient::~TriagePatient() {
		deleteSymp();
	}

	void TriagePatient::deleteSymp() {
		delete[] m_symptoms;
		m_symptoms = nullptr;
	}

	const char* TriagePatient::symptoms() const {
		return m_symptoms;
	}
}