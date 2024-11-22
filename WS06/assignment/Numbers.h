/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241101
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/
#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>
namespace seneca {
   class Numbers {

      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
      int numberCount()const;

   public:
      Numbers();
      Numbers(const char* filename);
      double average()const;
      double max()const;
      double min()const;

      ~Numbers();
      Numbers(const Numbers& src);
      Numbers& operator=(const Numbers& src);
      bool load();
      void save();
      Numbers& operator+=(double val);
      std::ostream& display(std::ostream& ostr)const;
     
   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SENECA_NUMBERS_H_

