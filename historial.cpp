#include <iostream>
#include <windows.h>
#include <string>
#include "historial.h"
#include "paciente.h"
#include "colors.h"
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

bool existePaciente(const string& nombre, const string& dni) {
    for (int i = 0; i < cont; i++) {
        if (Registro[i].nombre == nombre && Registro[i].DNI == dni) {
            return true;
        }
    }
    return false;
}

void registrarDiagnostico(Diagnostico historial[], int &total){
	
	string nombre;
    bool nombreValido = false;
	cout<<CYAN<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╗"<<endl;
	cout<<" ║                    REGISTRO DE NUEVO DIAGNOSTICO                      ║"<<endl;
	cout<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╝"<<endl<<endl; 
    
    do{
		cout << CYAN<<" Ingrese el nombre del paciente: ";
		cin.ignore();
	    getline(cin, nombre);
	    for (int i = 0; nombre[i] != '\0'; i++){
            if (nombre[i] !=' '){
                nombreValido = true;
                break;
            }
        }
        if (!nombreValido){
            cout << RED<<" El nombre no puede estar vacio!!!"<<ORANGE<<" Intentelo de nuevo!!!"<<endl;
        }
        
	}while(!nombreValido);
	historial[total].nombrePaciente = nombre;
    string dni;
    bool dniValido = false;

    do {
        cout << CYAN<<" Ingrese el DNI del paciente (8 digitos): ";
        getline(cin, dni);
        int contador = 0;
        bool soloNumeros = true;

        for (int i = 0; dni[i] != '\0'; i++) {
            contador++;
            if (dni[i] < '0' || dni[i] > '9') {
                soloNumeros = false;
                break;
            }
        }

        if (contador == 8 && soloNumeros) {
            dniValido = true;
        } else {
            cout <<RED<<" El DNI debe contener exactamente 8 digitos numericos!!!"<<endl;
        }

    } while (!dniValido);
    
	if (!existePaciente(nombre, dni)) {
	    cout << RED << " El paciente no está registrado!!!" << ORANGE << " Regístrelo antes de añadir un diagnóstico." << endl;
	    Sleep(2000); system("cls");
	    return;
	}
	
    historial[total].dni = dni;

	string fecha;
    bool fechaValida = false;
    
    do{
	    cout << CYAN<<" Fecha del diagnostico(YYYY-MM-DD): ";
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
	    	cout << RED<<" Formato de fecha invalido!!!"<<ORANGE<<" Use el formato: (YYYY-MM-DD)"<<endl;
	    }
    
	}while (!fechaValida);
	historial[total].fecha = fecha;
	string descripcion;
	bool descripcionValida = false;
	
	do{
	
	    cout << CYAN<<" Descripcion del diagnostico: ";
	    getline(cin, descripcion);
	    
		for (int i = 0; descripcion[i] != '\0'; i++) {
	        if (descripcion[i] != ' ') {
	            descripcionValida = true;
	            break;
	        }
	    }
	
	    if (!descripcionValida) {
	        cout << RED<<"La descripcion no puede estar vacia ni contener solo espacios!!!"<<ORANGE<<" Intentelo de nuevo"<<endl;
	    }
	    
	}while(!descripcionValida);
	
	historial[total].descripcion = descripcion;

    total++;
    cout<<CYAN<<" ════════════════════════•"<<GREEN<<"Diagnostico registrado"<<CYAN<<"•════════════════════════"<<endl<<endl; 
    Sleep(1500);system("cls");
	
}

void mostrarHistorial(Diagnostico historial[], int &total){
	string nombre;
	cout<<CYAN<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╗"<<endl;
	cout<<" ║                 CONSULTA DE HISTORIAL POR PACIENTE                    ║"<<endl;
	cout<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╝"<<endl<<endl; 

    cout << CYAN<<" Ingrese el nombre del paciente a consultar: ";
    cin.ignore();
    getline(cin, nombre);

    bool encontrado = false;

    for (int i = 0; i < total; i++){
        if (historial[i].nombrePaciente == nombre){
        	cout << CYAN<<" ╔═══════════════════════════"<<BLUE<<"●•●"<<CYAN<<"═══════════════════════════╗"<<endl;
    		cout << CYAN<<"  Historial medico de " <<BLUE<< nombre << CYAN<<" " << endl;
			cout << CYAN<<"  DNI: " << historial[i].dni << endl;
            cout << CYAN<<"  Fecha: " << historial[i].fecha << endl;
            cout << CYAN<<"  Diagnostico: " << historial[i].descripcion << endl;
            cout << CYAN<<" ╚═══════════════════════════"<<BLUE<<"●•●"<<CYAN<<"═══════════════════════════╝"<<endl<<endl;
            encontrado = true;
        }
    }
    if (!encontrado){
        cout << RED<<" No se encontraron diagnosticos para este paciente!!!" << endl<<endl;
        Sleep(1500); system("cls"); return;
    }
	cout<<CYAN<<" Presione enter para regresar al menú... ";
	cin.get(); system("cls");
}

void modificarDiagnostico(Diagnostico historial[], int total) {
    string nombre;
    cout << CYAN << " ╔══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╗" << endl;
    cout << " ║                    MODIFICACION DE DIAGNOSTICO                        ║" << endl;
    cout << " ╚══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╝" << endl << endl;

    cout << CYAN << " Ingrese el nombre del paciente cuyo diagnóstico desea modificar: ";
    cin.ignore();
    getline(cin, nombre);
    bool encontrado = false;

    for (int i = 0; i < total; i++) {
        if (historial[i].nombrePaciente == nombre) {
            encontrado = true;
            bool continuar = true;
            while (continuar) {
                system("cls");
                for (int i = 0; i < total; i++){
			        if (historial[i].nombrePaciente == nombre){
			        	cout << CYAN<<" ╔═══════════════════════════"<<BLUE<<"●•●"<<CYAN<<"═══════════════════════════╗"<<endl;
			    		cout << CYAN<<"  Historial medico de " <<BLUE<< nombre << CYAN<<" " << endl;
						cout << CYAN<<"  DNI: " << historial[i].dni << endl;
			            cout << CYAN<<"  Fecha: " << historial[i].fecha << endl;
			            cout << CYAN<<"  Diagnostico: " << historial[i].descripcion << endl;
			            cout << CYAN<<" ╚═══════════════════════════"<<BLUE<<"●•●"<<CYAN<<"═══════════════════════════╝"<<endl<<endl;
			            encontrado = true;
			        }
			    }
                cout << CYAN << " ¿Qué desea modificar?" << endl;
                cout << " A) Fecha del diagnóstico" << endl;
                cout << " B) Descripción" << endl;
                cout << " C) DNI" << endl;
                cout << " D) Todos los campos" << endl;
                cout << " S) Regresar al menu anterior..." << endl;
                cout << " Seleccione una opción: ";

                char opcion;
                cin >> opcion;
                cin.ignore(1000, '\n');

                switch (opcion){
                    case 'A': 
                    case 'a': {
                    	system("cls");
                        string nuevaFecha;
                        bool fechaValida = false;
                        	cout<<CYAN<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╗"<<endl;
							cout<<" ║                             EDITAR FECHA                              ║"<<endl;
							cout<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╝"<<endl<<endl; 
                        do {
                            cout << endl<< CYAN << " Ingrese la nueva fecha (YYYY-MM-DD): ";
                            getline(cin, nuevaFecha);
                            if (nuevaFecha.length() == 10 && nuevaFecha[4] == '-' && nuevaFecha[7] == '-') {
                                fechaValida = true;
                            } else {
                                cout << RED << " Formato de fecha inválido!!!" << endl;
                                
                            }
                        } while (!fechaValida);
                        historial[i].fecha = nuevaFecha;
                        cout<<endl<<CYAN<<" ═══════════════════════════•"<<GREEN<<"Fecha actualizada"<<CYAN<<"•═══════════════════════════"<<endl<<endl;
                        Sleep(1500); system("cls");
                        break;
                    }
                    case 'B': 
                    case 'b': {
                    	system("cls");
                        string nuevaDescripcion;
                        bool valido = false;
                        cout<<CYAN<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╗"<<endl;
						cout<<" ║                          EDITAR DESCRIPCION                           ║"<<endl;
						cout<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╝"<<endl<<endl; 
                        do {
                            cout <<CYAN << " Ingrese la nueva descripción: ";
                            getline(cin, nuevaDescripcion);
                            if (nuevaDescripcion.find_first_not_of(' ') != string::npos) {
                                valido = true;
                            } else {
                                cout << RED << " La descripción no puede estar vacía!!!" << endl;
                            }
                        } while (!valido);
                        historial[i].descripcion = nuevaDescripcion;
                        cout<<CYAN<<" ════════════════════════•"<<GREEN<<"Descripción actualizada"<<CYAN<<"•═════════════════════════"<<endl<<endl;
                        Sleep(1500); system("cls");
                        break;
                    }
                    case'C':
                    case'c':{
                    	system("cls");
		                string nuevoDNI;
		                bool dniValido = false;
						cout<<CYAN<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╗"<<endl;
						cout<<" ║                              EDITAR DNI                               ║"<<endl;
						cout<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╝"<<endl<<endl; 
		                do {
		                    cout << CYAN<<" Ingrese el nuevo DNI (8 digitos numericos): ";
		                    getline(cin, nuevoDNI);
		
		                    int contador = 0;
		                    bool soloDigitos = true;
		
		                    for (int j = 0; nuevoDNI[j] != '\0'; j++) {
		                        contador++;
		                        if (nuevoDNI[j] < '0' || nuevoDNI[j] > '9') {
		                            soloDigitos = false;
		                            break;
		                        }
		                    }
		
		                    if (contador == 8 && soloDigitos) {
		                        dniValido = true;
		                    } else {
		                        cout << RED << " DNI inválido!!!" <<ORANGE<<" Debe contener exactamente 8 digitos numericos"<<endl;
		                    }
		
		                } while (!dniValido);
						encontrado = true;
		                historial[i].dni = nuevoDNI;
		                cout<<endl<<CYAN<<" ════════════════════════════•"<<GREEN<<"DNI actualizado"<<CYAN<<"•════════════════════════════"<<endl<<endl;
		            	Sleep(1500); system("cls");
					break;
					}
                    case 'D': 
                    case 'd': {
                    	system("cls");
                        string nuevaFecha;
                        bool fechaValida = false;
                        cout<<CYAN<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╗"<<endl;
						cout<<" ║                             EDITAR TODO                               ║"<<endl;
						cout<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╝"<<endl<<endl; 
                        do {
                            cout << CYAN << " Ingrese la nueva fecha (YYYY-MM-DD): ";
                            getline(cin, nuevaFecha);
                            if (nuevaFecha.length() == 10 && nuevaFecha[4] == '-' && nuevaFecha[7] == '-') {
                                fechaValida = true;
                            } else {
                                cout << RED << " Formato de fecha inválido!" << endl;
                            }
                        } while (!fechaValida);
                        historial[i].fecha = nuevaFecha;
                        string nuevaDescripcion;
                        bool descValida = false;
                        do {
                            cout << CYAN << " Ingrese la nueva descripción: ";
                            getline(cin, nuevaDescripcion);
                            if (nuevaDescripcion.find_first_not_of(' ') != string::npos) {
                                descValida = true;
                            } else {
                                cout << RED << " La descripción no puede estar vacía!!!" << endl;
                            }
                        } while (!descValida);
                        historial[i].descripcion = nuevaDescripcion;
                        string nuevoDNI;
		                bool dniValido = false;
		
		                do {
		                    cout << CYAN<<" Ingrese el nuevo DNI (8 digitos numericos): ";
		                    getline(cin, nuevoDNI);
		
		                    int contador = 0;
		                    bool soloDigitos = true;
		
		                    for (int j = 0; nuevoDNI[j] != '\0'; j++) {
		                        contador++;
		                        if (nuevoDNI[j] < '0' || nuevoDNI[j] > '9') {
		                            soloDigitos = false;
		                            break;
		                        }
		                    }
		
		                    if (contador == 8 && soloDigitos) {
		                        dniValido = true;
		                    } else {
		                        cout << RED << " DNI inválido!!!" <<ORANGE<<" Debe contener exactamente 8 digitos numericos"<<endl;
		                    }
		
		                } while (!dniValido);
		                historial[i].dni = nuevoDNI;
		                cout<<endl<<CYAN<<" ════════════════════•"<<GREEN<<"Todos los Datos se actualizaron"<<CYAN<<"•════════════════════"<<endl<<endl;
				        Sleep(1500); system("cls");
		                
		            break;
                    }
                    case 'S':
                    case 's': {
                        continuar = false;
                        cout <<endl<< CYAN << " Saliendo al menú..." << endl;
                        Sleep(1500); system("cls");
                        break;
                    default:
                        cout << RED << " Opción inválida!!!"<<ORANGE<< " Intente nuevamente." << endl;
                        Sleep(1500); system("cls");
                        break;
                	}
            	}
            }
            break;
        }
    }

    if (!encontrado) {
        cout << RED << " No se encontró ningún diagnóstico para el paciente ingresado..." << endl;
        Sleep(1500); system("cls");
    }
}

void buscarPorFecha(Diagnostico historial[], int total){
    string fechaBuscar;
	cout<<CYAN<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╗"<<endl;
	cout<<" ║                 BUSQUEDA DE DIAGNOSTICOS POR FECHA                    ║"<<endl;
	cout<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╝"<<endl<<endl; 
    bool fechaValida = false;
    do {
        cout <<CYAN<< " Ingrese la fecha a buscar (YYYY-MM-DD): ";
        cin.ignore();
        getline(cin, fechaBuscar);
        int longitud = 0;
        for (int i = 0; fechaBuscar[i] != '\0'; i++) {
            longitud++;
        }
        if (longitud == 10 &&
            fechaBuscar[4] == '-' && fechaBuscar[7] == '-' &&
            fechaBuscar[0] >= '0' && fechaBuscar[0] <= '9' &&
            fechaBuscar[1] >= '0' && fechaBuscar[1] <= '9' &&
            fechaBuscar[2] >= '0' && fechaBuscar[2] <= '9' &&
            fechaBuscar[3] >= '0' && fechaBuscar[3] <= '9' &&
            fechaBuscar[5] >= '0' && fechaBuscar[5] <= '9' &&
            fechaBuscar[6] >= '0' && fechaBuscar[6] <= '9' &&
            fechaBuscar[8] >= '0' && fechaBuscar[8] <= '9' &&
            fechaBuscar[9] >= '0' && fechaBuscar[9] <= '9') {
            fechaValida = true;
        } else {
            cout << RED<<" Formato de fecha invalido!!!"<<ORANGE<<" Use el formato: YYYY-MM-DD"<<endl;
        }
    } while (!fechaValida);


    bool encontrado = false;
    for (int i = 0; i < total; i++){
        if (historial[i].fecha == fechaBuscar){
        	cout << CYAN<<" ╔═══════════════════════════"<<BLUE<<"●•●"<<CYAN<<"═══════════════════════════╗"<<endl;
        	cout << "  Diagnosticos registrados en la fecha: " << fechaBuscar <<endl;
            cout << "  Paciente: " << historial[i].nombrePaciente << endl;
            cout << "  DNI: " << historial[i].dni << endl;
            cout << "  Diagnostico: " << historial[i].descripcion << endl;
            cout << CYAN<<" ╚═══════════════════════════"<<BLUE<<"●•●"<<CYAN<<"═══════════════════════════╝"<<endl<<endl;
            encontrado = true;
        }
        
    }
	
    if (!encontrado){
        cout << RED<<"No se encontraron diagnosticos para esa fecha!!!"<<endl;
        Sleep(1500); system("cls");
    }
    cout <<" Presione enter para regresar al menú... ";
	cin.ignore(); cin.get(); system("cls");
}

void buscarPorDNI(Diagnostico historial[], int total) {
	cout<<CYAN<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╗"<<endl;
	cout<<" ║                    BUSQUEDA POR DNI DE PACIENTE                       ║"<<endl;
	cout<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╝"<<endl<<endl; 
    string dniBuscar;
	bool dniValido = false;
	
	do {
	    cout << " Ingrese el DNI a buscar (8 digitos): ";
	    cin.ignore();
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
	        cout << RED<<" DNI invalido!!!"<<ORANGE<<" Debe contener exactamente 8 digitos numericos"<<endl;
	        Sleep(1500); system("cls");
	    }
	} while (!dniValido);
	
    bool encontrado = false;
    for (int i = 0; i < total; i++) {
        if (historial[i].dni == dniBuscar) {
        	cout << CYAN<<" ╔═══════════════════════════"<<BLUE<<"●•●"<<CYAN<<"═══════════════════════════╗"<<endl;
        	cout << "  Diagnostico del paciente con DNI " << dniBuscar <<endl;
            cout << "  Paciente: " << historial[i].nombrePaciente << endl;
            cout << "  Fecha: " << historial[i].fecha << endl;
            cout << "  Diagnostico: " << historial[i].descripcion << endl;
            cout << CYAN<<" ╚═══════════════════════════"<<BLUE<<"●•●"<<CYAN<<"═══════════════════════════╝"<<endl<<endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << RED<<" No se encontraron diagnosticos para ese DNI!!!"<<endl;
        Sleep(1500); system("cls");
    }
    cout <<" Presione enter para regresar al menú... ";
	cin.ignore(); cin.get(); system("cls");
}
