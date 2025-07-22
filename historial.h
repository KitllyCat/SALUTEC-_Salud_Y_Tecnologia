#ifndef HISTORIAL_H
#define HISTORIAL_H
#include <iostream>
#include <windows.h>
#include <string>
#include "paciente.h"
using namespace std;

struct Diagnostico {
    string nombrePaciente;
    string dni;
    string fecha;
    string descripcion;
};
bool existePaciente(const string& nombre, const string& dni);
void registrarDiagnostico(Diagnostico historial[], int &total);
void mostrarHistorial(Diagnostico historial[], int &total);
void modificarDiagnostico(Diagnostico historial[], int total);
void buscarPorFecha(Diagnostico historial[], int total);
void buscarPorDNI(Diagnostico historial[], int total);

#endif