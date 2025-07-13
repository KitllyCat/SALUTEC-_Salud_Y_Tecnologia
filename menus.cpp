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
	Sleep(100);
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
	char opcion;
	bool end=false;
	do{
		cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗";
		cout<<endl<<CYAN<<" ║                     SALUTEC"<<RED<<"✛ "<<CYAN<<"- SALUD Y TECNOLOGIA                     ║";
		cout<<endl<<CYAN<<" ║                            "<<BLUE<<"MENU PRINCIPAL                             "<<CYAN<<"║"<<endl;
		cout<<CYAN<<" ║                                                                       ║"<<endl;
		cout<<CYAN<<" ║Bienvenido a Salutec, una clinica donde tu salud es nuestra prioridad. ║"<<endl;
		cout<<" ║Elija la opcion que desea realizar en el programa:                     ║"<<endl;
		cout<<" ║A) Acceder al registro de los pacientes                                ║"<<endl;
		cout<<" ║B) Acceder al historial medico de los pacientes                        ║"<<endl;
		cout<<" ║C) Acceder a la base de datos de  los pacientes                        ║"<<endl;
		cout<<" ║D) Salir                                                               ║"<<endl;
		cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
		cout<<" Selecione su opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 'A':
			case 'a':{
				cout<<endl<<GREEN<<" Cambiando de menú..."<<endl;
				Sleep(750);system("cls");
				system("cls");
				menuR_Pacientes();
				break;
			}
			case 'B':
			case 'b':{
				cout<<endl<<GREEN<<" Cambiando de menú..."<<endl;
				Sleep(750);system("cls");
				menuHistorial();
				break;
			}
			case 'C':
			case 'c':{
				cout<<endl<<GREEN<<" Cambiando de menú..."<<endl;
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
	char opcion;
	do{
		cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗";
		cout<<endl<<CYAN<<" ║                     SALUTEC"<<RED<<"✛ "<<CYAN<<"- SALUD Y TECNOLOGIA                     ║";
		cout<<endl<<CYAN<<" ║                        "<<BLUE<<"REGISTRO DE PACIENTES                          "<<CYAN<<"║"<<endl;
		cout<<CYAN<<" ║                                                                       ║"<<endl;
		cout<<CYAN<<" ║Te encuentras en el menu de registro de pacientes de la clinica.       ║"<<endl;
		cout<<" ║Elija la opcion que desea realizar en el programa:                     ║"<<endl;
		cout<<" ║A) Agregar paciente                                                    ║"<<endl;
		cout<<" ║B) Eliminar paciente                                                   ║"<<endl;
		cout<<" ║C) Actualizar paciente                                                 ║"<<endl;
		cout<<" ║D) Regresar al menu principal...                                       ║"<<endl;
		cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
		cout<<" Selecione su opcion: ";
		cin>>opcion;
		
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
				cout<<endl<<GREEN<<" Regresando al menú principal..."<<endl;
				Sleep(1500);system("cls");
				menuPrincipal();
				break;
			}
			default:{
				cout<<RED<<" Opción invalida!!!"<<ORANGE<<" Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(opcion!=5);
}

void menuHistorial(){
	char opcion;
	do{
		cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗";
		cout<<endl<<CYAN<<" ║                     SALUTEC"<<RED<<"✛ "<<CYAN<<"- SALUD Y TECNOLOGIA                     ║";
		cout<<endl<<CYAN<<" ║                          "<<BLUE<<"HISTORIAL MEDICO                             "<<CYAN<<"║"<<endl;
		cout<<CYAN<<" ║                                                                       ║"<<endl;
		cout<<CYAN<<" ║Te encuentras en el menu deL historial medico de los pacientes.        ║"<<endl;
		cout<<" ║Elija la opcion que desea realizar en el programa:                     ║"<<endl;
		cout<<" ║A) Registrar un nuevo diagnostico                                      ║"<<endl;
		cout<<" ║B) Mostrar el historial diagnostico                                    ║"<<endl;
		cout<<" ║C) Modificar el diagnogtico de un paciente                             ║"<<endl;
		cout<<" ║D) Buscar el diagnostico por fecha                                     ║"<<endl;
		cout<<" ║E) Buscar el diagnostico por DNI                                       ║"<<endl;
		cout<<" ║F) Regresar al menu principal...                                       ║"<<endl;
		cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
		cout<<" Selecione su opcion: ";
		cin>>opcion;
		
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
				cout<<endl<<GREEN<<" Regresando al menú principal..."<<endl;
				Sleep(1500);system("cls");
				menuPrincipal();
				break;
			}
			default:{
				cout<<RED<<" Opción invalida!!!"<<ORANGE<<" Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(opcion!=5);
}

void menuDatos(){
	char opcion;
	do{
		cout<<CYAN<<" ╔══════════════════════════════════•●•══════════════════════════════════╗";
		cout<<endl<<CYAN<<" ║                     SALUTEC"<<RED<<"✛ "<<CYAN<<"- SALUD Y TECNOLOGIA                     ║";
		cout<<endl<<CYAN<<" ║                           "<<BLUE<<"MENU DE DATOS                               "<<CYAN<<"║"<<endl;
		cout<<CYAN<<" ║                                                                       ║"<<endl;
		cout<<CYAN<<" ║Te encuentras en el menu de la base de datos de los pacientes.         ║"<<endl;
		cout<<" ║Elija la opcion que desea realizar en el programa:                     ║"<<endl;
		cout<<" ║A) Mostrar el listado de pacientes                                     ║"<<endl;
		cout<<" ║B) Buscar a un paciente por nombre                                     ║"<<endl;
		cout<<" ║C) Buscar a un paciente por su DNI                                     ║"<<endl;
		cout<<" ║D) Regresar al menu principal...                                       ║"<<endl;
		cout<<" ╚══════════════════════════════════•●•══════════════════════════════════╝"<<endl<<endl;
		cout<<" Selecione su opcion: ";
		cin>>opcion;
		cout<<endl;
		
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
				searchPatientByName(Registro, cont);
				break;
			}
			case 'C':
			case 'c':{
				system("cls");
				searchPatientByDNI(Registro, cont);
				break;
			}
			case 'D':
			case 'd':{
				cout<<endl<<GREEN<<" Regresando al menú principal..."<<endl;
				Sleep(1500);system("cls");
				menuPrincipal();
				break;
			}
			default:{
				cout<<RED<<" Opción invalida!!!"<<ORANGE<<" Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(opcion!=5);
}
