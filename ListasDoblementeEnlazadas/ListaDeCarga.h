#pragma once

/**
 * @struct NodoCarga
 * @brief Nodo para la lista doblemente enlazada del Mensaje.
 * Almacena el carácter ya decodificado.
 */
struct NodoCarga {
    char dato;            ///< El carácter decodificado.
    NodoCarga* siguiente; ///< Puntero al siguiente nodo.
    NodoCarga* previo;    ///< Puntero al nodo anterior.

    /**
     * @brief Constructor del NodoCarga.
     * @param d El carácter que almacenará el nodo.
     */
    NodoCarga(char d) : dato(d), siguiente(nullptr), previo(nullptr) {}
};

/**
 * @class ListaDeCarga
 * @brief Implementa una lista doblemente enlazada para el mensaje decodificado.
 *
 * Almacena los caracteres en el orden en que fueron procesados y
 * decodificados por el sistema.
 */
class ListaDeCarga {
private:
    NodoCarga* cabeza; ///< Puntero al inicio del mensaje.
    NodoCarga* cola;   ///< Puntero al final del mensaje (para inserción O(1)).
    int tamano;        ///< Número de caracteres en el mensaje.

public:
    /**
     * @brief Constructor. Crea una lista vacía.
     */
    ListaDeCarga();

    /**
     * @brief Destructor. Libera la memoria de todos los nodos de la lista.
     */
    ~ListaDeCarga();

    /**
     * @brief Inserta un carácter al final del mensaje.
     * @param dato El carácter decodificado a insertar.
     */
    void insertarAlFinal(char dato);

    /**
     * @brief Imprime el mensaje parcial (para el log)
     * Salida: [H][O][L]
     */
    void imprimirMensajeParcial();
    
    /**
     * @brief Imprime el mensaje final (limpio)
     * Salida: HOL
     */
    void imprimirMensajeFinal();
};