#include<iostream>
#include<malloc.h>
#include <stdlib.h>

using namespace std;
//ESTE PROGRAMA PERMITE REGISTRAR PACIENTES EN SU ORDEN DE LLEGADA CON SU NOMBRE Y NUMERO DE DOCUMENTO
struct nodo{
    int codigo;
    char nombre[20];
    char documento[9];
    nodo*sig;
};
 nodo *cab, *aux, *aux2;
 void registrar(){
      aux = (struct nodo *) malloc(sizeof(struct nodo)); //Pedir espacio de memoria 
      cout<<"INGRESE EL NOMBRE DEL PACIENTE:  "<<"\n"<<endl;;
      cout<<"INGRESE EL NUMERO DE DOCUMENTO:  "<<"\n"<<endl;;
      cin>>aux->nombre;
      cin>>aux->documento;
      aux->sig= NULL;                                
      if(cab==NULL){                           
      cab = (struct nodo *) malloc(sizeof(struct nodo));
      cab = aux;              //cabeza inicialmente es = aux y en su posicion siguiente se le asignara a aux el codigo 1 para indicar que es el primero en la cola
      cab->codigo=1;
      aux = NULL;
      free(aux);          //liberar memoria
     }else{
      aux2=cab;
      while(aux2->sig!=NULL){       //mientras aux2 en su siguiente posicion sea diferente a null, moverse por toda la cola
          aux2= aux2->sig;
      }
      aux->codigo = aux2->codigo+1;  //aux es igual al codigo 1 que de su apuntador cabeza y aux2 sera igual al codigo de aux1+1, es decir cada posicion siguiente el codigo aumentará 1
      aux2->sig = aux;   
      aux2 = aux = NULL;
      free(aux);
      free(aux2);
   }  
 }
void mostrar(){                      //visualizar el registro de los pacientes
    for(aux=cab; aux!=NULL; aux=aux->sig){
    cout<<"Codigo: "<<aux->codigo<<endl<<"Nombre: "<<aux->nombre<<endl<<"Documento: "<<aux->documento<<endl<<endl;
   }
}
int main(){             //menu de opciones parra registrar o visualizar los pacientes
   int opc= 0;

   do{
    cout<<"1. Registrar paciente:  "<<endl;
    cout<<"2. Ver paciente registrado:  "<<endl;
    cout<<"Elija una opcion:  "<<endl;
    cin>>opc;
    switch (opc){
      case 1: 
         registrar(); 
      break;

      case 2: 
         mostrar();  
      break;
    }
 }while (opc!=3);
 return 1; 
}

