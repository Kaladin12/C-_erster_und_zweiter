#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Falta hacer que autentique cuando registra auto, agregar ultimas tres letras
struct Archivos {
	string Paths[10] = {"usuarios.txt","autos.txt","modelos.txt","colores.txt","nacionalidades.txt","mx_estados.txt","us_estados.txt","","",""}; //
	string usuario[10] = {"","","","","","","","","",""};//CURP, Nombre, Apellido, Mes, Dia, Ano, Ciudad, Estado, Pais, genero
	string autos[6] = { "","","","","","" };//CURP, Marca, Linea,Modelo, Placas,Color
	char Vocales[5] = {'a','e','i','o','u'};
	string Consonantes[21] = { "b","c","d","f","g","h","j","k","l","m","n","p","q","r","s","t","v","w","x","y","z" };
	string Meses[12] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
	bool verdadero = false; string subcadena = "";
};
Archivos txt;
string Convertir_Mayusculas(string recibe) {
	string& convertir_upper = recibe;
	for (int i = 0; i < convertir_upper.length(); i++) {
		convertir_upper[i] = toupper(convertir_upper[i]);
	}
	return recibe;
}
void Leer_Archivos(int archivo, string parametro, int aq) {
	string line; int contador = 0;
	bool v=false;
	if (parametro != "")
		v = true;
	ifstream myfile("TXT\\" + txt.Paths[archivo]);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			if (v) {
				if (line.substr(0, line.find_first_of("-")) == parametro ) {
					if (aq == 1)
						txt.verdadero = true;
					else if (aq == 2) {
						txt.subcadena = line.substr(line.find_first_of("-") + 1);
					}
				} 
				else if ((line.substr(line.find_first_of("-") + 1)) == parametro) {
					txt.verdadero = true;
				}
			}
			else
				cout << "[" << contador + 1 << "]-- " << line << '\n'; contador += 1;
		}
		myfile.close();
	}
	else cout << "no se pudo abrir el archivo";
}
void CURP() {
	txt.usuario[0] = txt.usuario[2].substr(0, 1); int param = 0, contador=1;
	string Paterno = txt.usuario[2].substr(1,txt.usuario[2].find_first_of(" "));
	string Materno= txt.usuario[2].substr(txt.usuario[2].find_first_of(" ")+1);
	string Nombre = txt.usuario[1].substr(0,txt.usuario[1].find_first_of(" "));
	for (auto i : Paterno) {
		if (i == txt.Vocales[0] || i == txt.Vocales[1] || i == txt.Vocales[2] || i == txt.Vocales[3] || i == txt.Vocales[4]) {
			txt.usuario[0] = txt.usuario[0] + i; break; 
		}
	}
	txt.usuario[0] = txt.usuario[0] + Materno.substr(0, 1) + Nombre.substr(0,1)+ txt.usuario[5].substr(2);
	for (auto i : txt.Meses) {
		if (i == txt.usuario[3]) {
			if (contador < 10)
				txt.usuario[0] = txt.usuario[0] + "0" + to_string(contador);
			else
				txt.usuario[0] = txt.usuario[0] + to_string(contador);
			break;
		}
		contador += 1;
	}
	if (txt.usuario[4].length() == 1)
		txt.usuario[0] = txt.usuario[0] + "0" + txt.usuario[4]+ txt.usuario[9];
	else
		txt.usuario[0] = txt.usuario[0] + txt.usuario[4]+ txt.usuario[9];
	if (txt.usuario[8] == "MX") param = 5;
	else if (txt.usuario[8] == "US") param = 6;
	Leer_Archivos(param, txt.usuario[7], 2); txt.usuario[0] = txt.usuario[0] + txt.subcadena;
	string uno, dos, tres;
	for (int indice = 0; indice < Paterno.length(); indice++) {
		bool salir = false;
		for (int i_1 = 0; i_1 < 21; i_1++){
			cout << Paterno.substr(indice, 1);
			if (txt.Consonantes[i_1] == Paterno.substr(indice, 1)) {
				uno = txt.Consonantes[i_1]; salir = true; break;
			}
		} if (salir) break;
	} 
	for (int indice = 0; indice < Paterno.length(); indice++) {
		bool salir = false;
		for (int i_1 = 0; i_1 < 21; i_1++) {
			cout << Materno.substr(indice, 1);
			if (txt.Consonantes[i_1] == Materno.substr(indice, 1)) {
				dos = txt.Consonantes[i_1]; salir = true; break;
			}
		}if (salir) break;
	}
	for (int indice = 0; indice < Paterno.length(); indice++) {
		bool salir = false;
		for (int i_1 = 0; i_1 < 21; i_1++) {
			if (txt.Consonantes[i_1] == Nombre.substr(indice, 1)) {
				tres = txt.Consonantes[i_1]; salir = true; break;
			}
		}if (salir) break;
	}
	txt.usuario[0] = txt.usuario[0] + uno + dos + tres; txt.usuario[0] = Convertir_Mayusculas(txt.usuario[0]);
}
void Escribir(int archivo) {
	ofstream myfile("TXT\\" + txt.Paths[archivo], ofstream::app);
	if (myfile.is_open()){
		myfile <<endl<< txt.subcadena;
		myfile.close();
	}
}

void Dar_Alta(int archivo) {
	string respuesta="";
	if (archivo == 0) {
		cout << "Introduzca sus nombres: [Respete las mayusculas]\n"; getline(cin, txt.usuario[1]); txt.usuario[1] = txt.usuario[1] + " ";
		cout << "Introduzca sus Apellidos [Paterno y Materno]: [Respete las mayusculas]\n"; getline(cin, txt.usuario[2]); txt.usuario[2] = txt.usuario[2] + " ";
		cout << "Introduzca su mes de nacimiento [ejemplo: Noviembre]: "; getline(cin, txt.usuario[3]);
		cout << "Introduzca su dia de nacimiento: "; getline(cin, txt.usuario[4]);
		cout << "Introduzca su ano de nacimiento: "; getline(cin, txt.usuario[5]);
		cout << "Introduzca su nacionalidad: \n"; Leer_Archivos(4, "",0); getline(cin, respuesta);
		if (respuesta == "1") {
			txt.usuario[8] = "MX";
			cout << "Introduzca el estado: [Respete las mayusculas]\n"; getline(cin, respuesta); Leer_Archivos(5, respuesta,1);
			if (txt.verdadero) {
				txt.usuario[7] = respuesta; txt.verdadero = false;
			}
			else {
				cout << "Estado Inexistente, Introduzca uno correcto: \n";
				while (txt.verdadero == false) {
					cout << "Introduzca el estado: [Respete las mayusculas]\n"; getline(cin, respuesta); Leer_Archivos(5, respuesta,1);
					if (txt.verdadero)
						txt.usuario[7] = respuesta;
				}	txt.verdadero = false;
			}
		}
		else if (respuesta == "2") {
			txt.usuario[8] = "US";
			cout << "Introduzca el estado: [Respete las mayusculas]\n"; getline(cin, respuesta); Leer_Archivos(6, respuesta,1);
			if (txt.verdadero) {
				txt.usuario[7] = respuesta; txt.verdadero = false;
			}
			else {
				cout << "Estado Inexistente, Introduzca uno correcto: \n";
				while (txt.verdadero == false) {
					cout << "Introduzca el estado: [Respete las mayusculas]\n"; getline(cin, respuesta); Leer_Archivos(6, respuesta,1);
					if (txt.verdadero)
						txt.usuario[7] = respuesta;
				}	txt.verdadero = false;
			}
		}
		else
			txt.usuario[5] = "Otro";
		cout << "Introduzca su ciudad de nacimiento: [Respete las mayusculas]\n"; getline(cin, txt.usuario[6]);
		cout << "Introduzca su genero: \n[H]--Hombre\n[M]--Mujer"; getline(cin, txt.usuario[9]);
		CURP();
		txt.subcadena = txt.usuario[0] + "-" + txt.usuario[1] + "-" + txt.usuario[2] + "-" + txt.usuario[3] + "-" + txt.usuario[4] + "-" + txt.usuario[5] + "-" + txt.usuario[6] + "-" + txt.usuario[7] + "-" + txt.usuario[8] + "\n";
		Escribir(0);
	}
	else {
		cout << "Introduzca Marca: [Primera letra mayuscula]\n"; getline(cin, respuesta); 
		Leer_Archivos(2, respuesta, 1);
		if (txt.verdadero) {
			txt.autos[1] = respuesta; txt.verdadero = false;
		}
		else {
			cout << "Marca Inexistente, Introduzca uno correcto: \n";
			while (txt.verdadero == false) {
				cout << "Introduzca Marca: [Primera letra mayuscula]\n"; getline(cin, respuesta); Leer_Archivos(2, respuesta, 1);
				if (txt.verdadero)
					txt.autos[1] = respuesta;
			}	txt.verdadero = false;
		}
		cout << "Introduzca Linea: [Primera letra mayuscula]\n"; getline(cin, respuesta);
		Leer_Archivos(2, respuesta, 1);
		if (txt.verdadero) {
			txt.autos[2] = respuesta; txt.verdadero = false;
		}
		else {
			cout << "Marca Inexistente, Introduzca uno correcto: \n";
			while (txt.verdadero == false) {
				cout << "Introduzca Marca: [Primera letra mayuscula]\n"; getline(cin, respuesta); Leer_Archivos(2, respuesta, 1);
				if (txt.verdadero)
					txt.autos[2] = respuesta;
			}	txt.verdadero = false;
		}
		cout << "Introduzca Modelo (ano): "; getline(cin,txt.autos[3]);
		cout << "Introduzca las Placas: "; getline(cin,txt.autos[4]);
		cout << "Introduzca Color: [Primera letra mayuscula]\n"; getline(cin, respuesta);
		Leer_Archivos(3, respuesta, 1);
		if (txt.verdadero) {
			txt.autos[5] = respuesta; txt.verdadero = false;
		}
		else {
			cout << "Color Inexistente, Introduzca uno correcto: \n";
			while (txt.verdadero == false) {
				cout << "Introduzca Color: \n"; getline(cin, respuesta); Leer_Archivos(3, respuesta, 1);
				if (txt.verdadero)
					txt.autos[5] = respuesta;
			}	txt.verdadero = false;
		}
		txt.subcadena = txt.autos[0]+"-"+txt.autos[1]+"-"+txt.autos[2]+"-"+txt.autos[3]+"-" + txt.autos[4] + "-" + txt.autos[5];
		Escribir(1);
	}
}
void Consultar(string CURP, int tipo) {
	Leer_Archivos(0,CURP,1);
	if (txt.verdadero) {
		string line;
		ifstream myfile("TXT\\" + txt.Paths[1]);
		if (myfile.is_open()){
			while (getline(myfile, line)){
				size_t encontrado = line.find(CURP);
				if (tipo == 0) {
					if (encontrado != string::npos) {
						cout << line.substr(line.find_first_of("-") + 1) << endl; txt.verdadero = true;
					}
					else {
						txt.verdadero = false;
					}
				}
				else if (tipo == 1) {
					if (encontrado != string::npos)
						txt.verdadero = true;
				}
			}
			myfile.close();
		}
	}
}
void Consulta_Nombre(string Nombre) {
	string line;
		ifstream myfile("TXT\\" + txt.Paths[0]);
		if (myfile.is_open()){
			while (getline(myfile, line)){
				size_t encontrado = line.find(Nombre);
				if (encontrado != string::npos) {
					string n = line.substr(0, line.find_first_of("-"));
					string line_2;
					ifstream myfile_2("TXT\\" + txt.Paths[1]);
					if (myfile_2.is_open()) {
						while (getline(myfile_2, line_2)) {
							size_t encontrado = line_2.find(n);
							if (encontrado != string::npos) {
								cout << line_2 << endl;
							}
						}
						myfile.close();
					}
				}
			}
			myfile.close();
		}
}
int main() {
	string respuesta="", salir="";
	do
	{
		cout << "Que desea hacer?: \n[a]--Registrar Usuario\n[b]--Registrar Automovil\n[c]--Consultar por CURP\n[d]--Consultar por Nombre";getline(cin, respuesta);
		if (respuesta == "a") {
			system("cls"); Dar_Alta(0); cout << txt.subcadena; txt.subcadena = "";
		}
		else if (respuesta=="b"){
			system("cls"); cout << "Ingrese CURP: [Respete las mayusculas]\n"; getline(cin, respuesta); Consultar(respuesta,1);
			if (txt.verdadero) {
				txt.verdadero = false; txt.autos[0] = respuesta;
				Dar_Alta(1);
			}
			else {
				while (txt.verdadero==false){
				 system("cls"); cout << txt.verdadero; cout << "Uusario no encontrado, Vuelva a intentarlo\n";
					cout << "Ingrese CURP: [Respete las mayusculas]\n"; getline(cin, respuesta); Consultar(respuesta, 1);
					if (txt.verdadero) {
						txt.autos[0] = respuesta;
						Dar_Alta(1); txt.verdadero = true;
					} 
				}txt.verdadero = false;
			}
		}
		else if(respuesta=="c"){
			system("cls");
			cout << "Ingrese CURP: [Respete las mayusculas]\n"; getline(cin, respuesta);
			Consultar(respuesta,0);
			if (txt.verdadero==false){
				while (txt.verdadero == false) {
					cout << txt.verdadero; cout << "Usario no encontrado, Vuelva a intentarlo\n";
					cout << "Ingrese CURP: "; getline(cin, respuesta); Consultar(respuesta, 1);
					if (txt.verdadero) {
						Consultar(respuesta,0);
						txt.verdadero = true;
					}
				}txt.verdadero = false;
			}
		}
		else {
			system("cls");
			cout << "Ingrese Nombre sin apellidos: [Respete las mayusculas]\n"; getline(cin, respuesta);
			Consulta_Nombre(respuesta);
		}
	 cout << "Desea continuar?: [y]--si [n]--no\n"; getline(cin, salir);
	 system("cls");
	} while (salir!="n");
	system("pause");
	return EXIT_SUCCESS;
}