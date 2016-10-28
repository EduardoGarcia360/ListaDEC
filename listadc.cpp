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

void ListaDC::mostrarLista(){
    cout<<"==============================="<<endl;
    if(cima==false){
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
        if(aux->siguiente==inicio){
            /*solo hay un nodo*/
            aux->anterior = NULL;
            aux->siguiente = NULL;
            inicio = NULL;
            free(aux);
            cima=false;
            encontrado=true;
        }else{
            while(aux->siguiente!=inicio){
                if(aux->dato==d){
                    if(ant==NULL){
                        if(aux->siguiente!=inicio){
                            /*es el "primer" nodo de la lista*/
                            NodoDC* tmp=aux;
                            ant = aux->anterior;
                            ant->siguiente = aux->siguiente;
                            aux = aux->siguiente;
                            aux->anterior = ant;
                            inicio=aux;
                            free(tmp);
                            encontrado=true;
                            break;
                        }
                    }else{
                        /*esta en medio de dos nodos*/
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
            }//fin while
        }
    }
    return encontrado;
}

