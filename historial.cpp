#include <iostream>
#include <string>
#include "historial.h"
using namespace std;

Diagnostico historial[100] = {
    {"Ureliano Buendia", "60449025", "2024-01-10", "Gripe comun, descanso y paracetamol"},
    {"Olaf Linares", "33096724", "2024-02-15", "Dolor lumbar, se indica fisioterapia"},
    {"Maricielo Tapia", "90337611", "2024-03-01", "Alergia estacional, se receta loratadina"},
    {"Jimmy Chambe", "20658732", "2024-03-20", "Presion arterial alta, iniciar tratamiento"},
    {"Yadira Flores", "60573822", "2024-04-08", "Dolor de garganta, infeccion leve"},
    {"Gabriel Peñaloza", "75236112", "2024-05-04", "Lesion leve en pierna, se recomienda reposo"},
    {"Zhamyra Ramos", "91885473", "2024-05-28", "Chequeo general, todo en orden"},
    {"Ignacia Hernandez", "33762819", "2024-06-10", "Diabetes tipo II, control mensual"},
    {"Mauricio Gutierrez", "54073862", "2024-06-20", "Dolor de estomago, dieta blanda"},
    {"Diego Jaramillo", "60456915", "2024-07-01", "Infeccion respiratoria leve"}
};

int totalDiagnosticos = 10;

void registrarDiagnostico(Diagnostico historial[], int &total){
	
	string nombre;
    bool nombreValido = false;
    
    cout << "\n ========================================" << endl;
	cout << "|     REGISTRO DE NUEVO DIAGNOSTICO     |" << endl;
	cout << " ========================================\n";
    
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
            cout << "\n[!] El nombre no puede estar vacio, intentelo de nuevo\n";
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
	        cout << "\n[!] Formato de fecha invalido, use el formato: YYYY-MM-DD\n";
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
	        cout << "\n[!] La descripcion no puede estar vacia ni contener solo espacios, intentelo de nuevo\n";
	    }
	    
	}while(!descripcionValida);
	
	historial[total].descripcion = descripcion;

    total++;
    cout << "[+] Diagnostico registrado\n";
	
}

void mostrarHistorial(Diagnostico historial[], int &total){
	
	string nombre;
	
	cout << "\n =======================================" << endl;
	cout << "|   CONSULTA DE HISTORIAL POR PACIENTE  |" << endl;
	cout << " =======================================\n";

    cout << "\nIngrese el nombre del paciente a consultar: ";
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
        cout << "\n[!]No se encontraron diagnosticos para este paciente" << endl;
    }
}

void modificarDiagnostico(Diagnostico historial[], int total) {
    string nombre;
    
    cout << "\n =======================================" << endl;
	cout << "|      MODIFICACION DE DIAGNOSTICO      |" << endl;
	cout << " =======================================\n";
	
    cout << "\nIngrese el nombre del paciente cuyo diagnóstico desea modificar: ";
    getline(cin, nombre);

    bool encontrado = false;

    for (int i = 0; i < total; i++){
        if (historial[i].nombrePaciente == nombre){
            cout << "\n--- Diagnostico encontrado ---\n";
            cout << "Fecha: " << historial[i].fecha << endl;
            cout << "Descripcion: " << historial[i].descripcion << endl;

            cout << "\nQue desea modificar?\n";
            cout << "a. Solo la fecha\n";
            cout << "b. Solo la descripcion\n";
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
                        cout << "[!] La fecha no puede estar vacia\n";
                    }
                    
                } while (!valido);

                historial[i].fecha = nuevaFecha;
                if (opcion == 'a'){
                    cout << "[+] Fecha actualizada correctamente\n";
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
                        cout << "[!] La descripcion no puede estar vacia\n";
                    }
                } while (!valido);

                historial[i].descripcion = nuevaDescripcion;
                cout << "[+] Descripcion actualizada correctamente\n";
            }

            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\n[!] No se encontro ningun diagnostico para el paciente ingresado\n";
    }
}

void buscarPorFecha(Diagnostico historial[], int total){
    string fechaBuscar;
    
    cout << "\n ========================================" << endl;
	cout << "|   BUSQUEDA DE DIAGNOSTICOS POR FECHA   |" << endl;
	cout << " ========================================\n";

    cout << "\nIngrese la fecha a buscar (formato YYYY-MM-DD): ";
    getline(cin, fechaBuscar);

    bool encontrado = false;
    cout << "\n=== Diagnosticos registrados en la fecha: " << fechaBuscar << " ===\n";
    for (int i = 0; i < total; i++){
        if (historial[i].fecha == fechaBuscar){
            cout << "\nPaciente: " << historial[i].nombrePaciente << endl;
            cout << "Diagostico: " << historial[i].descripcion << endl;
            cout << "---------------------------------------\n";
            encontrado = true;
        }
    }

    if (!encontrado){
        cout << "[!] No se encontraron diagnosticos para esa fecha\n";
    }
}

void buscarPorDNI(Diagnostico historial[], int total) {
    
    cout << "\n ====================================" << endl;
    cout << "|    BUSQUEDA POR DNI DE PACIENTE    |" << endl;
    cout << " ====================================\n";

    string dniBuscar;
	bool dniValido = false;

	do {
	    cout << "Ingrese el DNI a buscar (8 digitos): ";
	    getline(cin, dniBuscar);
	
	    int contador = 0;
	    bool soloDigitos = true;
	
	    for (int i = 0; dniBuscar[i] != '\0'; i++) {
	        if (dniBuscar[i] >= '0' && dniBuscar[i] <= '9') {
	            contador++;
	        } else {
	            soloDigitos = false;
	            break;
	        }
	    }
	
	    if (contador == 8 && soloDigitos) {
	        dniValido = true;
	    } else {
	        cout << "[!] DNI invalido, debe contener exactamente 8 digitos numericos\n";
	    }
	} while (!dniValido);
	
    bool encontrado = false;
    for (int i = 0; i < total; i++) {
        if (historial[i].dni == dniBuscar) {
        	cout << "\n=== Diagnostico del paciente con DNI " << dniBuscar << " ===\n";
            cout << "\nPaciente: " << historial[i].nombrePaciente << endl;
            cout << "Fecha: " << historial[i].fecha << endl;
            cout << "Diagnostico: " << historial[i].descripcion << endl;
            cout << "--------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "\n[!] No se encontraron diagnosticos para ese DNI\n";
    }
}



