/*
Citation and Sources...
Final Project Milestone 1
Module: IOAble
Filename: IOAble.h
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
#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

namespace seneca {

	class IOAble {
	public:
		virtual std::ostream& write(std::ostream& out) const = 0;
		virtual std::istream& read(std::istream& in) = 0;
		virtual ~IOAble() {};
	};

	std::ostream& operator<< (std::ostream& out, const IOAble& src);
	std::istream& operator>> (std::istream& in, IOAble& src);
}


#endif
