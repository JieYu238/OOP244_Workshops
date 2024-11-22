/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241115
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/

#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {

   class Rectangle : public LblShape {
      // Width of the rectangle
      // Height of the rectangle
       size_t m_width;
       size_t m_height;
   public:
      // Default constructor
       Rectangle();

      // Constructor that initializes label, width, and height
       Rectangle(const char* label, size_t width, size_t height);

      // Draws the rectangle using the label, width, and height
       void draw(std::ostream& out)const;

      // Gets specifications of the rectangle (label, width, height) from input
       void getSpecs(std::istream& in);
   };

}

#endif // !SENECA_RECTANGLE_H
