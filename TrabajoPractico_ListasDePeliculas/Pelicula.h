#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

#include "Lista.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <sstream>
using namespace std;

class Pelicula{
    private:
        string nombre_pelicula;
        string genero;
        int puntaje;
        string director;
        Lista<string> actores;

    public:

       //constructor
        Pelicula();

        //Destructor
        //Precondiciones: pelicula creada
        //postcondiciones: libera todos los recursos de la lista
        virtual ~Pelicula();

        //Precondiciones:-
        //Postcondiciones: devuelve el nombre de la pelicula-
        string devolver_nombre_pelicula();

        //Precondiciones:-
        //Postcondiciones: devuelve el genero de la pelicula-
        string devolver_genero();

        //Precondiciones:-
        //Postcondiciones: devuelve el puntaje de la pelicula-
        int devolver_puntaje();

        //Precondiciones:-
        //Postcondiciones: devuelve el director de la pelicula-
        string devolver_director();

        //Precondiciones:-
        //Postcondiciones: devuelve la lista de actores de la pelicula-
        Lista<string> devolver_actores();

        //Precondiciones:-
        //Postcondiciones: agrega un nombre a la pelicula-
        void agregar_nombre_pelicula(string nombre);

        //Precondiciones:-
        //Postcondiciones: agrega el genero de la pelicula-
        void agregar_genero(string gen);

        //Precondiciones:-
        //Postcondiciones: agrega el puntaje de la pelicula-
        void agregar_puntaje(int numero);

        //Precondiciones:-
        //Postcondiciones: agrega el director de la pelicula-
        void agregar_director(string dir);

        //Precondiciones:-
        //Postcondiciones: agrega la lista de actores de la pelicula-
        void agregar_actores(Lista<string> act);

        //Precondiciones:-
        //Postcondiciones: carga la cantidad de actores de la pelicula a la lista de actores-
        void cargar_actores(string total_actores);

        //pre: recibe datos de una pelicula
        //post: agrega estos datos a la pelicula que llamo a este metodo
        void cargar_pelicula(string nombre_pelicula,string genero,int puntaje,string director);

        //pre: -
        //post: muestra en pantalla la informacion de la pelicula
        void mostrar_pelicula();
};


#endif // PELICULA_H_INCLUDED
