#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

const int Cant=100;

struct Paciente {
    string nombre;
    string DNI;
    string edad;
    string sexo;
    string T_sangre;
    string numero;
    string direccion;
};

extern Paciente Registro[Cant];
extern int cont;

void Agregar_Paciente(Paciente Registro[], int &cont);
void Eliminar_Paciente(Paciente Registro[], int &cont);
void Actualizar_Paciente(Paciente Registro[], int &cont);

#endif