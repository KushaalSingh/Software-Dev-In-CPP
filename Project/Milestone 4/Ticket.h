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