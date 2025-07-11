#ifndef SEARCH_H
#define SEARCH_H
#include "paciente.h"

void showPatient(Paciente pacient[], int count); //Muestra los datos de los pacientes
void listPatients(Paciente pacient[], int count); //Listado general de pacientes
void searchPatientByName(); //Listado por el nombre del paciente
void searchPatientByDNI();

#endif