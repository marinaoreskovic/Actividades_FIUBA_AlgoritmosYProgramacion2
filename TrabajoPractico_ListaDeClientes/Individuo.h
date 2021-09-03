#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include <iostream>

using namespace std;

class Individuo{
    protected:
        string nombre;
    public:
        //Constructor sin parametros
        Individuo();

        //Constructor con parametros de Individuo
        Individuo(string nom);

        //Destructor
        ~Individuo();


};




#endif
