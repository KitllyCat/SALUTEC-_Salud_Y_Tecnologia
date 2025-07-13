#include<iostream>
#include<string>
#include <windows.h>

using namespace std;
const int Cant=100;
int cont=0;

struct Paciente{
	string nombre;
	int edad;
	string sexo;
	string T_sangre;
	int numero;
	string direccion;
};

Paciente Registro[Cant];

void(Paciente Registro[], int &cont){
	cout << "==========================================================" << endl;
    cout << "                REGISTRO DE PACIENTE" << endl;
    cout << "==========================================================" << endl;
    cout<<endl;
    
    cout<<"Nombre: ";
    cout<<cont+1<<".-: ";
    cin.ignore();
    getline(cin, Registro[cont].nombre);
    cout<<endl;
    cout<<"Edad: ";
    cin>>Registro[cont].edad;
    cout<<endl;
    cout<<"Sexo: ";
    getline(cin, Registro[cont].sexo);
    cout<<endl;
    cout<<"Tipo de sangre: ";
    getline(cin, Registro[cont].T_sangre);
    cout<<"NÃºmero: ";
    cout<<endl;
    cin>>Registro[cont].numero;
    cout<<"DirecciÃ³n: ";
    cgetline(cin, Registro[cont].direccion);
	cout<<endl;
	
	cont++;
	cout<<"-------------------Paciente registrado--------------------"<<endl;
	cout<<endl;
}