#include "Nodo.h"

//typedef Cliente Dato;

// Constructor con parametro
Nodo::Nodo(Dato d) {
    dato = d;
    izq = 0;
    der = 0;

}

// Destructor
Nodo::~Nodo() {
    // No hace nada
}

// Setear el dato
void Nodo::agregar_dato(Dato d) {
    dato = d;
}

// Setear el ptr al sig
void Nodo::agregar_izquierdo(Nodo* izquierdo) {
    izq = izquierdo;
}

// Setear el ptr al sig
void Nodo::agregar_derecho(Nodo* derecho) {
    der = derecho;
}

// Devolver el dato
Dato Nodo::obtener_dato() {
    return dato;
}

// Devolver el izquierdo
Nodo* Nodo::obtener_izquierdo() {
    return izq;
}

// Devolver el derecho
Nodo* Nodo::obtener_derecho() {
    return der;
}


// Tiene siguiente?
bool Nodo::tiene_izquierdo() {
     return (izq != 0);
}

// Tiene siguiente?
bool Nodo::tiene_derecho() {
     return (der != 0);
}
void Nodo::mostrar_dato(){

    dato.mostrar_cliente();
}



void Nodo::mostrar_nodos(){

  if(tiene_izquierdo())
    obtener_izquierdo()->mostrar_nodos();

  mostrar_dato();

  if (tiene_derecho())
    obtener_derecho()->mostrar_nodos();

}