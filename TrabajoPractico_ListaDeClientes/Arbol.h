#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include <iostream>


using namespace std;

class Arbol{
    private:
           // Punteros de la lista, para cabeza y nodo actual:
        Nodo* raiz;
        int cantidad;
        int altura;

    public:
        // Constructor y destructor básicos:
        Arbol();
        ~Arbol();

        //pre: debe ser un dato valido
        //post:  Inserta un dato en árbol ordenado
        void insertar(Dato dato);

        //pre: deben existir ambos nodos
        //post: swapear nodos
        void swap(Nodo* nodo_1,Nodo* nodo_2);

        //Buscar nodo
        //pre: debe ser un dato valido
        //post: devuelve el nodo del dato a buscar
        Dato buscar(Dato dato);

        //pre: debe ser un dato valido
        //post: borra dato del arbol sin devolver
        void borrar_sin_devolver(Dato dato);

        // Comprobar si es un nodo hoja:
        //pre: debe existir el nodo a comprobar
        //post: Comprueba si es un nodo hoja:
        bool es_hoja(Nodo* r);


        //pre: debe existir el arbol
        //post: llama a mostrar nodos para mostrar ordenadamente el arbol
        void mostrar_arbol();

        //pre: -
        //post: da la posicion del nodo en el arbol
        Nodo* posicionar_dato(Nodo*nodo_actual,Dato dato);

        //pre: debe existir el nodo
        //post: obtiene el nodo izquierdo o derecho ,elimina el nodo y lo setea en null
        void Podar(Nodo* nodo);

};
#endif
