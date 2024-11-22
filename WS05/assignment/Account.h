/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241011
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      

      operator bool()const;
        
      operator int()const;

      operator double()const;
     
      bool operator ~()const;
  
      Account& operator=(int a_number);

      Account& operator=(Account& account);

      Account& operator+=(double add_balance);

      Account& operator-=(double red_balance);

      Account& operator<<(Account& account);

      Account& operator>>(Account& account);
   };

   double operator+(const Account& account1, const Account& account2);

   double operator+=(double& balance, const Account& account);

}
#endif // SENECA_ACCOUNT_H_