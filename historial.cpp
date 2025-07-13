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
	
	string nombre;
    bool nombreValido = false;
    
    do{
		cout << "Ingrese el nombre del paciente: ";
	    getline(cin, nombre);
	    
	    for (int i = 0; nombre[i] != '\0'; i++){
            if (nombre[i] !=' '){
                nombreValido = true;
                break;
            }
        }
        
        if (!nombreValido){
            cout << "\n[X] El nombre no puede estar vacio, intentelo de nuevo\n";
        }
        
	}while(!nombreValido);
	
	historial[total].nombrePaciente = nombre;

	string fecha;
    bool fechaValida = false;
    
    do{
	    cout << "Fecha del diagnostico: ";
	    getline(cin, fecha);
	    
	    int longitud = 0;
	    for (int i = 0; fecha[i] != '\0'; i++){
	    	longitud++;
		}
		
	    if (longitud == 10 &&
	        fecha[4] == '-' && fecha[7] == '-' &&
	        fecha[0] >= '0' && fecha[0] <= '9' &&
	        fecha[1] >= '0' && fecha[1] <= '9' &&
	        fecha[2] >= '0' && fecha[2] <= '9' &&
	        fecha[3] >= '0' && fecha[3] <= '9' &&
	        fecha[5] >= '0' && fecha[5] <= '9' &&
	        fecha[6] >= '0' && fecha[6] <= '9' &&
	        fecha[8] >= '0' && fecha[8] <= '9' &&
	        fecha[9] >= '0' && fecha[9] <= '9'){
	        fechaValida = true;
	    } else{
	        cout << "\n[X] Formato de fecha invalido, Use el formato: YYYY-MM-DD\n";
	    }
    
	}while (!fechaValida);
	
	historial[total].fecha = fecha;
	
	
	string descripcion;
	bool descripcionValida = false;
	
	do{
	
	    cout << "Descripcion del diagnostico: ";
	    getline(cin, descripcion);
	    
		for (int i = 0; descripcion[i] != '\0'; i++) {
	        if (descripcion[i] != ' ') {
	            descripcionValida = true;
	            break;
	        }
	    }
	
	    if (!descripcionValida) {
	        cout << "\n[X] La descripcion no puede estar vacia ni contener solo espacios, intentelo de nuevo\n";
	    }
	    
	}while(!descripcionValida);
	
	historial[total].descripcion = descripcion;

    total++;
    cout << "[+] Diagnostico registrado\n";
	
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

void modificarDiagnostico(Diagnostico historial[], int total) {
    string nombre;
    cout << "Ingrese el nombre del paciente cuyo diagnóstico desea modificar: ";
    cin.ignore();
    getline(cin, nombre);

    bool encontrado = false;

    for (int i = 0; i < total; i++){
        if (historial[i].nombrePaciente == nombre){
            cout << "\n--- Diagnóstico encontrado ---\n";
            cout << "Fecha: " << historial[i].fecha << endl;
            cout << "Descripción: " << historial[i].descripcion << endl;

            cout << "\nQue desea modificar?\n";
            cout << "a. Solo la fecha";
            cout << "b. Solo la descripcion";
            cout << "c. Ambas\n";
            cout << "Elija una opcion: ";
            char opcion;
            cin >> opcion;
            cin.ignore();

            if (opcion == 'a' || opcion == 'c'){
                string nuevaFecha;
                bool valido = false;
                do{
                    cout << "Ingrese la nueva fecha: ";
                    getline(cin, nuevaFecha);
        
                    for (int j = 0; nuevaFecha[j] != '\0'; j++){
                        if (nuevaFecha[j] != ' '){
                            valido = true;
                            break;
                        }
                    }
                    if (!valido){
                        cout << "La fecha no puede estar vacia\n";
                    }
                    
                } while (!valido);

                historial[i].fecha = nuevaFecha;
                if (opcion == 'a'){
                    cout << "Fecha actualizada correctamente\n";
                }
            }

            if (opcion == 'b' || opcion == 'c'){
                string nuevaDescripcion;
                bool valido = false;
                do {
                    cout << "Ingrese la nueva descripcion: ";
                    getline(cin, nuevaDescripcion);
                   
                    for (int j = 0; nuevaDescripcion[j] != '\0'; j++) {
                        if (nuevaDescripcion[j] != ' '){
			
                            valido = true;
                            break;
                        }
                    }
                    if (!valido){
                        cout << "La descripcion no puede estar vacia\n";
                    }
                } while (!valido);

                historial[i].descripcion = nuevaDescripcion;
                cout << "Descripcion actualizada correctamente\n";
            }

            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nNo se encontro ningun diagnostico para el paciente ingresado\n";
    }
}
