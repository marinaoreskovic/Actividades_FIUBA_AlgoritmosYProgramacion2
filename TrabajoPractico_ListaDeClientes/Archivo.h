#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <fstream>
#include "Arbol.h"
#include "Lista.h"
#include "Individuo.h"
#include "Familia.h"

using namespace std;

class Archivo{

    private:

    public:
    	// PRE:recice un arbol abb
        // POST: agrega a una lista los familiares/individuos y muestra por pantalla si ocurrio un error al abrir el archivo
    	void cargar_archivo(Arbol &abb,int precio);
    	// PRE: recibe un arbol abb, y un archivo clientes abierto
        // POST: agrega a una lista los familiares/individuos
    	void cargar_archivo_clientes(Arbol &abb,ifstream &clientes_txt,int precio);

};



#endif // ARCHIVO_H_INCLUDED
