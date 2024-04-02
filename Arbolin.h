#ifndef PRACTICA_2_ARBOLIN_H
#define PRACTICA_2_ARBOLIN_H

#include "Nodo.h"

template <typename T>
class Arbolin {

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

    Nodo<T>* findRecursive(Nodo<T>* node, int dato) {
        if (node == nullptr || node->obtenerDato() == dato) {
            return node;
        }

        if (dato < node->obtenerDato()) {
            return findRecursive(node->irAnterior(), dato);
        } else {
            return findRecursive(node->irSiguiente(), dato);
        }
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

    string obtenerInfoDato(T dato){
        Nodo<T> obtenido = find(dato);
        if (obtenido != nullptr){
            return obtenido.obtenerInfo();
        } else {
            return "No encontrado";
        }
    }





public:
    void insert(T dato, string infoContacto) /*{
        root = insertRecursive(root, dato, infoContacto);
    }*/;
    Arbolin() {
        root = nullptr;
    }

    Nodo<T>* find(T dato) {
        return findRecursive(root, dato);
    }
};

template <typename T>
void Arbolin<T>::insert(T dato, string infoContacto) {
    root = insertRecursive(root, dato, infoContacto);
}
#endif //PRACTICA_2_ARBOLIN_H
