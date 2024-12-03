/*
Citation and Sources...
Final Project Milestone 1
Module: Ticket
Filename: Ticket.cpp
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

#include "Ticket.h"

namespace seneca {

    Ticket::Ticket(int number) {
        m_number = number;
    }

    Time Ticket::time() const {
        return m_time;
    }

    int Ticket::number() const {
        return m_number;
    }

    void Ticket::resetTime() {
        m_time.reset();
    }

    void Ticket::setNumber(int number) {
        m_number = number;
    }

    void Ticket::setTime(const Time& time) {
        m_time = time;
    }

    std::ostream& Ticket::write(std::ostream& ostr) const {
        if (&ostr != &std::cout) {
            ostr << m_number << "," << m_time;
        }
        else {
            ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
        }
        return  ostr;
    }

    std::istream& Ticket::read(std::istream& istr) {
        istr >> m_number;
        istr.ignore(10000, ',');
        return istr >> m_time;
    }
}