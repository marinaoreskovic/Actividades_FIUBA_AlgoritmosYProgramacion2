#include "Menu.h"


Menu::Menu()
{
    //ctor
}

void agregar_individuo(Arbol &abb,int precio,int telefono){

	string nombre_cliente;
	cout<<"ingrese el nombre del cliente"<<endl;
	cin>>nombre_cliente;

	cout<<"Ingrese su precio base :"<<endl;
    cin>>precio;

	Cliente cliente_individuo(nombre_cliente,telefono,precio);

	Dato cliente_buscado=abb.buscar(cliente_individuo);

	while(cliente_buscado.devolver_telefono()==telefono){ //esto significa,el numero que le quiero agregara al cliente nuevo
															  //lo encontre en el arbol,por lo que ya esta en uso asique pruebo con este+1
		telefono++;

		cliente_individuo.modificar_telefono(telefono);

		cliente_buscado=abb.buscar(cliente_individuo);
	}

	abb.insertar(cliente_individuo);

}

void agregar_familia(Arbol &abb,int precio,int telefono){

	Lista familiares;
	string nombre_cliente_actual;
	do{
		cout<<"Ingrese el nombre de un integrante de la familia o cero para salir"<<endl;
		cin>>nombre_cliente_actual;
		if(nombre_cliente_actual!="0")
			familiares.agregar(nombre_cliente_actual);
	}while(nombre_cliente_actual!="0");

	cout<<"Ingrese su precio base :"<<endl;
    cin>>precio;

    Cliente cliente_familiar(familiares,telefono,precio);

	Dato cliente_buscado=abb.buscar(cliente_familiar);

	while(cliente_buscado.devolver_telefono()==telefono){ //esto significa,el numero que le quiero agregara al cliente nuevo
															  //lo encontre en el arbol,por lo que ya esta en uso asique pruebo con este+1
		telefono++;

		cliente_familiar.modificar_telefono(telefono);

		cliente_buscado=abb.buscar(cliente_familiar);
	}

    abb.insertar(cliente_familiar);
}

void Menu::eliminar_cliente(Arbol &abb){

	string nombre;
	int precio;
	int telefono;
	cout<<"Ingrese el numero del cliente que desea dar de baja: "<<endl;
	cin>>telefono;

	Dato cliente_a_borrar(nombre,telefono,precio);

	cliente_a_borrar=abb.buscar(cliente_a_borrar);

	if(cliente_a_borrar.devolver_telefono()==telefono){
	
        cout<<"Se ha dado de baja con exito al cliente:"<<endl;
        cliente_a_borrar.mostrar_cliente();		
		abb.borrar_sin_devolver(cliente_a_borrar);
	}else{
        cout<<"El cliente que desea dar de baja no existe."<<endl;
	}

}

void Menu::agregar_cliente(Arbol &abb,int precio){

	int telefono=LEGAJO;
	int opcion_ingresada;

	cout<<"________________________________________________"<<endl;
	cout<<"||__Ingrese el tipo de cliente que agregara___||"<<endl;
	cout<<"||                                            ||"<<endl;
	cout<<"||-Unico individuo........................[1]-||"<<endl;
	cout<<"||                                            ||"<<endl;
    cout<<"||-Grupo familiar.........................[2]-||"<<endl;
    cout<<"||¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯||"<<endl;
    cout<<"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<<endl<<endl;


	cin>>opcion_ingresada;
	if(opcion_ingresada==1)
		agregar_individuo(abb,precio,telefono);

	else if(opcion_ingresada==2)
		agregar_familia(abb,precio,telefono);

	else
		cout<<"Ingresaste una opcion invalida crack"<<endl;
}


void Menu::buscar_cliente(Arbol &abb){ //porque al buscar un cliente entro al constructo

	string nombre; //busco por el numero asique ni pido el nombre,pero igual lo tengo que ingresar para crearme un cliente el cual buscar
	int precio; //busco por el numero asique ni pido el precio,pero igual lo tengo que ingresar para crearme un cliente el cual buscar
	int telefono;
	cout<<"Ingrese el numero del cliente que esta buscando"<<endl;
	cin>>telefono;

	Dato cliente_buscado(nombre,telefono,precio);

	cliente_buscado=abb.buscar(cliente_buscado);

	if(cliente_buscado.devolver_telefono()==telefono){//si coincide el numero encontrado con el telefono que ingrese,lo encontre y lo muestro en pantalla

		cout<<"Se encontró el cliente,sus datos son:"<<endl;
		cliente_buscado.mostrar_cliente();

	}
	else
		cout<<"No se encontró el cliente buscado"<<endl;



}

void Menu::imprimir(){
	cout<<"________________________________________________"<<endl;
	cout<<"||_________Ingrese la opcion de desee_________||"<<endl;
	cout<<"||                                            ||"<<endl;
	cout<<"||-Agregar un cliente.....................[1]-||"<<endl;
	cout<<"||                                            ||"<<endl;
    cout<<"||-Dar de baja a un cliente...............[2]-||"<<endl;
	cout<<"||                                            ||"<<endl;
    cout<<"||-Lista clientes.........................[3]-||"<<endl;
	cout<<"||                                            ||"<<endl;
    cout<<"||-Buscar un cliente......................[4]-||"<<endl;
	cout<<"||                                            ||"<<endl;
    cout<<"||-Salir..................................[5]-||"<<endl;
    cout<<"||¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯||"<<endl;
    cout<<"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<<endl<<endl;
}

void Menu::ejecutar(Arbol &abb,int precio){

    int opcion;
	do{
        imprimir();
        cin>>opcion;
        system("clear");
		switch(opcion){
			case 1:
				agregar_cliente(abb,precio);
				break;
			case 2:
				eliminar_cliente(abb);
			    break;
			case 3:
				abb.mostrar_arbol();
			    break;
			case 4:
				buscar_cliente(abb);
			    break;
		}

        cin.ignore();
        cout <<"Presione enter para continuar"<<endl;
        cin.get();

		system("clear");
	}while(opcion!=5);
}

Menu::~Menu()
{
    //dtor
}
