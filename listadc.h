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
    bool estaVacia();
    void insertar(int d);
    void mostrarLista();
    bool eliminar(int d);
    void modificar(int d, int n);
};

#endif // LISTADC_H
