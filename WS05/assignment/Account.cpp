/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241011
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool()const {
       return m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0;
   }

   Account::operator int()const {
       return m_number;
   }

   Account::operator double()const {
       return m_balance;
   }

   bool Account::operator~()const {
       return m_number == 0;
   }
 
   Account& Account::operator=(int a_number) {
       if (m_number == 0) {
           if (a_number >= 10000 && a_number <= 99999) {
               m_number = a_number;
           }
           else {
               setEmpty();
           }
           
       }
       return *this;
   }

   Account& Account::operator=(Account& account) {
       if (m_number == 0 && account.m_number >= 10000 && account.m_number <= 99999 && account.m_balance >= 0.0) {
           m_number = account.m_number;
           m_balance = account.m_balance;
           account.m_number = 0;
           account.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator+=(double add_balance) {
       if (*this && add_balance >= 0.0) {
           m_balance += add_balance;
       }
       return *this;
   }

   Account& Account::operator-=(double red_balance) {
       if (*this && red_balance >= 0.0 && m_balance >= red_balance) {
           m_balance -= red_balance;
       }
       return *this;
   }

   Account& Account::operator<<(Account& account) {
       if (this != &account && *this && account) {
           m_balance += account.m_balance;
           account.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& account) {
       if (this != &account && *this && account) {
           account.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   double operator+(const Account& account1, const Account& account2) {
       if (account1 && account2) {
           return double(account1) + double(account2);
       }
       else {
           return 0.0;
       }
   }

   double operator+=(double& balance, const Account& account) {
       return balance += double(account);
   }
}