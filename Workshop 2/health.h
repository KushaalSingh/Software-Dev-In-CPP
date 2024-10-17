#ifndef SENECA_HEALTH_H
#define SENECA_HEALTH_H

namespace seneca {

	class SuperHealth {
		double m_value = 1000.0;

	public:
		SuperHealth& operator-=(int dmg) {
			m_value -= dmg / 2.0;
			return *this;
		}

		SuperHealth& operator=(int newVal) {
			m_value = newVal;
			return *this;
		}

		operator int() const {
			return static_cast<int>(m_value);
		}
	};

	struct InfiniteHealth {
		InfiniteHealth& operator-=(int) { return *this; }
		InfiniteHealth& operator=(int) { return *this; }
		operator int() const { return 1; }
	};
}
#endif