/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241122
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/
#include <iostream>
#include "Transcript.h"
#include "Utils.h"
using namespace std;
namespace seneca {

	Transcript::Transcript(const char* name, size_t studentNumber) :m_name{ nullptr }, m_studentNumber{studentNumber} {
		if (name) {
			m_name = new char[ut.strlen(name) + 1];
			ut.alocpy(m_name, name);
		}
	}

	Transcript::Transcript(const Transcript& src) :Marks{ src }{
		m_studentNumber = src.m_studentNumber;
		if (src.m_name) {
			m_name = new char[ut.strlen(src.m_name) + 1];
			ut.alocpy(m_name, src.m_name);
		}
	}

	Transcript& Transcript::operator=(const Transcript& src) {
		if (this != &src) {
			Marks::operator=(src);
			delete[] m_name;
			m_name = new char[ut.strlen(src.m_name) + 1];
			ut.alocpy(m_name, src.m_name);
			m_studentNumber = src.m_studentNumber;
		}
		return *this;
	}

	Transcript::~Transcript() {
		delete[] m_name;
	}

	ostream& Transcript::display(ostream& ostr)const {
		ostr << m_name << " " << "(" << m_studentNumber <<")" << endl;
		ostr << "--------------------------------------------------------------------------" << endl;
		Marks::display(ostr);
		return ostr;
	}
}
