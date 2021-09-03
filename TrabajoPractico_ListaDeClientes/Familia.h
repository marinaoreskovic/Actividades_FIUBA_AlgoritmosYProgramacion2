#ifndef FAMILIA_H
#define FAMILIA_H
#include "Lista.h"



class Familia{
    protected:
        Lista nombres;
    public:
        //Constructor sin parametros        
        Familia();

        //Constructor con parametros
        Familia(Lista &nom);

        Lista devolver_lista();

        //Destructor
        ~Familia();

};

 


#endif