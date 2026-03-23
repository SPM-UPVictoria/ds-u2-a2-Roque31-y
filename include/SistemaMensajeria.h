#ifndef SISTEMA_MENSAJERIA_H
#define SISTEMA_MENSAJERIA_H

#include "GestorRutas.h"
#include "GestorPaquetes.h"

class SistemaMensajeria {
private:
    GestorRutas gestorRutas;
    GestorPaquetes gestorPaquetes;

    std::string* puntosControl;
    int capacidadPuntos;
    int cantidadPuntos;
    int indiceActual;

    int contadorPaquetes;

    void mostrarMenu() const;

    void menuRutas();
    void menuPaquetes();
    void menuCamion();
    void menuMatrices();

    void cargarPuntosControl();
    void simularAvanceCamion();
    void mostrarPosicionCamion() const;

    Paquete leerPaqueteDesdeConsola();

public:
    SistemaMensajeria();
    ~SistemaMensajeria();

    void ejecutar();
    void mostrarResumenGeneral() const;
};

#endif
