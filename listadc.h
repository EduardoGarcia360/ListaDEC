#ifndef LISTADC_H
#define LISTADC_H

typedef struct NodoDC NodoDC;
typedef struct ListaDC ListaDC;

struct NodoDC{
    int dato;
    NodoDC* siguiente;
    NodoDC* anterior;
    NodoDC(int dato);
};

struct ListaDC{
    NodoDC* inicio;
    NodoDC* obtenerInicio();
    bool estaVacia();
    void insertar(int d);
    void mostrarLista();
    bool eliminar(int d);
    void modificar(int d, int n);
    void graficar(NodoDC* ini);
    int buscar(int clave);
};

#endif // LISTADC_H
