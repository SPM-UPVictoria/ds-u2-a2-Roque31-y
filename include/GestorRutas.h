#ifndef GESTOR_RUTAS_H
#define GESTOR_RUTAS_H

#include "Ruta.h"

class GestorRutas {
private:
    Ruta ruta;

    int* distancias;
    int tamDistancias;

    int** tiempos;
    int filasTiempos;
    int columnasTiempos;

    struct NodoDisperso {
        int fila;
        int columna;
        int valor;
        NodoDisperso* siguiente;

        NodoDisperso(int f, int c, int v) : fila(f), columna(c), valor(v), siguiente(0) {}
    };

    NodoDisperso* matrizDispersa;

    void limpiarMatriz2D();
    void limpiarMatrizDispersa();

public:
    GestorRutas();
    ~GestorRutas();

    Ruta& obtenerRuta();
    const Ruta& obtenerRuta() const;

    void configurarDistancias(int tam);
    bool setDistancia(int indice, int valor);
    void mostrarDistancias() const;

    void configurarTiempos(int filas, int columnas);
    bool setTiempo(int fila, int columna, int valor);
    void mostrarTiempos() const;

    void agregarPrioridad(int fila, int columna, int valor);
    void mostrarMatrizDispersa() const;
};

#endif
