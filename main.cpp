#include <iostream>

#include "Grupos.h"

#include <string>
#include "sstream"
#include "vector"

using namespace std;

int cantGruposs = 0;
Grupos* grupos = new Grupos();

    void identificarCreacion(string input){
        int cont_int = 0, cont_strg = 0, cont_char = 0, cont_date = 0;
        string nombreGrupo = "", comando = "";

        istringstream iss(input);
        vector<string> palabras;
        string palabra;

        while (iss >> palabra) {
            palabras.push_back(palabra);
        }
        int tamano = palabras.size();

        cout << "Las palabras separadas son:" << endl;
        string listado[palabras.size()];
        int cont = 0;
        for (const auto& p : palabras) {
            listado[cont] = p;
            cont++;
        }
        cont = 2;

        for (int i = 0; i < tamano-1; ++i) {
            if (listado[i] == "ADD" && listado[i+1] == "NEW-GROUP"){
                try {
                    while(listado[i+cont] != "FIELDS"){
                    nombreGrupo += listado[i + cont] + " ";
                    cont++;
                    }
                } catch (const runtime_error& e){
                    cout<<"EL CODIGO NO HA SIDO INGRESADO CORRECTAMENTE, POR FAVOR REVISE LA INSERSION"<<endl;
                    break;
                }
            }
            if (listado[i] == "("){
                for (int j = i+1; j < tamano; ++j) {
                    if (listado[j] == "CHAR," || listado[j] == "CHAR"){
                        cont_char++;
                        comando += listado[j-1];
                        comando += " CHAR,";
                    } else if (listado[j] == "INTEGER," || listado[j] == "INTEGER"){
                        cont_int++;
                        comando += listado[j-1];
                        comando += " INTEGER,";
                    } else if (listado[j] == "DATE," || listado[j] == "DATE") {
                        cont_date++;
                        comando += listado[j-1];
                        comando += " DATE,";
                    } else if (listado[j] == "STRING," || listado[j] == "STRING"){
                        cont_strg++;
                        comando += listado[j-1];
                        comando += " STRING,";
                    } else if (listado[j] == ");"){
                        int conteo = cont_int + cont_date + cont_char + cont_strg;

                        grupos->agregarGrupo(nombreGrupo, comando);
                        cantGruposs++;
                    }
                }
                break;
            }
        }
    }

/*int encontrarGrupos(string nombre){
    if (Gruposs[0] == nullptr){
        return -1;
    } else {
        for (int i = 0; i < cantGruposs; ++i) {
            if (Gruposs[i]->getName() == nombre){
                return i;
            }
        }
        return -1;
    }
    return -1;
}
 */

    void identificarInsercion(string input){
        string nombreGrupos = "";
        string comp = "ADD CONTACT IN ";
        if (input.length() > comp.length() && input.substr(0, 15) == "ADD CONTACT IN "){
            input.erase(0, comp.length());
            int tam = input.length();
            for (int i = 0; i < tam; ++i) {
                if (input.substr(i, 8) == " FIELDS "){
                    nombreGrupos = input.substr(0, i+1);
                    input.erase(0, i+7);

                    if (input[0] == ' '){
                        input.erase(0, 1);
                    }
                    if(input.length() > 0 && input[0] == '('){
                        input.erase(0, 1);
                    }
                    if(input.length() > 3 && input.substr(input.length()-2) == ");"){
                        input.erase(input.length()-2, 2);
                    }
                    break;
                }
            }
            input += " ";
            grupos->agregarContacto(nombreGrupos, input);



        } else {
            cout<<"ESTRUCTURA DEL COMANDO NO RECONOCIDA, VERIFIQUE EL COMANDO"<<endl;
            cout<<"Presione ENTER para continuar"<<endl;
            cin>>nombreGrupos;
        }
    }

    void identificarBusqueda(string input){
        string nombreGrupos = "", cont = "FIND CONTACT IN ", busqueda = "", dato = "";
        if (input.length() > cont.length() && input.substr(0, cont.length()) == "FIND CONTACT IN "){
            input.erase(0, cont.length());
            int tam = input.length();
            for (int i = 0; i < tam; ++i) {
                if (input.substr(i, 15) == " CONTACT-FIELD "){
                    nombreGrupos = input.substr(0, i+1);
                    input.erase(0, i+14);
                    for (int j = 0; j < input.length(); ++j) {
                        if (input[j] != '='){
                            busqueda += input[j];
                        } else {
                            input.erase(0, j);
                            dato = input;
                        }
                    }
                    break;
                }
            }
            cout<<"Los datos del contacto son"<<endl;
            if(busqueda[0]==' '){
                busqueda.erase(0,1);
            }
            if(dato[0] == '='){
                dato.erase(0,1);
            }
            cout<<nombreGrupos<<endl;

            cout<<busqueda<<endl;

            cout<<dato<<endl;

            cout<<grupos->buscar(nombreGrupos,busqueda, dato)<<endl;
        }

    }

    int hash(string input){
        int hashValue = 0;
        for (char ch : input) {
            hashValue += static_cast<int>(ch);
        }
        return hashValue;
    }






int main() {
    bool fin = false;
    int opcion;
    string input;
    /*for (int i = 0; i < 2; ++i) {
        string cade;
        getline(cin, cade);
        identificarCreacion(cade);
    }
    string cade;
    getline(cin, cade);
    //identificarInsercion(cade);*/




     while (!fin){
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"----------   SISTEMA DE GESTION DE CONTACTOS  ----------"<<endl;
        cout<<"1.   Ingresar Nuevos Grupos"<<endl;
        cout<<"2.   Insercion de Contactos"<<endl;
        cout<<"3.   Buscar Contactos"<<endl;
        cout<<"4.   Salir"<<endl;
         getline(cin, input);
         opcion = stoi(input);



         switch (opcion) {
             case 1:
                 cout<<"Comando Creacion"<<endl;
                 getline(cin, input);
                 identificarCreacion(input);
                 break;
             case 2:
                 cout<<"Comando Inserciom"<<endl;
                 getline(cin, input);
                 identificarInsercion(input);
                 break;
             case 3:
                 cout<<"Comando Busqueda"<<endl;
                 getline(cin, input);
                 identificarBusqueda(input);
                 break;
             case 4:
                 break;
         }

    }


    return 0;
}
