/////////////////////////////////////////////////////////////////
// Name: Jie Yu
// Email: jyu238@myseneca.ca
// Student ID: 152519237
// Date: 20240919
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
#include<string>
namespace seneca {
   class CC {
       char* name;
       unsigned long long number;
       short expYear;
       short expMonth;
       short cvv;
      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
      bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const;
      void prnNumber(unsigned long long CCnum)const;
   public:
       void set();
       void cleanUp();
       bool isEmpty()const;
       void set(const char* cc_name, unsigned long long cc_no, short m_cvv, short m_expMon = 12, short m_expYear = 24);
       void display()const;
   };

}
#endif // !SENECA_CC_H_


