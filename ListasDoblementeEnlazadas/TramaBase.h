#pragma once

// --- Declaraciones Adelantadas (Forward Declarations) ---
// En lugar de incluir los headers completos, le decimos al compilador
// que estas clases existen. Esto evita dependencias circulares y
// acelera la compilación.
class ListaDeCarga;
class RotorDeMapeo;

/**
 * @class TramaBase
 * @brief Clase base abstracta para todas las tramas del protocolo PRT-7.
 *
 * Define la interfaz común 'procesar' que deben implementar
 * todas las tramas concretas.
 */
class TramaBase {
public:
    /**
     * @brief Destructor virtual.
     *
     * OBLIGATORIO para la limpieza de memoria polimórfica.
     * Asegura que se llame al destructor de la clase derivada
     * correcta (ej. ~TramaLoad) cuando se hace 'delete'
     * sobre un puntero TramaBase*.
     */
    virtual ~TramaBase() {}

    /**
     * @brief Método virtual puro para procesar la trama.
     *
     * Las clases derivadas implementarán la lógica específica
     * (añadir a la lista o rotar el rotor).
     *
     * @param carga Puntero a la ListaDeCarga del mensaje.
     * @param rotor Puntero al RotorDeMapeo actual.
     */
    virtual void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) = 0;
};