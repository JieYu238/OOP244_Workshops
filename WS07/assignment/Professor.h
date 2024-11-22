/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241108
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include <iostream>
#include"Employee.h"
namespace seneca {
    class Professor:public Employee {
        char* m_subjectName;
        int m_numSections;
        double devPay()const;
    public:
        Professor();
        Professor(const char* name, const char* subjName, int numSec, size_t empNo, double sal);
        ~Professor();
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout)const;
        std::ostream& title(std::ostream& ostr = std::cout)const;
        
        //input and output helper operator overloads
        friend std::ostream& operator<<(std::ostream& ostr, const Professor& P);
        friend std::istream& operator>>(std::istream& istr, Professor& P);
    };

    
}
#endif // !SENECA_PROFESSOR_H
