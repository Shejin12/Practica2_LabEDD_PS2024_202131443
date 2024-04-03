#ifndef PRACTICA_2_Grupos_H
#define PRACTICA_2_Grupos_H

#include "Grupo.h"
#include "Arbolin.h"
#include "Log.h"

class Grupos{
private:
    Log* logger = new Log();
    string nombreGrupos;
    Grupo** contactos;
    string comandoInsersion;
    int cantGrupos = 0;
    int size = 5;


    int contContactos = 0;

public:

    Grupos(){
        //nombreGrupos = nombre;
        contactos = new Grupo * [size];
        for (int i = 0; i < size; ++i) {
            contactos[i] = nullptr;
        }
        size = 5;
    }

    Grupos(string nombre){
        nombreGrupos = nombre;
        contactos = new Grupo * [size];
        for (int i = 0; i < size; ++i) {
            contactos[i] = nullptr;
        }
        size = 5;
    }

    string getName(){
        return nombreGrupos;
    }

    void ingresarContacto(Grupo* newContac){
        if (contactos[0] == nullptr){
            contactos[0] = newContac;
        } else {
            int tamContactos = sizeof(contactos) / sizeof(contactos[0]);
            if(contContactos >= tamContactos){

            }
            contactos[contContactos] = newContac;
        }
        contContactos++;
    }

    int hash(string input){
        int hashValue = 0;
        int res = 0;
        for (char ch : input) {
            hashValue += static_cast<int>(ch);
        }
        res = hashValue % size;
        cout<<"Res: "<<res<<endl;
        return res;
    }

    void agregarGrupo(string name, string comando){
        int pos = hash(name);
        if (contactos[pos] == nullptr){
            contactos[pos] = new Grupo(name, comando);
            cantGrupos++;
        } else {
            cout<<"Colision"<<endl;
            logger->log("Clase Grupos: Colision al agregar grupo");
        }

        if (cantGrupos > (size*.6)){
            int newSize = size * 2;
            Grupo** aux = new Grupo *[newSize];
            for (int i = 0; i < newSize; ++i) {
                aux[i] = nullptr;
            }
            int auxSize = size;
            size = newSize;

            for (int i = 0; i < auxSize; ++i) {
                if (contactos[i] != nullptr){
                    int pos = hash(contactos[i]->obtenerNombew());
                    if (aux[pos] == nullptr){
                        aux[pos] = contactos[i];
                        cout<<contactos[i]->obtenerNombew()<< " reubicado"<<endl;
                    } else {
                        cout<<"Colision al redimensionar grupos"<<endl;
                        logger->log("Clase Grupos: Colision al redimensionar grupos");
                    }
                }
            }

        }
    }

    void agregarContacto(string grupo, string comando){
        int pos = hash(grupo);
        Grupo* dondeAgregar = contactos[pos];
        if(dondeAgregar != nullptr){
            dondeAgregar->agregarContacto(comando);
        }else{
            logger->log("Clase Grupos: Fallo al agregar contacto");
        }
    }

    string buscar(string nombreGrupo, string campo, string dato){
        int pos = hash(nombreGrupo);
        if (contactos[pos] != nullptr){
            string contacto = contactos[pos]->busqueda(campo, dato);
            logger->log("Clase Grupos: " + contacto);
            return contactos[pos]->busqueda(campo, dato);
        } else {
            logger->log("Clase Grupos: Contacto no encontrado");
            return "Contacto no encontrado";
        }
    }

    void exportar(string name){
        int pos = hash(name);
        if(contactos[pos] != nullptr){
            contactos[pos]->exportar();
        }else{
            cout<<"Se quiso exportar el grupo " << name << " pero es nulo"<<endl;
        }

    }
};

#endif //PRACTICA_2_Grupos_H
