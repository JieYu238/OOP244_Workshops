#include <iostream>
#include "dma.h"
using namespace std;
namespace seneca {

	void reverse() {
		int num;//the number of doubleNumber
		double* doubleNumber = nullptr;//the address of the dynamic array
		int i;
		cout << "Enter the number of double values:\n> ";
		cin >> num;
		doubleNumber = new double[num];//// allocates dynamic memory
		for (i = 0; i < num; i++) {
			cout << (i + 1) << "> ";
			cin >> doubleNumber[i];
		}
		for (i = num-1; i >=0; i--) {
			cout << doubleNumber[i] << endl;
		}
		delete[] doubleNumber;
	}

	Contact* getContact() {
		Contact* contactInfo = new Contact;
		cout << "Name: ";
		cin.ignore(1000, '\n');//clear remainint newline characters in the input buffer
		cin.getline(contactInfo->m_name, 21);
		cout << "Last name: ";
		cin.getline(contactInfo->m_lastname, 31);
		cout << "Phone number: ";
		cin >> contactInfo->m_phoneNumber;
		cin.ignore(1000, '\n');
		return contactInfo;
	}

	void display(Contact& contactInfo) {
		cout << contactInfo.m_name << " " << contactInfo.m_lastname << ", +" << contactInfo.m_phoneNumber << endl;
	}

	void deallocate(Contact* contactInfo) {
		delete contactInfo;
	}

	void setEmpty(Contact& contactInfo) {
		contactInfo.m_name[0] = '\0';//set array to empty
		contactInfo.m_lastname[0] = '\0';
		contactInfo.m_phoneNumber = 0;
	}

}
