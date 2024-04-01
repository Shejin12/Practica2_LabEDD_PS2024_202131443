#include <iostream>

#include "Campo.h"

#include <string>
#include "sstream"
#include "vector"

using namespace std;

int cantCampos = 0;
Campo* campos[50];

    void identificarCreacion(string input){
        int tamano = input.length();
        int cont_int = 0, cont_strg = 0, cont_char = 0, cont_date = 0;
        string nombreGrupo = "", comando = "";
        Campo* nuevo;

        istringstream iss(input);
        vector<string> palabras;
        string palabra;

        while (iss >> palabra) {
            palabras.push_back(palabra);
        }

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
                    cout<<nombreGrupo<<endl;
                    nuevo = new Campo(nombreGrupo);
                } catch (const runtime_error& e){
                    cout<<"EL CODIGO NO HA SIDO INGRESADO CORRECTAMENTE, POR FAVOR REVISE LA INSERSION"<<endl;
                    break;
                }
            } else if (listado[i] == "("){
                for (int j = i+1; j < tamano; ++j) {
                    if (listado[j] == "CHAR," || listado[j] == "CHAR"){
                        cont_char++;
                        comando += "CHAR ";
                    } else if (listado[j] == "INTEGER," || listado[j] == "INTEGER"){
                        cont_int++;
                        comando += "INTEGER ";
                    } else if (listado[j] == "DATE," || listado[j] == "DATE") {
                        cont_date++;
                        comando += "DATE ";
                    } else if (listado[j] == "STRING," || listado[j] == "STRING"){
                        cont_strg++;
                        comando += "STRING ";
                    } else if (listado[j] == ");"){
                        int conteo = cont_int + cont_date + cont_char + cont_strg;

                        campos[cantCampos] = nuevo;
                        nuevo->definirComando(comando, conteo);
                        cantCampos++;
                    }
                }
                break;
            } else {
                break;
            }
        }
    }

    Campo* buscarNombreCampo(string name){
        for (int i = 0; i < cantCampos; ++i) {
            if (campos[i]->getName() == name){
                return campos[i];
            }
        }
        return nullptr;
    }

    void identificarInsercion(string input){
        string nombreCampo = "";
        if (input.substr(0, 15) == "ADD CONTACT IN "){
            input.erase(0, 15);
            int tam = input.length();
            for (int i = 0; i < tam; ++i) {
                if (input.substr(i, 8) == " FIELDS "){
                    nombreCampo = input.substr(0, i);
                }
            }
        }
    }

    bool encontrado(string nombre){
        for (int i = 0; i < cantCampos; ++i) {
            
        }
    }





int main() {
    bool fin = false;
    int opcion;
    for (int i = 0; i < 50; ++i) {
        campos[50] = new Campo();
    }
    string cade;
    getline(cin, cade);
    identificarInsercion(cade);


    /*

     while (!fin){
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"----------   SISTEMA DE GESTION DE CONTACTOS  ----------"<<endl;
        cout<<"1.   Ingresar Nuevos Grupos"<<endl;
        cout<<"2.   Insercion de Contactos"<<endl;

    }

     */
    return 0;
}
