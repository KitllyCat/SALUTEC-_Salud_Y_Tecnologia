#include<iostream>
#include<string>
#include <windows.h>
#inclde "paciente.h"

using namespace std;

R_Paciente[9]={
	{"Ureliano Fernandez", "18", "M", "O+", "923094702", "Miraflores - Av. Torres"},
	{"Olaf Mendoza", "20", "M", "O-", "907539421", "Barranco Calle - Pardos"},
	{"Maricielo Tapia", "22", "F", "O+", "926983513", "Madgalena - Av. Alamos"},
	{"Jimmy Chambe", "30", "M", "B+", "904533861", "Santa Elena - Av. "},
	{"Yadira Arias", "19", "F", "O+", "929473911", "Alameda Asoc.Las Perlas"},
	{"Gabriel Peñaloza", "25", "M", "B-", "938491036", "Los Perales Calle"},
	{"Zhamyra Ramos", "40", "M", "O-", "900372954", "Miraflores Av. Torres"},
	{"Ignacia Hernandez", "57", "M", "B+", "925095173", "Miraflores Av. Torres"},
	{"Mauricio Gutierrez", "17", "M", "O+", "937520947", "Miraflores Av. Torres"},
	{"Diego Jaramillo", "15", "F", "O-", "921957740", "Miraflores Av. Torres"},

};

Paciente Registro[Cant];

void Agregar_Paciente(Paciente Registro[], int &cont){
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
    cout<<"Número: ";
    cout<<endl;
    cin>>Registro[cont].numero;
    cout<<"Dirección: ";
    cgetline(cin, Registro[cont].direccion);
	cout<<endl;
	
	cont++;
	cout<<"-------------------Paciente registrado--------------------"<<endl;
	cout<<endl;
}

int main(){
	
}