#include "Parseador.h"
#include "TramaLoad.h"  // Necesario para 'new TramaLoad'
#include "TramaMap.h"   // Necesario para 'new TramaMap'

// Librerías de C para parseo
#include <cstring>  // Para strtok (manejo de strings) y strcmp (comparar strings)
#include <cstdlib>  // Para atoi (convertir string a entero)
#include <iostream> // Para imprimir errores

namespace Parseador {

    TramaBase* parsearTrama(char* lineaCruda) {
        
        // strtok necesita un delimitador. En PRT-7, es la coma.
        const char* delimitador = ",";

        // 1. Obtener el primer token (el tipo de trama: 'L' o 'M')
        //    strtok recibe la cadena en la primera llamada.
        char* tokenTipo = strtok(lineaCruda, delimitador);

        if (tokenTipo == nullptr) {
            std::cerr << "Error: Trama vacía o mal formada." << std::endl;
            return nullptr;
        }

        // 2. Obtener el segundo token (el valor)
        //    strtok recibe NULL en llamadas subsecuentes para
        //    continuar en la misma cadena.
        char* tokenValor = strtok(NULL, delimitador);

        if (tokenValor == nullptr) {
            std::cerr << "Error: Trama incompleta, falta valor después de '" 
                      << tokenTipo << "'" << std::endl;
            return nullptr;
        }

        // 3. Decidir qué tipo de trama instanciar
        
        // Usamos strcmp (string compare) de <cstring>
        // Devuelve 0 si son idénticos.
        if (strcmp(tokenTipo, "L") == 0) {
            // Es una TramaLoad.
            // El valor (tokenValor) es un string de un solo char, ej. "A".
            // Solo nos interesa el primer carácter.
            if (strlen(tokenValor) > 0) {
                // Capturamos el carácter 'A' de la cadena "A"
                char dato = tokenValor[0]; 
                
                // Manejo especial para el espacio
                if (strcmp(tokenValor, "Space") == 0) {
                    dato = ' ';
                }

                return new TramaLoad(dato);
            }
        } 
        else if (strcmp(tokenTipo, "M") == 0) {
            // Es una TramaMap.
            // El valor (tokenValor) es un string de número, ej. "5" o "-3".
            // Usamos atoi (ASCII to Integer) de <cstdlib>
            int rotacion = atoi(tokenValor);
            return new TramaMap(rotacion);
        }

        // Si llega aquí, el tipo de trama no es 'L' ni 'M'
        std::cerr << "Error: Tipo de trama desconocido '" << tokenTipo << "'" << std::endl;
        return nullptr;
    }

} // namespace Parseador