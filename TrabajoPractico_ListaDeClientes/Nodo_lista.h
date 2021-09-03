#ifndef NODO_LISTA_H_INCLUDED
#define NODO_LISTA_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

typedef string Dat;

class Nodo_lista{
    private:
        Dat elemento;
        Nodo_lista* siguiente;
    public:
        //Constructor
        Nodo_lista();

        ~Nodo_lista();

        // precondiciones:  Ninguna
        // postcondiciones: Crea un nodo con el Dat y el puntero a NULL
        Nodo_lista(Dat elemento);

        // Obtener el puntero al nodo siguiente
        // precondiciones:  nodo creado
        // postcondiciones: Devuelve el puntero al siguiente nodo si es el último devuelve NULL
        Nodo_lista* obtener_siguiente();

        //precondiciones: recibe un Nodo_lista
        //postcondiciones: lo pone como siguiente del nodo pelicula que llamo al metodo
        void asignar_siguiente(Nodo_lista* elemento);

        //postcondiciones: inicializa un nodo con siguiente NULL
        void inicializar_nodo();

        // precondiciones:  nodo creado
        // postcondiciones: V si tiene siguiente F sino
        bool ultimo_nodo();

        // precondiciones: -
        //postcondiciones: devuelve el elemento del nodo
        Dat obtener_elemento();

};

#endif // NODO_LISTA_H_INCLUDED
