#ifndef MENU_H
#define MENU_H

#include "Lista.h"
#include "Pelicula.h"
#include "Archivo.h"

class Menu{
    public:
        //Constructor
        Menu();

        //pre: -
        //post: Imprime el menu del sistema
        void imprimir();

        //pre: Las listas deben existir
        //post: Ejecuta el menu a travez de una lista
        void ejecutar(Archivo texto,Lista<Pelicula> &peliculas_vistas,Lista<Pelicula> &peliculas_no_vistas,Lista<Pelicula> &peliculas_recomendadas);

        //Destructor
        ~Menu();
};

#endif // MENU_H
