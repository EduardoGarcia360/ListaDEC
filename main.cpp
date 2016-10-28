#include <QCoreApplication>
#include "iostream"
#include "arbolavl.h"
#include "listadc.h"
#include "tablahash.h"
#include "string.h"
#include "cstdlib"
#include "iostream"
#include "fstream"
#include "cstdlib"
#include "QString"

using namespace std;

//TablaHash* mitabla = (TablaHash*)malloc(sizeof(TablaHash));
//ArbolAVL* miarbol= (ArbolAVL*)malloc(sizeof(ArbolAVL));
ListaDC* milista= (ListaDC*)malloc(sizeof(ListaDC));

int main()
{
    /*
    mitabla->insertar(15);
    mitabla->insertar(26);
    mitabla->insertar(29);
    mitabla->insertar(2);
    mitabla->insertar(18);
    mitabla->insertar(28);
    mitabla->mostrar();
    mitabla->modificar(29, 40);
    mitabla->mostrar();
    QString w = mitabla->buscar(26);
    cout<<"=="<<endl;
    cout<<w.toStdString()<<endl;
    **/

    /*
    algo = mitabla->porcentajeLlenado();
    a = QString::number(algo, 'f', 2);
    cout<<a.toStdString()<<endl;

    mitabla->insertar(28);
    mitabla->mostrar();
    **/

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
    cout<<"============="<<endl;
    **/


    milista->insertar(5);
    milista->insertar(10);
    milista->insertar(20);
    milista->insertar(30);
    milista->insertar(50);
    milista->mostrarLista();

    milista->eliminar(5);
    milista->eliminar(20);
    milista->eliminar(10);
    milista->eliminar(30);
    milista->eliminar(50);
    milista->mostrarLista();

    cout<<"<===================>"<<endl;

    milista->insertar(12);
    milista->insertar(17);
    milista->insertar(20);
    milista->mostrarLista();

}
