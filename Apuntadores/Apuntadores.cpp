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

float* E3(float radio) {
	float Datos[3] = {0,0,0};
	Datos[0] = 3.14159 * (radio * radio);
	Datos[1] = 2 * 3.14159 * radio;
	Datos[2] = 2 * radio; float* pD = Datos;
	return pD;
}
int main() {
	string eleccion = "";
	do {
		cout << "\nESCOGE ALGO: \n[a]--Ejercicio 1\n[b]--Ejercicio 2\n[c]--Ejercicio 3\n"; cin >> eleccion;
		if (eleccion == "a")
			E1();
		else if (eleccion == "b")
			E2();
		else if (eleccion=="c") {
			float radio; cout << "Radio: "; cin >> radio; float* ptr = E3(radio);
			cout << "Area: " << ptr[0] << "\nCircunferencia " << ptr[1] << "\nDiametro " << ptr[2];
		}
	} while (eleccion=="a"|| eleccion == "b"|| eleccion == "c");
	cin.get();
	return EXIT_SUCCESS;
}