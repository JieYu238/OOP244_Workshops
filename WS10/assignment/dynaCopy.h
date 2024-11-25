/********************************************************************************************************************************
Name:   Jie Yu
Student ID: 152519237
Email:  jyu238@myseneca.ca
Date:   20241129
*********************************************************************************************************************************
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*********************************************************************************************************************************
********************************************************************************************************************************/
#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H
#include"Utils.h"

namespace seneca {
	
	template<typename T>
	T* dynaCopy(const T* src, int size) {
		if (!src) return nullptr;

		T* res = new T[size];
		for (int i = 0; i < size; i++) {
			res[i] = src[i];
		}
		return res;
	}

	template<>
	char* dynaCopy(const char* src, int size) {
		if (!src) return nullptr;

		char* res = new char[size+1];
		ut.strcpy(res, src, size);
		return res;
	}

	template<typename T>
	T* dynaCopy(T*& des, const T* src, int size) {
		if (des) delete[] des;
		des = dynaCopy(src, size);
		return des;
	}

	template<typename T>
	void prnArray(const T* array, int size) {
		for (int i = 0; i < size; i++) {
			if (i) std::cout << ", ";
			std::cout << array[i];
		}
		std::cout << std::endl;
	}


}

#endif // !SENECA_DYNACOPY_H

