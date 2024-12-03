#include "IOAble.h"

namespace seneca {

	std::ostream& operator<< (std::ostream& out, const IOAble& src) {
		return src.write(out);
	}

	std::istream& operator>> (std::istream& in, IOAble& src) {
		return src.read(in);
	}
}