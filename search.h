#ifndef SEARCH_H
#define SEARCH_H
#include "paciente.h"
#include <iostream>
#include <windows.h>
#include <string>

extern Paciente Registro[];
extern int cont;

void showPatient(Paciente paciente); //Muestra los datos de los pacientes
void listPatients(Paciente paciente[], int cont); //Listado general de pacientes
void searchPatientByName(Paciente paciente[], int cont); //Listado de pacientes ordenados por nombre
void searchPatientByDNI(Paciente paciente[], int cont); //Listado de pacientes ordenado por DNI

#endif