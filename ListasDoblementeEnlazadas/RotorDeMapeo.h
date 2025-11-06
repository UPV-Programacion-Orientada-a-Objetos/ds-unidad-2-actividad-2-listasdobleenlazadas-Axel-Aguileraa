#pragma once

/**
 * @struct NodoRotor
 * @brief Nodo para la lista circular doblemente enlazada del Rotor.
 * Almacena un solo carácter.
 */
struct NodoRotor {
    char caracter;      ///< El carácter (A-Z) almacenado en este nodo.
    NodoRotor* siguiente; ///< Puntero al siguiente nodo en el anillo.
    NodoRotor* previo;    ///< Puntero al nodo anterior en el anillo.

    /**
     * @brief Constructor del NodoRotor.
     * @param c El carácter que almacenará el nodo.
     */
    NodoRotor(char c) : caracter(c), siguiente(this), previo(this) {}
};

/**
 * @class RotorDeMapeo
 * @brief Implementa una lista circular doblemente enlazada para el cifrado.
 *
 * Actúa como un "disco de cifrado" que mantiene el alfabeto (A-Z) y
 * puede rotar para cambiar el mapeo de caracteres.
 */
class RotorDeMapeo {
private:
    NodoRotor* cabeza; ///< Puntero 'cero' actual. Indica el inicio del mapeo.
    int tamano;        ///< Número de nodos en el rotor (debería ser 26).

public:
    /**
     * @brief Constructor. Crea el rotor con el alfabeto A-Z.
     */
    RotorDeMapeo();

    /**
     * @brief Destructor. Libera la memoria de todos los nodos del rotor.
     */
    ~RotorDeMapeo();

    /**
     * @brief Mueve el puntero 'cabeza' N posiciones.
     * @param N El número de pasos a rotar. Positivo para la derecha
     * (siguiente), negativo para la izquierda (previo).
     */
    void rotar(int N);

    /**
     * @brief Calcula el carácter decodificado basado en la rotación actual.
     *
     * Esta es la lógica central. Toma un carácter de entrada (ej. 'W')
     * y calcula su offset desde 'A' (ej. 22). Luego, se posiciona en la
     * 'cabeza' actual (ej. 'C') y avanza ese mismo offset (22 pasos)
     * para encontrar el carácter mapeado (ej. 'Y').
     *
     * @param in El carácter de entrada (ej. 'W').
     * @return El carácter decodificado (ej. 'Y').
     */
    char getMapeo(char in);
};