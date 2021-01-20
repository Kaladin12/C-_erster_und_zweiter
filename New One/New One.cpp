#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <thread>
#include <locale>
#include <stdlib.h>
#include "Personajes.h"
#include <cstdlib>
using namespace std;

struct Skill {
	string name[2];
	string descp[2];
	int manaCost;
	int dmg;
};

struct Hero {
	string name[2]; // Class
	int atk;
	int def;
	int hp;
	int mana;
	int color;
	int id;
	bool unlocked;
	Skill skills[4];
};

struct Enemy {
	string name[2];
	int atk;
	int def;
	int hp;
	int mana;
	int type;
	int status = 0;
};

struct Status {
	string name[2];
};

struct gameVariables {
	int chosenHero = 0;
	string username = "";
	int user_level = 0;
	int score = 0;
	int Dificultad = 1;
	bool Medallas_obtenidas[5] = { false,false,false,false,false };
	int puntaje = 0;
};

Hero heroes[4];
Enemy enemies[4];
Enemy bosses[2];
Enemy finalBoss[1];
Skill skills[16];
gameVariables gameVar;
Hero currentPlayer[2];

void createEnemies();
void createSkills();
void border();
void showMainMenu();
void createHeroes();
void setScreenResolution(int x, int y);
void clearEntity();
void characterSelect(int player);
void fightScreen(int opponent, int type, int potions);
void intro();
void clearTextBox();
void createEnemySequence();
void historyMode(int k);
void fightMenu(int opponent, int potions);
void clearDescriptionBox();
void clearTitleBox();
void Marco();
void MenuOpciones();
void GameOver();
void Marge_Simpson(int y, int respuesta_marge, int marge_love);
void Minijuego();
void Mis_medallas();
void Puntuaciones();
void Homero(int y);
void Tutorial_DoWhile(int orientacion, int tipo);
void Tutorial(int tipo);
void User_LogIn();
int enemyAttack(int opponent);
void vsMode();
void survivalMode();
void Transition_Screen(int opponent, int tipe, int character);
void CargarPartida();
// Game variables
string menuOptions[2][4] = {
		{ "Iniciar","Opciones","Tutorial","Salir"},
		{ "Start", "Options","Tutorial", "Exit " } };

Enemy enemySequence[7];

// 0 - esp
// 1 - eng
int language = 1;
bool game_over = false;
inline int random(int inicio, int limite) { return inicio + rand() % (1 + limite - inicio); }

int main() {
	createSkills();
	createHeroes();
	createEnemies();
	createEnemySequence();
	User_LogIn();
	Tutorial(0);
	setScreenResolution(600, 438);
	while (true) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		showMainMenu(); break;
	}
	if (game_over == false)
		GameOver();
	exit(0);
	system("pause>arch");//>arch
	return 0;
}

void gotoxy(int x, int y) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void createHeroes() {
	// KNIGHT
	heroes[0].name[0] = "CABALLERO";
	heroes[0].name[1] = "KNIGHT";
	heroes[0].atk = 20;
	heroes[0].def = 13;
	heroes[0].hp = 80;
	heroes[0].mana = 100;
	heroes[0].color = 15;
	heroes[0].unlocked = true;
	heroes[0].id = 0;
	heroes[0].skills[0] = skills[0];
	heroes[0].skills[1] = skills[1];
	heroes[0].skills[2] = skills[2];
	heroes[0].skills[3] = skills[3];
	// WIZARD
	heroes[1].name[0] = "MAGO";
	heroes[1].name[1] = "MAGE";
	heroes[1].atk = 20;
	heroes[1].def = 6;
	heroes[1].hp = 120;
	heroes[1].mana = 130;
	heroes[1].color = 11;
	heroes[1].id = 1;
	heroes[1].unlocked = true;
	// SAMURAI
	heroes[2].name[0] = "SAMURAI";
	heroes[2].name[1] = "SAMURAI";
	heroes[2].atk = 27;
	heroes[2].def = 8;
	heroes[2].hp = 90;
	heroes[2].mana = 120;
	heroes[2].color = 13;
	heroes[2].id = 2;
	heroes[2].unlocked = false;
	// HOMER
	heroes[3].name[0] = "HOMERO";
	heroes[3].name[1] = "HOMER";
	heroes[3].atk = 37;
	heroes[3].def = 17;
	heroes[3].hp = 115;
	heroes[3].mana = 100;
	heroes[3].color = 14;
	heroes[3].id = 3;
	heroes[3].unlocked = false;
}

void createEnemies() {
	// SPONGEBOB
	enemies[0].name[0] = "BOB ESPONJA";
	enemies[0].name[1] = "SPONGEBOB SQUAREPANTS";
	enemies[0].atk = 14;
	enemies[0].def = 8;
	enemies[0].hp = 38;
	enemies[0].type = 0;

	// GARFIELD
	enemies[1].name[0] = "GARFIELD";
	enemies[1].name[1] = "GARFIELD";
	enemies[1].atk = 20;
	enemies[1].def = 10;
	enemies[1].hp = 45;
	enemies[1].type = 0;
	// SANTA
	bosses[0].name[0] = "SANTA CLAUS";
	bosses[0].name[1] = "SANTA CLAUS";
	bosses[0].atk = 23;
	bosses[0].def = 9;
	bosses[0].hp = 70;
	bosses[0].type = 1;
	// WINNIE POOH
	enemies[2].name[0] = "WINNIE POOH";
	enemies[2].name[1] = "WINNIE POOH";
	enemies[2].atk = 25;
	enemies[2].def = 14;
	enemies[2].hp = 100;
	enemies[2].type = 0;
	// HOMER
	enemies[3].name[0] = "HOMERO";
	enemies[3].name[1] = "HOMER";
	enemies[3].atk = 30;
	enemies[3].def = 10;
	enemies[3].hp = 45;
	enemies[3].type = 0;
	// SQUIDWARD
	bosses[1].name[0] = "CALAMARDO";
	bosses[1].name[1] = "SQUIDWARD";
	bosses[1].atk = 33;
	bosses[1].def = 10;
	bosses[1].hp = 76;
	bosses[1].type = 1;
	// MICKEY MOUSE
	finalBoss[0].name[0] = "MICKEY MOUSE";
	finalBoss[0].name[1] = "MICKEY MOUSE";
	finalBoss[0].atk = 30;
	finalBoss[0].def = 15;
	finalBoss[0].hp = 100;
	finalBoss[0].type = 2;
}

void createSkills() {
	// a
	skills[0].name[0] = "SED DE SANGRE";
	skills[0].name[1] = "BLOODLUST";
	skills[0].descp[0] = "Ataque que te cura.";
	skills[0].descp[1] = "Attack with lifesteal.";
	skills[0].manaCost = 23;
	skills[0].dmg = 2;
	// a
	skills[2].name[0] = "FURIA";
	skills[2].name[1] = "FURY";
	skills[2].descp[0] = "Aumenta tu ataque.";
	skills[2].descp[1] = "Buffs your attack.";
	skills[2].manaCost = 23;
	skills[2].dmg = 2;
	// a
	skills[1].name[0] = "INCINERAR";
	skills[1].name[1] = "INCINERATE";
	skills[1].descp[0] = "Cenizas a cenizas, polvo al polvo. Gran daño al enemigo.";
	skills[1].descp[1] = "Ashes to ashes, dust to dust. Great damage to the enemy.";
	skills[1].manaCost = 23;
	skills[1].dmg = 2;
	// a
	//     
	skills[3].name[0] = "EL BARTO";
	skills[3].name[1] = "EL BARTO";
	skills[3].descp[0] = "Tus manos sobre la garganta de tu enemigo. Reduce defensa de enemigo.";
	skills[3].descp[1] = "Your hands over your enemy\'s throat. Reduce enemy's defense.";
	skills[3].manaCost = 23;
	skills[3].dmg = 2;
}

void createEnemySequence() {
	float multiplicacion = 1;
	if (gameVar.Dificultad == 0)
		multiplicacion = 0.8;
	else if (gameVar.Dificultad == 2)
		multiplicacion = 1.2;
	enemySequence[0] = enemies[0];
	enemySequence[1] = enemies[1];
	enemySequence[2] = bosses[0];
	enemySequence[3] = enemies[2];
	enemySequence[4] = enemies[3];
	enemySequence[5] = bosses[1];
	enemySequence[6] = finalBoss[0];
	for (auto i : enemySequence) {
		i.atk = int(multiplicacion * float(i.atk));
		i.hp = int(multiplicacion * float(i.hp));
		i.def = int(multiplicacion * float(i.def));
	}
}

void User_LogIn() {
	int item = 0;
	string Login[2] = { "Ingresa nombre de usuario","   Enter your username   " };
	string opciones_idioma[2] = { "Espanol","English" };
	do {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		gotoxy(35, 10); cout << "                  ";
		gotoxy(35, 10);	cout << "<" << opciones_idioma[item] << ">";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (GetAsyncKeyState(VK_RIGHT) != 0) {
			item += 1;
			if (item == 2)
				item = 0;
		}
		else if (GetAsyncKeyState(VK_LEFT) != 0) {
			item -= 1;
			if (item == -1)
				item = 1;
		}
		else if (GetAsyncKeyState(VK_RETURN) != 0) {
			language = item;
			break;
		}
		Sleep(200);
	} while (true);
	gotoxy(30, 15); cout << Login[language];
	cin.ignore();
	do
	{
		gotoxy(35, 16); getline(cin, gameVar.username);
		if (GetAsyncKeyState(VK_RETURN) != 0) {
			GameOver();
			break;
		}
		Sleep(200);
	} while (true);
}

void Tutorial(int tipo) {
	system("cls");
	Marco();
	string tutorial[2][9] = { "Este es el tutorial de controles para menus","Para desplazarte en los menus, aplica lo siguiente:","Tecla flecha ARRIBA para ir hacia arriba","Tecla flecha ABAJO  para ir hacia abajo","Tecla ESPACIO para ir al manu anterior","ENTER para acceder a la opcion seleccionada","   En las opciones como la siguiente   ","Flecha IZQUIERDA para ir hacia atras","Flecha DERECHA para ir hacia adelante",
	"  This is the controls tutorial for menus  ","To move through menus, do the following:      ","   UP arrow key to go Upward       ","     DOWN arroy key to go Downward     ","     SPACE key to go previous menu    ","    ENTER key to access selected option    ","In options as following, move like this: ","    LEFT arroy key to go backward   ","    RIGHT arrow key to go forward    " };
	gotoxy(25, 2);	cout << tutorial[language][0];
	gotoxy(25, 8); cout << tutorial[language][1];
	gotoxy(2, 11);	cout << tutorial[language][2];
	gotoxy(2, 12);	cout << tutorial[language][3];
	gotoxy(2, 13);	cout << tutorial[language][4];
	gotoxy(2, 14);  cout << tutorial[language][5];
	Tutorial_DoWhile(0, tipo);
	Sleep(1200);
	gotoxy(35, 17);  cout << tutorial[language][6];
	gotoxy(2, 18);  cout << tutorial[language][7];
	gotoxy(2, 19);  cout << tutorial[language][8];
	Tutorial_DoWhile(1, tipo);
	Sleep(1500);
}

void Tutorial_DoWhile(int orientacion, int tipo) {
	string menus[2][4] = { "  Salir ","Continuar","Opcion 3","Opcion 4","  Exit  ","Option 2","Option 3","Option 4" };
	int item = 0, hasta = 2, salir = 0;
	int y = 11;
	do {
		if (GetAsyncKeyState(VK_SPACE) != 0) {
			break;
		}
		if (orientacion == 0) {
			y = 11; //menu horizontal
			hasta = 4;
			for (int indice = 0; indice < hasta; indice++, y++) {
				gotoxy(45, y);
				if (indice == item) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "Enter";
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "Items";
				}
			}
			if (GetAsyncKeyState(VK_RETURN) != 0) {
				break;
			}
			else if (orientacion == 0) {
				if (GetAsyncKeyState(VK_UP) != 0) {
					item -= 1;
					if (item == -1)
						item = 3;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0) {
					item += 1;
					if (item == 4)
						item = 0;
				}
			}
		}
		else {
			do {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				gotoxy(45, 18); cout << "                  ";
				gotoxy(45, 18);	cout << "<" << menus[language][item] << ">";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				if (GetAsyncKeyState(VK_RIGHT) != 0) {
					item += 1;
					if (item == 2)
						item = 0;
				}
				else if (GetAsyncKeyState(VK_LEFT) != 0) {
					item -= 1;
					if (item == -1)
						item = 1;
				}
				else if (GetAsyncKeyState(VK_RETURN) != 0) {
					salir = 1; break;
				}
				Sleep(200);
			} while (true);
		}
		if (salir == 1) {
			break;
		}
		Sleep(250);
	} while (true);
}
void showMainMenu() {
	int item = 0;
	Marco();
	gotoxy(60, 1); cout << gameVar.username;
	Sleep(1000);
	do { //Imprime opciones: Iniciar Juego, Opciones, Salir
		gotoxy(35, 10);
		for (int indice = 0; indice < 4; indice++) {
			if (item == indice) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << menuOptions[language][indice] << endl;
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menuOptions[language][indice] << endl;
			}
			if (indice == 0) gotoxy(35, 11);
			else if (indice == 1) gotoxy(35, 12);
			else if (indice == 2) gotoxy(35, 13);
			else if (indice == 3) gotoxy(35, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (GetAsyncKeyState(VK_UP) != 0) {
			item -= 1;
			if (item == -1)
				item = 3;
		}
		else if (GetAsyncKeyState(VK_DOWN) != 0) {
			item += 1;
			if (item == 4)
				item = 0;
		}
		else if (GetAsyncKeyState(VK_RETURN) != 0) {
			if (item == 0) { //Iniciar Juego
				int Chosen_mode = -1;
				system("cls"); Marco();
				string Gamemods[2][3] = { "Modo Historia","1 VS 1","Supervivencia","History Mode ","1 VS 1","Survival     " };
				int elegido = 0, new_y = 10; cin.ignore();
				do
				{
					new_y = 10;
					for (int indice = 0; indice < 3; indice++, new_y++) {
						if (elegido == indice) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						}
						else {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						gotoxy(35, new_y); cout << Gamemods[language][indice] << endl;
					}
					if (GetAsyncKeyState(VK_DOWN) != 0) {
						elegido += 1;
						if (elegido == 3)
							elegido = 0;
					}
					else if (GetAsyncKeyState(VK_UP) != 0) {
						elegido -= 1;
						if (elegido == -1)
							elegido = 2;
					}
					else if (GetAsyncKeyState(VK_RETURN) != 0) {
						Chosen_mode = elegido;
					}
					else if (GetAsyncKeyState(VK_SPACE) != 0) {
						break;
					}
					if (Chosen_mode == 0) {
						historyMode(0);
						break;
					}
					else if (Chosen_mode == 1) {
						vsMode();
						break;
					}
					else if (Chosen_mode == 2) {
						survivalMode();
						break;
					}
					Sleep(200);
				} while (true);
				//historyMode(); gotoxy(0, 0);
				system("cls"); Marco();
			}
			else if (item == 1) {
				system("cls"); //Opciones
				MenuOpciones(); system("cls"); Marco();
			}
			else if (item == 2) {
				Tutorial(1);
				system("cls");
				Marco();
			}
			else if (item == 3) {
				system("cls");
				GameOver();
				break;
			}
		}
		Sleep(150);
	} while (true);
}

void MenuOpciones() {
	int sub = 0;
	system("cls");
	string opciones_main[2][6] = { {"Idioma    ","Dificultad","Mejores Puntajes","Mis medallas","Minijuego","Cargar Partida"},{"Language","Difficulty ","Best Scores     ","My Medals   ","Minigame ","Load Match    "} };
	string opciones_Dificultad[2][3] = { {"Facil","Moderado","Maestro"},{"Easy ","Normal  ","Hard   "} };
	string opciones_idioma[2] = { "Espanol","English" };
	Marco();
	gotoxy(65, 1); cout << gameVar.username;
	do {
		gotoxy(30, 10);
		for (int indice = 0; indice < 6; indice++) {
			if (sub == indice) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << opciones_main[language][indice] << endl;
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << opciones_main[language][indice] << endl;
			}
			if (indice == 0) gotoxy(30, 11);
			else if (indice == 1) gotoxy(30, 12);
			else if (indice == 2) gotoxy(30, 13);
			else if (indice == 3) gotoxy(30, 14);
			else if (indice == 4) gotoxy(30, 15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (GetAsyncKeyState(VK_UP) != 0) {//Mueve Arriba
			sub -= 1;
			if (sub == -1)
				sub = 5;
		}
		else if (GetAsyncKeyState(VK_DOWN) != 0) {//Mueve Abajo
			sub += 1;
			if (sub == 6)
				sub = 0;
		}
		else if (GetAsyncKeyState(VK_RETURN) != 0) {//Enter presionado
			if (sub == 0) {
				sub = 0;
				do
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					gotoxy(30, 10); cout << "                                                                  ";
					gotoxy(30, 10);	cout << "<" << opciones_idioma[sub] << ">";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					if (GetAsyncKeyState(VK_RIGHT) != 0) {
						sub += 1;
						if (sub == 2)
							sub = 0;
					}
					else if (GetAsyncKeyState(VK_LEFT) != 0) {
						sub -= 1;
						if (sub == -1)
							sub = 1;
					}
					else if (GetAsyncKeyState(VK_RETURN) != 0) {
						language = sub; break;
					}
					else if (GetAsyncKeyState(VK_SPACE) != 0) {
						break;
					}
					Sleep(200);
				} while (true);
			}
			else if (sub == 1) {
				sub = 0;
				do {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					gotoxy(29, 11); cout << "                                                                  ";
					gotoxy(30, 11);	cout << "<" << opciones_Dificultad[language][sub] << ">";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					if (GetAsyncKeyState(VK_RIGHT) != 0) {
						sub += 1;
						if (sub == 3)
							sub = 0;
					}
					else if (GetAsyncKeyState(VK_LEFT) != 0) {
						sub -= 1;
						if (sub == -1)
							sub = 2;
					}
					else if (GetAsyncKeyState(VK_RETURN) != 0) {
						gameVar.Dificultad = sub;
						createEnemySequence();
						break;
					}
					else if (GetAsyncKeyState(VK_SPACE) != 0) {
						break;
					}
					Sleep(150);
				} while (true);
			}
			else if (sub == 2) {
				Puntuaciones();
				do
				{
					if (GetAsyncKeyState(VK_SPACE) != 0) {
						system("cls"); Marco(); break;
					}
					Sleep(200);
				} while (true);
			}
			else if (sub == 3) {
				Mis_medallas();
				do
				{
					if (GetAsyncKeyState(VK_SPACE) != 0) {
						system("cls"); Marco(); break;
					}
					Sleep(200);
				} while (true);
			}
			else if (sub == 4) {
				system("cls");
				Minijuego();
			}
			else if (sub == 5) {
				system("cls");
				CargarPartida();
				system("cls"); Marco();
			}
		}
		else if (GetAsyncKeyState(VK_SPACE) != 0)
			break;
		Sleep(150);
	} while (true);
}

void CargarPartida() {
	system("cls");
	Marco();
	std::string Matriz[100][4], linea;
	for (int i = 0; i < 100; i++) {
		for (int i2 = 0; i2 < 4; i2++) {
			Matriz[i][i2] = "";
		}
	}int contador = 0;
	ifstream myf("TXT\\user_" + gameVar.username + ".txt");
	if (myf.is_open()) {
		while (getline(myf, linea)) {
			Matriz[contador][0] = linea.substr(0, linea.find_first_of("-")); linea = linea.substr(linea.find_first_of("-") + 1);
			Matriz[contador][1] = linea.substr(0, linea.find_first_of("-")); linea = linea.substr(linea.find_first_of("-") + 1);
			Matriz[contador][2] = linea.substr(0, linea.find_first_of("-")); linea = linea.substr(linea.find_first_of("-") + 1);
			Matriz[contador][3] = linea;
			contador += 1;
		}
		myf.close();
	}
	int item = 0;
	bool salir = false;
	do {
		int y = 10;
		for (int i = 0; i < contador - 1; i++, y++) {
			if (item == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				gotoxy(25, y); cout << "Puntos: " << Matriz[i][0] << " Jugador: " << Matriz[i][2] << " Nivel " << Matriz[i][3];
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				gotoxy(25, y); cout << "Puntos: " << Matriz[i][0] << " Jugador: " << Matriz[i][2] << " Nivel " << Matriz[i][3];
			}
		}
		if (GetAsyncKeyState(VK_DOWN) != 0) {
			item += 1;
			if (item == contador - 1)
				item = 0;
		}
		else if (GetAsyncKeyState(VK_UP) != 0) {
			item -= 1;
			if (item == 0)
				item = contador - 2;
		}
		else if (GetAsyncKeyState(VK_RETURN) != 0) {
			salir = true;
		}
		else if (GetAsyncKeyState(VK_SPACE) != 0) {
			break;
		}
		if (salir) {
			gameVar.username = Matriz[item][1];
			currentPlayer[0].id = stoi(Matriz[item][2]);
			historyMode(stoi(Matriz[item][3]));
			break;
		}
		Sleep(200);
	} while (true);
}

void Marco() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	for (int indice = 0; indice < 80; indice++) {
		gotoxy(indice, 0);
		cout << char(178);
	}
	for (int i = 0; i < 24; i++) {
		gotoxy(0, i);
		cout << char(178);
		gotoxy(79, i);
		cout << char(178);
	}
	for (int indice = 0; indice < 80; indice++) {
		gotoxy(indice, 24);
		cout << char(178);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void GameOver() {
	game_over = true;
	ofstream myfile("TXT\\usuarios.txt", ofstream::app);
	if (myfile.is_open()) {
		myfile << to_string(gameVar.score) + "-"; //Puntos
		myfile << gameVar.username + "-";
		myfile << to_string(currentPlayer[0].id) + "-";//Caracter
		myfile << gameVar.user_level << endl;//Nivel
		myfile.close();
	}
	ofstream myf("TXT\\user_" + gameVar.username + ".txt", ofstream::app);
	if (myf.is_open()) {
		myf << to_string(gameVar.score) + "-"; //Puntos
		myf << gameVar.username + "-";
		myf << to_string(currentPlayer[0].id) + "-";//Caracter
		myf << gameVar.user_level << endl;//Nivel
		myf.close();
	}
	ofstream f("TXT\\user_" + gameVar.username + "_medals.txt");
	if (f.is_open()) {
		f << to_string(gameVar.Medallas_obtenidas[0]) + "-";
		f << to_string(gameVar.Medallas_obtenidas[1]) + "-";
		f << to_string(gameVar.Medallas_obtenidas[2]) + "-";
		f << to_string(gameVar.Medallas_obtenidas[3]) + "-";
		f << to_string(gameVar.Medallas_obtenidas[4]);
		f.close();
	}
}

void border() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	for (int indice = 0; indice < 80; indice++) {
		gotoxy(indice, 0);
		cout << char(178);

	}
	for (int i = 0; i < 24; i++) {
		gotoxy(0, i);
		cout << char(178);
		gotoxy(79, i);
		cout << char(178);
	}
	for (int indice = 0; indice < 80; indice++) {
		gotoxy(indice, 24);
		cout << char(178);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void setScreenResolution(int x, int y) {
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 100, 100, x, y, TRUE); }
}

void characterSelect(int player) {
	string options[2] = { "ELIGE TU PERSONAJE, JUGADOR ", "CHOOSE YOUR CHARACTER, PLAYER " };
	string espHeroStory[11][4] = { {"Soldado sadista experimentado en el arte de la guerra. Desde niño sufría de","Mago hambriento de conocimiento, que lo llevó a la práctica de magias","Nadie sabe quién es, nadie ha visto su cara, nadie sabe qué hace en Arkansas.","Transportado a esta dimensión gracias a Mickey con la promesa de una cerveza."},
								{"abuso por sus padres y desarrolló una personalidad agresiva e impulsiva.","oscuras que empezaron a corromper su alma, que poco a poco lo llevaron a su","Se dice que esconde su cara debido a las lesiones de lepra que tiene en la","Homero al darse cuenta del plan malévolo de Mickey, decide hacer lo correcto"},
								{"Decidió entrar al ejercito para poder canalizar sus impulsos y obtener placer","propia perdición. Es muy conocido en Arkansas por su grupo elitista de","cara. Está en exilio debido a crímenes que cometió en su país de origen.","y evitar el fin de la raza humana. Es un poco tonto, pero su poder no debe"},
								{"causando dolor, participando en bastantes batallas. Fue expulsado del ","seguidores a los que enseñaba magia. Interesado en un nuevo hechizo oscuro y","Lucha con su katana y por sus propios intereses.","de ser subestimado."},
								{"ejercito debido a conflictos que tenía con sus compañeros. Pasaron meses en","en necesidad de un individuo, decidió engañar a uno de sus seguidores y","",    ""},
								{"los que reprimía sus deseos, y un día, desesperado en la noche, escapó lejos","aplicarselo, incinerando vivo al seguidor hasta volverlo cenizas.","",      ""},
								{"con su armadura y su espada con el fin de satisfacer su necesidad de","Busca encontrar una forma de purgar su alma de dicha corrupción.","",             ""},
								{"violencia, causando una masacre en Arkansas. Busca una forma de redimir sus","Experto en magia con gran arsenal de hechizos.","",             ""},
								{"acciones. Posee mucha vida y defensa con decente ataque.","","",""},
								{"","","",""} };

	string engHeroStory[11][4] = { {"Sadist soldier experienced in the art of war. As a kid he used to be abused","Wizard with a hunger for knowledge that drove him to learn dark magic, which","Nobody has seen his face, nobody knows who he is, what he’s doing at Arkansas",                 "Accepted being transported into this dimension thanks to Mickey with the"},
									{"physically by his parents and developed an aggresive and impulsive","started to corrupt his soul, that little by little started to take him to his","and no one has even seen his face, since he’s always hiding his face. It has",                         "promise of getting a cold beer, Homer, after knowing the evil plans of"},
									{"personality. He decided to enter the army as a way to canalize his impulses","own perdition. It’s famous on Arkansas because of his elitist group of","been said that he hides his face because of the scars in his face that the",                         "Mickey, decides to do good and save the human race. He's a little dumb,"},
									{"and obtain pleasure inflicting pain. Was discharged from the army because of","followers who he teaches magic. Interested in learning a new spell and in","leprocy has left him. He’s exiled because of crimes he commited in his place",                       "but his power should not be underestimated."},
									{"the number of conflicts he used to have with other soldiers. Months passed in","need of a target for it, he decided to trick one of his followers and casted","of origin. Fights with his katana and for his own interests, it’s agile, has",                   ""},
									{"which he abstained from violence, and one night, desperate, he left with his","it on him, incinerating the follower alive until he ended up in ashes.","the capacity of evading attacks, but it’s slightly weak.",                                          ""},
									{"armor and sword with the purpose of satisfying his need for violence, causing","He’s searching for a way to purge his soul from said corruption.","",                                                                                                           ""},
									{"a massacre in Arkansas. He’s searching for a way to redeem his actions. Has a","Expert in magic with a great arsenal of spells.","",                                                                                                                            ""},
									{"lot of health and defense with decent attack.","","",                                                                                                                                                                                                         ""},
									{"","","",                                                                                                                                                                                                                                                      ""} };
	setScreenResolution(720, 800);
	while (player > 0) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		for (int indice = 0; indice < 80; indice++) {
			gotoxy(indice, 0);  cout << char(178);
			gotoxy(indice, 3);  cout << char(178);
			gotoxy(indice, 26); cout << char(178);
			gotoxy(indice, 40); cout << char(178);
		}
		for (int i = 0; i < 41; i++) {
			gotoxy(0, i);
			cout << char(178);
			gotoxy(79, i);
			cout << char(178);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Datos Adversario
		gotoxy(25, 1); cout << options[language] << player;
		int y = 5;
		int n = 0;
		bool end = false;
		gotoxy(2, 33);
		while (end != true) {
			if (GetAsyncKeyState(VK_RIGHT) != 0) {
				n++;
				if (n > 3)
					n = 3;
				if (heroes[2].unlocked != true && n == 2) {
					if (heroes[3].unlocked == true)
						n = 3;
					else
						n = 1;
				}
				if (heroes[3].unlocked != true && n == 3) {
					if (heroes[2].unlocked == true)
						n = 2;
					else
						n = 1;
				}

			}
			else if (GetAsyncKeyState(VK_LEFT) != 0) {
				n--;
				if (heroes[2].unlocked != true && n == 2)
					n = 1;
				if (n < 0)
					n = 0;
			}
			else if (GetAsyncKeyState(VK_SPACE) != 0) {
				system("cls");
				clearEntity();
				border();
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				gameVar.chosenHero = n;
				break;
			}
			switch (n) {
			case 0:
				clearTitleBox();
				gotoxy(35, 2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); cout << heroes[n].name[language];
				break;
			case 1:
				clearTitleBox();
				gotoxy(35, 2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); cout << heroes[n].name[language];
				break;
			case 2:
				clearTitleBox();
				gotoxy(35, 2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << heroes[n].name[language];
				break;
			case 3:
				clearTitleBox();
				gotoxy(35, 2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cout << heroes[n].name[language];
				break;
			default:
				cout << "???";
				break;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			clearEntity();
			for (int i = 0; i < 19; i++) {
				gotoxy(23, y + i);
				cout << personajes::imagen[n][i];
			}
			gotoxy(1, 27);
			setlocale(LC_ALL, "spanish");
			clearTextBox();
			if (language == 0) {
				for (int i = 0; i < 11; i++) {
					gotoxy(1, 28 + i);
					cout << espHeroStory[i][n];
				}
			}
			else if (language == 1) {
				for (int i = 0; i < 11; i++) {
					gotoxy(1, 28 + i);
					cout << engHeroStory[i][n];
				}
			}
			Sleep(1000);
			locale::global(std::locale("C"));
		}
		if (player == 1) {
			currentPlayer[0] = heroes[n];
			player--;
		}
		else if (player == 2) {
			currentPlayer[1] = heroes[n];
			player--;
		}
	}
}

void Mis_medallas() {
	string Medals[2][5] = { "Cazador de Gigantes","Merikurisumasu","Fondo de Bikini","Suerte de Novato","Tengo Prisa","Giant Hunter","Merikurisumasu","Bikini Buttom","Newcommers Luck","Hurried" };// FFF-Gana el modo supervivencia en modo dificil", "Vence a Santa Calus con el Samurai", "Consigue derrotar a Calamardo y Bob Esponja en modo dificil", "Moriste contra BobEsponja", "Completa el juego sin perder", "Defeat final bosses in Master Mode", "Defeat Santa Claus with Samurai", "Defeat Skidward and SpongeBob in Master Mode", "Defeat your first enemy withouth drenches", "Complete de game without losing"
	system("cls");
	Marco();
	string linea, substrings[4] = { "","","","" };
	string Array_Pts[2] = { "Mis Medallas","My Medals" };
	gotoxy(65, 2); cout << gameVar.username;
	gotoxy(33, 4); cout << Array_Pts[language];
	ifstream myf("TXT\\user_" + gameVar.username + ".txt");
	if (myf.is_open()) {
		getline(myf, linea);
		substrings[0] = linea.substr(linea.find_first_of("-") + 1);
		substrings[1] = substrings[0].substr(substrings[0].find_first_of("-") + 1);
		substrings[2] = substrings[1].substr(substrings[1].find_first_of("-") + 1);
		substrings[3] = substrings[2].substr(substrings[2].find_first_of("-") + 1);
		gotoxy(30, 10);
		if (linea.substr(0, 1) == "1")
			cout << Medals[language][0] << ": Obtenida"; //Aqu� va el nombre?
		else if (linea.substr(0, 1) == "0" || linea != "1")
			cout << Medals[language][0] << ": No Obtenida";
		gotoxy(30, 11);
		if (linea.substr(2, 1) == "1")
			cout << Medals[language][1] << ": Obtenida";
		else if (linea.substr(2, 1) == "0" || linea != "1")
			cout << Medals[language][1] << ": No Obtenida";
		gotoxy(30, 12);
		if (linea.substr(4, 1) == "1")
			cout << Medals[language][2] << ": Obtenida";
		else if (linea.substr(4, 1) == "0" || linea != "1")
			cout << Medals[language][2] << ": No Obtenida";
		gotoxy(30, 13);
		if (linea.substr(6, 1) == "1")
			cout << Medals[language][3] << ": Obtenida";
		else if (linea.substr(6, 1) == "0" || linea != "1")
			cout << Medals[language][3] << ": No Obtenida";
		gotoxy(30, 14);
		if (linea.substr(8, 1) == "1")
			cout << Medals[language][4] << ": Obtenida";
		else if (linea.substr(8, 1) == "0" || linea != "1")
			cout << Medals[language][4] << ": No Obtenida";
		myf.close();
	}
	else {
		gotoxy(30, 10); cout << Medals[language][0] << ": No Obtenida";
		gotoxy(30, 11); cout << Medals[language][1] << ": No Obtenida";
		gotoxy(30, 12); cout << Medals[language][2] << ": No Obtenida";
		gotoxy(30, 13); cout << Medals[language][3] << ": No Obtenida";
		gotoxy(30, 14); cout << Medals[language][4] << ": No Obtenida";
	}
}

void Imprime_marco_marge() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	for (int indice = 0; indice < 80; indice++) {
		gotoxy(indice, 0);	cout << char(178);
		gotoxy(indice, 3);	cout << char(178);
		gotoxy(indice, 26);	cout << char(178);
		gotoxy(indice, 34);	cout << char(178);
		gotoxy(indice, 40);	cout << char(178);
	}
	for (int i = 0; i < 41; i++) {
		gotoxy(0, i);
		cout << char(178);
		gotoxy(79, i);
		cout << char(178);
	}
}

void Marge_Simpson(int respuesta_marge, int marge_love, int imagen_marge) {
	int x_corazon = 55;
	system("cls"); Imprime_marco_marge();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(35, 1); cout << "Marge Simpson"; gotoxy(x_corazon, 1); for (int corazon = 0; corazon < marge_love; corazon++, x_corazon++) {
		cout << characters::hearts; gotoxy(x_corazon, 1);
	}
	int y = 5;
	gotoxy(2, 14); cout << characters::frases[language][respuesta_marge];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(35, y);
	for (int i = 0; i < 20; i++) {
		cout << characters::marge[imagen_marge][i]; y += 1;
		gotoxy(35, y);
	}
}

void Homero(int y) {
	gotoxy(40, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	for (int i = 0; i < 20; i++, y++) {
		gotoxy(40, y);
		cout << characters::marge[0][i];
	}
	y = 9; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	for (int i = 0; i < 5; i++, y++) {
		gotoxy(2, y);
		cout << characters::marge_historia[language][i];
	}
	string enter[2] = { "Presiona Enter para comenzar","    Press Enter to Begin    " };
	gotoxy(30, 20); cout << enter[language];
	do {
		if (GetAsyncKeyState(VK_RETURN) != 0) {
			break;
		}
	} while (true);
}

void Minijuego() {
	setScreenResolution(960, 694);
	Marco(); int y = 2;
	Homero(y);
	Sleep(500);
	system("cls"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	Imprime_marco_marge();
	int marge_love = 2, respuesta_marge = 0, level = 0, perdiste = 0;
	Marge_Simpson(respuesta_marge, marge_love, 1);
	do {
		int seleccionado = 0;
		do {
			y = 29;
			for (int i = 0; i < 3; i++, y++) {
				gotoxy(3, y);
				if (seleccionado == i) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << characters::opciones[language][level][i];
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << characters::opciones[language][level][i];
				}
			}
			if (GetAsyncKeyState(VK_DOWN) != 0) {
				seleccionado += 1;
				if (seleccionado == 3)
					seleccionado = 0;
			}
			else if (GetAsyncKeyState(VK_UP) != 0) {
				seleccionado -= 1;
				if (seleccionado == -1)
					seleccionado = 2;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				if (level == 0) {
					if (seleccionado == 0) {
						respuesta_marge = 4;
						marge_love -= 1;
						Marge_Simpson(respuesta_marge, marge_love, 1);
						perdiste = 1;
						break;
					}
					else if (seleccionado == 1 || seleccionado == 2) {
						respuesta_marge = 1;
						marge_love += 1;
						level += 1;
						Marge_Simpson(respuesta_marge, marge_love, 2);
					}
				}
				else if (level == 1) {
					if (seleccionado == 0) {
						respuesta_marge = 2;
						marge_love += 2;
						level += 1;
						Marge_Simpson(respuesta_marge, marge_love, 2);//3
					}
					else if (seleccionado == 1) {
						respuesta_marge = 5;
						marge_love -= 1;
						perdiste = 2;
						Marge_Simpson(respuesta_marge, marge_love, 1);
						break;
					}
					else if (seleccionado == 2) {
						respuesta_marge = 5;
						marge_love -= 1;
						perdiste = 2;
						Marge_Simpson(respuesta_marge, marge_love, 1);
						break;
					}
				}
				else if (level == 2) {
					if (seleccionado == 0) {
						string winner[2] = { "Ganaste!!!","You Win" };
						respuesta_marge = 6;
						marge_love += 2;
						Marge_Simpson(respuesta_marge, marge_love, 4);
						gotoxy(35, 27); winner[language];
						break;
					}
					else if (seleccionado == 1) {
						respuesta_marge = 4;
						marge_love -= 1;
						perdiste = 1;
						Marge_Simpson(respuesta_marge, marge_love, 1);
						break;
					}
					else if (seleccionado == 2) {
						respuesta_marge = 3;
						marge_love -= 1;
						perdiste = 2;
						Marge_Simpson(respuesta_marge, marge_love, 1);
						break;
					}
				}
			}
			else if (GetAsyncKeyState(VK_SPACE) != 0) {
				perdiste = 0;
				break;
			}
			Sleep(200);
		} while (true);
		Sleep(2000);
		if (perdiste != 0) {
			system("cls"); Marco(); y = 2;
			gotoxy(20, y);
			for (int i = 0; i < 20; i++) {
				cout << characters::marge[3][i]; y += 1;
				gotoxy(20, y);
			}
		}
		Sleep(4000);
		system("cls"); Marco(); break;
	} while (true);
}

void clearEntity() {
	for (int i = 4; i < 25; i++) {
		gotoxy(3, i);
		cout << "                                                                  ";
	}
}

void fightScreen(int opponent, int type, int potions) {
	system("cls");
	locale::global(std::locale("C"));
	int item = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), heroes[gameVar.chosenHero].color);
	for (int indice = 0; indice < 80; indice++) {
		gotoxy(indice, 0);  cout << char(178);
		gotoxy(indice, 3);  cout << char(178);
		gotoxy(indice, 26); cout << char(178);
		gotoxy(indice, 34); cout << char(178);
		gotoxy(indice, 40); cout << char(178);
	}
	for (int i = 0; i < 41; i++) {
		gotoxy(0, i);
		cout << char(178);
		gotoxy(79, i);
		cout << char(178);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Datos Adversario
	gotoxy(65, 1); cout << gameVar.username;
	gotoxy(2, 1); cout << gameVar.score;
	clearTitleBox();
	 gotoxy(35, 2); cout << enemySequence[opponent].name[language]; gotoxy(65, 2); cout << "HP: " << enemySequence[opponent].hp;
	for (int i = 0; i < 19; i++) {
		gotoxy(20, 5 + i);
		cout << characters::imagen[opponent][i];
	}
	if (opponent == 6 && gameVar.Dificultad == 2) {
		gameVar.Medallas_obtenidas[2] = true;
	}
	if (opponent == 3 && gameVar.chosenHero == 2) {
		gameVar.Medallas_obtenidas[1] = true;
	}
	if (type == 0)
		fightMenu(opponent, potions);

}

void fightMenu(int opponent, int potions) {
	int damage = 0;
	string attack[2][5] = { {"EL JUGADOR", " ATACÓ CAUSANDO ", " DE DAÑO", "EL ENEMIGO", " CAUSANDO " }, { "PLAYER ", " ATTACKED, DEALING ", " DMG", "THE ENEMY", " DEALING "} };
	string spells[2][5] = { {"USÓ ", "SED DE SANGRE,","INCINERAR,", "FURIA", "EL BARTO,"}, {"USED ", "BLOODLUST,","INCINERATE,", "FURY", "EL BARTO,"} };
	string options[2][4] = { {"ATACAR","HABILIDADES","DEFENDER","CURAR"}, {"ATTACK","SKILLS","DEFEND","HEAL"} };
	string descriptions[2][4] = { {"Ataque regular.","Habilidades especiales que requieren de mana.","Protegerse un ataque.","Curarse una cantidad de vida."},
								{"Regular attack.","Special skills that require mana.","Defend against an attack.","Heal an amount of HP."} };
	string defense[2] = { " SE DEFIENDE", " DEFENDS HIMSELF" };
	string heal[2] = { " USA UNA POCIÓN PARA CURARSE", " USES A POTION TO HEAL HIMSELF" };
	int item = 0;
	do {
		gameVar.score = currentPlayer[0].hp * 38;
		clearDescriptionBox();
		gotoxy(5, 28);
		for (int i = 0; i < 4; i++) {
			if (item == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				if (i == 1)
					cout << skills[gameVar.chosenHero].name[language];
				else {
					cout << options[language][i] << endl;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				gotoxy(5, 37);
				if (i == 1)
					cout << skills[gameVar.chosenHero].descp[language] << endl;
				else {
					cout << descriptions[language][i] << endl;
				}
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				if ((i == 3 && potions < 1) || i == 1 && currentPlayer[0].mana < 1)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				if (i == 1)
					cout << skills[gameVar.chosenHero].name[language];
				else {
					cout << options[language][i] << endl;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			gotoxy(5, 29 + i);
		}
		if (GetAsyncKeyState(VK_UP) != 0) {
			item -= 1;
			if (item == -1 && potions > 0)
				item = 3;
			if (potions < 1 && item == -1)
				item = 2;
			if (currentPlayer[0].mana < 1 && item == 1)
				item = 0;

		}
		else if (GetAsyncKeyState(VK_DOWN) != 0) {
			item += 1;
			if (item == 4)
				item = 0;
			if (potions < 1 && item == 3)
				item = 0;
			if (currentPlayer[0].mana < 1 && item == 1)
				item = 2;
		}
		else if (GetAsyncKeyState(VK_RETURN) != 0) {
			if (item == 0) {
				if ((currentPlayer[0].atk - enemySequence[opponent].def) > 0) {
					damage = 0;
					damage = currentPlayer[0].atk - enemySequence[opponent].def;
					enemySequence[opponent].hp = enemySequence[opponent].hp - damage;
					gotoxy(1, 24); cout << attack[language][0] << attack[language][1] << damage << attack[language][2];
					Sleep(1000);
					break;
				}
			}
			else if (item == 1) {
				if (gameVar.chosenHero == 0) {
					damage = 0;
					damage = currentPlayer[0].atk - enemySequence[opponent].def;
					enemySequence[opponent].hp = enemySequence[opponent].hp - damage;
					if (currentPlayer[0].hp + damage >= heroes[gameVar.chosenHero].hp)
						currentPlayer[0].hp = heroes[gameVar.chosenHero].hp;
					else
						currentPlayer[0].hp += damage;
					gotoxy(1, 24); cout << attack[language][0] << spells[language][0] << spells[language][1] << attack[language][4] << damage << attack[language][2];
					currentPlayer[0].mana -= 20;
					Sleep(1000);
					break;
				}
				else if (gameVar.chosenHero == 1) {
					damage = 0;
					damage = 40 - enemySequence[opponent].def;
					enemySequence[opponent].hp = enemySequence[opponent].hp - damage;
					gotoxy(1, 24); cout << attack[language][0] << spells[language][0] << spells[language][2] << attack[language][4] << damage << attack[language][2];
					currentPlayer[0].mana -= 25;
					Sleep(1000);
					break;
				}
				else if (gameVar.chosenHero == 2) {
					currentPlayer[0].atk += 5;
					gotoxy(1, 24); cout << attack[language][0] << spells[language][0] << spells[language][3];
					currentPlayer[0].mana -= 25;
					Sleep(1000);
					break;
				}
				else if (gameVar.chosenHero == 3) {
					enemySequence[opponent].def -= 3;
					damage = 0;
					damage = 30 - enemySequence[opponent].def;
					enemySequence[opponent].hp -= damage;
					gotoxy(1, 24); cout << attack[language][0] << spells[language][0] << spells[language][4] << attack[language][4] << damage << attack[language][2];
					currentPlayer[0].mana -= 25;
					Sleep(1000);
					break;
				}
			}
			// Defend
			else if (item == 2) {
				gotoxy(1, 24); cout << attack[language][0] << defense[language];
				Sleep(1000);
				currentPlayer[0].def += 7;
				break;
			}
			// Curar
			else if (item == 3) {
				if (heroes[currentPlayer[0].id].hp <= (currentPlayer[0].hp + 35) && potions > 0) {
					currentPlayer[0].hp = heroes[currentPlayer[0].id].hp;
				}
				else if (potions > 0) {
					currentPlayer[0].hp += 35;
				}
				gotoxy(1, 24); cout << attack[language][0] << heal[language];
				Sleep(1000);
				potions--;
				break;
			}
		}
		gotoxy(50, 28); cout << "HP: " << currentPlayer[0].hp;
		gotoxy(50, 29); cout << "MANA: " << currentPlayer[0].mana;
		gotoxy(50, 30);
		if (language == 0)
			cout << "POCIONES: " << potions;
		else
			cout << "POTIONS: " << potions;
		Sleep(150);
		gameVar.score = 0;
	} while (true);
	if (enemySequence[opponent].hp > 0) {
		gotoxy(1, 25); cout << attack[language][3] << attack[language][1] << enemyAttack(opponent) << attack[language][2];
		Sleep(1000);
		//Sleep(1000);
		if (currentPlayer[0].hp > 0) {
			fightScreen(opponent, 0, potions);
		}
	}
}


int enemyAttack(int opponent) {
	srand(time(NULL));
	int damage = 0;
	int option = random(0, 1);
	if (option == 1) {
		if (enemySequence[opponent].atk - currentPlayer[0].def > 0) {
			damage = enemySequence[opponent].atk - currentPlayer[0].def;
			currentPlayer[0].hp = currentPlayer[0].hp - damage;
		}
	}
	return damage;
}

void clearTextBox() {
	for (int i = 0; i < 13; i++) {
		gotoxy(1, 27 + i);
		cout << "                                                                             ";
	}
}

void clearDescriptionBox() {
	for (int i = 35; i < 39; i++) {
		gotoxy(1, i);
		cout << "                                                                            ";
	}
}

void clearTitleBox() {
	gotoxy(1, 2);
	cout << "                                                                            ";
}

void intro() {
	int j = 0;
	int pages = 0;
	string history[43][2] = { {"Había una vez un pueblo llamado",      "Once upon a time, there was a town"},
							{"Arkansas, donde la gente vivía feliza",   "called Arkansas, where people lived"},
							{"su día a día, disfrutando de fiestas",  "happily with parties everyday, but"},
							{"sin parar, pero todo cambió cuando un",  "everything changed when a stranger"},
							{"extraño llamado Varik llegó al pueblo.",    "named Varik came to this town. Varik"},
							{"Varik se denominaba como un profeta,",    "called himself as a seer, who started"},
							{"el cual predecía en las calles cómo el",    "predicting at the streets how the end"},
							{"fin del mundo sería provocado por ",     "of the world was gonna be provoked by"},
							{"entidades que ningún hombre es capaz",   "entities that no man would be capable"},
							{"de comprender, entidades de otra ",       "of understanding, entities from another"},
							{"dimensión superiores a la raza humana",  " dimension, superior to the human race"},
							{"que traerán hambruna y muerte.",         "that would bring war and pestilence."},
							{"Rondaba las calles en su ropa sucia y",   "He used to lurk the streets in his"},
							{"rota, gritando hasta lastimar su",        "dirty and ripped clothes, screaming on"},
							{"garganta sobre el futuro que aún nadie", "top of his lungs a future that no one"},
							{"llegaba comprender. Desesperado a que",   "was able to comprehend yet. Desperate "},
							{"nadie lo escuchara, decidió secuestrar", "that nobody was listening to him, he"},
							{"a un hombre en una plaza donde el",       "decided to kidnap a person in a plaza"},
							{"pueblo se reunía, amenazando con",       "where the people of the town used to"},
							{"apuñalarlo con la esperanza de que",     "meet, threatening that he would stab "},
							{"alguien lo escuchara.",                   "him with the hope that someone would"},
							{"Cuando menos se dio cuenta, una",     "listen to him. While he was distracted"},
							{"persona de la multitud se lanzó hacia",  "a person from the mob jumped at Varik,"},
							{"Varik, desarmandolo y liberando a",       "disarming him and liberating the person"},
							{"aquella persona privada de su libertad.", "Varik ended up being captured and later"},
							{"Varik terminó siendo capturado y",       "decapitated in front of hundreds of"},
							{"posteriormente decapitado en frente de",  "persons, still begging people to listen"},
							{"cientos de personas, aún implorando que",    "to him."},
							{"escucharan su mensaje.",                  ""},
							{"El cielo de repente se puso rojo, el",    "The sky suddenly turned red, the floor"},
							{"suelo empezó a temblar y gritos llenos", "began to shake and screams full of pain"},
							{"de dolor rodearon toda plaza. Desde tu",  "surrounded the plaza. From your cold"},
							{"fría y sucia celda, te preguntas qué",  "and dirty cell, you wonder what is"},
							{"es lo que está sucediendo allá afuera.",    "going out there.  Someone, who you"},
							{"Alguien, que tu crees es una persona, ",  "think is a person, enters with cloak"},
							{"entra encapuchada, y con una",			"hiding his face and with a scythe, and"},
							{"acción imperceptible para el ojo humano",    "with an action unperciptible to the"},
							{"abre tu celda y se retira sin ninguna",   "human eye, opens your cell and leaves"},
							{"palabra. Conforme los gritos se",         "without saying a word. As the screams"},
							{"vuelven más y más fuertes, ignoras por",    "turn more and more louder, you ignore"},
							{"qué este entete ha liberado y decides",  "thinking about who is he or why would"},
							{"armarte para cualquier situación que",   "he free you and decided to get ready"},
							{"se avecine."                          ,   " for whatever is going on out there."},
	};
	setScreenResolution(700, 694);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), heroes[gameVar.chosenHero].color);
	for (int indice = 0; indice < 80; indice++) {
		gotoxy(indice, 0);  cout << char(178);
		gotoxy(indice, 3);  cout << char(178);
		gotoxy(indice, 26); cout << char(178); // 13
		gotoxy(indice, 40); cout << char(178);
	}
	for (int i = 0; i < 41; i++) {
		gotoxy(0, i);
		cout << char(178);
		gotoxy(79, i);
		cout << char(178);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Datos Adversario
	setlocale(LC_ALL, "spanish");
	clearTextBox();
	for (int i = 0; i < 21; i++) {
		gotoxy(1, 28 + j);
		cout << history[i][language] << " ";
		i++;
		cout << history[i][language];
		j++;
	}
	while (true) {
		int j = 0;
		if (GetAsyncKeyState(VK_RETURN) != 0) {
			clearTextBox();
			for (int i = 22; i < 43; i++) {
				gotoxy(1, 28 + j);
				cout << history[i][language] << " ";
				i++;
				if (i == 43)
					break;
				cout << history[i][language] << endl;
				j++;
			}
				break;
		}
	}
	int y = 5;
	gotoxy(5, y);
	setlocale(LC_ALL, "en_US.UTF-8");
}

void Puntuaciones() {
	system("cls");
	Marco();
	string Array_Pts[2] = { "Puntuaciones Top","Top Scores" };
	gotoxy(33, 4); cout << Array_Pts[language];
	vector<string> Datos;
	vector<int> Puntuaciones;
	string linea; int y = 12;
	ifstream myf("TXT\\usuarios.txt");
	if (myf.is_open()) {
		while (getline(myf, linea)) {
			Datos.push_back(linea);
		}
		myf.close();
	} int contador = 0;
	for (auto i : Datos) {
		Puntuaciones.push_back(stoi(i.substr(0, i.find_first_of("-"))));
	}
	sort(Puntuaciones.begin(), Puntuaciones.end());
	reverse(Puntuaciones.begin(), Puntuaciones.end());
	gotoxy(32, y);
	for (auto i : Puntuaciones) {
		for (auto n : Datos) {
			if (stoi(n.substr(0, n.find_first_of("-"))) == i) {
				cout << "#" << contador << ": " << n.substr(0, n.size() - 4) << endl; contador += 1; y += 1; break;
			}
		}
		gotoxy(32, y);
		if (contador >= 5)
			break;
	}
}

void historyMode(int k) {
	setScreenResolution(960, 694);
	characterSelect(1);
	intro();
	createEnemySequence();
	int potions = 3;
	int i = k;
	for (; i < 7; i++) {
		fightScreen(i, 0, potions);
		// refill
		if (currentPlayer[0].hp < 1) {
			gameVar.score = currentPlayer[0].hp * 38;
			Transition_Screen(i, 3, currentPlayer[i].id);
			if (i == 0) {
				gameVar.Medallas_obtenidas[3] = true;
			}
			break;
		}
		else {
			if (enemySequence[i].hp < 1) {
				if (i == 2 || i == 5)
					Transition_Screen(i, 2, 0);
				else if (i == 6)
					Transition_Screen(i, 4, 0);
				else
					Transition_Screen(i, 1, 0);
			}
			currentPlayer[0].hp = heroes[gameVar.chosenHero].hp;
			currentPlayer[0].mana = heroes[gameVar.chosenHero].mana;
			currentPlayer[0].atk = heroes[gameVar.chosenHero].atk;
			currentPlayer[0].def = heroes[gameVar.chosenHero].def;
		}
		system("cls");
	}
	if (i == 7) {
		gameVar.Medallas_obtenidas[4] = true;
	}
	if (gameVar.Dificultad == 1) {
		heroes[2].unlocked = true;
	}
}

void survivalMode() {
	system("cls");
	characterSelect(1);
	system("cls");
	createEnemySequence();
	int potions = 3;
	locale::global(std::locale("C"));
	string intro[2][2] = { "Pelearás contra una serie de enemigos sin recuperar tu", "vida tras batalla. SOBREVIVE!!!",
		"You'll fight against an horde of enemies without being able to heal","between fights. SURVIVE!!!" };
	int item = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), heroes[gameVar.chosenHero].color);
	for (int indice = 0; indice < 80; indice++) {
		gotoxy(indice, 0);  cout << char(178);
		gotoxy(indice, 3);  cout << char(178);
		gotoxy(indice, 40); cout << char(178);
	}
	for (int i = 0; i < 41; i++) {
		gotoxy(0, i);
		cout << char(178);
		gotoxy(79, i);
		cout << char(178);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Datos Adversario
	gotoxy(65, 1); cout << gameVar.username;
	clearTitleBox();
	gotoxy(5, 4); cout << intro[language][0];
	gotoxy(5, 5); cout << intro[language][1];
	for (int i = 2; i < 6; i += 3) {
		fightScreen(i, 0, potions);
		// refill
		if (currentPlayer[0].hp < 1) {
			Transition_Screen(i, 3, currentPlayer[0].id);
		}
		else {
			Transition_Screen(i, 1, currentPlayer[0].id);
			currentPlayer[0].atk = heroes[currentPlayer[0].id].atk;
			currentPlayer[0].def = heroes[currentPlayer[0].id].def;

		}
		if (i == 5) {
			fightScreen(i + 1, 0, potions);
			// refill
			if (currentPlayer[0].hp < 1) {
				Transition_Screen(i + 1, 3, currentPlayer[0].id);
			}
			else {
				currentPlayer[0].atk = heroes[currentPlayer[0].id].atk;
				currentPlayer[0].def = heroes[currentPlayer[0].id].def;
				Transition_Screen(i + 1, 5, currentPlayer[0].id);
				heroes[3].unlocked = true;
			}
			system("cls");

		}
	}

}

void vsMode() {
	characterSelect(2);
	system("cls");
	int player = 0;
	int playerVs = 0;
	int item = 0;
	int y = 5;
	int damage = 0;
	int potions[2] = { 3,3 };
	string attack[2][5] = { {"EL JUGADOR", " ATACÓ CAUSANDO ", " DE DAÑO", "EL ENEMIGO", " CAUSANDO " }, { "PLAYER ", " ATTACKED, DEALING ", " DMG", "THE ENEMY", " DEALING "} };
	string spells[2][5] = { {"USÓ ", "SED DE SANGRE,","INCINERAR,", "FURIA", "EL BARTO,"}, {"USED ", "BLOODLUST,","INCINERATE,", "FURY", "EL BARTO,"} };
	string options[2][4] = { {"ATACAR","HABILIDADES","DEFENDER","CURAR"}, {"ATTACK","SKILLS","DEFEND","HEAL"} };
	string turn[2] = { "TURNO DE JUGADOR ", "TURN OF PLAYER " };
	string descriptions[2][4] = { {"Ataque regular.","Habilidades especiales que requieren de mana.","Protegerse un ataque.","Curarse una cantidad de vida."},
								{"Regular attack.","Special skills that require mana.","Defend against an attack.","Heal an amount of HP."} };
	string defense[2] = { " SE DEFIENDE", " DEFENDS HIMSELF" };
	string heal[2] = { " USA UNA POCIÓN PARA CURARSE", " USES A POTION TO HEAL HIMSELF" };
	while (currentPlayer[0].hp > 0 && currentPlayer[1].hp > 0) {
		locale::global(std::locale("C"));
		if (player == 1)
			playerVs = 0;
		else if (player == 0)
			playerVs = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), currentPlayer[player].color);
		for (int indice = 0; indice < 80; indice++) {
			gotoxy(indice, 0);  cout << char(178);
			gotoxy(indice, 3);  cout << char(178);
			gotoxy(indice, 26); cout << char(178);
			gotoxy(indice, 34); cout << char(178);
			gotoxy(indice, 40); cout << char(178);
		}
		for (int i = 0; i < 41; i++) {
			gotoxy(0, i);
			cout << char(178);
			gotoxy(79, i);
			cout << char(178);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Datos Adversario
		gotoxy(65, 1); cout << gameVar.username;
		clearTitleBox();
		gotoxy(6, 2); cout << turn[language] << player + 1; gotoxy(65, 2); cout << "HP: " << currentPlayer[playerVs].hp;
		clearEntity();
		for (int i = 0; i < 19; i++) {
			gotoxy(23, y + i);
			cout << personajes::imagen[currentPlayer[playerVs].id][i];
		}
		item = 0;
		do {
			gameVar.score = currentPlayer[0].hp * 38;
			for (int i = 0; i < 7; i++) {
				gotoxy(1, 27 + i);
				cout << "                                                                             ";
			}
			clearDescriptionBox();
			gotoxy(1, 24);
			cout << "                                                    ";
			gotoxy(5, 28);
			for (int i = 0; i < 4; i++) {
				if (item == i) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					if (i == 1)
						cout << skills[currentPlayer[player].id].name[language];
					else {
						cout << options[language][i] << endl;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					gotoxy(5, 37);
					if (i == 1)
						cout << skills[currentPlayer[player].id].descp[language] << endl;
					else {
						cout << descriptions[language][i] << endl;
					}
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					if ((i == 3 && potions[player] < 1) || i == 1 && currentPlayer[0].mana < 1)
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
					if (i == 1)
						cout << skills[currentPlayer[player].id].name[language];
					else {
						cout << options[language][i] << endl;
					}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				gotoxy(5, 29 + i);
			}
			if (GetAsyncKeyState(VK_UP) != 0) {
				item -= 1;
				if (item == -1 && potions[player] > 0)
					item = 3;
				if (potions[player] < 1 && item == -1)
					item = 2;
				if (currentPlayer[player].mana < 1 && item == 1)
					item = 0;

			}
			else if (GetAsyncKeyState(VK_DOWN) != 0) {
				item += 1;
				if (item == 4)
					item = 0;
				if (potions[player] < 1 && item == 3)
					item = 0;
				if (currentPlayer[player].mana < 1 && item == 1)
					item = 2;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				setlocale(LC_ALL, "spanish");
				if (item == 0) {
					if ((currentPlayer[player].atk - currentPlayer[playerVs].def) > 0) {
						damage = 0;
						damage = currentPlayer[player].atk - currentPlayer[playerVs].def;
						currentPlayer[playerVs].hp = currentPlayer[playerVs].hp - damage;
						gotoxy(1, 24);
						cout << attack[language][0] << attack[language][1] << damage << attack[language][2];
						Sleep(1000);
						break;
					}
				}
				else if (item == 1) {
					if (gameVar.chosenHero == 0) {
						damage = 0;
						damage = currentPlayer[player].atk - currentPlayer[playerVs].def;
						currentPlayer[playerVs].hp = currentPlayer[playerVs].hp - damage;
						if (currentPlayer[player].hp + damage >= heroes[gameVar.chosenHero].hp)
							currentPlayer[player].hp = heroes[gameVar.chosenHero].hp;
						else
							currentPlayer[player].hp += damage;
						gotoxy(1, 24); cout << attack[language][0] << spells[language][0] << spells[language][1] << attack[language][4] << damage << attack[language][2];
						currentPlayer[0].mana -= 20;
						Sleep(1000);
						break;
					}
					else if (gameVar.chosenHero == 1) {
						damage = 0;
						damage = 40 - currentPlayer[playerVs].def;
						currentPlayer[playerVs].hp = currentPlayer[playerVs].hp - damage;
						gotoxy(1, 24); cout << attack[language][0] << spells[language][0] << spells[language][2] << attack[language][4] << damage << attack[language][2];
						currentPlayer[0].mana -= 25;
						Sleep(1000);
						break;
					}
					else if (gameVar.chosenHero == 2) {
						currentPlayer[player].atk += 5;
						gotoxy(1, 24); cout << attack[language][0] << spells[language][0] << spells[language][3];
						currentPlayer[0].mana -= 25;
						Sleep(1000);
						break;
					}
					else if (gameVar.chosenHero == 3) {
						currentPlayer[playerVs].def -= 3;
						damage = 0;
						damage = 30 - currentPlayer[playerVs].def;
						currentPlayer[playerVs].hp -= damage;
						gotoxy(1, 24); cout << attack[language][0] << spells[language][0] << spells[language][4] << attack[language][4] << damage << attack[language][2];
						currentPlayer[0].mana -= 25;
						Sleep(1000);
						break;
					}
				}
				// Defend
				else if (item == 2) {
					gotoxy(1, 24); cout << attack[language][0] << defense[language];
					Sleep(1000);
					currentPlayer[player].def += 7;
					break;
				}
				// Curar
				else if (item == 3) {
					if (heroes[currentPlayer[player].id].hp <= (currentPlayer[player].hp + 35) && potions[player] > 0) {
						currentPlayer[0].hp = heroes[currentPlayer[0].id].hp;
					}
					else if (potions[player] > 0) {
						currentPlayer[0].hp += 35;
					}
					gotoxy(1, 24); cout << attack[language][0] << heal[language];
					Sleep(1000);
					potions[player]--;
					break;
				}
			}
			gotoxy(50, 28); cout << "HP: " << currentPlayer[player].hp;
			gotoxy(50, 29); cout << "MANA: " << currentPlayer[player].mana;
			gotoxy(50, 30);
			if (language == 0)
				cout << "POCIONES: " << potions[player];
			else
				cout << "POTIONS: " << potions[player];
			Sleep(150);
			gameVar.score = 0;
		} while (true);
		if (player == 1)
			player--;
		else if (player == 0)
			player++;
		if (currentPlayer[player].hp < 1) {
			if (player == 1)
				player--;
			else if (player == 0)
				player++;
			Transition_Screen(0, 0, player);
		}
		// Game Over Screen
	}
}

void Transition_Screen(int opponent, int tipe, int character) {
	system("cls");
	Marco();
	locale::global(std::locale("C"));
	string message[6][2] = { { "GANA EL JUGADOR ", "THE WINNER IS PLAYER " },{"MATASTE A ","YOU KILLED " },{"MATASTE AL JEFE ", "YOU KILLED THE BOSS "},{"TE HA MATADO ", "YOU'VE BEEN KILLED BY "},{"MATASTE AL JEFE FINAL!!! ", "YOU KILLED THE FINAL BOSS!!! "},{"VENCISTE A TODOS LOS JEFES!!!","YOU'VE KILLED EVERY BOSS"} };
	string enemyMessage[2][7] = { {"LO SIENTO DON CANGREJOOOOOOOOOO!!!!","Yo solo quería lasaña. :(","Joooojooo...jooojo....jo.....","D�nde est� el amor.","NOO, MARGEEEEEEEEEEE","Don Cangrejo no me paga lo suficiente para esto.","(MICKEY) Volveré. Pronto. Y LOS PUGARÉ A TODOS."},
								{"SORRY MR. KRAAAAAAAAAABS!!!!!","I just wanted some lasagna. :(","Hoooohooo...hoooho....ho....","Where's the love.","NOO, MARGEEEEEEEEEEE","Mr. Krabs doesn't pay me enough for this","(MICKEY) I'll be back. Soon. AND I'LL PURGE ALL OF YOU."} };
	int item = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), heroes[gameVar.chosenHero].color);
	for (int indice = 0; indice < 80; indice++) {
		gotoxy(indice, 0);  cout << char(178);
		gotoxy(indice, 3);  cout << char(178);
		gotoxy(indice, 40); cout << char(178);
	}
	for (int i = 0; i < 41; i++) {
		gotoxy(0, i);
		cout << char(178);
		gotoxy(79, i);
		cout << char(178);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Datos Adversario
	gotoxy(65, 1); cout << gameVar.username;
	clearTitleBox();
	if (tipe == 0 || tipe == 1) {
		if (tipe == 0) {//Mataste A
			gotoxy(30, 2); cout << message[tipe][language] << " " << character;
			for (int i = 0; i < 19; i++) {
				gotoxy(20, 5 + i);
				cout << characters::imagen[opponent][i];
			}
			gotoxy(1, 25); cout << enemyMessage[language][opponent];
		}
		else { //MATASTE ENEMIGO
			gotoxy(30, 2); cout << message[tipe][language] << " " << enemySequence[opponent].name[language];
			int y = 5;
			for (int i = 0; i < 19; i++) {
				gotoxy(20, 5 + i);
				cout << characters::imagen[opponent][i];
			}
			gotoxy(1, 25); cout << enemyMessage[language][opponent];
		}
	}
	else if (tipe == 2) {//MATASTE JEFE
		gotoxy(30, 2); cout << message[2][language] << " " << enemySequence[opponent].name[language];
		for (int indice = 0; indice < 20; indice++) {
			gotoxy(20, 4 + indice); cout << characters::imagen[opponent][indice];
		}
		gotoxy(1, 25); cout << enemyMessage[language][opponent];
	}
	else if (tipe == 3) {//TE MATARON
		gotoxy(30, 2); cout << message[3][language];
		for (int indice = 0; indice < 20; indice++) {//JEFE FINAL
			gotoxy(20, 5 + indice); cout << characters::transiciones[2][indice];
		}

	}
	else if (tipe == 4) {//JEFE FINAL
		gotoxy(30, 2); cout << message[4][language];
		for (int indice = 0; indice < 19; indice++) {
			gotoxy(10, 5 + indice); cout << characters::transiciones[1][indice];
		}
		gotoxy(1, 25); cout << enemyMessage[language][opponent];
	}
	else if (tipe == 5) {
		gotoxy(30, 2); cout << message[4][language];
		for (int indice = 0; indice < 20; indice++) {
			if (language == 0) {
				gotoxy(20, 3 + indice); cout << characters::transiciones[3][indice];
			}
			else {
				gotoxy(20, 3 + indice); cout << characters::transiciones[4][indice];
			}
		}
	}
	do {
		clearDescriptionBox();
		gotoxy(0, 0);
		if (GetAsyncKeyState(VK_RETURN) != 0) {
			break;
		}
		Sleep(150);
	} while (true);
}