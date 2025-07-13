#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <string>
using namespace std;

struct Diagnostico {
    string nombrePaciente;
    string dni;
    string fecha;
    string descripcion;
};

void registrarDiagnostico(Diagnostico historial[], int &total);
void mostrarHistorial(Diagnostico historial[], int &total);
void modificarDiagnostico(Diagnostico historial[], int total);
void buscarPorFecha(Diagnostico historial[], int total);

#endif
