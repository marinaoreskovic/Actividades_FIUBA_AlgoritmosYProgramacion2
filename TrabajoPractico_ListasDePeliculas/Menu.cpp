#include "Menu.h"

Menu::Menu()
{
    //ctor
}

void Menu::imprimir(){
	cout<<"1. Mostrar peliculas vistas"<<endl;
    cout<<"2. Mostrar peliculas no vistas"<<endl;
    cout<<"3. Mostrar peliculas recomendadas"<<endl;
    cout<<"4. Salir"<<endl<<endl;
    cout<<" Ingrese una opcion a elegir :"<<endl;
}

void Menu::ejecutar(Archivo texto,Lista<Pelicula> &peliculas_vistas,Lista<Pelicula> &peliculas_no_vistas,Lista<Pelicula> &peliculas_recomendadas){

    int opcion;
	do{
        imprimir();
        cin>>opcion;
        system("clear");
		switch(opcion){
			case 1:
				peliculas_vistas.mostrar_lista_peliculas();
				break;
			case 2:
				peliculas_no_vistas.mostrar_lista_peliculas();
			    break;
			case 3:
				texto.agregar_recomendadas(peliculas_recomendadas,peliculas_vistas,peliculas_no_vistas,peliculas_recomendadas);
	    		peliculas_recomendadas.mostrar_lista_peliculas();
			    break;
			case 4:
			    break;
		}

        cin.ignore();
        cout <<"Presione enter para continuar"<<endl;
        cin.get();

		system("clear");
	}while(opcion!=4);
}

Menu::~Menu()
{
    //dtor
}
