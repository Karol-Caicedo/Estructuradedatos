#include <iostream>
#include <malloc.h>

using namespace std;

struct vehiculo
{
    int placa;
    char nombre[30];
    char tipo_vehiculo[6]; //Coche o Moto
    vehiculo *sig;
};

vehiculo *aux, *cab;

char coche[20] = "Coche";
char moto[20] = "Moto";
int numero_vehiculos = 0;
int Caja_parqueadero = 0;

int registrar(){
    int volver = 0;
    char Opc_vehiculo[20];
    int volver_registrar = 0;
    
 do{
    cout<<"Bienvenido al parqueadero el callejon negro"<<endl;
    cout<<"\n";
        
    //pide memoria
    aux = (struct vehiculo *) malloc (sizeof(struct vehiculo));
    cout<<"Ingresa el nombre del propietario del vehiculo: "<<endl;
    cin>>aux->nombre;    
    cout<<"\n";

    cout<<"Ingresa la placa del vehiculo: "<<endl;
    cin>>aux->placa;

     do{
        cout<<"Escribe el tipo de vehiculo tal cual (Coche / Moto): "<<endl;
        cin>>aux->tipo_vehiculo;
	volver = 0;
	if (aux->tipo_vehiculo[0] == coche[0]){
	    if(aux->tipo_vehiculo[1] == coche[1]){
		if(aux->tipo_vehiculo[2] == coche[2]){
  	            Caja_parqueadero = Caja_parqueadero + 1000;
		}else{
		     cout << "Opcion Invalida, Escriba la opcion tal cual (Coche / Moto)..." << endl;
		     volver = 1;
		}
	    }else{
		 cout << "Opcion Invalida, Escriba la opcion tal cual (Coche / Moto)..." << endl;
		 volver = 1;
		 }
	}else if (aux->tipo_vehiculo[0] == moto[0]){
		if(aux->tipo_vehiculo[1] == moto[1]){
		   if(aux->tipo_vehiculo[2] == moto[2]){
		      Caja_parqueadero = Caja_parqueadero + 500;
		   }else{
		      cout << "Escriba la opcion tal cual (Coche / Moto)..." << endl;
		      volver = 1;
	           }
	       }else{
		      cout << "Escriba la opcion tal cual (Coche / Moto)..." << endl;
		      volver = 1;
		}
	}else {
		cout << "Escriba la opcion tal cual (Coche / Moto)..." << endl;
	        volver = 1; 
        }
}while(volver == 1);
        
 //Almacenar en Lifo
 if(cab==NULL){
    cab = aux;
    cab->sig = NULL;
}else{
    aux->sig =cab;
    cab = aux;
}
 aux = NULL;
 free(aux);

 cout<<"El registro ha sido exitoso"<<endl;
 system("pause");
 cout<<"Desea hacer otro registro? (1.SI/2.NO)"<<endl;
 cin>>volver_registrar;
}while(volver_registrar!=2);
return 0;
}


int mostrar(){
    if(cab!=NULL){
    	aux = cab;
    	while(aux!=NULL){
    	    cout<<"-> Propietario: "<<aux->nombre<<endl;
            cout<<"Placa: "<<aux->placa<<endl;
            cout<<"Tipo de vehiculo: "<<aux->tipo_vehiculo<<endl;
            cout<<"------------------------------------------------------"<<endl;
    	    aux = aux->sig;
	}
		
        cout<<"Dinero en Caja: $"<<Caja_parqueadero<<endl;
        system("pause"); 
  }else{
        cout<<"Vacio..."<<endl;
        cout<<"No hay Vehiculos en el parqueadero"<<endl;
        cout<<"Dinero en Caja: $"<<Caja_parqueadero<<endl;
        system("pause");
    }
    return 0;
}

int retirar(){
	//Eliminar tipo Lifo
    if(cab!=NULL){
	//Datos
	aux = cab;
	cout<<"-> Propietario: "<<aux->nombre<<endl;
        cout<<"Placa: "<<aux->placa<<endl;
        cout<<"Tipo de vehiculo: "<<aux->tipo_vehiculo<<endl;
        cout<<"Este vehiculo se eliminara..."<<endl;
        system("pause");
        
        //Si es un Coche se suma 100 a la caja
        if (aux->tipo_vehiculo[0] == coche[0]){
	   Caja_parqueadero = Caja_parqueadero + 100;
	}else{ //Si es una moto se le suma 50 a la caja
	     Caja_parqueadero = Caja_parqueadero + 50;
	}
		
	//Elimina vehículo
	cab = cab->sig;
	free(aux);
		
	cout<<"Vehiculo eliminado..."<<endl;
        system("pause");	
	}
	return 0;
}

int main(){
    int opc = 0;
    do{
        cout<<"\nMenu"<<endl;
        cout<<"1. Registrar Vehiculo "<<endl;
        cout<<"2. Retirar Vehiculo "<<endl;
        cout<<"3. Mostrar Datos"<<endl;
        cout<<"4. Salir"<<endl;
        cin>>opc;
        switch (opc)
        {
            case 1: registrar(); break;
            case 2: retirar(); break;
            case 3: mostrar(); break;
            case 4: cout<<"BYE"; break;
            default:cout<<"Opcion Invalida."; break;
        }
    }while(opc!=4);
}
