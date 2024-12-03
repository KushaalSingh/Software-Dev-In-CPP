/*
Citation and Sources...
Final Project Milestone 1
Module: Patient
Filename: Patient.cpp
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

#include "Patient.h"
#include "Utils.h"

namespace seneca {

	Patient::Patient(int ticketNum) : m_name(nullptr), m_OHIP(0), m_ticket(ticketNum) {}

	Patient::Patient(const Patient& src) : m_name(nullptr), m_OHIP(src.m_OHIP), m_ticket(src.m_ticket) {
		U.allocStringCopy(m_name, src.m_name);
	}

	Patient::~Patient() {
		deleteName();
	}

	void Patient::deleteName() {
		delete[] m_name;
		m_name = nullptr;
	}

	bool Patient::operator== (char ch) const {
		return (type() == ch);
	}

	bool Patient::operator== (const Patient& src) const {
		return (type() == src.type());
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Time Patient::time() const {
		return m_ticket.time();
	}

	int Patient::number() const {
		return m_ticket.number();
	}

	Patient::operator bool() const {
		return m_name;
	}

	Patient::operator const char* () const {
		return m_name;
	}

	std::ostream& Patient::write(std::ostream& out) const {
		if (&out == &std::clog) {
			if (!m_name) out << "Invalid Patient Record" << std::endl;
			else {
				out.width(53);
				out.setf(std::ios::left);
				out.fill('.');
				out << m_name;
				out << m_OHIP;
				out.width(5);
				out.setf(std::ios::right);
				out.fill(' ');
				out << m_ticket.number() << " " << m_ticket.time();
				out.unsetf(std::ios::right);
				return out;
			}
		}
		else if (&out == &std::cout) {
			if (!m_name) out << "Invalid Patient Record" << std::endl;
			else {
				out << m_ticket << std::endl;
				out << m_name << ", OHIP: " << m_OHIP << std::endl;
				return out;
			}
		}
		else out << type() << "," << m_name << "," << m_OHIP << "," << m_ticket;
		return out;
	}

	Patient& Patient::operator= (const Patient& src) {
		U.allocStringCopy(m_name, src.m_name);
		m_OHIP = src.m_OHIP;
		m_ticket.setNumber(src.number());
		m_ticket.setTime(src.m_ticket.time());
		return *this;
	}

	std::istream& Patient::read(std::istream& in) {
		if (&in == &std::cin) {
			char input_str[NAME_LEN + 1];
			std::cout << "Name: ";
			in.get(input_str, (NAME_LEN + 1), '\n');
			U.allocStringCopy(m_name, input_str);
			in.ignore(10000, '\n');
			std::cout << "OHIP: ";
			m_OHIP = U.getIntInRange(100000000, 999999999);
			return in;
		}
		else {
			char input_str[NAME_LEN + 1];
			if (!in.get(input_str, (NAME_LEN + 1), ',')) {
				deleteName();
				return in;
			}
			U.allocStringCopy(m_name, input_str);
			in.ignore(10000, ',');
			in >> m_OHIP;
			in.ignore(10000, ',');
			m_ticket.read(in);
			return in;
		}
	}
}