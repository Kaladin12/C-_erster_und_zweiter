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
	for (int  indice = 0; indice < 5; indice++)
	{
		cout << (pH+indice)<<" "<<*(pH+indice)<<endl;
	}
}

float* E3(float radio) {
	float Datos[3]; 
	Datos[0] = 3.14159 * (radio * radio);
	Datos[1] = 2 * 3.14159 * radio;
	Datos[2] = 2 * radio;float* pD = Datos;
	return pD;
}
int main() {
	//E1();
	E2(); float radio; cout << "Radio: "; cin >> radio;
	float* retorno=E3(radio);
	for (int  i = 0; i < 3; i++){
		cout << (retorno + i)  << endl;;
	}

	cin.get();
	return EXIT_SUCCESS;
}
