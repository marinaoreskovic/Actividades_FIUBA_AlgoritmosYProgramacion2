#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include "Lista.h"
#include "Pelicula.h"
const int PUNTAJE_RECOMENDADO = 7;

using namespace std;
class Archivo{

    private:

    public:

        /*Pre:recibe una lista de listas de peliculas
        Post:abre los archivos .txt y llama al metodo cargar archivo*/
        template < typename Dato >
        void cargar_archivo_peliculas(Lista<Dato> &lista,ifstream &peliculas_txt);

        /*Pre:recibe una lista peliculas
        Post:le carga las peliculas a la lista*/
        template < typename Dato >
        void cargar_archivo(Lista<Dato>  &lista_vistas,Lista<Dato> &lista_no_vistas);

        /*Pre:no hay ninguna pelicula que este tanto en la lista de vistas como en la de no vistas
        Post:carga las peliculas no vistas que cumplan con el criterio de seleccion a la lista de recomendadas*/
        template < typename Dato >
        void agregar_recomendadas(Lista<Dato> &peliculas_recomendadas,Lista<Dato> &lista_vistas,Lista<Dato> &lista_no_vistas,Lista<Dato> &lista_recomendadas);

};


template < typename Dato >
void Archivo::cargar_archivo(Lista<Dato>  &lista_vistas,Lista<Dato> &lista_no_vistas){

    ifstream peliculas_vistas;

    ifstream peliculas_no_vistas;

    peliculas_vistas.open("peliculas_vistas.txt");

    peliculas_no_vistas.open("peliculas_no_vistas.txt");

    if (!peliculas_vistas || !peliculas_no_vistas)
        cout<<"ocurrió un problema al abrir el archivo de peliculas vistas "<<endl;

    else{

        cargar_archivo_peliculas(lista_vistas,peliculas_vistas);

        cargar_archivo_peliculas(lista_no_vistas,peliculas_no_vistas);

    }
    peliculas_no_vistas.close();
    peliculas_vistas.close();
}

template < typename Dato >
void Archivo::cargar_archivo_peliculas(Lista<Dato> &lista,ifstream &peliculas_txt){

    string nombre_pelicula;
    string genero;
    string director;
    string actores;
    string aux;
    int puntaje;

    do{
        Pelicula pelicula;
        getline(peliculas_txt,nombre_pelicula);
        getline(peliculas_txt,genero);
        getline(peliculas_txt,aux);
        puntaje=atoi(aux.c_str());
        getline(peliculas_txt,director);//uso director para guardar el valor de puntaje
        getline(peliculas_txt,actores);
        pelicula.cargar_actores(actores);

        pelicula.cargar_pelicula(nombre_pelicula,genero,puntaje,director);

        lista.agregar(pelicula);

        getline(peliculas_txt,actores);//con esto me salteo la linea de espacio entre las peliculas

    }while(!peliculas_txt.eof());

}

template < typename Dato >
void Archivo::agregar_recomendadas(Lista<Dato> &peliculas_recomendadas,Lista<Dato> &lista_vistas,Lista<Dato> &lista_no_vistas,Lista<Dato> &lista_recomendadas){
    Pelicula pelicula_vista, pelicula_no_vista, pelicula_recomendada;
    int j;
    int i=1;
    if(!lista_vistas.lista_vacia() && !lista_no_vistas.lista_vacia()){
        while(i<=lista_vistas.devolver_tamanio()){
            pelicula_vista = lista_vistas.obtener_dato(i);
            j=1;
            while(j<=lista_no_vistas.devolver_tamanio()){
                pelicula_no_vista = lista_no_vistas.obtener_dato(j);
                if(pelicula_no_vista.devolver_genero() == pelicula_vista.devolver_genero() &&(pelicula_vista.devolver_director()== pelicula_no_vista.devolver_director()|| pelicula_no_vista.devolver_puntaje()>=PUNTAJE_RECOMENDADO)){
                   lista_recomendadas.agregar(pelicula_no_vista);
                }
                j++;
            }
            i++;
        }
    }
}

#endif // ARCHIVO_H_INCLUDED
