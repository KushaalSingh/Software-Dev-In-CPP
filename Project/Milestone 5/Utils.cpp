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

    int Utils::strcmp(const char* s1, const char* s2)const {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }

    void Utils::allocStringCopy(char*& str, const char* src) {
        str = new char[strlen(src) + 1];
        strcpy(str, src);
    }

    int Utils::hasNonDigit(const char* str, int& value) {
        int digit = 0;
        int str_len = (int)strlen(str);
        bool isNgtv = isNegative(str);
        if (isNgtv) digit++;
        for (int i = 0; i < str_len; i++) if (str[i] >= 48 && str[i] <= 57) digit++;
        if (digit == 0) return 0;
        else if (digit < str_len) return 1;
        else if (digit == str_len) {
            value = atoi(str);
            return 2;
        }
        else return -1;
    }

    bool Utils::isNegative(const char* str) {
        for (int i = 0; i < (int)strlen(str); i++) if (str[i] >= 48 && str[i] <= 57 && str[i - 1] == '-') return true;
        return false;
    }

    int Utils::getIntInRange(int lwLm, int upLm) {
        char str[32];
        int value, stst = 1;
        while (stst) {
            std::cin.getline(str, 32);
            int result = hasNonDigit(str, value);
            switch (result) {
            case 0:
                std::cout << "Bad integer value, try again: ";
                break;
            case 1:
                std::cout << "Only enter an integer, try again: ";
                break;
            case 2:
                if (value < lwLm || value > upLm) {
                    std::cout << "Invalid value enterd, retry[" << lwLm << " <= value <= " << upLm << "]: ";
                }
                else {
                    return value;
                }
                break;
            case -1:
                std::cerr << "ERROR: This should not happen";
                break;
            }
        }
        return -1;
    }
}