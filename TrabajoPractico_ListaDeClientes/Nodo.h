#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Cliente.h"

using namespace std;

typedef Cliente Dato;

class Nodo {
    private:
        Dato  dato;     // Dato a almacenar
        Nodo* izq;      // Puntero a nodo izquierdo
        Nodo* der;      //Puntero a nodo izquierdo

    public:         // Constructor con parametro
        // PRE:  Ninguna
        // POST: Crea un nodo con el dato d
        //       y el puntero a NULL
        Nodo(Dato d);

        // Destructor
        // PRE:  Nodo creado
        // POST: No hace nada
        ~Nodo();
        // Setea el dato (lo cambia)
        // PRE:  el nodo tiene que estar creado
        //       d tiene que ser un dato válido
        // POST: el nodo queda con el dato d
        void  agregar_dato(Dato d);

        // Setear el puntero al nodo izquierdo
        // PRE:  nodo creado y puntero válido
        // POST: el puntero al siguiente apuntará a izq
        void  agregar_izquierdo(Nodo* izquierdo);

        // Setear el puntero al nodo derecho
        // PRE:  nodo creado y puntero válido
        // POST: el puntero al siguiente apuntará a der
        void  agregar_derecho(Nodo* derecho);


        // Obtener el dato
        // PRE:  nodo creado
        // POST: devuelve el dato que contiene el nodo
        Dato  obtener_dato();

        // Obtener el puntero al nodo izquierdo
        // PRE:  nodo creado
        // POST: Devuelve el puntero al siguiente nodo
        //       si es el último devuelve NULL
        Nodo* obtener_izquierdo();

        // Obtener el puntero al nodo derecho
        // PRE:  nodo creado
        // POST: Devuelve el puntero al siguiente nodo
        //       si es el último devuelve NULL
        Nodo* obtener_derecho();

        // ¿Hay un siguiente?
        // PRE:  nodo creado
        // POST: V si tiene sig. F sino
        bool tiene_siguiente();

        bool tiene_izquierdo();

        bool tiene_derecho();

        void mostrar_dato();

        Nodo* posicionar_dato_nuevo(Dato dato);

        // PRE: metodo recursivo que muestra,ordenadamente de mayor a menor,los nodos de un arbol
        void mostrar_nodos();

};
#endif // NODO_H_INCLUDED
