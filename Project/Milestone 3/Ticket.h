/*
Citation and Sources...
Final Project Milestone 1
Module: Ticket
Filename: Ticket.h
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
#ifndef SENECA_TICKET_H
#define SENECA_TICKET_H

#include "Time.h"
#include "IOAble.h"

namespace seneca {

    class Ticket : public IOAble {
    private:
        Time m_time;
        int m_number;

    public:
        Ticket(int number);
        Time time()const;
        int number()const;
        void resetTime();
        void setNumber(int number);
        void setTime(const Time& time);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
    };
}
#endif