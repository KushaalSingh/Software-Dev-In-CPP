#include "TestPatient.h"

namespace seneca {

	int nextTestTicket = 1;

	TestPatient::TestPatient() : Patient(nextTestTicket++) {}

	char TestPatient::type() const {
		return 'C';
	}

	std::ostream& TestPatient::write(std::ostream& out) const {
		if (&out == &std::cout) out << "Contagion TEST" << std::endl;
		Patient::write(out);
		return out;
	}

	std::istream& TestPatient::read(std::istream& in) {
		Patient::read(in);
		if (&in != &std::cin) nextTestTicket = number() + 1;
		return in;
	}

}