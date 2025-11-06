#pragma once

#include "TramaBase.h"

/**
 * @class TramaMap
 * @brief Trama concreta que representa una instrucción de mapeo (ej. "M,5").
 *
 * Hereda de TramaBase e implementa la lógica de rotación
 * del rotor.
 */
class TramaMap : public TramaBase {
private:
    int rotacion; ///< El número de pasos a rotar (ej. 5 o -3).

public:
    /**
     * @brief Constructor de TramaMap.
     * @param r El número de pasos de rotación.
     */
    TramaMap(int r);

    /**
     * @brief Destructor (virtual por herencia).
     */
    virtual ~TramaMap() {}

    /**
     * @brief Implementación de la lógica de mapeo.
     *
     * Llama al método 'rotar' del RotorDeMapeo. No necesita
     * interactuar con la ListaDeCarga.
     *
     * @param carga Puntero a la ListaDeCarga (no se usa, pero es
     * parte de la firma).
     * @param rotor Puntero al RotorDeMapeo actual.
     */
    virtual void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) override;
};