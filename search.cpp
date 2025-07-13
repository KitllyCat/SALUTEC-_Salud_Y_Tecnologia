#include <iostream>
#include <string>
#include "search.h"
using namespace std;

void showPatient(Paciente pacient){
    cout << "Nombre: " << pacient.nombre << endl;
    cout << "DNI: " << pacient.DNI << endl;
    cout << "Edad: " << pacient.edad << endl;
    cout << "Sexo: " << pacient.sexo << endl;
    cout << "Tipo de sangre: " << pacient.T_sangre << endl;
    cout << "Número celular: " << pacient.numero << endl;
    cout << "Dirección" << pacient.direccion << endl;
}

void listPatients(Paciente pacient[], int count){
    if (count != 0){
        cout << "Listado general de pacientes" << endl;
        for (int i = 0; i < count; i++) {
            cout << "\nPaciente N°" << i + 1 << ":" << endl;
            showPatient(pacient[i]);
        }
    }else {
        cout << "\nERROR - Ni un paciente registrado." << endl;
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
            cout << "\nPaciente encontrado:" << endl;
            showPatient(pacient[i]);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "\nPaciente no encontrado." << endl;
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
            cout << "\nPaciente encontrado:" << endl;
            showPatient(pacient[i]);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "\nPaciente no encontrado." << endl;
    }
}