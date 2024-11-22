/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241115
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/
#ifndef SENECA_LINE_H
#define SENECA_LINE_H

#include"LblShape.h"

namespace seneca {

   class Line:public LblShape {
       // Length of the line
       size_t m_length;
   public:
      // Default constructor
       Line();

      // Constructor that initializes label and length
       Line(const char* label, size_t length);

      // Draws the line, using the label and length
       void draw(std::ostream& out)const;

      // Gets specifications of the line (label and length) from input
       void getSpecs(std::istream& in);
   };

}

#endif // !SENECA_LINE_H
