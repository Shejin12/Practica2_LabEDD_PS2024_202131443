#ifndef PRACTICA_2_CAMPO_H
#define PRACTICA_2_CAMPO_H

#include "Contacto.h"

class Campo{
private:
    string nombreCampo;
    Contacto* contactos[50];
    string comandoInsersion;
    int cantInsersion = 0;

    int contContactos = 0;

public:

    Campo(){
    }

    Campo(string nombre){
        nombreCampo = nombre;
    }

    string getName(){
        return nombreCampo;
    }

    void definirComando(string comando, int cant){
        comandoInsersion = comando;
        cantInsersion = cant;
    }

    void ingresarCampo(Contacto* newContac){
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

    bool verificarComando(string input){

    }

};

#endif //PRACTICA_2_CAMPO_H
