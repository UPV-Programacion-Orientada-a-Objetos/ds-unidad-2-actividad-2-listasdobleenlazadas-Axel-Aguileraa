#pragma once

#include "TramaBase.h"
// No necesitamos incluir ListaDeCarga.h o RotorDeMapeo.h aquí,
// TramaBase.h ya los declaró (forward) y solo los usamos en el .cpp

/**
 * @class TramaLoad
 * @brief Trama concreta que representa una carga de datos (ej. "L,A").
 *
 * Hereda de TramaBase e implementa la lógica de decodificación
 * y almacenamiento.
 */
class TramaLoad : public TramaBase {
private:
    char dato; ///< El carácter original recibido (ej. 'A').

public:
    /**
     * @brief Constructor de TramaLoad.
     * @param d El carácter leído de la trama.
     */
    TramaLoad(char d);

    /**
     * @brief Destructor (virtual por herencia).
     */
    virtual ~TramaLoad() {}

    /**
     * @brief Implementación de la lógica de carga.
     *
     * Obtiene el mapeo del rotor para 'dato' y lo inserta
     * en la ListaDeCarga.
     *
     * @param carga Puntero a la ListaDeCarga del mensaje.
     * @param rotor Puntero al RotorDeMapeo actual.
     */
    virtual void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) override;
};