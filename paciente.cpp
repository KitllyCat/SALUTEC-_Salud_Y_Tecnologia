#include "paciente.h"

using namespace std;

R_Paciente[9]={
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
    Paciente Registro[Cant];
    int cont=10;

	void Agregar_Paciente(Paciente Registro[], int &cont){
	cout << "==========================================================" << endl;
    cout << "                REGISTRO DE PACIENTE" << endl;
    cout << "==========================================================" << endl;
    cout<<endl;

    cin.ignore();
    
    cout<<cont+1<<".- ";
    cout<<"Nombre: ";
    getline(cin, Registro[cont].nombre);
    for (size_t i = 0; i < Registro[cont].nombre.size(); ++i) {
        char c = Registro[cont].nombre[i];
        if (c >= 'a' && c <= 'z') {
            Registro[cont].nombre[i] = c - ('a' - 'A');
        }
    }
    cout<<endl;
    bool valido;
    do {
        cout << "DNI: ";
        getline(cin, Registro[cont].DNI);
        string dni = Registro[cont].DNI;
        valido = (dni.size() == 8);
        if (valido) {
            for (char c : dni) {
                if (c < '0' || c > '9') {
                    valido = false;
                    break;
                }
            }
        }
        if (!valido) {
        	cout<<endl;
            cout << "DNI inválido, debe contener 8 dígitos"<<endl<<endl;
        }
    } while (!valido); 
    cout<<endl;
    bool Evalido;
    do {
        cout << "Edad: ";
        getline(cin, Registro[cont].edad);
        string Ed = Registro[cont].edad;
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
            cout << "Edad invalida"<<endl<<endl;
        }
    } while (!Evalido); 
    cout<<endl;
    do{
    	cout<<"Sexo (M/F): ";
		getline(cin, Registro[cont].sexo);
    	if(Registro[cont].sexo!="M" && Registro[cont].sexo!="F" && Registro[cont].sexo!="m" && Registro[cont].sexo!="f"){
    	    cout<<"Error solo ingrese 'M' o 'F' "<<endl<<endl;
    	}
	}while(Registro[cont].sexo!="M" && Registro[cont].sexo!="F" && Registro[cont].sexo!="m" && Registro[cont].sexo!="f");
    cout<<endl;
    cout<<"Tipo de sangre: ";
	getline(cin, Registro[cont].T_sangre);
    cout<<endl;
    bool Nvalido;
    do {
        cout<<"Número: ";
        getline(cin, Registro[cont].numero);
        string N = Registro[cont].numero;
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
            cout << "Número inválido, debe contener 9 dígitos"<<endl<<endl;
        }
    } while (!Nvalido); 
    cout<<endl;
    cout<<"Dirección: ";
    getline(cin, Registro[cont].direccion);
    for (size_t i = 0; i < Registro[cont].direccion.size(); ++i) {
        char c = Registro[cont].direccion[i];
        if (c >= 'a' && c <= 'z') {
            Registro[cont].direccion[i] = c - ('a' - 'A');
        }
    }
	cout<<endl;
	
	cont++;
	cout<<"-------------------Paciente registrado--------------------"<<endl;
	cout<<endl;
}

void Eliminar_Paciente(Paciente Registro[], int &cont){
	
	if(cont!=0){
	string paciente;
	bool eliminar = false;
	cout<<"==========================================================" << endl;
    cout<<"                   ELIMINAR PACIENTE" << endl;
    cout<<"==========================================================" << endl;	
    cout<<"Ingrese el nombre del paciente: ";
    cin.ignore();
    getline(cin, paciente);
    
    for (size_t i = 0; i < paciente.size(); ++i) {
        char c = paciente[i];
        if (c >= 'a' && c <= 'z') {
            paciente[i] = c - ('a' - 'A');
        }
    }
		
	for(int i=0; i<cont; i++){
		if(Registro[i].nombre == paciente){
			for(int j=i; j<cont-1; j++){
				Registro[j] = Registro[j+1];
			}
			cont--;
			cout<<endl;
	        cout<<"-------------------Paciente eliminado---------------------"<<endl;
	        cout<<endl;
			eliminar = true;
			break;
			}
		}
		if(!eliminar){
			cout<<"El paciente no esta registrado"<<endl;
		}
	}else{
		cout<<"No hay registro de pacientes"<<endl;
	}
}

void Actualizar_Nombre(Paciente Registro[], int &cont){  
	string Nnombre;
	cout<<"Ingrese el nombre : ";
	cin.ignore();
    getline(cin,Nnombre);
    cout<<endl;
    bool act =false;
    for(int i=0;i<cont;i++){
		if(Registro[i].nombre == Nnombre){
			cout<<"Actualizar nombre: ";
			getline(cin, Registro[i].nombre);
			cout<<endl;
			cout<<"-----------Dato actualizado------------"<<endl<<endl;
			
			act = true;
			break;
			}
		}		
	if(!act){
		cout<<endl;
		cout<<"-------------------Paciente no encontrado---------------------"<<endl;
		cout<<endl;
	    }
}

void Actualizar_Edad(Paciente Registro[], int &cont){  
	string Nnombre;
	cout<<"Ingrese el nombre : ";
	cin.ignore();
    getline(cin,Nnombre);
    cout<<endl;
    bool act =false;
    for(int i=0;i<cont;i++){
		if(Registro[i].nombre == Nnombre){
			bool Evalido;
			do{cout<<"Actualizar edad: ";
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
            cout << "Edad invalida"<<endl<<endl;
        }
    } while (!Evalido); 
			cout<<endl;
			cout<<"-----------Dato actualizado------------"<<endl<<endl;
			
			act = true;
			break;
			}
		}		
	if(!act){
		cout<<endl;
		cout<<"-------------------Paciente no encontrado---------------------"<<endl;
		cout<<endl;
	    }
}

void Actualizar_Numero(Paciente Registro[], int &cont){  
	string Nnombre;
	cout<<"Ingrese el nombre : ";
	cin.ignore();
    getline(cin,Nnombre);
    for (size_t i = 0; i < Nnombre.size(); ++i) {
        char c = =Nnombre[i];
        if (c >= 'a' && c <= 'z') {
            Nnombre[i] = c - ('a' - 'A');
        }
    }
    cout<<endl;
    bool act =false;
    for(int i=0;i<cont;i++){
		if(Registro[i].nombre == Nnombre){
			bool Nvalido;
			do {
				cout<<"Actualizar número: ";
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
            cout << "Número inválido, debe contener 9 dígitos"<<endl<<endl;
        }
    } while (!Nvalido); 
		cout<<endl;
		cout<<"-----------Dato actualizado------------"<<endl<<endl;
			
		act = true;
		break;
			}
		}		
	if(!act){
		cout<<endl;
		cout<<"-------------------Paciente no encontrado---------------------"<<endl;
		cout<<endl;
	    }
}

void Actualizar_Direccion(Paciente Registro[], int &cont){  
	string Nnombre;
	cout<<"Ingrese el nombre : ";
	cin.ignore();
    getline(cin,Nnombre);
    for (size_t i = 0; i < Nnombre.size(); ++i) {
        char c = =Nnombre[i];
        if (c >= 'a' && c <= 'z') {
            Nnombre[i] = c - ('a' - 'A');
        }
    }
    cout<<endl;
    bool act =false;
    for(int i=0;i<cont;i++){
		if(Registro[i].nombre == Nnombre){
			cout<<"Actualizar dirección: ";
			getline(cin, Registro[i].direccion);
    
			cout<<endl;
			cout<<"-----------Dato actualizado------------"<<endl<<endl;
			
			act = true;
			break;
			}
		}		
	if(!act){
		cout<<endl;
		cout<<"-------------------Paciente no encontrado---------------------"<<endl;
		cout<<endl;
	    }
}

void Actualizar_Paciente(Paciente Registro[], int &cont){
	void menuR_Pacientes();
	char RPTA;
	if(cont!=0){
	
	cout<<"==========================================================" << endl;
    cout<<"                   ACTUALIZAR PACIENTE" << endl;
    cout<<"==========================================================" << endl;	
    
		char dato;
		do{
			do{
			cout<<endl;	
			cout<<"------------DATOS A ACTUALIZAR----------"<<endl<<endl;
			cout << "a)Nombre" << endl;
			cout << "b)Edad" <<endl;
            cout << "c)Número de celular" <<endl;
            cout << "d)Dirección"<<endl<<endl;
            cout <<"Alternativa: ";
            cin >> dato;
            cout <<endl;
		
		switch (dato) {
			case 'a':{
				Actualizar_Nombre(Registro, cont);
				break;
			}
				
			case 'b':{
				Actualizar_Edad(Registro, cont);
				break;
			}
			
			case 'c':{
				Actualizar_Numero(Registro, cont);
				break;
			}
				
			case 'd':{
				Actualizar_Direccion(Registro, cont);
				break;
			}
			
			default:{
				cout<<endl;
				cout<<"-------Alternativa invalida--------";
				cout<<endl;
				break;
			}
		}
	cout<<"Desea actualizar otro dato? (S/N): ";
	cin>>RPTA;
	RPTA=toupper(RPTA);	
	}while(RPTA== 'S');
	cout<<"Regresando al menu principal..."<<endl<<endl;
	menuR_Pacientes();	
	}while(dato != 'd');
	}else{
		cout<<"No hay registro de pacientes"<<endl;
		cout<<endl;
	}
}