#include <iostream>
#include <windows.h>
#include <string>
#include "menus.h" //funcion para los menus del programa
#include "paciente.h" //utilidades registro_paciente
#include "historial.h"//utilidades historial_paciente
#include "search.h"//utilidades datos_paciente
#include "colors.h"//para los colores de la consola
using namespace std;

int main(){
	system("color F0"); //establecer la consola a todo el fondo blanco
	SetConsoleOutputCP(CP_UTF8); //para ascii utf8
	activarANSI();//activacion de los colores para consola win10/11
	//intro();
	menuPrincipal();
	cout<<endl<<CYAN<<" SALUTEC"<<RED<<"✛ "<<CYAN<<"- SALUD Y TECNOLOGIA"<<endl;
	return 0;
}
