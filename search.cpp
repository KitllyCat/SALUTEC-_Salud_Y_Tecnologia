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

void searchPatientByName(){

}

void searchPatientByDNI(){

}