#pragma once

#include "TramaBase.h" // Necesitamos saber qué es TramaBase*

/**
 * @namespace Parseador
 * @brief Contiene funciones de utilidad estáticas para parsear
 * cadenas del protocolo PRT-7.
 *
 * No se puede instanciar, solo se usan sus métodos estáticos.
 */
namespace Parseador {

    /**
     * @brief Parsea una línea de texto cruda y la convierte en un objeto Trama.
     *
     * Toma una cadena (ej. "M,-3") y usa lógica de parseo C-style
     * (strtok, atoi) para instanciar el objeto Trama derivado correcto
     * (ej. new TramaMap(-3)).
     *
     * @param lineaCruda Un puntero a un buffer de char (C-string) que
     * contiene la línea leída del serial.
     * IMPORTANTE: Esta función MODIFICA la cadena (efecto
     * de strtok).
     * @return Un puntero TramaBase* al nuevo objeto instanciado.
     * El llamador es responsable de hacer 'delete' a este puntero.
     * Retorna nullptr si la trama está mal formada.
     */
    TramaBase* parsearTrama(char* lineaCruda);

} // namespace Parseador