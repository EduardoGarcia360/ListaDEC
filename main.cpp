#include <QCoreApplication>
#include "iostream"
#include "arbolavl.h"
#include "listadc.h"
#include "string.h"
#include "cstdlib"
#include "iostream"
#include "fstream"
#include "cstdlib"

using namespace std;

//ArbolAVL* miarbol= (ArbolAVL*)malloc(sizeof(ArbolAVL));
ListaDC* milista= (ListaDC*)malloc(sizeof(ListaDC));

int main()
{
    /*
    miarbol->insertar(10);
    miarbol->insertar(5);
    miarbol->insertar(13);
    miarbol->insertar(1);
    miarbol->insertar(6);
    miarbol->insertar(17);
    miarbol->insertar(16);
    NodoAVL* raiz = miarbol->obtenerRaiz();
    miarbol->preOrden(raiz);
    if(miarbol->eliminar(16)){
        miarbol->preOrden(raiz);
    }else{
        cout<<"el papu"<<endl;
    }
    **/
    milista->insertar(5);
    milista->insertar(10);
    milista->insertar(20);
    milista->insertar(30);
    milista->insertar(50);
    if(!milista->estaVacia()){
        milista->mostrarLista();
    }
}
