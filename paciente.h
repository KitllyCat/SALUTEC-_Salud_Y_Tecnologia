#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

const int Cant=100;	
		
struct Paciente{
	string nombre;
	string DNI;
	string edad;
	string sexo;
	string T_sangre;
	string numero;
	string direccion;
};

Paciente Registro[Cant];

void Agregar_Paciente(Registro[], int cont);
void Eliminar_Paciente(Registro[], int cont);
void Actualizar_Paciente(Registro[], int cont);

#endif