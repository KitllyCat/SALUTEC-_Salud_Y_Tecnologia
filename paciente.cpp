#include <iostream>
#include <windows.h>
#include <string>
#include "paciente.h"
#include "menus.h"
#include "colors.h"
using namespace std;

Paciente Registro[Cant]={
	{"Ureliano Buendia", "60449025", "18", "M", "O+", "923094702", "Miraflores - Av. Torres"},
	{"Olaf Linares", "33096724", "20", "M", "O-", "907539421", "Barranco - Calle Los Pardos"},
	{"Maricielo Tapia", "90337611","22", "F", "O+", "926983513", "Madgalena - Av. Los Alamos"},
	{"Jimmy Chambe", "20658732","61", "M", "B+", "904533861", "Santa Elena - Asoc. Punta Hermosa"},
	{"Yadira Flores", "60573822","19", "F", "O+", "929473911", "Alameda - Av.Las Perlas"},
	{"Gabriel Peñaloza", "75236112","39", "M", "B-", "938491036", "Los Perales - Calle Almonte"},
	{"Zhamyra Ramos", "91885473","40", "F", "O-", "900372954", "Ciudad Perdida - Av. Lima"},
	{"Ignacia Hernandez", "33762819","57", "F", "B+", "925095173", "Calana - Calle Cuzco"},
	{"Mauricio Gutierrez", "54073862","17", "M", "O+", "937520947", "Puente Piedra - Asoc. La Paz"},
	{"Diego Jaramillo", "60456915","33", "M", "O-", "921957740", "Metropolitano - Av. Tacna"},

};
int cont=10;

void Agregar_Paciente(Paciente Registro[], int &cont){
	cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗"<<endl;
	cout<<" ║                         REGISTRO DE PACIENTE                          ║"<<endl;
	cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl; 
    cin.ignore();

    cout<<" "<<cont+1<<CYAN<<".-";
    do {
    	cout<<" Nombre: ";
	    getline(cin, Registro[cont].nombre);
        if (Registro[cont].nombre.empty()) {
            cout <<RED<<" Ingrese un nombre válido!!!"<<endl<<endl;
        }
    } while (Registro[cont].nombre.empty());

    cout<<endl;
    bool valido;
    do {
        cout <<CYAN<<" DNI: ";
        getline(cin, Registro[cont].DNI);
        valido = (Registro[cont].DNI.size() == 8);
        for (char c : Registro[cont].DNI) {
            if (!isdigit(c)) {
                valido = false;
                break;
            }
        }
        if (!valido) {
            cout << RED <<" DNI inválido, debe contener 8 dígitos!!!"<<endl<<endl;
        }
    } while (!valido);

    cout<<endl;
    bool Evalido;
    do {
        cout <<CYAN<<" Edad: ";
        getline(cin, Registro[cont].edad);
        Evalido = !Registro[cont].edad.empty();
        for (char c : Registro[cont].edad) {
            if (!isdigit(c)) {
                Evalido = false;
                break;
            }
        }
        if (!Evalido) {
            cout <<RED<<" Edad inválida!!!"<<endl<<endl;
        }
    } while (!Evalido); 

    cout<<endl;
    do {
    	cout<<CYAN<<" Sexo (M/F): ";
		getline(cin, Registro[cont].sexo);
    	if(Registro[cont].sexo != "M" && Registro[cont].sexo != "F" &&
    	   Registro[cont].sexo != "m" && Registro[cont].sexo != "f"){
    	    cout<<RED<<" Error!!! Solo ingrese 'M' o 'F' "<<endl<<endl;
    	}
	} while(Registro[cont].sexo != "M" && Registro[cont].sexo != "F" &&
	        Registro[cont].sexo != "m" && Registro[cont].sexo != "f");

    cout<<endl;
    bool TS = false;
	do {
        cout <<CYAN<<" Tipo de sangre: ";
        getline(cin, Registro[cont].T_sangre);
        string ts = Registro[cont].T_sangre;
        if (ts == "A+" || ts == "A-" || ts == "B+" || ts == "B-" ||
            ts == "AB+"|| ts == "AB-"|| ts == "O+" || ts == "O-" ||
            ts == "a+" || ts == "a-" || ts == "b+" || ts == "b-" ||
            ts == "ab+"|| ts == "ab-"|| ts == "o+" || ts == "o-") {
            TS = true;
        } else {
            cout <<RED<<" Tipo de sangre inválido!!!"<<endl<<endl;
        }
    } while (!TS);

    cout<<endl;
    bool Nvalido;
    do {
        cout<<CYAN<<" Número: ";
        getline(cin, Registro[cont].numero);
        Nvalido = (Registro[cont].numero.size() == 9);
        for (char c : Registro[cont].numero) {
            if (!isdigit(c)) {
                Nvalido = false;
                break;
            }
        }
        if (!Nvalido) {
            cout <<RED<<" Número inválido, debe contener 9 dígitos!!!"<<endl<<endl;
        }
    } while (!Nvalido); 

    cout<<endl;
    do {
    	cout<<CYAN<<" Dirección: ";
    	getline(cin, Registro[cont].direccion);
        if (Registro[cont].direccion.empty()) {
            cout <<RED<<" Ingrese una dirección válida!!!"<<endl<<endl;
        }
    } while (Registro[cont].direccion.empty());

	cout<<endl;
	cont++;

	cout<<CYAN<<" ══════════════════════════•"<<GREEN<<"Paciente registrado"<<CYAN<<"•══════════════════════════"<<endl<<endl; 
	Sleep(1500);
	system("cls");
}

void Eliminar_Paciente(Paciente Registro[], int &cont){
    if(cont == 0){
        cout<<RED<<" No hay registro de pacientes!!!"<<endl;
        Sleep(1500);
        system("cls");
        return;
    }
    string pacienteEliminado; 
    cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗"<<endl;
    cout<<" ║                          ELIMINAR PACIENTE                            ║"<<endl;
    cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl; 
    cout<<CYAN<<" Ingrese el nombre del paciente para eliminar: ";
    cin.ignore();
    getline(cin, pacienteEliminado);
    bool encontrado = false;

    for (int i = 0; i < cont; i++) {
        if (Registro[i].nombre == pacienteEliminado) {
            encontrado = true;

            cout << endl << GREEN << " Paciente encontrado:" << endl;
            showPatient(Registro[i]);

            char confirm;
            cout << GREEN << " ¿Está seguro que desea eliminar este paciente? (S/N): ";
            cin >> confirm;
            if (confirm == 'S' || confirm == 's') {
                for (int j = i; j < cont - 1; j++) {
                    Registro[j] = Registro[j + 1];
                }
                cont--;
                cout << GREEN << " Paciente eliminado correctamente!!!" << endl;
            } else {
                cout << RED << " Operación cancelada..." << endl;
            }
            break;
        }
    }

    if (!encontrado) {
        cout << RED << " No se encontró ningún paciente con ese nombre." << endl;
    }

    cout << endl << " Presione enter para regresar al menú...";
    cin.ignore(); cin.get();
    system("cls");
}

void Actualizar_Nombre(Paciente Registro[], int &cont){  
	cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗"<<endl;
	cout<<" ║                          ACTUALIZAR NOMBRE                            ║"<<endl;
	cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
	string Nnombre;
	cout<<CYAN<<" Ingrese el nombre del paciente: ";
	cin.ignore();
    getline(cin,Nnombre);
    cout<<endl;
    bool act =false;
    for(int i=0;i<cont;i++){
		if(Registro[i].nombre == Nnombre){
			cout<<CYAN<<" Actualiza el nuevo nombre: ";
			getline(cin, Registro[i].nombre);			
			cout<<endl;
			cout<<CYAN<<" ══════════════════════════•"<<GREEN<<"Paciente actualizado"<<CYAN<<"•══════════════════════════"<<endl<<endl;
			Sleep(1500);system("cls");
			act = true;
			break;
			}
		}
		
	if(!act){
		cout<<endl;
		cout<<RED<<" Paciente no encontrado!!!"<<endl;
		Sleep(1500);system("cls");
	    }
}

void Actualizar_Edad(Paciente Registro[], int &cont){  
	cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗"<<endl;
	cout<<" ║                          ACTUALIZAR EDAD                              ║"<<endl;
	cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
	string Nnombre;
	cout<<CYAN<<" Ingrese el nombre del paciente: ";
	cin.ignore();
    getline(cin,Nnombre);
    cout<<endl;
    bool act =false;
    for(int i=0;i<cont;i++){
		if(Registro[i].nombre == Nnombre){
			bool Evalido;
			do{cout<<CYAN<<" Actualiza la nueva edad: ";
			getline(cin, Registro[i].edad);
			string Ed = Registro[i].edad;
			Evalido = (Ed.size() == 3 || Ed.size() ==2 || Ed.size() ==1);
			if (Evalido) {
            for (char c : Ed) {
            	if (c < '0' || c > '9') {
                    Evalido = false;
                    break;
                }
            }
        }
        if (!Evalido) {
        	cout<<endl;
            cout <<RED<< " Edad inválida!!!"<<endl<<endl;
            Sleep(1500);system("cls");
        }
    } while (!Evalido); 
			cout<<endl;
			cout<<CYAN<<" ════════════════════════════•"<<GREEN<<"Dato actualizado"<<CYAN<<"•════════════════════════════"<<endl<<endl;
			Sleep(1500);system("cls");
			act = true;
			break;
			}
	}		
	if(!act){
		cout<<endl;
		cout<<RED<<" Paciente no encontrado!!!"<<endl;
		Sleep(1500);system("cls");
	    }
}

void Actualizar_Numero(Paciente Registro[], int &cont){  
	cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗"<<endl;
	cout<<" ║                          ACTUALIZAR NUMERO                            ║"<<endl;
	cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
	string Nnombre;
	cout<<CYAN<<" Ingrese el nombre del paciente: ";
	cin.ignore();
    getline(cin,Nnombre);
    cout<<endl;
    bool act =false;
    for(int i=0;i<cont;i++){
		if(Registro[i].nombre == Nnombre){
			bool Nvalido;
			do {
				cout<<CYAN<<" Actualiza el nuevo número: ";
				getline(cin, Registro[i].numero);
				string N = Registro[i].numero;
				Nvalido = (N.size() == 9);
				if (Nvalido) {
					for (char c : N) {	
					if (c < '0' || c > '9') {
                    Nvalido = false;
                    break;
                }
            }
        }
        if (!Nvalido) {
        	cout<<endl;
            cout << RED<<" Número inválido, debe contener 9 dígitos!!!"<<endl<<endl;
            Sleep(1500);system("cls");
        }
    } while (!Nvalido); 
		cout<<endl;
		cout<<CYAN<<" ════════════════════════════•"<<GREEN<<"Dato actualizado"<<CYAN<<"•════════════════════════════"<<endl<<endl;
		Sleep(1500);system("cls");
		act = true;
		break;
			}
		}		
	if(!act){
		cout<<endl;
		cout<<RED<<" Paciente no encontrado!!!"<<endl;
		Sleep(1500);system("cls");
		cout<<endl;
	    }
}

void Actualizar_Direccion(Paciente Registro[], int &cont){ 
	cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗"<<endl;
	cout<<" ║                         ACTUALIZAR DIRECCION                          ║"<<endl;
	cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
	string Nnombre;
	cout<<CYAN<<" Ingrese el nombre del paciente: ";
	cin.ignore();
    getline(cin,Nnombre);
    cout<<endl;
    bool act =false;
    for(int i=0;i<cont;i++){
		if(Registro[i].nombre == Nnombre){
			cout<<CYAN<<" Actualiza la nueva dirección: ";
			getline(cin, Registro[i].direccion);
			cout<<endl;
			cout<<CYAN<<" ════════════════════════════•"<<GREEN<<"Dato actualizado"<<CYAN<<"•════════════════════════════"<<endl<<endl;
			Sleep(1500);system("cls");
			act = true;
			break;
			}
		}		
	if(!act){
		cout<<endl;
		cout<<RED<<" Paciente no encontrado!!!"<<endl;
		Sleep(1500);system("cls");
		cout<<endl;
	    }
}

void Actualizar_Paciente(Paciente Registro[], int &cont){
	
	if(cont!=0){
		char dato;
			do{
			cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗"<<endl;
			cout<<" ║                        ACTUALIZAR UN PACIENTE                         ║"<<endl;
			cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl;
			cout<<CYAN<<" ══════════════════════════•"<<GREEN<<"DATOS A ACTUALIZAR"<<CYAN<<"•══════════════════════════"<<endl<<endl;
			cout << " A)Nombre" << endl;
			cout << " B)Edad" <<endl;
            cout << " C)Número de celular" <<endl;
            cout << " D)Dirección"<<endl;
            cout << " S)Salir"<<endl;
            cout << " Selecione su opcion: ";
            cin >> dato;
            cout <<endl;
		
		switch (dato) {
			case 'a':
			case 'A':{
				system("cls");
				Actualizar_Nombre(Registro, cont);
				break;
			}
				
			case 'b':
			case 'B':{
				system("cls");
				Actualizar_Edad(Registro, cont);
				break;
			}
			
			case 'c':
			case 'C':{
				system("cls");
				Actualizar_Numero(Registro, cont);
				break;
			}
				
			case 'd':
			case 'D':{
				system("cls");
				Actualizar_Direccion(Registro, cont);
				break;
			}
			
			case 's':
			case 'S':{
				cout<<endl<<GREEN<<" Regresando al menú anterior..."<<endl;
				Sleep(1500);system("cls");
				break;
			}
			
			default:{
				cout<<RED<<" Opción invalida!!!"<<ORANGE<<" Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(dato != 's');
	}else{
		cout<<RED<<"No hay registro de pacientes!!!"<<endl;
		cout<<endl;
		Sleep(1500);system("cls");
	}
}