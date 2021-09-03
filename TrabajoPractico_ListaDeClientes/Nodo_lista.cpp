#include "Nodo_lista.h"


Nodo_lista::Nodo_lista(){
    siguiente=0;
}

Nodo_lista::~Nodo_lista(){

}

Nodo_lista::Nodo_lista(Dat elemento){
    this->elemento=elemento;
    siguiente=0;
}


Nodo_lista* Nodo_lista::obtener_siguiente(){
    return siguiente;
}


void Nodo_lista::asignar_siguiente(Nodo_lista* siguiente_elemento){

    siguiente=siguiente_elemento;
}


void Nodo_lista::inicializar_nodo(){

    Nodo_lista* aux=0;
    siguiente=aux;
}


bool Nodo_lista::ultimo_nodo(){

    return (siguiente==0);
}


Dat Nodo_lista::obtener_elemento(){

    return elemento;
}

