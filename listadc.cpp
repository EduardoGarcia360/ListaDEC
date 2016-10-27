#include "listadc.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "iostream"
#include "sstream"

using namespace std;
bool p=false;
int tam=0;

NodoDC::NodoDC(int d){
    this->dato = d;
    this->siguiente = this;
    this->anterior = this;
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
            tam += 1;
        }else{
            nuevo->siguiente = ultimo->siguiente;
            ultimo->siguiente = nuevo;
            tam += 1;
        }
    }
}

void ListaDC::mostrarLista(){
    cout<<"==============================="<<endl;
    NodoDC* aux = ultimo->siguiente;
    do{
        cout<<aux->dato<<endl;
        aux = aux->siguiente;
    }while(aux != ultimo->siguiente);
    cout<<"==============================="<<endl;
}

bool ListaDC::eliminar(int d){
    NodoDC* actual;
    NodoDC* aux;
    bool encontrado=false;
    actual=ultimo;
    aux=ultimo->siguiente;
    int iteracion=0;

    while(actual->siguiente != NULL){
        if(iteracion==tam){
            /*ya le dio una vuelta por lo tanto no encontro el dato*/
            break;
        }else{
            if(aux->dato == d){
                NodoDC* tmp = aux->siguiente;
                actual->siguiente = tmp;
                free(aux);
                tam -= 1;
                encontrado=true;
                break;
            }else{
                actual = actual->siguiente;
                aux = aux->siguiente;
                iteracion += 1;
            }
        }
    }

    /*
    while(actual->siguiente != ultimo && !encontrado){
        if(actual->dato == d){
            encontrado = true;
        }else{
            actual = actual->siguiente;
        }
    }
    if(encontrado){
        NodoDC* aux = actual->siguiente;
        if(ultimo==ultimo->siguiente){
            free(ultimo);
            p=false;
        }else{
            if(aux==ultimo){
                ultimo=actual;
            }
            actual->siguiente = aux->siguiente;
        }
        //free(aux);
    }
    **/

    return encontrado;
}

