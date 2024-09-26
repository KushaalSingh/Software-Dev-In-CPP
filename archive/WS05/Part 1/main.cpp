#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h" // intentional

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; ++i)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	seneca::Book library[7];
	if (argc == 2) {
		std::ifstream file(argv[1]);
		int i = 0;
		std::string str;
		if (!file.is_open()) {
			std::cerr << "ERROR: CANNOT OPEN THE FILE" << std::endl;
			exit(AppErrors::CannotOpenFile);
		}
		while (file) {
			std::getline(file, str);
			if (str[0] != '#' && i < 7) {
				library[i] = seneca::Book(str);
				++i;
			}
		}
	}

	else {
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	auto fixPrice = [usdToCadRate, gbpToCadRate](seneca::Book& src) {
		if (src.country() == "US") src.price() *= usdToCadRate;
		else if (src.country() == "UK" && src.year() >= 1990 && src.year() <= 1999) src.price() *= gbpToCadRate;
 	};



	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (const auto& book : library) std::cout << book;
	


	std::cout << "-----------------------------------------\n\n";
	for (auto& book : library) fixPrice(book);


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (const auto& book : library) std::cout << book;


	std::cout << "-----------------------------------------\n";

	return cout;
}