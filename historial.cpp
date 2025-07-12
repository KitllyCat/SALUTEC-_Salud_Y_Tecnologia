#include <iostream>
#include <string>
#include "historial.h"
using namespace std;

Diagnostico historial[100] = {
    {"Ureliano Buendia", "2024-01-10", "Gripe comun, descanso y paracetamol"},
    {"Olaf Linares", "2024-02-15", "Dolor lumbar, se indica fisioterapia"},
    {"Maricielo Tapia", "2024-03-01", "Alergia estacional, se receta loratadina"},
    {"Jimmy Chambe", "2024-03-20", "Presion arterial alta, iniciar tratamiento"},
    {"Yadira Flores", "2024-04-08", "Dolor de garganta, infeccion leve"},
    {"Gabriel Peñaloza", "2024-05-04", "Lesion leve en pierna, se recomienda reposo"},
    {"Zhamyra Ramos", "2024-05-28", "Chequeo general, todo en orden"},
    {"Ignacia Hernandez", "2024-06-10", "Diabetes tipo II, control mensual"},
    {"Mauricio Gutierrez", "2024-06-20", "Dolor de estomago, dieta blanda"},
    {"Diego Jaramillo", "2024-07-01", "Infeccion respiratoria leve"}
};

int totalDiagnosticos = 10;

void registrarDiagnostico(Diagnostico historial[], int &total){
	
	cout << "Ingrese el nombre del paciente: ";
    cin.ignore();
    getline(cin, historial[total].nombrePaciente);

    cout << "Fecha del diagnostico: ";
    getline(cin, historial[total].fecha);

    cout << "Descripcion del diagnostico: ";
    getline(cin, historial[total].descripcion);

    total++;
    cout << "Diagnostico registrado\n";
}

void mostrarHistorial(Diagnostico historial[], int &total){
	
	string nombre;
    cout << "Ingrese el nombre del paciente a consultar: ";
    cin.ignore();
    getline(cin, nombre);

    bool encontrado = false;
    cout << "\n=== Historial medico de " << nombre << " ===" << endl;
    for (int i = 0; i < total; i++){
        if (historial[i].nombrePaciente == nombre){
            cout << "Fecha: " << historial[i].fecha << endl;
            cout << "Diagnostico: " << historial[i].descripcion << endl;
            cout << "---------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado){
        cout << "\nNo se encontraron diagnosticos para este paciente" << endl;
    }
}
