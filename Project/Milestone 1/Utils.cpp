/*
Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.cpp
Version  1.0
Author   Kushaal Singh
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
This module was provided for by professor so I have not added
any of it's contents.
-----------------------------------------------------------
*/
#include "Utils.h"
using namespace std;

namespace seneca {

    bool debug = false;
    Utils U;
    int Utils::getTime() {
        int mins = -1;
        if (debug) {
            int duration[]{ 3,5,9,20,30 };
            mins = (m_testMins %= 1440);
            m_testMins += duration[m_testIndex++ % 5];
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    void Utils::setDebugTime(int hour, int min) {
        seneca::debug = true;
        m_testMins = hour * 60 + min;
    }

}