#ifndef RUTA_H
#define RUTA_H

#include "Ciudad.h"

class Ruta {
private:
    struct NodoCiudad {
        Ciudad ciudad;
        NodoCiudad* siguiente;

        NodoCiudad(const Ciudad& ciudadNueva) : ciudad(ciudadNueva), siguiente(0) {}
    };

    NodoCiudad* cabeza;

public:
    Ruta();
    ~Ruta();

    void agregarCiudadFinal(const Ciudad& ciudad);
    bool eliminarCiudadPorNombre(const std::string& nombreCiudad);
    bool eliminarCiudadPorPosicion(int posicion);
    void mostrarRuta() const;
    bool estaVacia() const;
    int obtenerCantidadCiudades() const;
    void limpiar();
};

#endif
