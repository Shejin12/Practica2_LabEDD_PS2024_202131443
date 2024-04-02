#ifndef PRACTICA_2_GRUPO_H
#define PRACTICA_2_GRUPO_H

#include "ArbolChar.h"
#include "ArbolDate.h"
#include "ArbolInt.h"
#include "ArbolString.h"
#include "Arbol.h"
#include "Log.h"

class Grupo{
private:
    Log* logger = new Log();
    string nombre, listaTipos = "";
    string listaCampos;
    ArbolInt* Info_int[10];
    ArbolChar* Info_char[10];
    ArbolDate* Info_Date[10];
    ArbolString* Info_strings[10];

public:

    Grupo(string comando){
        listaTipos = comando;

        for (int i = 0; i < 10; i++){
            Info_Date[i] = nullptr;
            Info_char[i] = nullptr;
            Info_int[i] = nullptr;
            Info_strings[i] = nullptr;
        }

        string campo = "";
        for (int i = 0; i < comando.length(); ++i) {
            if(comando[i] != ',' && comando[i] != ' '){
                campo += comando[i];
            }else{
                if(campo != "STRING" && campo != "INTEGER" && campo != "CHAR" && campo != "DATE"){
                    agregarArbol(campo);
                    listaCampos+= campo+",";
                }
                campo = "";
            }
        }
    }



    int obtenerTipo(string campo){
        string candidato = "";
        string eval;

        for (int i = 0; i < listaTipos.length(); ++i) {
            if(listaTipos[i] != ','){
                candidato += listaTipos[i];
            }else{
                if(candidato.length() > campo.length() && candidato.substr(0, campo.length()) == campo){
                    candidato.erase(0, campo.length());
                    if(candidato == " STRING"){
                        return 0;
                    }else if(candidato == " INTEGER"){
                        return 1;
                    } else if(candidato == " CHAR"){
                        return 2;
                    } else if(candidato == " DATE"){
                        return 3;
                    }else{
                        cout<<"No se encontro el tipo de dato"<<endl;
                        return -1;
                    }
                }
                candidato = "";
            }
        }
        return -1;
    }

    void agregarContacto(string comando){
        string dato = "";
        string campo = "";
        int posArbol;
        int posListaCampos = 0;
        for (int i = 0; i < comando.length(); ++i) {
            if(comando[i] != ' '){
                dato += comando[i];
            }else{
                if(dato[dato.length()-1]!= ','){
                    dato+=',';
                }
                if(dato.length()>2 && dato[dato.length()-1] == ','){
                    dato.erase(dato.length()-1, 1);

                    //Encontrar el campo
                    for (int j = posListaCampos; j < listaCampos.length(); ++j) {
                        if(listaCampos[j]!= ','){
                            campo+=listaCampos[j];
                        }else{
                            //Quitar el espacio antes del campo si existe
                            if(campo.length() > 2  && campo[0] == ' '){
                                campo.erase(0,1);
                            }
                            //Agregar el valor
                            posArbol = hash(campo);
                            switch (obtenerTipo(campo)) {
                                case 0:// String
                                {
                                    ArbolString *aIns = Info_strings[posArbol];
                                    if (aIns != nullptr) {
                                        aIns->insert(dato, comando);
                                    } else {
                                        logger->log("Clase Grupo: Colision con el tipo de dato String");
                                    }
                                    break;
                                }

                                case 1: // Int
                                {
                                    ArbolInt *aInse = Info_int[posArbol];
                                    if (aInse != nullptr) {
                                        aInse->insert(stoi(dato), comando);
                                    } else {
                                        logger->log("Clase Grupo: Colision con el tipo de dato Integer");
                                    }
                                    break;
                                }

                                case 2: // Char
                                {
                                    ArbolChar *aInser = Info_char[posArbol];
                                    if (aInser != nullptr) {
                                        aInser->insert(dato[0], comando);
                                    } else {
                                        logger->log("Clase Grupo: Colision con el tipo de dato Char");
                                    }
                                    break;
                                }
                                case 3: // Date
                                {
                                    ArbolDate *aInse = Info_Date[posArbol];
                                    if (aInse != nullptr) {
                                        aInse->insert(dato, comando);
                                    } else {
                                        logger->log("Clase Grupo: Colision con el tipo de dato Date");
                                    }
                                    break;
                                }
                                default: // No se encontro
                                {
                                    logger->log("Clase Grupo: No se encontro el tipo de dato ");
                                    break;
                                }
                            }
                            campo = "";
                            dato = "";
                            posListaCampos = j+1;
                            break;
                        }
                    }

                }
            }
        }
    }



    void agregarArbol(string Campo){
        int tipo = obtenerTipo(Campo);
        int pos = hash(Campo);
        switch (tipo) {
            case 0:// String
            {
                ArbolString *aIns = Info_strings[pos];
                if (aIns == nullptr) {
                    Info_strings[pos] = new ArbolString();
                    cout<<"Se agrego el arbol string " << Campo<<endl;
                    logger->log("Clase Grupo: Se agrego el arbol string " + Campo);
                } else {
                    //Hubo una colision;
                    cout<<"Colision al agregar arbol string" << Campo<<endl;
                    logger->log("Clase Grupo: Colision al agregar arbol string " + Campo);
                }
                break;
            }

            case 1: // Int
            {
                ArbolInt *aInse = Info_int[pos];
                if (aInse == nullptr) {
                    Info_int[pos] = new ArbolInt();
                    cout<<"Se agrego el arbol int " << Campo<<endl;
                    logger->log("Clase Grupo: Se agrego el arbol int " + Campo);
                } else {
                    //Hubo una colision;
                    cout<<"Colision al agregar int string" << Campo<<endl;
                    logger->log("Clase Grupo: Colision al agregar arbol int " + Campo);
                }
                break;
            }

            case 2: // Char
            {
                ArbolChar *aInser = Info_char[pos];
                if (aInser == nullptr) {
                    Info_char[pos] = new ArbolChar();
                    cout<<"Se agrego el arbol Char " << Campo<<endl;
                    logger->log("Clase Grupo: Se agrego el arbol char " + Campo);
                } else {
                    //Hubo una colision;
                    cout<<"Colision al agregar arbol char" << Campo<<endl;
                    logger->log("Clase Grupo: Colision al agregar arbol char " + Campo);
                }
                break;
            }
            case 3: // Date
            {
                ArbolDate *aInse = Info_Date[pos];
                if (aInse == nullptr) {
                    Info_Date[pos] = new ArbolDate();
                    cout<<"Se agrego el arbol date " << Campo<<endl;

                    logger->log("Clase Grupo: Se agrego el arbol date " + Campo);
                } else {
                    //Hubo una colision;
                    cout<<"Colision al agregar arbol date" << Campo<<endl;
                    logger->log("Clase Grupo: Colision al agregar arbol date " + Campo);
                }
                break;
            }
            default: // No se encontro
            {
                logger->log("Clase Grupo: No se hallo un arbol compatible con " + Campo);
                break;
            }
        }
    }

    string busqueda(string campo, string dato){
        int tipo = obtenerTipo(campo);
        int pos = hash(campo);
        switch (tipo) {
            case 0:// String
            {
                ArbolString *aIns = Info_strings[pos];
                if (aIns != nullptr) {
                    return aIns->obtenerInfoDato(dato);
                } else {
                    logger->log("Clase Grupo: Colision al buscar");
                }
                break;
            }

            case 1: // Int
            {
                ArbolInt *aInse = Info_int[pos];
                if (aInse == nullptr) {
                    return aInse->obtenerInfoDato(stoi(dato));
                } else {
                    logger->log("Clase Grupo: Colision al buscar");
                }
                break;
            }

            case 2: // Char
            {
                ArbolChar *aInser = Info_char[pos];
                if (aInser == nullptr) {
                    return aInser->obtenerInfoDato(dato[0]);;
                } else {
                    logger->log("Clase Grupo: Colision al buscar");
                }
                break;
            }
            case 3: // Date
            {
                ArbolDate *aInse = Info_Date[pos];
                if (aInse == nullptr) {
                    return aInse->obtenerInfoDato(dato);
                } else {
                    logger->log("Clase Grupo: Colision al buscar");
                }
                break;
            }
            default: // No se encontro
            {
                logger->log("Clase Grupo: No se hallo un contacto con estos datos");
                break;
            }
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

    int hash(string input){
        int hashValue = 0;
        for (char ch : input) {
            hashValue += static_cast<int>(ch);
        }
        return hashValue % 10;
    }

};



#endif //PRACTICA_2_GRUPO_H
