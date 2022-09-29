#include "MyBlackBox.h"
#include "pch.h"
#include <iostream>
#include <random>

// F = Fibonacci
// F(4) = F(3) + F(2)
// F(3) = F(2) + F(1)
// F(2) = 1
// F(1) = 1
int Fibonacci(int v) {
	if (v == 2 || v == 1)
		return 1;

	return Fibonacci(v - 1) + Fibonacci(v - 2);
}
bool CPFSizeTest(const std::string cpfNumber) {
	//std::cout << cpfNumber.length();
	if (cpfNumber.length() != 11) {
		// All CPF Numbers are 11 digits
		return false;
	}
	return true;
}

bool CPFNumberTest(const std::string& cpfNumber) {
	for (char const& c : cpfNumber) {
		if (std::isdigit(c) == 0) return false;
	}
	return true;
}

/*0 - Rio Grande do Sul (RS)
1 - Distrito Federal(DF), Goi�s(GO), Mato Grosso do Sul(MS) e Tocantins(TO)
2 - Par�(PA), Amazonas(AM), Acre(AC), Amap�(AP), Rond�nia(RO) e Roraima(RR)
3 - Cear�(CE), Maranh�o(MA) e Piau�(PI)
4 - Pernambuco(PE), Rio Grande do Norte(RN), Para�ba(PB) e Alagoas(AL)
5 - Bahia(BA) e Sergipe(SE)
6 - Minas Gerais(MG)
7 - Rio de Janeiro(RJ) e Esp�rito Santo(ES)
8 - S�o Paulo(SP)
9 - Paran�(PR) e Santa Catarina(SC)*/
std::string CPFOrigin(const std::string cpfNumber) {
	switch (cpfNumber[cpfNumber.length() - 3]) {
	default:
		break;
	case '0':
		return "RS";
		break;
	case '1':
		return "DF-GO-MS-TO";
		break;
	case '2':
		return "PA-AM-AC-AP-RO-RR";
		break;
	case '3':
		return "CE-MA-PI";
		break;
	case '4':
		return "PE-RN-PB-AL";
		break;
	case '5':
		return "BA-SE";
		break;
	case '6':
		return "MG";
		break;
	case '7':
		return "RJ-ES";
		break;
	case '8':
		return "SP";
		break;
	case '9':
		return "PR-SC";
		break;
	}
}

float MyRandom(float min, float max) {
	if (max == min)
		return 0.f;

	int diff = (max - min) * 1000;
	return min + (rand() % diff) / 1000.f;
}