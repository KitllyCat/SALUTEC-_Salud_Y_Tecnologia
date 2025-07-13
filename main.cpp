#include <iostream>
#include <windows.h>
#include <string>
#include "menus.h" //funcion para los menus del programa
#include "paciente.h"
#include "historial.h"
#include "search.h"
#include "colors.h"//para los colores de la consola
using namespace std;

int main(){

	SetConsoleOutputCP(CP_UTF8);
	activarANSI();
	intro();
	menuPrincipal();
	
	return 0;
}
