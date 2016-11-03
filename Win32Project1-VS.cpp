// Win32Project1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "listadc.h"
#include <stdlib.h>
#include <malloc.h>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	listadc* milista=(listadc*)malloc(sizeof(listadc));
	milista->insertar(32);
	milista->insertar(15);
	milista->insertar(78);
	milista->insertar(46);
	milista->insertar(74);
	milista->mostrar();
	system("pause");
}

