#include "Cliente.h"

Cliente::Cliente(){

}

Cliente::Cliente(string nom,int tel,int prec): Individuo(nom){

	solo_un_integrante=true; //MUY IMPORTANTE PARA DESPUES SABER SI ES CLIENTE DE FAMILIA O DE INDIVIDUO
	this->descuento=DESCUENTO_INDIVIDUAL;
	this->nombre=nom;
	this->telefono=tel;
	this->precio=prec;

}

Cliente::Cliente(Lista &nom,int tel,int prec): Familia(nom){

	solo_un_integrante=false; //MUY IMPORTANTE PARA DESPUES SABER SI ES CLIENTE DE FAMILIA O DE INDIVIDUO
	this->descuento=DESCUENTO_FAMILIAR;
	this->telefono=tel;
	this->precio=prec;

}

/*Pre:-
  Post:segun la longitud del numero,imprime la cantdad 
  necesaria de puntos para que quede simetrico con los bordes*/
void calcular_distancia_numeros(int numero,char separador){


	string str=to_string(numero);
	int longitud=str.length(); 
	
	for(int i=0;i<8-longitud;i++)
		cout<<separador;

}

/*Pre:-
  Post:segun la longitud del nombre,imprime la cantdad 
  necesaria de espacios para que quede simetrico con los bordes*/
void calcular_distancia_nombre(string nombre){

	cout<<"________________________________________________"<<endl;
    cout<<"||_________________Integrantes________________||"<<endl;
    cout<<"||"<<nombre;
    int longitud=nombre.length(); 
    for(int i=0;i<44-longitud;i++)
        cout<<" ";
    cout<<"||"<<endl;
}


void Cliente::mostrar_cliente(){
	if(solo_un_integrante){
		cout<<"Datos del individuo:"<<endl;
		calcular_distancia_nombre(nombre);
	}
	else{
		cout<<"Datos de la familia:"<<endl;
		nombres.mostrar_lista();
	}



	cout<<"||____________________________________________||"<<endl;
	cout<<"||______________Datos_personales______________||"<<endl;
	cout<<"||                                            ||"<<endl;
	cout<<"||-Su telefono es.....................";

	calcular_distancia_numeros(telefono,CERO);

	cout<<telefono<<"||"<<endl;


	cout<<"||                                            ||"<<endl;
    cout<<"||-El precio de su servicio es:.......";

	calcular_distancia_numeros(precio,PUNTO);

	cout<<precio<<"||"<<endl;


	cout<<"||                                            ||"<<endl;
    cout<<"||-Con su descuento resulta :.........";




	float precio_descontado=precio*(1-descuento);
	int multiplo_10=100000;

	if((int)precio_descontado-precio_descontado)
		calcular_distancia_numeros(precio_descontado*100,PUNTO);
	else
		calcular_distancia_numeros(precio_descontado,PUNTO);

	cout<<precio_descontado<<"||"<<endl;	

    cout<<"||¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯||"<<endl;
    cout<<"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<<endl<<endl<<endl<<endl;

}

void Cliente::modificar_telefono(int tel){
	this->telefono=tel;
}

int Cliente::devolver_telefono(){
    return telefono;
}

bool Cliente::es_solo_un_integrante(){
	return solo_un_integrante;
}

Cliente::~Cliente(){

}
