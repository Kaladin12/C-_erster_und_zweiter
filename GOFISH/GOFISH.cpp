#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
struct Cartas {
	string ArrCartas[4][13] = {"2 de Rombo","3 de Rombo","4 de Rombo","5 de Rombo","6 de Rombo","7 de Rombo","8 de Rombo","9 de Rombo","10 de Rombo","J de Rombo","Q de Rombo","K de Rombo","As de Rombo","2 de Trebol","3 de Trebol","4 de Trebol","5 de Trebol","6 de Trebol","7 de Trebol","8 de Trebol","9 de Trebol","10 de Trebol","J de Trebol","Q de Trebol","K de Trebol","As de Trebol" ,"2 de Corazon","3 de Corazon","4 de Corazon","5 de Corazon","6 de Corazon","7 de Corazon","8 de Corazon","9 de Corazon","10 de Corazon","J de Corazon","Q de Corazon","K de Corazon","As de Corazon" ,"2 de Espadas","3 de Espadas","4 de Espadas","5 de Espadas","6 de Espadas","7 de Espadas","8 de Espadas","9 de Espadas","10 de Espadas","J de Espadas","Q de Espadas","K de Espadas","As de Espadas" };
	bool Elegidas[4][13];
	string pool[32] = {"","","","","","","","","","","","","","","","" ,"","","","","","","","" ,"","","","","","","",""};
	string Jugadores[4][7] = {"","","","","","","","","","","","","","","","" ,"","","","","","" ,"","","","","","" };
	int Combinaciones[4][13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int contador_pool=0;
	int Ganadores[4] = { 0,0,0,0 };
}; Cartas gofish;
void Inicializa_Bool() {
	for (int i = 0; i < 4; i++){
		for (int i2 = 0; i2 < 13; i2++){
			gofish.Elegidas[i][i2] = false;
		}
	}
}
int num_random(int inicio, int limite) {
	return inicio + rand() % (1 + limite - inicio);
}
void repartir_cartas_inicio(int jugadores) {
	int rnd_1, rnd_2;
	for (int indice_1 = 0; indice_1 < jugadores; indice_1++){
		for (int indice_2 = 0; indice_2 < 5; indice_2++){
			rnd_1 = num_random(0, 3); rnd_2 = num_random(0, 12);
			if (gofish.Elegidas[rnd_1][rnd_2]){
				while (gofish.Elegidas[rnd_1][rnd_2]){
					rnd_1 = num_random(0, 3); rnd_2 = num_random(0, 12);
				}
			}
			gofish.Elegidas[rnd_1][rnd_2] = true;
			gofish.Jugadores[indice_1][indice_2] = gofish.ArrCartas[rnd_1][rnd_2]; 
		}
	}
}
void Comprobar_Carts(int jugador,int jugadores) {
	string cambiar = "";
	cout << "Sus cartas son: "<<endl;
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
void RemezlcarCartas() {
	int last_i = 0, indice=0, sub=0;
	for (auto i : gofish.pool) {
		gofish.ArrCartas[indice][sub] = i; sub += 1;
		if (sub >= 13) {
			sub = 0; indice += 1;
		}
	}
}

void Escoge_de_Piscina(int jugador) {
	if (gofish.contador_pool==0){
		cout << "La piscina esta vacia. Escoge algo de la baraja.\n";
		Escoge_de_Baraja(jugador);
	}
	else {
		gofish.Jugadores[jugador][5] = gofish.pool[0]; gofish.contador_pool -= 1;
		for (int indice = 0; indice < gofish.contador_pool; indice++){
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
	cout << "Cual desea cambiar?: "; cin >> cambiar;
	if (cambiar.length()==1)
		cambiar = cambiar+" ";
	for (int indice = 0; indice < 6; indice++){
		if (gofish.Jugadores[jugador][indice].substr(0,2)==cambiar){
			gofish.contador_pool += 1;
		 	Recorrer_pool(jugador ,gofish.Jugadores[jugador][indice]);
			for (int sindice = indice; sindice < 5; sindice++){
				gofish.Jugadores[jugador][sindice] = gofish.Jugadores[jugador][sindice+1];
			}
			gofish.Jugadores[jugador][5] = "";
			break;
		}
	}//system("cls");
	Comprobar_Carts(jugador,0);
}
void Escaleras(int jugador, int numcarta) {
	int conta = 0, indice_inicial=0;
	for (int indice = 0; indice < (13-numcarta); indice++){
		for (int i = 0; i < numcarta-1; i++){
			if (gofish.Combinaciones[jugador][indice+i] == gofish.Combinaciones[jugador][indice+i + 1]) {
				conta += 1; indice_inicial = indice;
			}
		}
	}
	if (conta==5){
		if (indice_inicial == 8)
			cout << "Escalera Chida" << endl;
		else
			cout << "Escalera" << endl;
	}
}
void Combinaciones(int jugador, int numcarta) {
	for (int indice = 0; indice < numcarta; indice++) {
		for (int subidnice = 0; subidnice < 13; subidnice++) {
			if (gofish.Jugadores[jugador][indice].substr(0, 2) == gofish.ArrCartas[0][subidnice].substr(0, 2)) {
				gofish.Combinaciones[jugador][subidnice] += 1;
			}
		}
	}cout << endl;
	cout << "Tus combinaciones son: "<<endl;
	for (int indice = 0; indice < 13; indice++){
		if (gofish.Combinaciones[jugador][indice] == 0)
			cout << "";
		else if (gofish.Combinaciones[jugador][indice] == 2)
			cout << "Par de " << gofish.ArrCartas[0][indice].substr(0, 2) << endl;
		else if (gofish.Combinaciones[jugador][indice] == 3)
			cout << "Tercia de " << gofish.ArrCartas[0][indice].substr(0, 2) << endl;
		else if (gofish.Combinaciones[jugador][indice] == 4)
			cout << "Poker de " << gofish.ArrCartas[0][indice].substr(0, 2) << endl;
		else
			Escaleras(jugador,numcarta);
	}
	for (int indice = 0; indice < 13; indice++)
		gofish.Combinaciones[jugador][indice] = 0;
}
int suma(int numcarta) {
	for (int indice = 0; indice < numcarta; indice++){
		for (int i = 0; i < 6; i++){
			if (gofish.Jugadores[indice][i].substr(0, 2) == "K " || gofish.Jugadores[indice][i].substr(0, 2) == "Q " || gofish.Jugadores[indice][i].substr(0, 2) == "J "|| gofish.Jugadores[indice][i].substr(0, 2) == "10")
				gofish.Ganadores[indice] += 10;
			else
				gofish.Ganadores[indice] += stoi(gofish.Jugadores[indice][i].substr(0, 1));
		}
	}
	if (gofish.Ganadores[0] > gofish.Ganadores[1] && gofish.Ganadores[0] > gofish.Ganadores[2] && gofish.Ganadores[0] > gofish.Ganadores[3])
		return 0;
	else if (gofish.Ganadores[1] > gofish.Ganadores[0] && gofish.Ganadores[1] > gofish.Ganadores[2] && gofish.Ganadores[1] > gofish.Ganadores[3])
		return 1;
	else if (gofish.Ganadores[2] > gofish.Ganadores[0] && gofish.Ganadores[2] > gofish.Ganadores[1] && gofish.Ganadores[2] > gofish.Ganadores[3])
		return 2;
	else if (gofish.Ganadores[3] > gofish.Ganadores[0] && gofish.Ganadores[3] > gofish.Ganadores[1] && gofish.Ganadores[3] > gofish.Ganadores[2])
		return 3;
}
int Gnador(int numcarta) {
	for (int jugador = 0; jugador < numcarta; jugador++){
		for (int indice = 0; indice < numcarta; indice++) {
			for (int subidnice = 0; subidnice < 13; subidnice++) {
				if (gofish.Jugadores[jugador][indice].substr(0, 2) == gofish.ArrCartas[0][subidnice].substr(0, 2)) {
					gofish.Combinaciones[jugador][subidnice] += 1;}}}
		for (int indice = 0; indice < 13; indice++) {
			if (gofish.Combinaciones[jugador][indice] == 2)
				gofish.Ganadores[jugador] = 1;
			else if (gofish.Combinaciones[jugador][indice] == 3)
				gofish.Ganadores[jugador] = 2;
			else if (gofish.Combinaciones[jugador][indice] == 4)
				gofish.Ganadores[jugador] = 3;
			else{
				int conta = 0, indice_inicial = 0;
				for (int indice = 0; indice < (13 - numcarta); indice++) {
					for (int i = 0; i < numcarta - 1; i++) {
						if (gofish.Combinaciones[jugador][indice + i] == gofish.Combinaciones[jugador][indice + i + 1]) {
							conta += 1; indice_inicial = indice;
						}}}
				if (conta == 5) {
					if (indice_inicial == 8)
						gofish.Ganadores[jugador] = 5;
					else
						gofish.Ganadores[jugador] = 4;
				}}}}
	if (gofish.Ganadores[0] > gofish.Ganadores[1] && gofish.Ganadores[0] > gofish.Ganadores[2] && gofish.Ganadores[0] > gofish.Ganadores[3])
		return 0;
	else if (gofish.Ganadores[1] > gofish.Ganadores[0] && gofish.Ganadores[1] > gofish.Ganadores[2] && gofish.Ganadores[1] > gofish.Ganadores[3])
		return 1;
	else if (gofish.Ganadores[2] > gofish.Ganadores[0] && gofish.Ganadores[2] > gofish.Ganadores[1] && gofish.Ganadores[2] > gofish.Ganadores[3])
		return 2;
	else if (gofish.Ganadores[3] > gofish.Ganadores[0] && gofish.Ganadores[3] > gofish.Ganadores[1] && gofish.Ganadores[3] > gofish.Ganadores[2])
		return 3;
	else
		return suma(numcarta);
}
int main(){
	srand(time(NULL));
	Inicializa_Bool(); int respuesta = 0, indice = 0; string salir = "", baraja_o_pool; bool out = false;
	do{
		cout << "Ingrese numero de jugadores: \n[2]--2 Jugadores\n[3]--3 Jugadores\n[4]--4 Jugadores\n"; cin >> respuesta;
		repartir_cartas_inicio((respuesta)); 
		while (out==false){
			Comprobar_Carts(indice, respuesta);
			Combinaciones(indice,6);
			cout << "Deseas Plantarte o Continuar?: \n[P]--Plantarte\n[C]--Continuar\n"; cin >> baraja_o_pool;
			if (baraja_o_pool=="C"){
				cout << "De donde deseas obtener tu carta?: \n[a]--Pool (La primera carta del pool es) : " << gofish.pool[0] << "\n[b]--Baraja\n"; cin >> baraja_o_pool;
				if (baraja_o_pool == "a")
					Escoge_de_Piscina(indice);
				else
					Escoge_de_Baraja(indice); system("cls");
				Combinaciones(indice, 5);
				Dejar_Carta(indice);
			}
			else if (baraja_o_pool == "P") {
				system("cls"); cout << "Le queda un turno a cada jugador" << endl; int sindice = indice+1;
				while(sindice!=indice) {
					Comprobar_Carts(sindice, respuesta);
					Combinaciones(sindice, 6);
					cout << "De donde deseas obtener tu carta?: \n[a]--Pool (La primera carta del pool es) : " << gofish.pool[0] << "\n[b]--Baraja\n"; cin >> baraja_o_pool;
					if (baraja_o_pool == "a")
						Escoge_de_Piscina(sindice);
					else
						Escoge_de_Baraja(sindice); system("cls");
					Combinaciones(sindice, 5);
					Dejar_Carta(sindice); sindice += 1; if (sindice >= respuesta) sindice = 0;
				}
				cout << Gnador(respuesta) << "ha ganado"; out = true; break;
			}
			indice += 1;system("cls");
			if (indice>=respuesta)
				indice = 0;
		} 
		salir == "y";
	} while (salir!="y");
	cin.ignore(); system("pause");
	return EXIT_SUCCESS;
}

