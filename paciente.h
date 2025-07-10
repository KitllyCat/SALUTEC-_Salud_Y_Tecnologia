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
	int sexo;
	string T_sangre;
	int numero;
	string direccion;
};

Paciente Registro[Cant];

void Agregar_Paciente(Registro[], int cont);
void Eliminar_Paciente(Registro[], int cont);
void Actualizar_Paciente(Registro[], int cont);

#endif