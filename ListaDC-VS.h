#pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

class listadc{
	int dato;
	listadc* inicio=NULL;
	listadc* siguiente;
	listadc* anterior;
	bool cima = true;
public:
	listadc(int d){
		dato = d;
		siguiente = this;
		anterior = this;
	}
	~listadc(void);
	listadc* obtenerInicio(){
		return inicio;
	}

	bool estaVacia(){
		return inicio == NULL;
	}

	void insertar(int d){
		listadc* nuevo = new listadc(d);
		if (cima){
			inicio = nuevo;
			cima = false;
		}else{
			listadc* aux = inicio;

			while (aux->siguiente != inicio){
				aux = aux->siguiente;
			}
			aux->siguiente = nuevo;
			nuevo->anterior = aux;
			nuevo->siguiente = inicio;
			inicio->anterior = nuevo;
		}
	}

	void mostrar(){
		cout << "===============================" << endl;
		if (inicio == NULL){
			cout << "<===vacio===>" << endl;
		}
		else{
			listadc* aux = inicio;
			do{
				cout << aux->dato << endl;
				aux = aux->siguiente;
			} while (aux != inicio);
		}
		cout << "===============================" << endl;
	}

	void modificar(int d, int n){
		if (inicio != NULL){
			listadc* aux = inicio;
			while (aux->siguiente != inicio){
				if (aux->dato == d){
					aux->dato = n;
					break;
				}
				else{
					aux = aux->siguiente;
				}
			}
		}
	}

	bool eliminar(int d){
		bool encontrado = false;
		if (inicio != NULL){
			listadc* aux = inicio;
			listadc* ant = NULL;
			if (aux->siguiente == inicio){
				/*solo hay un nodo*/
				aux->anterior = NULL;
				aux->siguiente = NULL;
				inicio = NULL;
				cima = true;
				free(aux);
				encontrado = true;
			}
			else{
				while (aux->siguiente != inicio){
					if (aux->dato == d){
						if (ant == NULL){
							if (aux->siguiente != inicio){
								/*es el "primer" nodo de la lista*/
								listadc* tmp = aux;
								ant = aux->anterior;
								ant->siguiente = aux->siguiente;
								aux = aux->siguiente;
								aux->anterior = ant;
								inicio = aux;
								free(tmp);
								encontrado = true;
								break;
							}
						}
						else{
							/*esta en medio de dos nodos*/
							listadc* tmp = aux;
							aux->anterior = NULL;
							ant->siguiente = aux->siguiente;
							aux = aux->siguiente;
							aux->anterior = ant;
							free(tmp);
							encontrado = true;
							break;
						}
					}
					else{
						/*si no es igual avanza*/
						ant = aux;
						aux = aux->siguiente;
					}
				}//fin while
			}
		}
		return encontrado;
	}
	
	int buscar(int clave){
		if (inicio != NULL){
			bool encontrado = false;
			listadc* aux = inicio;
			while (aux->siguiente != inicio){
				if (aux->dato == clave){
					encontrado = true;
					return aux->dato;
					break;
				}
				else{
					aux = aux->siguiente;
				}
			}
			if (encontrado == false){
				return NULL;
			}
		}
		else{
			return NULL;
		}
	}

	void graficar(listadc* ini){
		string cuerpo = "digraph G{\n node[shape=circle, style=filled];\n edge[color=blue];rankdir=UD \n";
		string relacion = "";

		/*recorre toda la lista pero no si hay solo un nodo*/
		while (ini->siguiente != inicio){
			string dato = to_string(ini->dato);
			cuerpo += "\"" + dato + "\" [label=\"" + dato + "\" shape=\"record\"];\n";

			listadc* sig = ini->siguiente;
			listadc* ant = ini->anterior;
			relacion += "\"" + dato + "\"->\"" + to_string(sig->dato) + "\"\n";
			relacion += "\"" + dato + "\"->\"" + to_string(ant->dato) + "\"\n";
			ini = ini->siguiente;
		}

		/*cuando solo hay un dato o falte el nodo inicio*/
		string dato = to_string(ini->dato);
		cuerpo += "\"" + dato + "\" [label=\"" + dato + "\" shape=\"record\"];\n";

		listadc* sig = ini->siguiente;
		listadc* ant = ini->anterior;
		relacion += "\"" + dato + "\"->\"" + to_string(sig->dato) + "\"\n";
		relacion += "\"" + dato + "\"->\"" + to_string(ant->dato) + "\"\n";
		/*====================================*/

		string contenido = cuerpo + relacion + "\n}";

		ofstream escritura;
		escritura.open("C:\\Users\\Edu\\Downloads\\listadc.dot", ios::out);
		if (escritura.is_open()){
			cout << "abrio el archivo" << endl;
			escritura << contenido << endl;
		}
		else{
			cout << "nell prro" << endl;
		}
		escritura.close();
		system("dot -Tpng C:\\Users\\Edu\\Downloads\\listadc.dot -O");
	}
};