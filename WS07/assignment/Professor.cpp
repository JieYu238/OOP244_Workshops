/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241108
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/
#include <iostream>
#include<iomanip>
#include<algorithm>
#include "Employee.h"
#include "Utils.h"
#include"Professor.h"
namespace seneca {
    Professor::Professor() :Employee(),m_subjectName(nullptr),m_numSections(0){}

    Professor::Professor(const char* name, const char* subjName, int numSec, size_t empNo, double sal)
        :Employee(name, empNo, sal), m_subjectName(nullptr) ,m_numSections(numSec) {
        ut.alocpy(m_subjectName, subjName);
    }

    Professor::~Professor() {
        delete[] m_subjectName;
    }

    double Professor::devPay()const {
        return (0.01 * salary()) * m_numSections;
    }

    std::istream& Professor::read(std::istream& istr) {
        Employee::read(istr);

        istr.ignore();
        char tempSubject[1024];
        istr.getline(tempSubject, 1024, ',');
        if (tempSubject[0] != '\0') {
            ut.alocpy(m_subjectName, tempSubject);
        }

        istr >> m_numSections;

        return istr;
    }

    std::ostream& Professor::write(std::ostream& ostr)const {
        
        Employee::write(ostr);

        char tempPrint[21]{};
        if (m_subjectName) ut.strcpy(tempPrint, m_subjectName,  20);
        ostr << " ";
        ostr.width(20);
        ostr.setf(std::ios::left);
        ostr << tempPrint;
        ostr.unsetf(std::ios::left);

        ostr << " | ";
        ostr.width(5);
        ostr.setf(std::ios::right);
        ostr << m_numSections;
        ostr.unsetf(std::ios::right);

        ostr << " | ";
        ostr.width(8);
        ostr.precision(2);
        ostr.setf(std::ios::fixed);
        ostr << devPay() << " |";

        return ostr;
    }

    std::ostream& Professor::title(std::ostream& ostr)const {
        Employee::title(ostr);
        ostr << " Teaching Subject     | Sec # | $Dev Pay |";
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Professor& P) {
        return P.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Professor& P) {
        return P.read(istr);
    }
}