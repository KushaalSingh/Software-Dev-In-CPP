/*
Citation and Sources...
Final Project Milestone 1
Module: Patient
Filename: Patient.h
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
#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H

#include "IOAble.h"
#include "Ticket.h"

const int NAME_LEN = 50;

namespace seneca {

	class Patient : public IOAble {
	private:
		char* m_name;
		int m_OHIP;
		Ticket m_ticket;
		void deleteName();

	public:
		Patient(int ticketNum);
		~Patient();
		Patient(const Patient& src);
		virtual char type() const = 0;
		bool operator== (char ch) const;
		bool operator== (const Patient& src) const;
		void setArrivalTime();
		Time time() const;
		int number() const;
		operator bool() const;
		operator const char* () const;
		Patient& operator= (const Patient& src);
		std::ostream& write(std::ostream& out) const override;
		std::istream& read(std::istream& in) override;
	};


}


#endif
