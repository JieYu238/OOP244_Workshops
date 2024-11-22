/////////////////////////////////////////////////////////////////
// Name: Jie Yu
// Email: jyu238@myseneca.ca
// Student ID: 152519237
// Date: 20240919
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {

   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }

   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const {
       if (name == nullptr || strlen(name) < 3) {
           return false;
       }
       if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull) {
           return false;
       }
       if (cvv < 100 || cvv > 999) {
           return false;
       }
       if (expMon < 1 || expMon > 12) {
           return false;
       }
       if (expYear < 24 || expYear > 32) {
           return false;
       }
       return true;
   }
   


   void CC::prnNumber(unsigned long long CCnum) const {
       unsigned long long divisor = 1000000000000ull;
       for (int i = 0; i < 4; ++i) {
           unsigned long long group = CCnum / divisor;
           string groupStr = to_string(group);//convert number to string groupStr
           while (groupStr.length() < 4) {      //compare if it exists 0 before the groupStr
               groupStr = "0" + groupStr;       //create a new string consisting of 0 followed by groupStr
           }
           cout << groupStr;
           CCnum %= divisor;
           divisor /= 10000;
           if (i < 3) {
               cout << " ";
           }
       }
   }

   void CC::set() {
       name = nullptr;
       number = 0;
       expYear = 0;
       expMonth = 0;
       cvv = 0;
   }

   void CC::cleanUp() {
       freeMem(name);
       set();
   }

   bool CC::isEmpty()const {
       return name == nullptr;
   }

   void CC::set(const char* cc_name, unsigned long long cc_no, short m_cvv, short m_expMon, short m_expYear) {
       cleanUp();
       if (validate(cc_name, cc_no, m_cvv, m_expMon, m_expYear)) {
           alocpy(name, cc_name);
           number = cc_no;
           cvv = m_cvv;
           expYear = m_expYear;
           expMonth = m_expMon;
       }
   }
   
   void CC::display()const {
       if (isEmpty()) {
           cout << "Invalid Credit Card Record" << endl;
       }
       else
       {
           display(name, number, expYear, expMonth, cvv);
       }
   }
}