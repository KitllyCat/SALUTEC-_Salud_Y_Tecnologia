#ifndef PACIENTE_H
#define PACIENTE_H

#include<string>
using namespace std;

struct Paciente{
	string nombre;
	int DNI;
	int edad;
	string sexo;
	string T_sangre;
	int numero;
	string direccion;
};

void Agregar_Paciente(Paciente Registro[], int &cont);

#endif