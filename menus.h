#ifndef MENUS_GUI
#define MENUS_GUI
#include <iostream>
#include <windows.h>
#include <string>
#include "paciente.h"
#include "historial.h"
#include "search.h"
using namespace std;

extern Paciente Registro[];
extern int cont;
extern Diagnostico historial[];
extern int totalDiagnosticos;

void activarANSI();
void intro();
void imprimirLineaDinamica();
void menuPrincipal();
void menuR_Pacientes();
void menuHistorial();
void menuDatos();

#endif 