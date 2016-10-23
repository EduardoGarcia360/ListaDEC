#include "listadc.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "iostream"
#include "sstream"

using namespace std;
bool p=false;

NodoDC::NodoDC(int d){
    this->dato = d;
    this->siguiente = this;
}

bool ListaDC::estaVacia(){
    return ultimo==NULL;
}

void ListaDC::insertar(int d){
    NodoDC* nuevo = new NodoDC(d);
    if(ultimo!=NULL){
        if(p==false){
            ultimo=nuevo;
            p=true;
        }else{
            nuevo->siguiente = ultimo->siguiente;
            ultimo->siguiente = nuevo;
        }
    }
}

void ListaDC::mostrarLista(){
    NodoDC* aux = ultimo->siguiente;
    do{
        cout<<aux->dato<<endl;
        aux = aux->siguiente;
    }while(aux != ultimo->siguiente);
}

