#ifndef PRACTICA_2_ARBOL_H
#define PRACTICA_2_ARBOL_H

#include "Nodo.h"
#include "Log.h"

template <typename T>
class Arbol {

private:
    Nodo<T>* root;

    Nodo<T>* insertRecursive(Nodo<T>* node, T dato, string infoContacto) {
        if (node == nullptr) {
            Nodo<T>* newNode = new Nodo<T>();
            newNode->insertar(dato, infoContacto);
            return newNode;
        }

        if (dato < node->obtenerDato()) {
            node->definirAnterior(insertRecursive(node->irAnterior(), dato, infoContacto));
        } else if (dato > node->obtenerDato()) {
            node->definirSiguiente(insertRecursive(node->irSiguiente(), dato, infoContacto));
        }

        return node;
    }

    Nodo<T>* findRecursive(Nodo<T>* node, T dato) {
        if (node == nullptr || node->obtenerDato() == dato) {
            return nullptr;
        }
        if (node->obtenerDato() == dato){

        }

        if (dato < node->obtenerDato()) {
            return findRecursive(node->irAnterior(), dato);
        } else {
            return findRecursive(node->irSiguiente(), dato);
        }
    }

    Nodo<T>* buscarPorContenidoRecursivo(Nodo<T>* nodo, T contenido){
        if (nodo == nullptr ) {
            return nullptr;
        }

        if(nodo->obtenerDato() == contenido){
            return nodo;
        }else{
            Nodo<T>* temporal;
            if(nodo->irAnterior() != nullptr){
                temporal = buscarPorContenidoRecursivo(nodo->irAnterior(), contenido);
                if(temporal!= nullptr){
                    return temporal;
                }
            }
            if(nodo->irSiguiente() != nullptr){
                temporal = buscarPorContenidoRecursivo(nodo->irSiguiente(), contenido);
                if(temporal!= nullptr){
                    return temporal;
                }
            }
        }
        return nullptr;
    }


    int height(Nodo<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(height(node->irAnterior()), height(node->irSiguiente()));
    }

    int balanceFactor(Nodo<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->irAnterior()) - height(node->irSiguiente());
    }

    Nodo<T>* rotateRight(Nodo<T>* y) {
        Nodo<T>* x = y->irAnterior();
        Nodo<T>* T2 = x->irSiguiente();

        x->definirSiguiente(y);
        y->definirAnterior(T2);

        return x;
    }

    Nodo<T>* rotateLeft(Nodo<T>* x) {
        Nodo<T>* y = x->irSiguiente();
        Nodo<T>* T2 = y->irAnterior();

        y->definirAnterior(x);
        x->definirSiguiente(T2);

        return y;
    }

    Nodo<T>* balance(Nodo<T>* node, T dato) {
        int bf = balanceFactor(node);

        if (bf > 1 && dato < node->irAnterior()->obtenerDato()) {
            return rotateRight(node);
        }
        if (bf < -1 && dato > node->irSiguiente()->obtenerDato()) {
            return rotateLeft(node);
        }
        if (bf > 1 && dato > node->irAnterior()->obtenerDato()) {
            node->definirAnterior(rotateLeft(node->irAnterior()));
            return rotateRight(node);
        }
        if (bf < -1 && dato < node->irSiguiente()->obtenerDato()) {
            node->definirSiguiente(rotateRight(node->irSiguiente()));
            return rotateLeft(node);
        }

        return node;
    }







public:

    Arbol() {
        root = nullptr;
    }

    void insert(T dato, string infoContacto) {
        root = insertRecursive(root, dato, infoContacto);
    }


    Nodo<T>* find(T dato) {
        //return findRecursive(root, dato);
        return buscarPorContenidoRecursivo(root, dato);
    }

    string obtenerInfoDato(T dato){
        Nodo<T>* obtenido = find(dato);
        if (obtenido != nullptr){
            return obtenido->obtenerInfo();
        } else {
            return "No encontrado";
        }
    }
};

#endif //PRACTICA_2_ARBOL_H
