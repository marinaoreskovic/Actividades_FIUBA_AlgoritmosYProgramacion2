#include "Pelicula.h"

Pelicula::Pelicula(){

}

string Pelicula::devolver_nombre_pelicula(){
    return nombre_pelicula;
}

string Pelicula::devolver_genero(){
    return genero;
}

int Pelicula::devolver_puntaje(){
    return puntaje;
}

string Pelicula::devolver_director(){
    return director;
}

Lista<string> Pelicula::devolver_actores(){
    return actores;
}

void Pelicula::agregar_nombre_pelicula(string nombre){
    nombre_pelicula = nombre;
}

void Pelicula::agregar_genero(string gen){
    genero = gen;
}

void Pelicula::agregar_puntaje(int numero){
    puntaje = numero;
}

void Pelicula::agregar_director(string dir){
    director = dir;
}

void Pelicula::agregar_actores(Lista<string> act){
    actores = act;
}

void Pelicula::cargar_pelicula(string nombre_pelicula,string genero,int puntaje,string director){

    this->nombre_pelicula=nombre_pelicula;
    this->genero=genero;
    this->puntaje=puntaje;
    this->director=director;

}

void Pelicula::mostrar_pelicula(){

    cout<<"nombre_pelicula: "<<nombre_pelicula<<endl;
    cout<<"genero: "<<genero<<endl;
    cout<<"puntaje: "<<puntaje<<endl;
    cout<<"director: "<<director<<endl;
    int i=1;
    cout<<"Actores: ";
    while(i<actores.devolver_tamanio()){
        cout<<actores.obtener_dato(i)<<" | ";
        i++;
    }
    cout<<endl;
    cout<<"--------"<<endl;

}

Pelicula::~Pelicula()
{
    //dtor
}

void Pelicula::cargar_actores(string total_actores){
    string actor_actual;
    istringstream isstream(total_actores);
    while(isstream>>actor_actual){
        actores.agregar(actor_actual);
    }
}

