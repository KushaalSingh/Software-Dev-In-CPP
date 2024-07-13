#include "Utilities.h"

bool emptyStr(const std::string& str) {
	return str.empty() || std::all_of(str.begin(), str.end(), [](const char c) { return std::isspace(c); });
}

bool emptyStr(const int ptr[]) {
	return std::all_of(ptr[0], ptr[3], [](const int c) { return c == 0; });
}

int main(void) {
	std::string str = "0123456789";

	int ptr[3] = { 1, 2, 3 };
	

	if (emptyStr(ptr)) std::cout << "TRUE" << std::endl;
}