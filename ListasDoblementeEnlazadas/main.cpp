#include <iostream>
#include <cstring> // Para strcpy y strlen (manejo C-style)

// Nuestras clases de Estructuras de Datos
#include "ListaDeCarga.h"
#include "RotorDeMapeo.h"

// Nuestras clases de POO y Parseo
#include "TramaBase.h"
#include "TramaLoad.h" // Necesario para dynamic_cast
#include "TramaMap.h"  // Necesario para dynamic_cast
#include "Parseador.h"

/**
 * @brief Simulación de datos del Arduino.
 * Estas son las líneas que el Arduino enviaría por el puerto serial.
 */
const char* datosSimulados[] = {
    "L,H",
    "L,O",
    "L,L",
    "M,2",
    "L,A",
    "L,Space",
    "L,W",
    "M,-2",
    "L,O",
    "L,R",
    "L,L",
    "L,D"
};
const int numTramas = 12;

/**
 * @brief Función principal del Decodificador PRT-7
 */
int main() {
    std::cout << "Iniciando Decodificador PRT-7. Conectando a puerto COM..." << std::endl;
    // (Aquí iría la lógica real de conexión serial)
    std::cout << "Conexión establecida. Esperando tramas..." << std::endl << std::endl;

    // 1. Inicialización de las estructuras de datos
    ListaDeCarga miListaDeCarga;
    RotorDeMapeo miRotorDeMapeo;

    // 2. Bucle de Procesamiento (simulado)
    for (int i = 0; i < numTramas; ++i) {
        
        // --- Simulación de Lectura Serial ---
        const char* lineaOriginal = datosSimulados[i];

        // IMPORTANTE: strtok MODIFICA la cadena que parsea.
        // No podemos pasarle 'lineaOriginal' (que es const).
        // Debemos copiarla a un buffer temporal modificable.
        char buffer[64]; // Buffer de 64 chars, más que suficiente
        strncpy(buffer, lineaOriginal, 63);
        buffer[63] = '\0'; // Asegurar nul-termination

        // --- Inicio de Procesamiento ---
        std::cout << "Trama recibida: [" << lineaOriginal << "] -> Procesando...";

        // 3. Parsear
        //    Pasamos el buffer modificable a la función de parseo
        TramaBase* trama = Parseador::parsearTrama(buffer);

        if (trama != nullptr) {
            // 4. Ejecutar (Polimorfismo en acción)
            //    No sabemos si es TramaLoad o TramaMap, solo llamamos procesar
            trama->procesar(&miListaDeCarga, &miRotorDeMapeo);

            // 5. Lógica de Log (para igualar la salida del ejemplo)
            //    Usamos dynamic_cast para ver si la trama FUE de tipo TramaLoad,
            //    y así decidir si imprimimos el estado del mensaje.
            if (dynamic_cast<TramaLoad*>(trama) != nullptr) {
                std::cout << " Mensaje: ";
                miListaDeCarga.imprimirMensajeParcial();
            }
            
            std::cout << std::endl; // Termina la línea de log

            // 6. Limpiar Memoria
            delete trama;
            trama = nullptr;
        
        } else {
            // Error en el parseo
            std::cout << " -> TRAMA IGNORADA (mal formada)." << std::endl;
        }

        // Simular el delay del Arduino
        // En una app real, la lectura del serial bloquearía
        // en lugar de un bucle for.
    }

    // 3. Resultado Final
    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << "Flujo de datos terminado." << std::endl;
    std::cout << "MENSAJE OCULTO ENSAMBLADO:" << std::endl;
    
    miListaDeCarga.imprimirMensajeFinal();
    
    std::cout << "---" << std::endl;
    std::cout << "Liberando memoria... Sistema apagado." << std::endl;

    // La memoria de miListaDeCarga y miRotorDeMapeo
    // se libera automáticamente aquí cuando sus destructores son llamados.

    return 0;
}