#include <iostream>
#include <string>

using namespace std; string simbolo = "*", espacio = " ";
void  Dibuja_Tejado() {
	int contador = 10, a=1, distancia_max=20, distancia_min=15, k=0;
	while (contador>=0){
		for (int indice = 0; indice < contador+1; indice++)
			cout << espacio;
		if (contador == 10) {
			for (int indce = 0; indce < 25; indce++)
				cout << simbolo;
			cout << endl;
		}
		else if (contador>4&&contador<7) {
			cout << simbolo; int i = 0;
			for (int indice = 0; indice < 4; indice++) {
				cout << espacio;
			}cout << simbolo;
			for (int indice = 0; indice < 2+k; indice++) {
				cout << espacio;
			}cout << simbolo; 
			for (int indice = 0; indice < 4; indice++) {
				cout << espacio;
			}cout << simbolo;
			for (int indice = 0; indice < distancia_max; indice++)
				cout << espacio;
			cout << simbolo << endl;
		}
		else {
			cout << simbolo; int i = 0;
			for (int indice = 0; indice < 11 - contador; indice++) {
				cout << espacio<<espacio;
			}
			cout << simbolo;
			for (int indice = 0; indice < distancia_max; indice++)
				cout << espacio;
			cout <<simbolo<< endl;
		}
		contador -= 1;  a = a + 1;
	}
	for (int indice = 0; indice < 15; indice++){
		if (indice==0){
			for (int i = 0; i < 47; i++)
				cout << simbolo;
			cout << endl;
		}
		else if (indice == 9) {
			cout << simbolo;
			for (int i = 0; i < 9; i++)
				cout << espacio;
			for (int i = 0; i < 6; i++)
				cout << simbolo;
			for (int i = 0; i < 9; i++) {
				cout << espacio;
			}cout << simbolo;
			for (int i = 0; i < 20; i++) {
				cout << espacio;
			}cout << simbolo << endl;
		}
		else if (indice > 9) {
			cout << simbolo;
			for (int i = 0; i < 9; i++) {
				cout << espacio;
			}cout << simbolo;
			for (int i = 0; i < 4; i++) {
				cout << espacio;
			}cout << simbolo;
			for (int i = 0; i < 9; i++) {
				cout << espacio;
			}cout << simbolo;
			for (int i = 0; i < 20; i++) {
				cout << espacio;
			}cout << simbolo << endl;
		}
		else{
			cout << simbolo;
			for (int i = 0; i < 24; i++) {
				cout << espacio;
			}cout << simbolo;
			for (int i = 0; i < 20; i++) {
				cout << espacio;
			}cout << simbolo<<endl;
		}
	}
	for (int indice = 0; indice < 47; indice++)
		cout << simbolo;
}

int main()
{
	Dibuja_Tejado();
	system("pause");
	return EXIT_SUCCESS;
}
