#include "RotorDeMapeo.h"

// El constructor es responsable de construir el anillo A-Z
RotorDeMapeo::RotorDeMapeo() : cabeza(nullptr), tamano(0) {
    NodoRotor* ultimo = nullptr;

    for (char c = 'A'; c <= 'Z'; ++c) {
        NodoRotor* nuevoNodo = new NodoRotor(c);
        tamano++;

        if (cabeza == nullptr) {
            // Si es el primer nodo ('A'), se convierte en la cabeza
            cabeza = nuevoNodo;
            ultimo = nuevoNodo;
        } else {
            // Enlaza el nodo anterior con el nuevo
            ultimo->siguiente = nuevoNodo;
            nuevoNodo->previo = ultimo;
            // Actualiza el puntero 'ultimo'
            ultimo = nuevoNodo;
        }
    }

    // Al final, cerramos el círculo enlazando el último ('Z') con el primero ('A')
    if (cabeza != nullptr && ultimo != nullptr) {
        ultimo->siguiente = cabeza;
        cabeza->previo = ultimo;
    }
}

// El destructor debe romper el círculo antes de borrar para evitar un bucle infinito
RotorDeMapeo::~RotorDeMapeo() {
    if (cabeza == nullptr) {
        return;
    }

    NodoRotor* actual = cabeza;
    NodoRotor* ultimo = cabeza->previo;

    // 1. Rompemos el enlace circular
    ultimo->siguiente = nullptr; 

    // 2. Ahora podemos iterar y borrar como una lista normal
    while (actual != nullptr) {
        NodoRotor* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }

    cabeza = nullptr;
    tamano = 0;
}

void RotorDeMapeo::rotar(int N) {
    if (cabeza == nullptr) {
        return;
    }

    if (N > 0) {
        // Rotación positiva (hacia adelante)
        for (int i = 0; i < N; ++i) {
            cabeza = cabeza->siguiente;
        }
    } else {
        // Rotación negativa (hacia atrás)
        int pasos = -N; // Convertimos N a positivo
        for (int i = 0; i < pasos; ++i) {
            cabeza = cabeza->previo;
        }
    }
}

char RotorDeMapeo::getMapeo(char in) {
    // Si no es una letra mayúscula (ej. ' ' o un número),
    // devolvemos el carácter tal cual, sin mapeo.
    if (in < 'A' || in > 'Z') {
        return in;
    }

    // 1. Calcular el offset de la letra de entrada desde 'A'.
    //    Ej. 'A' -> 0, 'B' -> 1, ..., 'W' -> 22
    int offset = in - 'A';

    // 2. Empezar en la 'cabeza' actual (la posición 'cero')
    NodoRotor* nodoMapeado = cabeza;

    // 3. Avanzar el mismo número de pasos (offset) desde la 'cabeza'
    for (int i = 0; i < offset; ++i) {
        nodoMapeado = nodoMapeado->siguiente;
    }

    // 4. Devolver el carácter en esa posición final
    return nodoMapeado->caracter;
}