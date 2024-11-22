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
#include "Rectangle.h"
#include "Utils.h"

namespace seneca {

	Rectangle::Rectangle() :LblShape(), m_width(0), m_height(0) {};

	Rectangle::Rectangle(const char* label, size_t width, size_t height):LblShape(label),m_width(width),m_height(height) {
		if (m_height < 3) {
			m_height = 3;
		}
		if (m_width < strlen(label) + 2) {
			m_width = strlen(label) + 2;
		}
	}

	void Rectangle::getSpecs(std::istream& in) {
		LblShape::getSpecs(in);
		in >> m_width;
		in.ignore();
		in >> m_height;
		in.ignore();
	}

	void Rectangle::draw(std::ostream& out)const {
		if (m_width > 0 && m_height > 0) {
			//draw the top border
			out << "+" << std::string(m_width - 2, '-') << "+" << std::endl;
			
			//draw the label row
			out << "|" << std::left << std::setw(m_width - 2)<< label() << "|" << std::endl;

			//draw the empty middle rows
			for (size_t i = 0; i < m_height - 3; i++) {
				out << "|" << std::setw(m_width - 2) << std::setfill(' ') << " " << "|" << std::endl;
			}

			//draw the bottom border
			out << "+" << std::string(m_width - 2, '-') << "+" ;
		}
	}
}