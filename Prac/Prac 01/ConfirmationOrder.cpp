#include "ConfirmationOrder.h"

namespace seneca {

	bool ConfirmationOrder::valid(bool selfcheck, const ConfirmationOrder* src) {
		return (src != nullptr && src->m_toys != nullptr && src->m_count > 0 && (selfcheck ? this != src : true));
	}

	bool ConfirmationOrder::findToy(const Toy* toy) {
		for (size_t i = 0; i < m_count; i++) if (m_toys[i] == toy) return true;
	}

	ConfirmationOrder::ConfirmationOrder(const Toy* toys[], size_t count) : m_toys(nullptr), m_count(0) {
		if (toys != nullptr && count > 0) {
			m_count = count;
			m_toys = new const Toy * [m_count];
			for (size_t i = 0; i < m_count; i++) m_toys[i] = toys[i];
		}
	}

	ConfirmationOrder::ConfirmationOrder(const ConfirmationOrder& src) : m_toys(nullptr), m_count(0) {
		if (valid(false, &src)) {
			m_count = src.m_count;
			m_toys = new const Toy * [m_count];
			for (size_t i = 0; i < m_count; i++) m_toys[i] = src.m_toys[i];
		}
	}

	ConfirmationOrder::ConfirmationOrder(ConfirmationOrder&& src) noexcept : m_toys(src.m_toys), m_count(src.m_count) {
		src.m_toys = nullptr;
		src.m_count = 0;
	}

	ConfirmationOrder::~ConfirmationOrder() {
		delete[] m_toys;
	}

	ConfirmationOrder& ConfirmationOrder::operator = (const ConfirmationOrder& src) {
		if (valid(true, &src)) {
			delete[] m_toys;
			m_count = src.m_count;
			m_toys = new const Toy * [m_count];
			for (size_t i = 0; i < m_count; i++) m_toys[i] = src.m_toys[i];
		}
		return *this;
	}

	ConfirmationOrder& ConfirmationOrder::operator = (ConfirmationOrder&& src) noexcept {
		if (valid(true, &src)) {
			delete[] m_toys;
			m_toys = src.m_toys;
			m_count = src.m_count;

			src.m_toys = nullptr;
			src.m_count = 0;
		}
		return *this;
	}

	ConfirmationOrder& ConfirmationOrder::operator += (const Toy& toy) {
		if (valid(false, this) && !findToy(&toy)) {
			const Toy** temp = new const Toy * [m_count + 1];
			for (size_t i = 0; i < m_count; i++) temp[i] = m_toys[i];
			temp[m_count] = &toy;
			delete[] m_toys;
			m_toys = temp;
			++m_count;
		}
		return *this;
	}
}