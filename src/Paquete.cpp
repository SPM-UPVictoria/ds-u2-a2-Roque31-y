#include "../include/Paquete.h"
#include <iostream>

Paquete::Paquete() : id(0), destino(""), descripcion("") {}

Paquete::Paquete(int idPaquete, const std::string& destinoPaquete, const std::string& descripcionPaquete)
    : id(idPaquete), destino(destinoPaquete), descripcion(descripcionPaquete) {}

int Paquete::getId() const {
    return id;
}

std::string Paquete::getDestino() const {
    return destino;
}

std::string Paquete::getDescripcion() const {
    return descripcion;
}

void Paquete::mostrar() const {
    std::cout << "ID: " << id << ", Destino: " << destino << ", Descripcion: " << descripcion;
}
