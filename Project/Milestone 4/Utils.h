/* 
Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.h
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

#ifndef SENECA_UTILS_H_
#define SENECA_UTILS_H_

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

namespace seneca {

    class Utils {
        unsigned int m_testMins = 480;
        unsigned int m_testIndex = 0;
    public:
        void setDebugTime(int hour, int min);
        int getTime();
        int strcmp(const char* s1, const char* s2) const;

        //// MY CUSTOM FUNCTIONS ////

        void allocStringCopy(char*& str, const char* src);
        int hasNonDigit(const char* str, int& value);
        bool isNegative(const char* str);
        int getIntInRange(int lwLm, int upLm);
    };

    extern bool debug;
    extern Utils U;
}
#endif