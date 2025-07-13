#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

const int Cant=100;	
		
struct Paciente{
	string nombre;
	int DNI;
	int edad;
	string sexo;
	string T_sangre;
	int numero;
	string direccion;
};

void Agregar_Paciente(Registro, cont);
void Eliminar_Paciente(Registro, cont);

#endif