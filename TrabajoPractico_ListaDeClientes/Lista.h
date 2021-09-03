#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Nodo_lista.h"

class Lista{
    private:
        Nodo_lista* primer_elemento;
        int tamanio;
    public:
        //Constructor
        Lista();

        int devolver_tamanio();

        //pre:-
        //post: devuelve la "primer pelicula" de la lista de peliculas que lo llamó
        Nodo_lista* obtener_lista();

        //pre: debe ingresar una posicion valida > 1
        //post: devuelve el Dato segun la posicion de la lista a ingresar
        Dat obtener_Dat(int posicion);

        //pre: -
        //post: devuelve true si la lista esta vacia
        bool lista_vacia();

        //pre:recibe una pelicula
        //post:crea un nuevo nodo  con ésta, la agrega a la lista y aumenta el tamanio de la lista en 1
        void agregar(Dat d);

        //pre:-
        //post:muestra en pantalla la lista
        void mostrar_lista();

        void destructor_lista();

        ~Lista();
};




#endif // LISTA_H_INCLUDED
