#include "Arbol.h"
#include <stdio.h>

Arbol::Arbol(){
    cantidad = 0;
    raiz = 0;

}

Arbol::~Arbol(){
  Podar(raiz);

}

void Arbol::Podar(Nodo* nodo){
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
        if( !( (nodo->obtener_dato()).es_solo_un_integrante()) ){
          nodo->obtener_dato().devolver_lista().destructor_lista();
        }
      Podar(nodo->obtener_izquierdo()); // Podar izquierdo
      Podar(nodo->obtener_derecho());   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
  }

}



Nodo* Arbol::posicionar_dato(Nodo*nodo_actual,Dato dato){

  if(nodo_actual->obtener_dato().devolver_telefono() < dato.devolver_telefono()){

    if(nodo_actual->tiene_derecho()){
          return posicionar_dato(nodo_actual->obtener_derecho(),dato);
    }
  }

  else if(nodo_actual->obtener_dato().devolver_telefono() > dato.devolver_telefono())
    if(nodo_actual->tiene_izquierdo())
      return posicionar_dato(nodo_actual->obtener_izquierdo(),dato);

  return nodo_actual;
}


void Arbol::insertar(Dato dato){
  Nodo* nuevo = new Nodo(dato);

  //Si el arbol binario esta vacio
  if(!raiz){
    raiz = nuevo;
    cantidad++;
  }
  else{
    Nodo* padre =posicionar_dato(raiz,dato);

    if(padre->obtener_dato().devolver_telefono() < dato.devolver_telefono()){

      padre->agregar_derecho(nuevo);

    }
    else if (padre->obtener_dato().devolver_telefono() > dato.devolver_telefono()){

      padre->agregar_izquierdo(nuevo);

    }
  }
  cantidad++;
}


// Eliminar un elemento de un árbol ABB
void Arbol::borrar_sin_devolver(Dato dato){

  if( !( dato.es_solo_un_integrante()) ){
    dato.devolver_lista().destructor_lista();
  }


   Nodo* padre = NULL;
   Nodo* nodo;
   Nodo* actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(actual) {
      if(dato.devolver_telefono() == (actual->obtener_dato()).devolver_telefono() ) { // Si el valor está en el nodo actual
         if(es_hoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre){ // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if( padre->obtener_derecho() == actual){
                padre->agregar_derecho(NULL) ;
                
              }
               else if(padre->obtener_izquierdo() == actual){
                padre->agregar_izquierdo(NULL);
                
              }
            }
            delete actual; // Borrar el nodo
            actual = NULL;
            
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->tiene_derecho()) {
               nodo = actual->obtener_derecho();
               while(nodo->tiene_izquierdo() ) {
                  padre = nodo;
                  nodo = nodo->obtener_izquierdo();
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->obtener_izquierdo();
               while(nodo->tiene_derecho()){
                  padre = nodo;
                  nodo = nodo->obtener_derecho();
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            Dato aux = actual->obtener_dato();
            actual->agregar_dato(nodo->obtener_dato() );
            nodo->agregar_dato(aux);
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dato.devolver_telefono() > (actual->obtener_dato()).devolver_telefono() ){
          actual = actual->obtener_derecho();
          }
         else if(dato.devolver_telefono() < (actual->obtener_dato()).devolver_telefono() ){
          actual = actual->obtener_izquierdo();
          }
      }
   }
}


void Arbol::mostrar_arbol(){
  raiz->mostrar_nodos();
}



Dato Arbol::buscar(Dato dato){

  Nodo* buscador=posicionar_dato(raiz,dato);

  Dato cliente_buscado=buscador->obtener_dato();

  return cliente_buscado;

}

bool Arbol::es_hoja(Nodo* r) { 
  return !r->obtener_derecho() && !r->obtener_izquierdo(); 
}
