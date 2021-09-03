#include "Familia.h"

Familia::Familia(){
	
}

Familia::Familia(Lista &nom){
	nombres=nom;
}

Familia::~Familia(){

}

Lista Familia::devolver_lista(){
	return nombres;
}