#ifndef PRACTICA_2_CONTACTO_H
#define PRACTICA_2_CONTACTO_H

#include "ArbolChar.h"
#include "ArbolDate.h"
#include "ArbolInt.h"
#include "ArbolString.h"

class Contacto{
private:
    string nombre;
    ArbolInt* Info_int[5];
    ArbolChar* Info_char[5];
    ArbolDate* Info_Date[5];
    ArbolString* Info_strings[5];

public:
    Contacto(){
        for (int i = 0; i < 5; i++){
            Info_Date[i] = nullptr;
            Info_char[i] = nullptr;
            Info_int[i] = nullptr;
            Info_strings[i] = nullptr;
        }
    }

    void agregarNombre(string name){
        nombre = name;
    }

    void agregarChar(char dato){

    }

    void agregarInt(int dato){

    }

    void agregarStrn(string dato){

    }

    void agregarDate(char dato){

    }

};



#endif //PRACTICA_2_CONTACTO_H
