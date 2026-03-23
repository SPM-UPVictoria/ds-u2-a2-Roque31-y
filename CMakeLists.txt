cmake_minimum_required(VERSION 3.10)
project(ProyectoMensajeria)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(ProyectoMensajeria
    src/main.cpp
    src/Ciudad.cpp
    src/Ruta.cpp
    src/Paquete.cpp
    src/GestorRutas.cpp
    src/GestorPaquetes.cpp
    src/SistemaMensajeria.cpp
)
