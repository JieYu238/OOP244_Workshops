/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241129
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
namespace seneca {
   class Transcript :
      public Marks {
      // character pointer student name
       char* m_name{};
      // unsigned integer or size_t student number
       size_t m_studentNumber;
   public:
      // Constructor
       Transcript(const char* name, size_t studentNumber);
      // Rule of Three
       Transcript(const Transcript& src);
       Transcript& operator=(const Transcript& src);
      // Destructor
       ~Transcript();
       //override display
       std::ostream& display(std::ostream& ostr = std::cout)const;
   };
}
#endif // !SENECA_TRANSCRIPT_H


