# Versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Decodificador_PRT7 VERSION 1.0)

# Configurar el estándar de C++ (ej. C++11 o C++14)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añadir el ejecutable
# El ejecutable se llamará "Decodificador"
# y se construirá a partir de estos archivos fuente:
add_executable(Decodificador
    main.cpp
    RotorDeMapeo.cpp
    ListaDeCarga.cpp
    TramaLoad.cpp
    TramaMap.cpp
    Parseador.cpp
)

# Incluir Doxygen (si está instalado)
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # Ruta al archivo de configuración de Doxygen (Doxyfile)
    set(DOXYGEN_IN Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxygen)

    # Añadir un target "doc" para generar la documentación
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generando documentación con Doxygen..."
    )
    
    # Imprimir un mensaje
    message(STATUS "Doxygen encontrado. Ejecute 'make doc' o 'ninja doc' para generar la documentación.")
else()
    message(WARNING "Doxygen no se encontró. No se creará el target 'doc'.")
endif()

# Mensaje de finalización
message(STATUS "Proyecto configurado. Ejecute 'make' o 'ninja' para compilar el decodificador.")