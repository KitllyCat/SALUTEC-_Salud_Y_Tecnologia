#include <iostream>
#include <windows.h>
#include <string>
#include "search.h"
#include "paciente.h"
#include "colors.h"
using namespace std;

void showPatient(Paciente pacient){
	cout<<CYAN<<" ╔═════════════════════"<<BLUE<<"●•●"<<CYAN<<"═════════════════════╗"<<endl;
    cout<<"  Nombre: " << pacient.nombre << endl;
    cout<<"  DNI: " << pacient.DNI << endl;
    cout<<"  Edad: " << pacient.edad << endl;
    cout<<"  Sexo: " << pacient.sexo << endl;
    cout<<"  Tipo de sangre: " << pacient.T_sangre << endl;
    cout<<"  Número celular: " << pacient.numero << endl;
    cout<<"  Dirección" << pacient.direccion << endl;
    cout<<" ╚═════════════════════"<<BLUE<<"●•●"<<CYAN<<"═════════════════════╝"<<endl<<endl;
}

void listPatients(Paciente* pacient, int count) {
    if (cont != 0){
        cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗"<<endl;
		cout<<" ║                  LISTADO GENERAL DE LOS PACIENTES                     ║"<<endl;
		cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
        for (int i = 0; i < cont; i++) {
            cout << BLUE<<" Paciente N°" << i + 1 << ":" << endl;
            showPatient(pacient[i]);
        }
    }else {
        cout << RED <<" ERROR!!! - Ni un paciente registrado." << endl;
        Sleep(1500); system("cls");
    }
    cout << endl;
    cout<<" Presione enter para regresar al menú...";
	cin.ignore(); cin.get();
	system("cls");
}

void searchPatientByName(Paciente pacient[], int &count){
    string nombre;
    cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗"<<endl;
	cout<<" ║                          BUSCAR POR NOMBRE                            ║"<<endl;
	cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
    cout << CYAN<<" Ingrese el nombre que desea buscar:" ;
    cin.ignore();
    getline(cin, nombre);
    bool encontrado = false;
    for (int i = 0; i < count; i++) {
        if (pacient[i].nombre == nombre) {
            cout <<endl<< GREEN<<" Paciente encontrado:" << endl;
            showPatient(pacient[i]);
            cout<<" Presione enter para regresar al menú...";
			cin.ignore(); cin.get();
			system("cls");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << RED << " Paciente no encontrado!!!" << endl;
        Sleep(1500); system("cls");
    }
}

void searchPatientByDNI(Paciente pacient[], int &count){
	cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗"<<endl;
	cout<<" ║                           BUSCAR POR DNI                              ║"<<endl;
	cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
    string dni;
    cout << CYAN<<" Ingrese el DNI que desea buscar:" ;
    cin >> dni;
    cin.ignore();
    bool encontrado = false;
    for (int i = 0; i < count; i++) {
        if (pacient[i].DNI == dni) {
            cout << GREEN <<" Paciente encontrado:" << endl;
            showPatient(pacient[i]);
            cout<<" Presione enter para regresar al menú...";
			cin.ignore(); cin.get();
			system("cls");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << RED <<" Paciente no encontrado!!!" << endl;
    	Sleep(1500); system("cls");
    }
}