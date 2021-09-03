#include <string>
#include <iostream>
#include "Individuo.h"
#include "Familia.h"
#ifndef CLIENTE_H
#define CLIENTE_H

const char PUNTO='.';
const char CERO='0';
const float DESCUENTO_INDIVIDUAL=0.10;
const float DESCUENTO_FAMILIAR=0.35;


using namespace std;

class Cliente : public Individuo , public Familia{
    protected:
        int telefono;
        int precio;
        float descuento;
        bool solo_un_integrante;

    public:
        //Constructor
        Cliente();

        //Constructor con parametros de tipo Individuo
        Cliente(string nombre,int telefono,int precio);

        //Constructor con parametros de tipo Familia
        Cliente(Lista &nom,int telefono,int precio);

        //pre: -
        //post: imprime por pantalla los clientes
        void mostrar_cliente();

        //pre: debe ser un numero valido
        //post: agregar un telefono al cliente
        void modificar_telefono(int tel);

        // PRE: -
        // POST: obtiene el telefono
        virtual int devolver_telefono();

        virtual void mostrar_datos(){}

        virtual bool es_solo_un_integrante();

        //Destructor
        virtual ~Cliente();
};


#endif
