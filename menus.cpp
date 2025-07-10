#include "menus.h"
#include "paciente.h"

void menuPrincipal(){
	int opcion;
	do{
		cout<< "---SALUTEC--SALUD-Y-TECNOLOGIA-----"<<endl<<endl;
		cout<<"Elija la opcion que desea realizar en el programa:"<<endl;
		cout<<"1) Acceder al registro de pacientes"<<endl;
		cout<<"2) Eliminar un contacto existente"<<endl;
		cout<<"3) Mostrar todos los contactos guardados"<<endl;
		cout<<"4) Mostrar todos los contactos guardados en orden de correos"<<endl;
		cout<<"5) Salir"<<endl;
		cout<<"Selecione su opcion: ";
		cin>>opcion;
		cout<<endl;
		
		switch(opcion){
			case 1:{
				system("cls");
				menuR_Pacientes();
				break;
			}
			case 2:{
				system("cls");
				//eliminarContacto();
				break;
			}
			case 3:{
				system("cls");
				//mostrarListadoRegistrados();
				break;
			}
			case 4:{
				system("cls");
				//mostrarListadoExistentes();
				break;
			}
			case 5:{
				system("cls");
				cout<<"Saliendo del programa..."<<endl;
				break;
			}
			default:{
				cout<<"Opción invalida!!! Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(opcion!=5);
}
void menuR_Pacientes(){
	int opcion;
	do{
		cout<< "---SALUTEC--SALUD-Y-TECNOLOGIA-----"<<endl<<endl;
		cout<<"Elija la opcion que desea realizar en el programa:"<<endl;
		cout<<"1) agregar paciente"<<endl;
		cout<<"2) Eliminar paciente"<<endl;
		cout<<"3) actualizar paciente"<<endl;
		cout<<"4) Mostrar todos los pacientes"<<endl;
		cout<<"5) Salir"<<endl;
		cout<<"Selecione su opcion: ";
		cin>>opcion;
		cout<<endl;
		
		switch(opcion){
			case 1:{
				system("cls");
				Agregar_Paciente(Registro, cont);
				break;
			}
			case 2:{
				system("cls");
				Eliminar_Paciente(Registro, cont);
				break;
			}
			case 3:{
				system("cls");
				Actualizar_Paciente(Registro, cont);
				break;
			}
			case 4:{
				system("cls");
				//mostrarListadoExistentes();
				break;
			}
			case 5:{
				system("cls");
				cout<<"Saliendo del programa..."<<endl;
				break;
			}
			default:{
				cout<<"Opción invalida!!! Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(opcion!=5);
}
void menuHistorial(){
	
}
