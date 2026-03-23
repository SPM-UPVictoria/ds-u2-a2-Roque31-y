#include "../include/GestorPaquetes.h"
#include <iostream>

GestorPaquetes::GestorPaquetes() : frente(0), fin(0), cima(0) {}

GestorPaquetes::~GestorPaquetes() {
    limpiarCola();
    limpiarPila();
}

void GestorPaquetes::agregarPendiente(const Paquete& paquete) {
    NodoCola* nuevo = new NodoCola(paquete);

    if (fin == 0) {
        frente = nuevo;
        fin = nuevo;
        return;
    }

    fin->siguiente = nuevo;
    fin = nuevo;
}

bool GestorPaquetes::procesarPendiente(Paquete& paqueteProcesado) {
    if (frente == 0) {
        return false;
    }

    NodoCola* temporal = frente;
    paqueteProcesado = temporal->paquete;

    frente = frente->siguiente;
    if (frente == 0) {
        fin = 0;
    }

    delete temporal;
    return true;
}

void GestorPaquetes::agregarUrgente(const Paquete& paquete) {
    NodoPila* nuevo = new NodoPila(paquete);
    nuevo->siguiente = cima;
    cima = nuevo;
}

bool GestorPaquetes::procesarUrgente(Paquete& paqueteProcesado) {
    if (cima == 0) {
        return false;
    }

    NodoPila* temporal = cima;
    paqueteProcesado = temporal->paquete;

    cima = cima->siguiente;
    delete temporal;
    return true;
}

bool GestorPaquetes::hayPendientes() const {
    return frente != 0;
}

bool GestorPaquetes::hayUrgentes() const {
    return cima != 0;
}

void GestorPaquetes::mostrarPendientes() const {
    if (frente == 0) {
        std::cout << "No hay paquetes pendientes." << std::endl;
        return;
    }

    std::cout << "Paquetes pendientes (cola):" << std::endl;
    NodoCola* actual = frente;
    while (actual != 0) {
        std::cout << "  - ";
        actual->paquete.mostrar();
        std::cout << std::endl;
        actual = actual->siguiente;
    }
}

void GestorPaquetes::mostrarUrgentes() const {
    if (cima == 0) {
        std::cout << "No hay paquetes urgentes." << std::endl;
        return;
    }

    std::cout << "Paquetes urgentes (pila):" << std::endl;
    NodoPila* actual = cima;
    while (actual != 0) {
        std::cout << "  - ";
        actual->paquete.mostrar();
        std::cout << std::endl;
        actual = actual->siguiente;
    }
}

void GestorPaquetes::limpiarCola() {
    while (frente != 0) {
        NodoCola* temporal = frente;
        frente = frente->siguiente;
        delete temporal;
    }

    fin = 0;
}

void GestorPaquetes::limpiarPila() {
    while (cima != 0) {
        NodoPila* temporal = cima;
        cima = cima->siguiente;
        delete temporal;
    }
}
