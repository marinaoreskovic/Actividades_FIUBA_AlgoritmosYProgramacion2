#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Nodo.h"

template < typename Dato >

class Lista{
    private:
        Nodo<Dato>* primer_elemento;
        int tamanio;
    public:
        //Constructor
        Lista();

        int devolver_tamanio();

        //pre:-
        //post: devuelve la "primer pelicula" de la lista de peliculas que lo llamó
        Nodo<Dato>* obtener_lista();

        //pre: debe ingresar una posicion valida > 1
        //post: devuelve el dato segun la posicion de la lista a ingresar
        Dato obtener_dato(int posicion);

        //pre: -
        //post: devuelve true si la lista esta vacia
        bool lista_vacia();

        //pre:recibe una pelicula
        //post:crea un nuevo nodo pelicula con ésta, la agrega a la lista y aumenta el tamanio de la lista en 1
        void agregar(Dato pelicula);

        //pre:-
        //post:muestra en pantalla la lista de peliculas actual
        void mostrar_lista_peliculas();


        //pre:-
        //post:muestra en pantalla la lista actores de la pelicula actual
        void mostrar_lista_actores();
        //Destructor
        ~Lista();
};



template < typename Dato >
Lista<Dato>::Lista(){

    primer_elemento=0;//a esta no la puedo igualar a cero,tiene que tener una pelicula inicializada en cero y todo eso
    tamanio=0;

}

template < typename Dato >
Lista<Dato>::~Lista(){
    //dtor
    //cout <<"entro al destructor de lista de peliculas automaticamente"<<endl;
    Nodo<Dato>* aux=primer_elemento;
    Nodo<Dato>* borrar = primer_elemento;

    while(!lista_vacia() && tamanio==0){
        aux=primer_elemento;
        if(tamanio!=1){
            primer_elemento=primer_elemento->obtener_siguiente();//no hay necesidad de pasar al siguiente de "primero" si estoy por eliminarlo
            borrar = aux;
            delete borrar;
            tamanio--;
        }
    }

}


template < typename Dato >
int Lista<Dato>::devolver_tamanio(){
    return tamanio;
}


template < typename Dato >
void Lista<Dato>::agregar(Dato elemento){


    Nodo<Dato>* nuevo = new Nodo<Dato>(elemento);
    if(!lista_vacia())
        nuevo->asignar_siguiente(primer_elemento);

    primer_elemento=nuevo;
    tamanio++;
}

template < typename Dato >
Dato Lista<Dato>::obtener_dato(int pos){
    Nodo<Dato>* aux = primer_elemento;

    if (!lista_vacia()){
        for (int cont = 1;(cont < pos && aux); cont++){
            aux = aux->obtener_siguiente();
        }
        return aux->obtener_elemento();
    }
    else
        return aux->obtener_elemento(); //nunca lo voy a usar pero asi no me tira ningun warning
}

template < typename Dato >
bool Lista<Dato>::lista_vacia(){

    if( tamanio== 0){
        return true;
    }
    return false;
}

template < typename Dato >
void Lista<Dato>::mostrar_lista_peliculas(){

    Nodo<Dato>* aux=primer_elemento;
    int i=1;
    if(!lista_vacia()){
        while(i<=tamanio){
            i++;
            (aux->obtener_elemento()).mostrar_pelicula();
            aux=aux->obtener_siguiente();
        }
    }
}

template < typename Dato >
Nodo<Dato>* Lista<Dato>:: obtener_lista(){
    return primer_elemento;

}

#endif // LISTA_H_INCLUDED
