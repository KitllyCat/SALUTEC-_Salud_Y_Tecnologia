#include <iostream>
#include <string>
#include "search.h"
using namespace std;

void showPatient(Paciente pacient[], int count){
    for (int i = 0; i < count ; i++){
        cout << "Paciente N°" << i + 1;
        cout << "Nombre: " << pacient->nombre;
        cout << "DNI: " << pacient->DNI;
        cout << "Edad: " << pacient->edad;
        cout << "Sexo: " << pacient->sexo;
        cout << "Tipo de sangre: " << pacient->T_sangre;
        cout << "Número celular: " << pacient->numero;
        cout << "Dirección" << pacient->direccion;
    }
}

void listPatients(Paciente pacient[], int count){
    if (count != 0){
        cout << "Listado general de pacientes" << endl;
        for (int i = 0; i < count ; i++){
            cout << "Paciente N°" << i + 1;
            cout << "Nombre: " << pacient->nombre;
            cout << "DNI: " << pacient->DNI;
            cout << "Edad: " << pacient->edad;
            cout << "Sexo: " << pacient->sexo;
            cout << "Tipo de sangre: " << pacient->T_sangre;
            cout << "Número celular: " << pacient->numero;
            cout << "Dirección" << pacient->direccion;
        }
    }else {
        cout << "ERROR - Ni un paciente registrado." << endl;
    }
    cout << endl;
}

void searchPatientByName(){

}

void searchPatientByDNI(){

}