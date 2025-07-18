#ifndef SEARCH_H
#define SEARCH_H
#include "paciente.h"
#include "colors.h"
#include <iostream>
#include <windows.h>
#include <string>

extern Paciente Registro[];
extern int cont;

void showPatient(Paciente paciente); //Muestra los datos de los pacientes
void listPatients(Paciente* pacient, int count); //Listado general de pacientes
void listPatientsByAge(Paciente* pacient, int count);// listado general por edad
void searchPatientByName(Paciente paciente[], int &cont); //busqueda de pacientes ordenados por nombre
void searchPatientByDNI(Paciente paciente[], int &cont); //busqueda de pacientes ordenado por DNI

#endif