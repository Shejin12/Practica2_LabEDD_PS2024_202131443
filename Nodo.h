#ifndef PRACTICA_2_NODO_H
#define PRACTICA_2_NODO_H

#include <iostream>
using namespace std;

template <typename T>
class Nodo {
private:
    T dato;
    string infoContacto = "";
    Nodo<T>* Anterior;
    Nodo<T>* Siguiente;

public:
    Nodo(){
        Siguiente = nullptr;
        Anterior = nullptr;
    }

    void definirSiguiente(Nodo<T>* next){
        Siguiente = next;
    }

    void definirAnterior(Nodo<T>* prev){
        Anterior = prev;
    }

    Nodo<T>* irSiguiente(){
        return Siguiente;
    }

    Nodo<T>* irAnterior(){
        return Anterior;
    }

    void insertar(T dato, string infocontacto){
        this->dato = dato;
        this->infoContacto = infocontacto;
        cout<<"Se inserto " << dato<< endl;
    }

    T obtenerDato(){
        return dato;
    }

    void agregarInfo(string input){
        infoContacto += input;
    }

    string obtenerInfo(){
        return infoContacto;
    }
};
#endif //PRACTICA_2_NODO_H
