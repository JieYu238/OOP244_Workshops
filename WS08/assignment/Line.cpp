/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241115
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/
#include <iomanip>
#include<cstring>
#include "Line.h"
#include "Utils.h"
using namespace std;
namespace seneca {

	Line::Line() :LblShape(), m_length(0) {};

	Line::Line(const char* label, size_t length):LblShape(label), m_length(length ){
		if (m_length < strlen(label)) {
			m_length = strlen(label);
		}
	}

	void Line::getSpecs(std::istream& in) {
		
		LblShape::getSpecs(in);
		in >> m_length;
		in.ignore(1000,'\n');

	}

	void Line::draw(std::ostream& out)const {
		if (m_length > 0 && label() != nullptr) {
			out << label() << std::endl;
			for (size_t i = 0; i < m_length; i++) {
				out << "=";
			}
		}
	}
}
