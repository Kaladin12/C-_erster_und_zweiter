#include <iostream>
#include <string>

using namespace std;
void E1() {
	int A = 5; int* pA = &A;
	cout << pA << " " << *pA;
}

void E2() {
	int H4[5] = { 2,4,6,8,10 };
	int* pH = H4;
	for (int indice = 0; indice < 5; indice++)
	{
		cout << (pH + indice) << " " << *(pH + indice) << endl;
	}
}

double* E3(double radio) {
	double Datos[3]; double* pD; double pi = 3.14159;
	Datos[0] = pi * (radio * radio);
	Datos[1] = 2 * pi * radio;
	Datos[2] = 2 * radio;
	return pD;
}
int main() {
	//E1();
	E2(); double radio; cout << "Radio: "; cin >> radio;
	double* retorno = E3(radio);
	for (int i = 0; i < 3; i++) {
		cout << (retorno + i) << " " << retorno[i] << endl;;
	}

	cin.get();
	return EXIT_SUCCESS;
}