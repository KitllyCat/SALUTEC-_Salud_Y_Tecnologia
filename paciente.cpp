#inclde "paciente.h"

using namespace std;

R_Paciente[9]={
	{"Ureliano Fernandez", "60449025", "18", "M", "O+", "923094702", "Miraflores - Av. Torres"},
	{"Olaf Mendoza", "33096724", "20", "M", "O-", "907539421", "Barranco Calle - Pardos"},
	{"Maricielo Tapia", "90337611","22", "F", "O+", "926983513", "Madgalena - Av. Alamos"},
	{"Jimmy Chambe", "20658732","30", "M", "B+", "904533861", "Santa Elena - Av. "},
	{"Yadira Arias", "60573822","19", "F", "O+", "929473911", "Alameda Asoc.Las Perlas"},
	{"Gabriel Peñaloza", "75236112","25", "M", "B-", "938491036", "Los Perales Calle"},
	{"Zhamyra Ramos", "91885473","40", "F", "O-", "900372954", "Miraflores Av. Torres"},
	{"Ignacia Hernandez", "33762819","57", "F", "B+", "925095173", "Miraflores Av. Torres"},
	{"Mauricio Gutierrez", "54073862","17", "M", "O+", "937520947", "Miraflores Av. Torres"},
	{"Diego Jaramillo", "60456915","33", "M", "O-", "921957740", "Miraflores Av. Torres"},

};
    Paciente Registro[Cant];
    int cont=10;

	void Agregar_Paciente(Paciente Registro[], int &cont){
	cout << "==========================================================" << endl;
    cout << "                REGISTRO DE PACIENTE" << endl;
    cout << "==========================================================" << endl;
    cout<<endl;
    
    cout<<cont+1<<".- ";
    cout<<"Nombre: ";
    cin.ignore();
    getline(cin, Registro[cont].nombre);
    cout<<endl;
    cout<<"DNI: ";
    cin>>Registro[cont].DNI;
    cout<<endl;
    cout<<"Edad: ";
    cin>>Registro[cont].edad;
    cout<<endl;
    cout<<"Sexo: ";
    cin.ignore();
    getline(cin, Registro[cont].sexo);
    cout<<endl;
    cout<<"Tipo de sangre: ";
    cin.ignore();
    getline(cin, Registro[cont].T_sangre);
    cout<<endl;
    cout<<"Número: ";
    cin>>Registro[cont].numero;
    cout<<endl;
    cout<<"Dirección: ";
    cin.ignore();
    getline(cin, Registro[cont].direccion);
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