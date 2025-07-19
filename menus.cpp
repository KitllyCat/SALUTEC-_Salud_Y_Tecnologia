#include <iostream>
#include <windows.h>
#include <string>
#include "menus.h"
#include "paciente.h"
#include "historial.h"
#include "search.h"
#include "colors.h"

void activarANSI(){ //funcion para poner soporte de secuencias ANSI en la consola (cmd/powershell), y se pueda ver el color
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode=0;
    GetConsoleMode(hOut,&dwMode);
    dwMode|=ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut,dwMode);
}

void intro(){ //funcion extremadamente innecesaria, pero igual implementada :3
	Sleep(1000);
	cout<<CYAN<<"╔══════════════════════════════•●•══════════════════════════════╗"<<endl; 
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"██████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██░░░██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"╚══════════════════════════════•●•══════════════════════════════╝"<<endl;
	Sleep(200);system("cls");
	cout<<CYAN<<"╔══════════════════════════════•●•══════════════════════════════╗"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"██████"<<CYAN<<"░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"██████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"╚══════════════════════════════•●•══════════════════════════════╝"<<endl;
	Sleep(200); system("cls");
	cout<<CYAN<<"╔══════════════════════════════•●•══════════════════════════════╗"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░░"<<BLUE<<"█████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"██████"<<CYAN<<"░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"╚══════════════════════════════•●•══════════════════════════════╝"<<endl;
	Sleep(200);system("cls");
	cout<<CYAN<<"╔══════════════════════════════•●•══════════════════════════════╗"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░░"<<BLUE<<"█████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"██████"<<CYAN<<"░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"╚══════════════════════════════•●•══════════════════════════════╝"<<endl;
	Sleep(200);system("cls");
	cout<<CYAN<<"╔══════════════════════════════•●•══════════════════════════════╗"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░░"<<BLUE<<"█████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"██████"<<CYAN<<"░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░"<<BLUE<<"████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"█████"<<CYAN<<"░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"╚══════════════════════════════•●•══════════════════════════════╝"<<endl;
	Sleep(200);system("cls");
	cout<<CYAN<<"╔══════════════════════════════•●•══════════════════════════════╗"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░░"<<BLUE<<"█████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"████"<<CYAN<<"░░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"████"<<CYAN<<"░░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"██████"<<CYAN<<"░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░"<<BLUE<<"████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"█████"<<CYAN<<"░░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"╚══════════════════════════════•●•══════════════════════════════╝"<<endl;
	Sleep(200);system("cls");
	cout<<CYAN<<"╔══════════════════════════════•●•══════════════════════════════╗"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░░"<<BLUE<<"█████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"████"<<CYAN<<"░░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"████"<<CYAN<<"░░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"██████"<<CYAN<<"░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░"<<BLUE<<"████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"█████"<<CYAN<<"░░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░░░░░░║"<<endl; 
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"╚══════════════════════════════•●•══════════════════════════════╝"<<endl;
	Sleep(200);system("cls");
	cout<<CYAN<<"╔══════════════════════════════•●•══════════════════════════════╗"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░░"<<BLUE<<"█████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"████"<<CYAN<<"░░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░"<<RED<<"███"<<CYAN<<"░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░░░░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"████"<<CYAN<<"░░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░░░░░"<<RED<<"███"<<CYAN<<"░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██████"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░"<<RED<<"███"<<CYAN<<"░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"██████"<<CYAN<<"░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░"<<RED<<"█████████"<<CYAN<<"░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░"<<RED<<"█████████"<<CYAN<<"░░║"<<endl;
	cout<<CYAN<<"║░░░░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░"<<RED<<"█████████"<<CYAN<<"░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░░░░░░░░░░"<<RED<<"███"<<CYAN<<"░░░░░║"<<endl;
	cout<<CYAN<<"║░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░"<<BLUE<<"████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░"<<BLUE<<"███████"<<CYAN<<"░░░░░░"<<RED<<"███"<<CYAN<<"░░░░░║"<<endl;
	cout<<CYAN<<"║░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"██████"<<CYAN<<"░"<<BLUE<<"██"<<CYAN<<"░░"<<BLUE<<"█████"<<CYAN<<"░░░░"<<BLUE<<"██"<<CYAN<<"░░░"<<BLUE<<"█████"<<CYAN<<"░░░"<<BLUE<<"█████"<<CYAN<<"░░░░░░░"<<RED<<"███"<<CYAN<<"░░░░░║"<<endl;
	cout<<CYAN<<"║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║"<<endl;
	cout<<CYAN<<"╚══════════════════════════════•●•══════════════════════════════╝"<<endl;
	Sleep(1500);
	cout<<endl<<"\t\t  SALUTEC - SALUD Y TECNOLOGIA"<<endl;
	Sleep(2500);
	system("cls");
}

void menuPrincipal(){
	bool end=false;
	do{
		cout<<CYAN<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╗";
		cout<<endl<<CYAN<<" ║                     SALUTEC"<<RED<<"+ "<<CYAN<<"- SALUD Y TECNOLOGIA                     ║";
		cout<<endl<<CYAN<<" ║                            "<<BLUE<<"MENU PRINCIPAL                             "<<CYAN<<"║"<<endl;
		cout<<CYAN<<" ║                                                                       ║"<<endl;
		cout<<CYAN<<" ║Bienvenido a Salutec, una clinica donde tu salud es nuestra prioridad. ║"<<endl;
		cout<<" ║Elija la opcion que desea realizar en el programa:                     ║"<<endl;
		cout<<" ║A) Acceder al registro de los pacientes                                ║"<<endl;
		cout<<" ║B) Acceder al historial medico de los pacientes                        ║"<<endl;
		cout<<" ║C) Acceder a la base de datos de los pacientes                         ║"<<endl;
		cout<<" ║D) Salir                                                               ║"<<endl;
		cout<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<CYAN<<"══════════════════════════════════╝"<<endl<<endl;
		cout<<" Selecione su opcion: ";
		char opcion;
		cin >> opcion;
		cin.clear();
		cin.ignore(1000, '\n');
		
		switch(opcion){
			case 'A':
			case 'a':{
				cout<<endl<<GREEN<<" Cambiando al menú registros..."<<endl;
				Sleep(750);system("cls");
				system("cls");
				menuR_Pacientes();
				break;
			}
			case 'B':
			case 'b':{
				cout<<endl<<GREEN<<" Cambiando al menú de historial..."<<endl;
				Sleep(750);system("cls");
				menuHistorial();
				break;
			}
			case 'C':
			case 'c':{
				cout<<endl<<GREEN<<" Cambiando al menú de datos..."<<endl;
				Sleep(750);system("cls");
				menuDatos();
				break;
			}
			case 'D':
			case 'd':{
				system("cls");
				cout<<endl<<BLUE<<" Gracias por su visita~!!!"<<endl;
				Sleep(1500);system("cls");
				end=true;
				break;
			}
			default:{
				cout<<RED<<" Opción invalida!!!"<<ORANGE<<" Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(!end);
}

void menuR_Pacientes(){
	bool salir=false;
	do{
		cout<<MAGENTA<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<MAGENTA<<"══════════════════════════════════╗";
		cout<<endl<<MAGENTA<<" ║                     "<<CYAN<<"SALUTEC"<<RED<<"+ "<<CYAN<<"- SALUD Y TECNOLOGIA                     "<<MAGENTA<<"║";
		cout<<endl<<MAGENTA<<" ║                        "<<BLUE<<"REGISTRO DE PACIENTES                          "<<MAGENTA<<"║"<<endl;
		cout<<MAGENTA<<" ║                                                                       "<<MAGENTA<<"║"<<endl;
		cout<<MAGENTA<<" ║"<<CYAN<<"Te encuentras en el menu de registro de pacientes de la clinica.       "<<MAGENTA<<"║"<<endl;
		cout<<MAGENTA<<" ║"<<CYAN<<"Elija la opcion que desea realizar en el programa:                     "<<MAGENTA<<"║"<<endl;
		cout<<MAGENTA<<" ║"<<CYAN<<"A) Agregar paciente                                                    "<<MAGENTA<<"║"<<endl;
		cout<<MAGENTA<<" ║"<<CYAN<<"B) Eliminar paciente                                                   "<<MAGENTA<<"║"<<endl;
		cout<<MAGENTA<<" ║"<<CYAN<<"C) Actualizar paciente                                                 "<<MAGENTA<<"║"<<endl;
		cout<<MAGENTA<<" ║"<<CYAN<<"D) Regresar al menu principal...                                       "<<MAGENTA<<"║"<<endl;
		cout<<MAGENTA<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<MAGENTA<<"══════════════════════════════════╝"<<endl<<endl;
		cout<<CYAN<<" Selecione su opcion: ";
		char opcion;
		cin >> opcion;
		cin.clear();
		cin.ignore(1000, '\n');
		
		switch(opcion){
			case 'A':
			case 'a':{
				system("cls");
				Agregar_Paciente(Registro, cont);
				break;
			}
			case 'B':
			case 'b':{
				system("cls");
				Eliminar_Paciente(Registro, cont);
				break;
			}
			case 'C':
			case 'c':{
				system("cls");
				Actualizar_Paciente(Registro, cont);
				break;
			}
			case 'D':
			case 'd':{
				salir=true;
				cout<<endl<<GREEN<<" Regresando al menú principal..."<<endl;
				Sleep(1500);system("cls");
				return;
			}
			default:{
				cout<<RED<<" Opción invalida!!!"<<ORANGE<<" Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(!salir);
}

void menuHistorial(){
	bool salir=false;
	do{
		cout<<GREEN<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<GREEN<<"══════════════════════════════════╗";
		cout<<endl<<GREEN<<" ║                     "<<CYAN<<"SALUTEC"<<RED<<"+ "<<CYAN<<"- SALUD Y TECNOLOGIA                     "<<GREEN<<"║";
		cout<<endl<<GREEN<<" ║                          "<<BLUE<<"HISTORIAL MEDICO                             "<<GREEN<<"║"<<endl;
		cout<<GREEN<<" ║                                                                       "<<GREEN<<"║"<<endl;
		cout<<GREEN<<" ║"<<CYAN<<"Te encuentras en el menu deL historial medico de los pacientes.        "<<GREEN<<"║"<<endl;
		cout<<GREEN<<" ║"<<CYAN<<"Elija la opcion que desea realizar en el programa:                     "<<GREEN<<"║"<<endl;
		cout<<GREEN<<" ║"<<CYAN<<"A) Registrar un nuevo diagnostico                                      "<<GREEN<<"║"<<endl;
		cout<<GREEN<<" ║"<<CYAN<<"B) Mostrar el historial diagnostico                                    "<<GREEN<<"║"<<endl;
		cout<<GREEN<<" ║"<<CYAN<<"C) Modificar el diagnogtico de un paciente                             "<<GREEN<<"║"<<endl;
		cout<<GREEN<<" ║"<<CYAN<<"D) Buscar el diagnostico por fecha                                     "<<GREEN<<"║"<<endl;
		cout<<GREEN<<" ║"<<CYAN<<"E) Buscar el diagnostico por DNI                                       "<<GREEN<<"║"<<endl;
		cout<<GREEN<<" ║"<<CYAN<<"F) Regresar al menu principal...                                       "<<GREEN<<"║"<<endl;
		cout<<GREEN<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<GREEN<<"══════════════════════════════════╝"<<endl<<endl;
		cout<<CYAN<<" Selecione su opcion: ";
		char opcion;
		cin >> opcion;
		cin.clear();
		cin.ignore(1000, '\n');
		
		switch(opcion){
			case 'A':
			case 'a':{
				system("cls");
				registrarDiagnostico(historial, totalDiagnosticos);
				break;
			}
			case 'B':
			case 'b':{
				system("cls");
				mostrarHistorial(historial, totalDiagnosticos);
				break;
			}
			case 'C':
			case 'c':{
				system("cls");
				modificarDiagnostico(historial, totalDiagnosticos);
				break;
			}
			case 'D':
			case 'd':{
				system("cls");
				buscarPorFecha(historial, totalDiagnosticos);
				break;
			}
			case 'E':
			case 'e':{
				system("cls");
				buscarPorDNI(historial, totalDiagnosticos);
				break;
			}
			case 'F':
			case 'f':{
				salir=true;
				cout<<endl<<GREEN<<" Regresando al menú principal..."<<endl;
				Sleep(1500);system("cls");
				return;
			}
			default:{
				cout<<RED<<" Opción invalida!!!"<<ORANGE<<" Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(!salir);
}

void menuDatos(){
	bool salir=false;
	do{
		cout<<YELLOW<<" ╔══════════════════════════════════"<<BLUE<<"●•●"<<YELLOW<<"══════════════════════════════════╗";
		cout<<endl<<YELLOW<<" ║                     "<<CYAN<<"SALUTEC"<<RED<<"+ "<<CYAN<<"- SALUD Y TECNOLOGIA                     "<<YELLOW<<"║";
		cout<<endl<<YELLOW<<" ║                           "<<BLUE<<"MENU DE DATOS                               "<<YELLOW<<"║"<<endl;
		cout<<YELLOW<<" ║                                                                       "<<YELLOW<<"║"<<endl;
		cout<<YELLOW<<" ║"<<CYAN<<"Te encuentras en el menu de la base de datos de los pacientes.         "<<YELLOW<<"║"<<endl;
		cout<<YELLOW<<" ║"<<CYAN<<"Elija la opcion que desea realizar en el programa:                     "<<YELLOW<<"║"<<endl;
		cout<<YELLOW<<" ║"<<CYAN<<"A) Mostrar el listado de pacientes                                     "<<YELLOW<<"║"<<endl;
		cout<<YELLOW<<" ║"<<CYAN<<"B) Mostrar el listado de pacientes por edad                            "<<YELLOW<<"║"<<endl;
		cout<<YELLOW<<" ║"<<CYAN<<"C) Buscar a un paciente por nombre                                     "<<YELLOW<<"║"<<endl;
		cout<<YELLOW<<" ║"<<CYAN<<"D) Buscar a un paciente por su DNI                                     "<<YELLOW<<"║"<<endl;
		cout<<YELLOW<<" ║"<<CYAN<<"E) Regresar al menu principal...                                       "<<YELLOW<<"║"<<endl;
		cout<<YELLOW<<" ╚══════════════════════════════════"<<BLUE<<"●•●"<<YELLOW<<"══════════════════════════════════╝"<<endl<<endl;
		cout<<CYAN<<" Selecione su opcion: ";
		char opcion;
		cin >> opcion;
		cin.clear();
		cin.ignore(1000, '\n');
	
		switch(opcion){
			case 'A':
			case 'a':{
				system("cls");
				listPatients(Registro, cont);
				break;
			}
			case 'B':
			case 'b':{
				system("cls");
				listPatientsByAge(Registro, cont);
				break;
			}
			case 'C':
			case 'c':{
				system("cls");
				searchPatientByName(Registro, cont);
				break;
			}
			case 'D':
			case 'd':{
				system("cls");
				searchPatientByDNI(Registro, cont);
				break;
			}
			case 'e':
			case 'E':{
				salir=true;
				cout<<endl<<GREEN<<" Regresando al menú principal..."<<endl;
				Sleep(1500);system("cls");
				return;
			}
			default:{
				cout<<RED<<" Opción invalida!!!"<<ORANGE<<" Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(!salir);
}
