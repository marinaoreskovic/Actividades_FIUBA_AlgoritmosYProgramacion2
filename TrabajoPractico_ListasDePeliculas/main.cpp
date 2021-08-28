#include <iostream>
#include "Lista.h"
#include "Menu.h"
#include "Archivo.h"

using namespace std;

int main(){

    cout << "Hellooooooo world!" << endl;

    Lista<Pelicula> peliculas_vistas;

    Lista<Pelicula> peliculas_no_vistas;

    Lista<Pelicula> peliculas_recomendadas;

    Archivo texto;

    texto.cargar_archivo(peliculas_vistas,peliculas_no_vistas);

    Menu menu;
    menu.ejecutar(texto,peliculas_vistas,peliculas_no_vistas,peliculas_recomendadas);

    //entro al destructor de listas automaticamente

    return 0;
}
