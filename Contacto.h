#ifndef PRACTICA_2_CONTACTO_H
#define PRACTICA_2_CONTACTO_H

#include "ArbolChar.h"
#include "ArbolDate.h"
#include "ArbolInt.h"
#include "ArbolString.h"

class Contacto{
    string nombre;
    ArbolInt* Info_int[5];
    ArbolChar* Info_char[5];
    ArbolDate* Info_Date[5];
    ArbolString* Info_strings[5];

    Contacto(){
        for (int i = 0; i < 5; i++){
            Info_Date[i] = nullptr;
            Info_char[i] = nullptr;
            Info_int[i] = nullptr;
            Info_strings[i] = nullptr;
        }
    }
};



#endif //PRACTICA_2_CONTACTO_H
