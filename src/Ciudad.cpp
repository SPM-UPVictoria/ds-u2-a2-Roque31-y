#include "../include/Ciudad.h"

Ciudad::Ciudad() : nombre("") {}

Ciudad::Ciudad(const std::string& nombreCiudad) : nombre(nombreCiudad) {}

void Ciudad::setNombre(const std::string& nombreCiudad) {
    nombre = nombreCiudad;
}

std::string Ciudad::getNombre() const {
    return nombre;
}
