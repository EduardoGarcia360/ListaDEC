#include <QCoreApplication>
#include "listadc.h"

using namespace std;

ListaDC* milista = (ListaDC*)malloc(sizeof(ListaDC));

int main()
{

    milista->insertar(5);
    milista->insertar(10);
    milista->insertar(20);
    milista->insertar(30);
    milista->insertar(50);
    milista->insertar(12);
    milista->modificar(30,80);
    milista->modificar(5,99);
    milista->eliminar(50);
    milista->mostrarLista();
    NodoDC* inicio = milista->obtenerInicio();
    milista->graficar(inicio);

}
