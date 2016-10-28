#include "listadc.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "iostream"
#include "sstream"
#include "fstream"
#include "QString"
#include "cstdlib"

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

NodoDC* ListaDC::obtenerInicio(){
    return inicio;
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

void ListaDC::modificar(int d, int n){
    if(inicio!=NULL){
        NodoDC* aux = inicio;
        while(aux->siguiente!=inicio){
            if(aux->dato == d){
                aux->dato = n;
                break;
            }else{
                aux = aux->siguiente;
            }
        }
    }
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

int ListaDC::buscar(int clave){
    if(inicio!=NULL){
        bool encontrado=false;
        NodoDC* aux = inicio;
        while(aux->siguiente!=inicio){
            if(aux->dato == clave){
                encontrado=true;
                return aux->dato;
                break;
            }else{
                aux = aux->siguiente;
            }
        }
        if(encontrado==false){
            return NULL;
        }
    }else{
        return NULL;
    }
}

void ListaDC::graficar(NodoDC *ini){
    QString cuerpo="digraph G{\n node[shape=circle, style=filled];\n edge[color=blue];rankdir=UD \n";
    QString relacion="";

    while(ini->siguiente!=inicio){
        QString dato = QString::number(ini->dato);
        cuerpo += "\""+dato+"\" [label=\""+dato+"\" shape=\"record\"];\n";

        NodoDC* sig = ini->siguiente;
        NodoDC* ant = ini->anterior;
        relacion += "\""+dato+"\"->\""+QString::number(sig->dato)+"\"\n";
        relacion += "\""+dato+"\"->\""+QString::number(ant->dato)+"\"\n";
        ini = ini->siguiente;
    }

    QString dato = QString::number(ini->dato);
    cuerpo += "\""+dato+"\" [label=\""+dato+"\" shape=\"record\"];\n";

    NodoDC* sig = ini->siguiente;
    NodoDC* ant = ini->anterior;
    relacion += "\""+dato+"\"->\""+QString::number(sig->dato)+"\"\n";
    relacion += "\""+dato+"\"->\""+QString::number(ant->dato)+"\"\n";

    QString contenido = cuerpo + relacion + "\n}";

    ofstream escritura;
        escritura.open("/home/eduardo/Descargas/dato.dot", ios::out);
        if(escritura.is_open()){
            cout<<"abrio el archivo"<<endl;
            escritura<<contenido.toStdString()<<endl;
        }else{
            cout<<"nell prro"<<endl;
        }
        escritura.close();
        system("dot -Tpng /home/eduardo/Descargas/dato.dot -o /home/eduardo/datosalida.png");
}
