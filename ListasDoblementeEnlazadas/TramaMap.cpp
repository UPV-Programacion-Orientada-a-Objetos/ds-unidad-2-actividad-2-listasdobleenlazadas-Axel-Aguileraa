#include "TramaMap.h"
#include "RotorDeMapeo.h" // Solo necesitamos el rotor
#include <iostream>       // Para la salida de consola

TramaMap::TramaMap(int r) : rotacion(r) {
    // Constructor inicializa la rotación
}

void TramaMap::procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) {
    // 1. Llama al método rotar del rotor con el valor almacenado
    rotor->rotar(this->rotacion);

    // 2. Informar en consola (como en el ejemplo)
    std::cout << " -> ROTANDO ROTOR ";
    if (this->rotacion > 0) {
        std::cout << "+";
    }
    std::cout << this->rotacion << ".";
    
    // 3. ¡Lógica añadida para cumplir el requisito de salida!
    std::cout << " (Ahora 'A' se mapea a '" << rotor->getMapeo('A') << "')";
}