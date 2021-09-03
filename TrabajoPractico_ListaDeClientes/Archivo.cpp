#include "Archivo.h"


void Archivo::cargar_archivo(Arbol &abb,int precio){
    ifstream clientes;
    clientes.open("clientes.txt");
        if (!clientes){
        cout<<"Ocurrió un problema al abrir el archivo de clientes "<<endl;
        }
            else{
                cargar_archivo_clientes(abb,clientes,precio);
            }
    clientes.close();
}

void Archivo::cargar_archivo_clientes(Arbol &abb,ifstream &clientes_txt,int precio){
    

    int telefono;
    string nombre;
    string aux;

    do{
        getline(clientes_txt,aux,',');
        telefono=atoi(aux.c_str());
        getline(clientes_txt,nombre);

        int hay_coma;
        hay_coma=nombre.find(',');
     
            if(hay_coma>0){
                Lista familiares;
                string nombre_familiar;

                int pos=0;
                int coma=0;
                    while(hay_coma>0){
                        coma=nombre.find(',',pos); 
                        nombre_familiar=nombre.substr(pos,coma-pos);
                        pos=coma+1;
                        hay_coma=nombre.find(',',pos);

                        familiares.agregar(nombre_familiar);
                    }
                nombre_familiar=nombre.substr(pos);
                familiares.agregar(nombre_familiar);

                Cliente cliente_familiar(familiares,telefono,precio);

                abb.insertar(cliente_familiar);

            }
            else{
                Cliente cliente_individuo(nombre,telefono,precio);

                abb.insertar(cliente_individuo);
            }

    }while(!clientes_txt.eof());


}