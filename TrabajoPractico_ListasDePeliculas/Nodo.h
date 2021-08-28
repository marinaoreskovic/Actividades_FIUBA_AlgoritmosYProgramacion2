#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template < typename Dato >

class Nodo{
    private:
        Dato elemento;
        Nodo<Dato>* siguiente;
    public:
        //Constructor
        Nodo();

        // precondiciones:  Ninguna
        // postcondiciones: Crea un nodo con el dato y el puntero a NULL
        Nodo(Dato elemento);

        // Obtener el puntero al nodo siguiente
        // precondiciones:  nodo creado
        // postcondiciones: Devuelve el puntero al siguiente nodo si es el último devuelve NULL
        Nodo<Dato>* obtener_siguiente();

        //precondiciones: recibe un Nodo
        //postcondiciones: lo pone como siguiente del nodo pelicula que llamo al metodo
        void asignar_siguiente(Nodo<Dato>* elemento);

        //postcondiciones: inicializa un nodo con siguiente NULL
        void inicializar_nodo();

        // precondiciones:  nodo creado
        // postcondiciones: V si tiene siguiente F sino
        bool ultimo_nodo();

        // precondiciones: -
        //postcondiciones: devuelve el elemento del nodo
        Dato obtener_elemento();

};
template < typename Dato >
Nodo<Dato>::Nodo(){
    siguiente=0;
}

template < typename Dato >
Nodo<Dato>::Nodo(Dato elemento){

    this->elemento=elemento;
    siguiente=0;
}


template < typename Dato >
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
    return siguiente;
}

template < typename Dato >
void Nodo<Dato>::asignar_siguiente(Nodo<Dato>* siguiente_elemento){

    siguiente=siguiente_elemento;
}

template < typename Dato >
void Nodo<Dato>::inicializar_nodo(){

    Nodo<Dato>* aux=0;
    siguiente=aux;
}

template < typename Dato >
bool Nodo<Dato>::ultimo_nodo(){

    return (siguiente==0);
}

template < typename Dato >
Dato Nodo<Dato>::obtener_elemento(){

    return elemento;
}

#endif // NODO_H_INCLUDED
