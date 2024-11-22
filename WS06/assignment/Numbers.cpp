/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241101
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace seneca {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }

   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

   Numbers::~Numbers() {
       save();//Save the values in the file by calling the save method (see the [Save() method]
       delete[] m_numbers;
       delete[] m_filename;
   }

   Numbers::Numbers(const Numbers& src) {
       setEmpty();
       m_isOriginal = false;
       *this = src;//directly call the copy assignment operator overload method
   }

   Numbers& Numbers::operator=(const Numbers& src) {
       if (this != &src) {

           //clean up
           delete[] m_numbers;

           //shallow copy
           m_numCount = src.m_numCount;

           //deep copy
           if (src.m_numbers != nullptr) {
               //allocate memory
               m_numbers = new double[m_numCount];
               for (int i = 0; i < m_numCount; i++) {
                   m_numbers[i] = src.m_numbers[i];
               }
           }
           else {
               m_numbers = nullptr;
           }

       }
       return *this;
   }

   int Numbers::numberCount()const {
       ifstream file(m_filename);
       int linesCount = 0;
       char ch;

       if (file.is_open()) {
           while ((ch=file.get())!=EOF) {
               if (ch == '\n') {
                   ++linesCount;
               }
           }
           file.close();
       }

       return linesCount; 
   }

   bool Numbers::load() {

       if (m_numCount <= 0) {
           setEmpty();
           return false;
       }

       delete[] m_numbers;
       m_numbers = new double[m_numCount];

       ifstream file(m_filename);
       if (!file.is_open()) {
           setEmpty();
           return false;
       }

       int index = 0;
       while ( index < m_numCount && file >> m_numbers[index] ) {
           index++;
       }

       if (index != m_numCount) {
           delete[] m_numbers;
           setEmpty();
           return false;
       }

       return true;
   }

   void Numbers::save() {
       if (m_isOriginal &&  m_numCount > 0) {
           ofstream file(m_filename);

           if (file.is_open()) {
              
               for (int i = 0; i < m_numCount; i++) {
                   file << m_numbers[i] << '\n';
               }

               file.close();
           }
       }
   }

   Numbers& Numbers::operator+=(double val) {
       double* temp = new double[m_numCount + 1];

       for (int i = 0; i < m_numCount; i++) {
           temp[i] = m_numbers[i];
       }
       temp[m_numCount] = val;
       m_numCount++;

       delete[] m_numbers;
       m_numbers = temp;

       sort();

       return *this;
   }

   
   ostream& Numbers::display(ostream& ostr)const {
       if ( m_numCount > 0) {
           ostr << "=========================" << endl;
           if (m_isOriginal) {
               ostr << m_filename;
           }
           else {
               ostr << "*** COPY ***";
           }
           ostr << endl;

           ostr.setf(ios::fixed);
           ostr.precision(2);

           for (int i = 0; i < m_numCount; i++) {
               ostr << m_numbers[i] ;
               if (i < m_numCount - 1) {
                   ostr << ", ";
               }
           }
           ostr << endl;

           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;

           
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() << endl;
           ostr << "Average:         " << average() << endl;

           ostr.unsetf(ios::fixed);
           ostr.precision(6);

           ostr << "=========================";
       }
       else {
           ostr << "Empty list";
       }

       return ostr;
   }

   ostream& operator<<(ostream& os, const Numbers& N) {
       N.display(os);
       return os;
   }
   istream& operator>>(istream& istr, Numbers& N) {
       double value;
       if (istr >> value) {
           N += value;
       }
       return istr;
   }

}
