#include "listadc.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "iostream"
#include "sstream"

using namespace std;
bool cima=false;

NodoDC::NodoDC(int d){
    this->dato = d;
    this->siguiente = this;
    this->anterior = this;
}

bool ListaDC::estaVacia(){
    return inicio==NULL;
}

void ListaDC::insertar(int d){
    NodoDC* nuevo = new NodoDC(d);
    if(inicio){//inicio==null
        if(cima==false){
            inicio = nuevo;
            cima=true;
        }else{
            NodoDC* aux = inicio;
            while(aux->siguiente != inicio){
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
            nuevo->anterior = aux;
            nuevo->siguiente = inicio;
            inicio->anterior = nuevo;
        }
    }
}

void ListaDC::mostrarLista(){
    cout<<"==============================="<<endl;
    if(inicio==NULL){
        cout<<"<===vacio===>"<<endl;
    }else{
        NodoDC* aux = inicio;
        do{
            cout<<aux->dato<<endl;
            aux = aux->siguiente;
        }while(aux!=inicio);
    }
    cout<<"==============================="<<endl;
}

bool ListaDC::eliminar(int d){
    bool encontrado=false;
    if(inicio!=NULL){
        NodoDC* aux = inicio;
        NodoDC* ant = NULL;
        while(aux->siguiente!=inicio){
            if(aux->dato==d){
                if(ant==NULL){
                    if(aux->siguiente==inicio){
                        /*solo hay un nodo*/
                        aux->anterior = NULL;
                        aux->siguiente = NULL;
                        free(inicio);//inicio = NULL;
                        free(aux);//inicio=NULL
                        cima=false;
                        encontrado=true;
                        break;
                    }else{
                        /*es el nodo inicio*/
                        NodoDC* tmp=aux;
                        ant = aux->anterior;
                        ant->siguiente = aux->siguiente;
                        aux = aux->siguiente;
                        aux->anterior = ant;
                        inicio=aux;
                        free(tmp); //ant=NULL;
                        encontrado=true;
                        break;
                    }
                }else{
                    /*tiene nodos sig y ant*/
                    NodoDC* tmp = aux;
                    aux->anterior = NULL;
                    ant->siguiente = aux->siguiente;
                    aux = aux->siguiente;
                    aux->anterior = ant;
                    free(tmp);
                    encontrado=true;
                    break;
                }
            }else{
                /*si no es igual avanza*/
                ant = aux;
                aux = aux->siguiente;
            }
        }
    }
    return encontrado;
}

