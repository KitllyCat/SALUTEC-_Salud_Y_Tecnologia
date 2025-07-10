#include <iostream>
#include <string>
#include "historial.h"
using namespace std;

void registrarDiagnostico(Diagnostico historial[], int &total){
	
	cout << "Ingrese el nombre del paciente: ";
    cin.ignore();
    getline(cin, historial[total].nombrePaciente);

    cout << "Fecha del diagnostico: ";
    getline(cin, historial[total].fecha);

    cout << "Descripcion del diagnostico: ";
    getline(cin, historial[total].descripcion);

    total++;
    cout << "Diagnostico registrado\n";
}

void mostrarHistorial(){
	
}
