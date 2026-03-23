#ifndef GESTOR_PAQUETES_H
#define GESTOR_PAQUETES_H

#include "Paquete.h"

class GestorPaquetes {
private:
    struct NodoCola {
        Paquete paquete;
        NodoCola* siguiente;

        NodoCola(const Paquete& nuevoPaquete) : paquete(nuevoPaquete), siguiente(0) {}
    };

    struct NodoPila {
        Paquete paquete;
        NodoPila* siguiente;

        NodoPila(const Paquete& nuevoPaquete) : paquete(nuevoPaquete), siguiente(0) {}
    };

    NodoCola* frente;
    NodoCola* fin;

    NodoPila* cima;

    void limpiarCola();
    void limpiarPila();

public:
    GestorPaquetes();
    ~GestorPaquetes();

    void agregarPendiente(const Paquete& paquete);
    bool procesarPendiente(Paquete& paqueteProcesado);

    void agregarUrgente(const Paquete& paquete);
    bool procesarUrgente(Paquete& paqueteProcesado);

    bool hayPendientes() const;
    bool hayUrgentes() const;

    void mostrarPendientes() const;
    void mostrarUrgentes() const;
};

#endif
