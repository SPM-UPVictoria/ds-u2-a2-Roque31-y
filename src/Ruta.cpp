#include "../include/Ruta.h"
#include <iostream>

Ruta::Ruta() : cabeza(0) {}

Ruta::~Ruta() {
    limpiar();
}

void Ruta::agregarCiudadFinal(const Ciudad& ciudad) {
    NodoCiudad* nuevo = new NodoCiudad(ciudad);

    if (cabeza == 0) {
        cabeza = nuevo;
        return;
    }

    NodoCiudad* actual = cabeza;
    while (actual->siguiente != 0) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
}

bool Ruta::eliminarCiudadPorNombre(const std::string& nombreCiudad) {
    if (cabeza == 0) {
        return false;
    }

    if (cabeza->ciudad.getNombre() == nombreCiudad) {
        NodoCiudad* temporal = cabeza;
        cabeza = cabeza->siguiente;
        delete temporal;
        return true;
    }

    NodoCiudad* actual = cabeza;
    while (actual->siguiente != 0 && actual->siguiente->ciudad.getNombre() != nombreCiudad) {
        actual = actual->siguiente;
    }

    if (actual->siguiente == 0) {
        return false;
    }

    NodoCiudad* temporal = actual->siguiente;
    actual->siguiente = temporal->siguiente;
    delete temporal;
    return true;
}

bool Ruta::eliminarCiudadPorPosicion(int posicion) {
    if (posicion < 0 || cabeza == 0) {
        return false;
    }

    if (posicion == 0) {
        NodoCiudad* temporal = cabeza;
        cabeza = cabeza->siguiente;
        delete temporal;
        return true;
    }

    NodoCiudad* actual = cabeza;
    int indice = 0;

    while (actual->siguiente != 0 && indice < posicion - 1) {
        actual = actual->siguiente;
        indice++;
    }

    if (actual->siguiente == 0) {
        return false;
    }

    NodoCiudad* temporal = actual->siguiente;
    actual->siguiente = temporal->siguiente;
    delete temporal;
    return true;
}

void Ruta::mostrarRuta() const {
    if (cabeza == 0) {
        std::cout << "Ruta vacia." << std::endl;
        return;
    }

    NodoCiudad* actual = cabeza;
    int indice = 0;

    std::cout << "Ruta actual:" << std::endl;
    while (actual != 0) {
        std::cout << "  [" << indice << "] " << actual->ciudad.getNombre() << std::endl;
        actual = actual->siguiente;
        indice++;
    }
}

bool Ruta::estaVacia() const {
    return cabeza == 0;
}

int Ruta::obtenerCantidadCiudades() const {
    int cantidad = 0;
    NodoCiudad* actual = cabeza;

    while (actual != 0) {
        cantidad++;
        actual = actual->siguiente;
    }

    return cantidad;
}

void Ruta::limpiar() {
    NodoCiudad* actual = cabeza;

    while (actual != 0) {
        NodoCiudad* temporal = actual;
        actual = actual->siguiente;
        delete temporal;
    }

    cabeza = 0;
}
