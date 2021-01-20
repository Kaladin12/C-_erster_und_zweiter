#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
struct Cartas {
	string ArrCartas[4][13] = { "2 de Rombo","3 de Rombo","4 de Rombo","5 de Rombo","6 de Rombo","7 de Rombo","8 de Rombo","9 de Rombo","10 de Rombo","J de Rombo","Q de Rombo","K de Rombo","As de Rombo","2 de Trebol","3 de Trebol","4 de Trebol","5 de Trebol","6 de Trebol","7 de Trebol","8 de Trebol","9 de Trebol","10 de Trebol","J de Trebol","Q de Trebol","K de Trebol","As de Trebol" ,"2 de Corazon","3 de Corazon","4 de Corazon","5 de Corazon","6 de Corazon","7 de Corazon","8 de Corazon","9 de Corazon","10 de Corazon","J de Corazon","Q de Corazon","K de Corazon","As de Corazon" ,"2 de Espadas","3 de Espadas","4 de Espadas","5 de Espadas","6 de Espadas","7 de Espadas","8 de Espadas","9 de Espadas","10 de Espadas","J de Espadas","Q de Espadas","K de Espadas","As de Espadas" };
	bool Elegidas[4][13];
	string pool[32] = { "","","","","","","","","","","","","","","","" ,"","","","","","","","" ,"","","","","","","","" };
	string Jugadores[4][7] = { "","","","","","","","","","","","","","","","" ,"","","","","","" ,"","","","","","" };
	int Combinaciones[4][13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int contador_pool = 0;
	bool Ganadores[4][7] = { false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false };
	int suma[4] = { 0,0,0,0 };
}; Cartas gofish;
int mayor = -1, mayor_1 = -1, jug = -1; bool out = false, seis = false, escalera=false;
void Inicializa_Bool() {
	for (int i = 0; i < 4; i++) {
		for (int i2 = 0; i2 < 13; i2++) {
			gofish.Elegidas[i][i2] = false;
		}
	}
}
int num_random(int inicio, int limite) {
	return inicio + rand() % (1 + limite - inicio);
}
void repartir_cartas_inicio(int jugadores) {
	int rnd_1, rnd_2;
	for (int indice_1 = 0; indice_1 < jugadores; indice_1++) {
		for (int indice_2 = 0; indice_2 < 5; indice_2++) {
			rnd_1 = num_random(0, 3); rnd_2 = num_random(0, 12);
			if (gofish.Elegidas[rnd_1][rnd_2]) {
				while (gofish.Elegidas[rnd_1][rnd_2]) {
					rnd_1 = num_random(0, 3); rnd_2 = num_random(0, 12);
				}
			}
			gofish.Elegidas[rnd_1][rnd_2] = true;
			gofish.Jugadores[indice_1][indice_2] = gofish.ArrCartas[rnd_1][rnd_2];
		}
	}
}
void Comprobar_Carts(int jugador, int jugadores) {
	string cambiar = "";
	cout << "Sus cartas son: " << endl;
	for (int indice_2 = 0; indice_2 < 7; indice_2++) {
		cout << gofish.Jugadores[jugador][indice_2] << " ";
	}cout << endl;
}
void Escoge_de_Baraja(int jugador) {
	int indice = num_random(0, 3), subidncie = num_random(0, 12);
	if (gofish.Elegidas[indice][subidncie]) {
		while (gofish.Elegidas[indice][subidncie]) {
			indice = num_random(0, 3); subidncie = num_random(0, 12);
		}
	}
	cout << "Tu carta es: " << gofish.ArrCartas[indice][subidncie] << endl;
	gofish.Elegidas[indice][subidncie] = true;
	gofish.Jugadores[jugador][5] = gofish.ArrCartas[indice][subidncie];
	Comprobar_Carts(jugador, 0);
}
void Escoge_de_Piscina(int jugador) {
	if (gofish.contador_pool == 0) {
		cout << "La piscina esta vacia. Escoge algo de la baraja.\n";
		Escoge_de_Baraja(jugador);
	}
	else {
		gofish.Jugadores[jugador][5] = gofish.pool[0]; gofish.contador_pool -= 1;
		for (int indice = 0; indice < gofish.contador_pool; indice++) {
			gofish.pool[indice] = gofish.pool[indice + 1];
		} gofish.pool[gofish.contador_pool + 1] = "";
	}
}
void Recorrer_pool(int jugador, string cambio) {
	string auxiliar = gofish.pool[0]; gofish.pool[0] = cambio; int contador = gofish.contador_pool;
	while (contador >= 1) {
		gofish.pool[contador] = gofish.pool[contador - 1]; contador -= 1;
	}
	gofish.pool[0] = cambio;
}
void Dejar_Carta(int jugador) {
	Comprobar_Carts(jugador, 0); string cambiar;
	cout << "\nPara dejar una carta ingrese su valor: Ejemplo--Escriba K si desea dejar un K\n\nCual desea cambiar?: "; cin >> cambiar;
	if (cambiar.length() == 1)
		cambiar = cambiar + " ";
	for (int indice = 0; indice < 6; indice++) {
		if (gofish.Jugadores[jugador][indice].substr(0, 2) == cambiar) {
			gofish.contador_pool += 1;
			Recorrer_pool(jugador, gofish.Jugadores[jugador][indice]);
			for (int sindice = indice; sindice < 5; sindice++) {
				gofish.Jugadores[jugador][sindice] = gofish.Jugadores[jugador][sindice + 1];
			}
			gofish.Jugadores[jugador][5] = "";
			break;
		}
	}
	Comprobar_Carts(jugador, 0);
}
void Escaleras(int jugador, int numcarta) {
	int Auxiliar[6] = { 0,0,0,0,0,0 };
	for (int indice = 0; indice < numcarta-1; indice++) {
		if (gofish.Jugadores[jugador][indice].substr(0, 2) == "J ")
			Auxiliar[indice] = 11;
		else if (gofish.Jugadores[jugador][indice].substr(0, 2) == "Q ")
			Auxiliar[indice] = 12;
		else if (gofish.Jugadores[jugador][indice].substr(0, 2) == "K ")
			Auxiliar[indice] = 13;
		else if (gofish.Jugadores[jugador][indice].substr(0, 2) == "As")
			Auxiliar[indice] = 14;
		else if (gofish.Jugadores[jugador][indice].substr(0, 2) == "10")
			Auxiliar[indice] = 10;
		else {
			string ind = gofish.Jugadores[jugador][indice].substr(0, 1);
			Auxiliar[indice] = stoi(ind);
		}
	}
	int auxiliar;
	for (int indice = 0; indice < numcarta-1; indice++) {
		for (int ibindice = 0; ibindice < numcarta - 1; ibindice++) {
			if (Auxiliar[ibindice] > Auxiliar[ibindice + 1]) {
				auxiliar = Auxiliar[ibindice];	
				Auxiliar[ibindice] = Auxiliar[ibindice+1]; 
				Auxiliar[ibindice+1] = auxiliar;
			}
		}
	}
	if ((Auxiliar[0] == Auxiliar[1] - 1 && Auxiliar[0] == Auxiliar[2] - 2 && Auxiliar[0] == Auxiliar[3] - -3 && Auxiliar[0] == Auxiliar[4] - 4) || (Auxiliar[1] == Auxiliar[2] - 1 && Auxiliar[1] == Auxiliar[3] - 2 && Auxiliar[1] == Auxiliar[4] - 3 && Auxiliar[1] == Auxiliar[5] - 4)) {
		if ((Auxiliar[5] == 14 && Auxiliar[4]==13)||(Auxiliar[4] == 14 && Auxiliar[3] == 13)) {
			cout << "Escalera Chida" << endl; gofish.Ganadores[jugador][6] = true; escalera = true;
		}
		else {
			cout << "Escalera" << endl; gofish.Ganadores[jugador][5] = true; escalera = true;
		}
	}
	else if ((Auxiliar[0] == Auxiliar[1] && Auxiliar[0] == Auxiliar[2] && Auxiliar[0] == Auxiliar[3]) && (Auxiliar[1] == Auxiliar[2] && Auxiliar[1] == Auxiliar[3] && Auxiliar[1] == Auxiliar[4]) || (Auxiliar[2] == Auxiliar[3] && Auxiliar[2] == Auxiliar[4] && Auxiliar[2] == Auxiliar[5])) {
		cout << "Poker " << endl; gofish.Ganadores[jugador][4] = true;
	}
}
void Combinaciones(int jugador, int numcarta) {
	int contador_dos = 0;  escalera = false;
	for (int indice = 0; indice < numcarta; indice++) {
		for (int subidnice = 0; subidnice < 13; subidnice++) {
			if (gofish.Jugadores[jugador][indice].substr(0, 2) == gofish.ArrCartas[0][subidnice].substr(0, 2)) {
				gofish.Combinaciones[jugador][subidnice] += 1;
			}
		}
	}cout << endl;
	cout << "Tus combinaciones son: " << endl;
	for (int indice = 0; indice < 13; indice++) {
		if (gofish.Combinaciones[jugador][indice] == 0)
			cout << "";
		else if (gofish.Combinaciones[jugador][indice] == 2) {
			cout << "Par de " << gofish.ArrCartas[0][indice].substr(0, 2) << endl; gofish.Ganadores[jugador][0] = true; contador_dos += 1;
			if (contador_dos == 3) { gofish.Ganadores[jugador][1] = true; cout << "TRES" << endl; }
		}
		else if (gofish.Combinaciones[jugador][indice] == 3) {
			cout << "Tercia de " << gofish.ArrCartas[0][indice].substr(0, 2) << endl; gofish.Ganadores[jugador][2] = true;
			if (gofish.Ganadores[jugador][0] = true)
				gofish.Ganadores[jugador][3] = true;
		}
			Escaleras(jugador, numcarta); if (escalera) break; 
		/*else if (gofish.Combinaciones[jugador][indice] == 4) {
		cout << "Poker de " << gofish.ArrCartas[0][indice].substr(0, 2) << endl; gofish.Ganadores[jugador][4] = true;
		}*/
	}
	for (int indice = 0; indice < 13; indice++)
		gofish.Combinaciones[jugador][indice] = 0;
}

void Suma(int num_jugadores) {
	for (int indice = 0; indice < num_jugadores; indice++) {
		gofish.suma[indice] = 0;
	}
	for (int jugador = 0; jugador < num_jugadores; jugador++) {
		for (int indice = 0; indice < 6; indice++) {
			for (int subindice = 0; subindice < 13; subindice++) {
				if (gofish.ArrCartas[0][subindice].substr(0, 2) == gofish.Jugadores[jugador][indice].substr(0, 2)) {
					if (gofish.Jugadores[jugador][indice].substr(0, 2) == "10" || gofish.Jugadores[jugador][indice].substr(0, 2) == "J " || gofish.Jugadores[jugador][indice].substr(0, 2) == "Q " || gofish.Jugadores[jugador][indice].substr(0, 2) == "K ")
						gofish.suma[jugador] += 10;
					else if (gofish.Jugadores[jugador][indice].substr(0, 2) == "As")
						gofish.suma[jugador] += 11;
					else
						gofish.suma[jugador] += stoi(gofish.Jugadores[jugador][indice].substr(0, 2));
				}
			}
		}
	} mayor = -1;
	for (int indice = 0; indice < num_jugadores - 1; indice++) {
		if (gofish.suma[indice] > gofish.suma[indice]) {
			jug = indice;
		}
	}
}

void Ganador(int jugadores, int numcartas) {
	for (int jugador = 0; jugador < jugadores; jugador++) {
		for (int indice = 0; indice < 6; indice++) {
			if (gofish.Ganadores[jugador][indice]) {
				if (mayor <= indice) {
					mayor_1 = mayor; mayor = indice; jug = jugador;
				}
			}
		}
	}
	if (mayor_1 == mayor) {
		Suma(jugadores);
	}
}

void SalirSeisCartas(int jugador) {
	int contador = 0;
	if (gofish.Ganadores[jugador][1]) {//|| gofish.Ganadores[jugador][3] || gofish.Ganadores[jugador][4] || gofish.Ganadores[jugador][5] || gofish.Ganadores[jugador][6]
		out = true; jug = jugador; seis = true;
	}
}

int main() {
	srand(time(NULL));
	Inicializa_Bool(); int respuesta = 0, contador_baraja = 0, indice = 0; string salir = "", baraja_o_pool;
	do {
		cout << "Ingrese numero de jugadores: \n[2]--2 Jugadores\n[3]--3 Jugadores\n[4]--4 Jugadores\n"; cin >> respuesta; system("cls");
		repartir_cartas_inicio((respuesta));
		while (out == false) {
			Comprobar_Carts(indice, respuesta);
			Combinaciones(indice, 6); SalirSeisCartas(indice); if (out) break;
			cout << "Deseas Plantarte o Continuar?: \n[P]--Plantarte\n[C]--Continuar\n"; cin >> baraja_o_pool; system("cls");
			if (baraja_o_pool == "C") {
				cout << "De donde deseas obtener tu carta?: \n[a]--Pool (La primera carta del pool es) : " << gofish.pool[0] << "\n[b]--Baraja\n"; cin >> baraja_o_pool;
				if (baraja_o_pool == "a")
					Escoge_de_Piscina(indice);
				else
					Escoge_de_Baraja(indice); system("cls");
				Combinaciones(indice, 6);
				SalirSeisCartas(indice); if (out) break;
				Dejar_Carta(indice);
				Combinaciones(indice, 5);
			}
			else if (baraja_o_pool == "P") {
				system("cls"); cout << "Le queda un turno a cada jugador" << endl; int sindice = indice + 1; if (sindice >= respuesta) sindice = 0;
				while (sindice != indice) {
					Comprobar_Carts(sindice, respuesta);
					Combinaciones(sindice, 6); SalirSeisCartas(indice); if (out) break;
					cout << "De donde deseas obtener tu carta?: \n[a]--Pool (La primera carta del pool es) : " << gofish.pool[0] << "\n[b]--Baraja\n"; cin >> baraja_o_pool;
					if (baraja_o_pool == "a")
						Escoge_de_Piscina(sindice);
					else
						Escoge_de_Baraja(sindice); system("cls");
					Combinaciones(indice, 6);
					SalirSeisCartas(indice); if (out) break;
					Dejar_Carta(sindice); Combinaciones(sindice, 5); sindice += 1; if (sindice >= respuesta) sindice = 0; system("cls");
				} out = true;
				break;
			}
			indice += 1; system("cls");
			if (indice >= respuesta)
				indice = 0;//Agregar la salida si se acaban la baraja
			for (int indice = 0; indice < 4; indice++) {
				for (int sindice = 0; sindice < 13; sindice++) {
					if (gofish.Elegidas[indice][sindice] == false)
						contador_baraja += 1;
				}
			}
			if (contador_baraja == 0)
				out = true;
			system("cls");
		} Suma(respuesta);
		if (seis == false)
			Ganador(respuesta, 5);
		cout << "El ganador es el jugador " << jug + 1 << endl;
		salir = "y";
	} while (salir != "y");
	cin.ignore(); system("pause");
	return EXIT_SUCCESS;
}