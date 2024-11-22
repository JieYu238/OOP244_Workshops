/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241115
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/
#include "LblShape.h"
#include "Utils.h"

using namespace std;
namespace seneca {

	const char* LblShape::label()const {
		return m_label;
	}

	LblShape::LblShape() {
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label):m_label(nullptr){
		m_label = ut.alocpy(label);
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}

	void LblShape::getSpecs(std::istream& in) {
		char temp[81];
		in.getline(temp, 81, ',');

		delete[] m_label;

		m_label = ut.alocpy(temp);
	}
}