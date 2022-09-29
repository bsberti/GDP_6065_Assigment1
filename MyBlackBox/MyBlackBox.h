#pragma once

#include <iostream>

#ifdef  MYBLACKBOXLIBRARY_EXPORT
#define MYBLACKBOX_API __declspec(dllexport)
#else
#define MYBLACKBOX_API __declspec(dllimport)
#endif //  MYBLACKBOX_EXPORT

// Use extern "C" so C++ compiler does nott mess with
// the header we defined
extern "C" {
	MYBLACKBOX_API int Fibonacci(int v);
	MYBLACKBOX_API float MyRandom(float min, float max);
	MYBLACKBOX_API bool CPFSizeTest(const std::string cpfNumber);
	MYBLACKBOX_API bool CPFNumberTest(const std::string& cpfNumber);
	MYBLACKBOX_API std::string CPFOrigin(const std::string cpfNumber);
}