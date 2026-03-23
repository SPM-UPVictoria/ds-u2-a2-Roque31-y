#include "../include/GestorRutas.h"
#include <iostream>

GestorRutas::GestorRutas()
    : distancias(0), tamDistancias(0), tiempos(0), filasTiempos(0), columnasTiempos(0), matrizDispersa(0) {}

GestorRutas::~GestorRutas() {
    delete[] distancias;
    limpiarMatriz2D();
    limpiarMatrizDispersa();
}

Ruta& GestorRutas::obtenerRuta() {
    return ruta;
}

const Ruta& GestorRutas::obtenerRuta() const {
    return ruta;
}

void GestorRutas::configurarDistancias(int tam) {
    if (tam <= 0) {
        std::cout << "Tamano invalido para matriz 1D." << std::endl;
        return;
    }

    delete[] distancias;
    distancias = new int[tam];
    tamDistancias = tam;

    for (int i = 0; i < tamDistancias; i++) {
        distancias[i] = 0;
    }
}

bool GestorRutas::setDistancia(int indice, int valor) {
    if (indice < 0 || indice >= tamDistancias || distancias == 0) {
        return false;
    }

    distancias[indice] = valor;
    return true;
}

void GestorRutas::mostrarDistancias() const {
    if (distancias == 0) {
        std::cout << "Matriz 1D no configurada." << std::endl;
        return;
    }

    std::cout << "Distancias (Matriz 1D):" << std::endl;
    for (int i = 0; i < tamDistancias; i++) {
        std::cout << "  [" << i << "] = " << distancias[i] << std::endl;
    }
}

void GestorRutas::configurarTiempos(int filas, int columnas) {
    if (filas <= 0 || columnas <= 0) {
        std::cout << "Dimensiones invalidas para matriz 2D." << std::endl;
        return;
    }

    limpiarMatriz2D();

    filasTiempos = filas;
    columnasTiempos = columnas;

    tiempos = new int*[filasTiempos];
    for (int i = 0; i < filasTiempos; i++) {
        tiempos[i] = new int[columnasTiempos];
        for (int j = 0; j < columnasTiempos; j++) {
            tiempos[i][j] = 0;
        }
    }
}

bool GestorRutas::setTiempo(int fila, int columna, int valor) {
    if (tiempos == 0 || fila < 0 || fila >= filasTiempos || columna < 0 || columna >= columnasTiempos) {
        return false;
    }

    tiempos[fila][columna] = valor;
    return true;
}

void GestorRutas::mostrarTiempos() const {
    if (tiempos == 0) {
        std::cout << "Matriz 2D no configurada." << std::endl;
        return;
    }

    std::cout << "Tiempos aproximados (Matriz 2D):" << std::endl;
    for (int i = 0; i < filasTiempos; i++) {
        for (int j = 0; j < columnasTiempos; j++) {
            std::cout << tiempos[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void GestorRutas::agregarPrioridad(int fila, int columna, int valor) {
    NodoDisperso* actual = matrizDispersa;
    while (actual != 0) {
        if (actual->fila == fila && actual->columna == columna) {
            actual->valor = valor;
            return;
        }
        actual = actual->siguiente;
    }

    NodoDisperso* nuevo = new NodoDisperso(fila, columna, valor);
    nuevo->siguiente = matrizDispersa;
    matrizDispersa = nuevo;
}

void GestorRutas::mostrarMatrizDispersa() const {
    if (matrizDispersa == 0) {
        std::cout << "Matriz dispersa vacia." << std::endl;
        return;
    }

    std::cout << "Rutas prioritarias (Matriz dispersa):" << std::endl;

    NodoDisperso* actual = matrizDispersa;
    while (actual != 0) {
        std::cout << "  (" << actual->fila << ", " << actual->columna << ") = " << actual->valor << std::endl;
        actual = actual->siguiente;
    }
}

void GestorRutas::limpiarMatriz2D() {
    if (tiempos != 0) {
        for (int i = 0; i < filasTiempos; i++) {
            delete[] tiempos[i];
        }
        delete[] tiempos;
    }

    tiempos = 0;
    filasTiempos = 0;
    columnasTiempos = 0;
}

void GestorRutas::limpiarMatrizDispersa() {
    NodoDisperso* actual = matrizDispersa;

    while (actual != 0) {
        NodoDisperso* temporal = actual;
        actual = actual->siguiente;
        delete temporal;
    }

    matrizDispersa = 0;
}
