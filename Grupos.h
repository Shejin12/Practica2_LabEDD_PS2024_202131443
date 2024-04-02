#ifndef PRACTICA_2_Grupos_H
#define PRACTICA_2_Grupos_H

#include "Grupo.h"
#include "Arbolin.h"

class Grupos{
private:
    string nombreGrupos;
    Grupo** contactos;
    string comandoInsersion;
    int cantInsersion = 0;
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

    void definirComando(string comando, int cant){
        comandoInsersion = comando;
        cantInsersion = cant;
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
            contactos[pos] = new Grupo(comando);
        } else {
            cout<<"Colision"<<endl;
        }
    }

    void agregarContacto(string grupo, string comando){
        int pos = hash(grupo);
        Grupo* dondeAgregar = contactos[pos];
        if(dondeAgregar != nullptr){
            dondeAgregar->agregarContacto(comando);
        }else{
            // Informar en log
        }
    }

    string buscar(string nombreGrupo, string campo, string dato){
        int pos = hash(nombreGrupo);
        if (contactos[pos] != nullptr){
            return contactos[pos]->busqueda(campo, dato);
        } else {
            cout<<"Grupo no encontrado"<<endl;
            return "No hay";
        }
    }

};

#endif //PRACTICA_2_Grupos_H
