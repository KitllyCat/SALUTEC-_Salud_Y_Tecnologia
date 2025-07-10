#include <iostream>
#include <string>
#include "historial.h"
using namespace std;

void registrarDiagnostico(){
	string nombre;
	
    cout << "Ingrese el nombre del paciente: ";
    cin.ignore();
    getline(cin, nombre);

    for (int i = 0; i < cont; i++) {
        if (Registro[i].nombre == nombre) {
            if (Registro[i].totalDiagnosticos < 10) {
                Diagnostico diag;
                cout << "Fecha del diagnostico: ";
                getline(cin, diag.fecha);
                cout << "Descripcion del diagnostico: ";
                getline(cin, diag.descripcion);

                Registro[i].historial[Registro[i].totalDiagnosticos] = diag;
                Registro[i].totalDiagnosticos++;

                cout << "\nDiagnostico registrado con exito\n";
            } else {
                cout << "El historial de este paciente esta lleno\n";
            }
            return;
        }
    }
    cout << "Paciente no encontrado\n";
	
}
void mostrarHistorial(){
	
}
