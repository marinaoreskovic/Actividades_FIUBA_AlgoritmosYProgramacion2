#ifndef MENU_H
#define MENU_H

#include "Arbol.h"
#include "Archivo.h"

const int LEGAJO=101004;


class Menu{
    public:
        //Constructor
        Menu();

        //pre: Los datos ingresados deben ser validos
        //post: Agrega clientes al arbol
        void agregar_cliente(Arbol &abb,int precio);

        //pre: Los datos ingresados deben ser validos
        //post: Busca el cliente segun el numero de telefono que se ingrese
        void buscar_cliente(Arbol &abb);

        //pre: Los datos ingresados deben ser validos
        //post: Elimina el cliente segun el numero e telefono que se ingrese
        void eliminar_cliente(Arbol &abb);

        //pre: -
        //post: Imprime el menu del sistema
        void imprimir();

        //pre: Las listas deben existir
        //post: Ejecuta el menu a travez de una lista
        void ejecutar(Arbol &abb,int precio);

        //Destructor
        ~Menu();
};

#endif // MENU_H
