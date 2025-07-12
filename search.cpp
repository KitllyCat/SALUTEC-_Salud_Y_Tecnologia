#include <iostream>
#include <string>
#include "search.h"
using namespace std;

void showPatient(Paciente pacient){
    cout << "Nombre: " << pacient.nombre;
    cout << "DNI: " << pacient.DNI;
    cout << "Edad: " << pacient.edad;
    cout << "Sexo: " << pacient.sexo;
    cout << "Tipo de sangre: " << pacient.T_sangre;
    cout << "Número celular: " << pacient.numero;
    cout << "Dirección" << pacient.direccion;
}

void listPatients(Paciente pacient[], int count){
    if (count != 0){
        cout << "Listado general de pacientes" << endl;
        for (int i = 0; i < count; i++) {
            cout << "Paciente N°" << i + 1 << ":" << endl;
            showPatient(pacient[i]);
        }
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
            showPatient(pacient[i]);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Paciente no encontrado." << endl;
    }
}

void searchPatientByDNI(Paciente pacient[], int count){
    int dni;
    cout << "Ingrese el DNI que desea buscar:" << endl;
    cin >> dni;
    cin.ignore();
    bool encontrado = false;
    for (int i = 0; i < count; i++) {
        if (pacient[i].DNI == dni) {
            cout << "Paciente encontrado:" << endl;
            showPatient(pacient[i]);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Paciente no encontrado." << endl;
    }
}