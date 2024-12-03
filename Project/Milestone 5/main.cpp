#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "Utils.h"
using namespace seneca;

void copyFile(const char* des, const char* src) {
    std::ifstream infile(src);
    std::ofstream outfile(des);
    if (outfile) {
        char ch;
        while (infile.get(ch)) {
            outfile.put(ch);
        }
    }
}

void displayFile(const char* fname) {
    std::ifstream fin(fname);
    char ch;
    std::cout << std::endl << "******  Content of file: \"" << fname << "\":" << std::endl;
    while (fin.get(ch)) std::cout << ch;
    std::cout << "***************************************************" << std::endl << std::endl;
}

void theApp() {
    PreTriage P("smalldata.csv");
    P.run();
}

int main() {
    copyFile("smalldata.csv", "smalldata.csv.bak");
    seneca::debug = true;
    U.setDebugTime(8, 41);
    theApp();
    displayFile("smalldata.csv");
    return 0;
}