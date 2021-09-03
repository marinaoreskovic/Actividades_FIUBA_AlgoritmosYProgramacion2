#include "Lista.h"


Lista::Lista(){
    primer_elemento=0;
    tamanio=0;
}


Lista::~Lista(){
    //dtor
}

void Lista::destructor_lista(){
    //dtor
  Nodo_lista* aux=primer_elemento;

    while(!lista_vacia()){
        aux=primer_elemento;
            primer_elemento=primer_elemento->obtener_siguiente();
            delete aux;
            tamanio--;
    }

}

int Lista::devolver_tamanio(){
    return tamanio;
}


void Lista::agregar(Dat elemento){

    Nodo_lista* nuevo = new Nodo_lista(elemento);
    if(!lista_vacia())
        nuevo->asignar_siguiente(primer_elemento);

    primer_elemento=nuevo;
    tamanio++;
}


Dat Lista::obtener_Dat(int pos){
    Nodo_lista* aux = primer_elemento;

    if (!lista_vacia()){
        for (int cont = 1;(cont < pos && aux); cont++){
            aux = aux->obtener_siguiente();
        }
        return aux->obtener_elemento();
    }
    else
        return aux->obtener_elemento();
}


bool Lista::lista_vacia(){

    if( tamanio== 0){
        return true;
    }
    return false;
}

void calcular_distancia_nombres(string nombre){

    int longitud=nombre.length(); 
    
    for(int i=0;i<44-longitud;i++)
        cout<<" ";
    cout<<"||"<<endl;
}


void Lista::mostrar_lista(){

    Nodo_lista* aux=primer_elemento;
    int i=1;
    if(!lista_vacia()){
        cout<<"________________________________________________"<<endl;
        cout<<"||_________________Integrantes________________||"<<endl;
        while(i<=tamanio){
            i++;
            cout<<"||"<<(aux->obtener_elemento());
            calcular_distancia_nombres(aux->obtener_elemento());
            aux=aux->obtener_siguiente();
        }
    }
}


Nodo_lista* Lista::obtener_lista(){
    return primer_elemento;
}
