#include <iostream>
#include <string>
#include "search.h"
using namespace std;

void showPatient(Paciente pacient[], int count){
    for (int i = 0; i < count ; i++){
        cout << "Paciente N°" << i + 1;
        cout << "Nombre: " << pacient[i].nombre;
        cout << "DNI: " << pacient[i].DNI;
        cout << "Edad: " << pacient[i].edad;
        cout << "Sexo: " << pacient[i].sexo;
        cout << "Tipo de sangre: " << pacient[i].T_sangre;
        cout << "Número celular: " << pacient[i].numero;
        cout << "Dirección" << pacient[i].direccion;
    }
}

void listPatients(Paciente pacient[], int count){
    if (count != 0){
        cout << "Listado general de pacientes" << endl;
        showPatient(pacient, count);
    }else {
        cout << "ERROR - Ni un paciente registrado." << endl;
    }
    cout << endl;
}

void searchPatientByName(Paciente pacient[], int count){
    string nombre;
    cout << "Ingrese el nombre que desea buscar:" << endl;
    getline(cin, nombre);
    bool encontrado = false;
    for (int i = 0; i < count; i++) {
        if (pacient[i].nombre == nombre) {
            cout << "Paciente encontrado:" << endl;
            cout << "Nombre: " << pacient[i].nombre << endl;
            cout << "DNI: " << pacient[i].DNI << endl;
            cout << "Edad: " << pacient[i].edad << endl;
            cout << "Sexo: " << pacient[i].sexo << endl;
            cout << "Tipo de sangre: " << pacient[i].T_sangre << endl;
            cout << "Número celular: " << pacient[i].numero << endl;
            cout << "Dirección: " << pacient[i].direccion << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Paciente no encontrado." << endl;
    }
}

void searchPatientByDNI(){
    
}