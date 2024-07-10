 #define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"
using namespace std;
namespace seneca {
	const double PI = 3.14159265;
	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}
	bool Canister::isEmpty()const {
		return m_contentVolume < 0.00001;
	}
	bool Canister::hasSameContent(const Canister& C) const{
		if (m_contentName && C.m_contentName)
			return strcmp(m_contentName, C.m_contentName) == 0;
		return false;
	}
	void Canister::setName(const char* Cstr) {
		if (Cstr && m_usable) {
			delete[] m_contentName;
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}
	 }

	Canister::Canister() {
		setToDefault();
	}

	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}
	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();
		if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
			m_height = height;
			m_diameter = diameter;
			setName(contentName);
		}
		else {
			m_usable = false;
		}
	}
	Canister::~Canister() {
		delete[] m_contentName;
	}
	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}
	double Canister::capacity() const {
		return PI * (m_height - 0.267) * (m_diameter / 2.0) * (m_diameter / 2.0);
	}

	double Canister::volume() const {
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName) {
		if (!contentName) {
			m_usable = false;
		}
		else if (isEmpty()) {
			setName(contentName);
		}
		else if (!hasSameContent(Canister(contentName))) {
			m_usable = false;
		}
		return *this;
	}
	Canister& Canister::pour(double quantity) {
		if (m_usable && quantity > 0.0) {
			if (quantity + m_contentVolume <= capacity()) {
				m_contentVolume += quantity;
			}
			else {
				m_usable = false;
			}
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C) {
		setContent(C.m_contentName);
		if (!C.isEmpty()) {
			if (volume() > capacity() - C.volume()) {
				C.m_contentVolume -= capacity() - volume();
				m_contentVolume = capacity();
			}
			else {
				pour(C.m_contentVolume);
				C.m_contentVolume = 0.0;
			}
		}
		return *this;
	}

	std::ostream& Canister::display() const {
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);

		std::cout << std::setw(7) << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable) {
			std::cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr) {
			std::cout << " of " << std::setw(7) << m_contentVolume << "cc   " << m_contentName;
		}
		return std::cout;
	}
}