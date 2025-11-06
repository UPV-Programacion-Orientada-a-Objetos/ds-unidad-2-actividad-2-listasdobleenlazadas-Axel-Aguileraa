#include "ListaDeCarga.h"
#include <iostream> // Necesario solo para imprimirMensaje

ListaDeCarga::ListaDeCarga() : cabeza(nullptr), cola(nullptr), tamano(0) {
    // La lista inicia vacía
}

ListaDeCarga::~ListaDeCarga() {
    NodoCarga* actual = cabeza;
    while (actual != nullptr) {
        NodoCarga* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    cabeza = nullptr;
    cola = nullptr;
    tamano = 0;
}

void ListaDeCarga::insertarAlFinal(char dato) {
    NodoCarga* nuevoNodo = new NodoCarga(dato);
    tamano++;

    if (cabeza == nullptr) {
        // Si la lista está vacía, cabeza y cola son el mismo nodo
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        // 1. El 'siguiente' de la cola actual es el nuevo nodo
        cola->siguiente = nuevoNodo;
        // 2. El 'previo' del nuevo nodo es la cola actual
        nuevoNodo->previo = cola;
        // 3. Movemos el puntero 'cola' al nuevo nodo
        cola = nuevoNodo;
    }
}

void ListaDeCarga::imprimirMensajeParcial() {
    NodoCarga* actual = cabeza;
    while (actual != nullptr) {
        std::cout << "[" << actual->dato << "]";
        actual = actual->siguiente;
    }
    // Sin salto de línea
}

void ListaDeCarga::imprimirMensajeFinal() {
    NodoCarga* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato;
        actual = actual->siguiente;
    }
    std::cout << std::endl; // Salto de línea al final
}