#include "TramaLoad.h"
#include "ListaDeCarga.h" // Incluimos los headers completos aquí
#include "RotorDeMapeo.h"  // porque necesitamos llamar a sus métodos.
#include <iostream>        // Para la salida de consola

TramaLoad::TramaLoad(char d) : dato(d) {
    // Constructor inicializa el dato
}

void TramaLoad::procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) {
    // 1. Pregunta al rotor por el carácter mapeado
    char decodificado = rotor->getMapeo(this->dato);

    // 2. Inserta el resultado en la lista de carga
    carga->insertarAlFinal(decodificado);

    // 3. Informar en consola (como en el ejemplo)
    std::cout << " -> Fragmento '" << this->dato 
              << "' decodificado como '" << decodificado << "'.";
}