#include "../include/SistemaMensajeria.h"
#include "../include/Ciudad.h"
#include <iostream>
#include <string>

SistemaMensajeria::SistemaMensajeria()
    : puntosControl(0), capacidadPuntos(0), cantidadPuntos(0), indiceActual(0), contadorPaquetes(1) {}

SistemaMensajeria::~SistemaMensajeria() {
    delete[] puntosControl;
}

void SistemaMensajeria::ejecutar() {
    int opcion = -1;

    while (opcion != 0) {
        mostrarMenu();
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida." << std::endl;
            continue;
        }

        switch (opcion) {
            case 1:
                menuRutas();
                break;
            case 2:
                menuPaquetes();
                break;
            case 3:
                menuCamion();
                break;
            case 4:
                menuMatrices();
                break;
            case 5:
                mostrarResumenGeneral();
                break;
            case 0:
                std::cout << "Saliendo del sistema..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    }
}

void SistemaMensajeria::mostrarMenu() const {
    std::cout << "\n===== SISTEMA DE MENSAJERIA =====" << std::endl;
    std::cout << "1. Gestion de rutas" << std::endl;
    std::cout << "2. Gestion de paquetes" << std::endl;
    std::cout << "3. Simulacion camion (cola circular)" << std::endl;
    std::cout << "4. Manejo de matrices" << std::endl;
    std::cout << "5. Resumen general" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

void SistemaMensajeria::menuRutas() {
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n--- Gestion de Rutas ---" << std::endl;
        std::cout << "1. Agregar ciudad al final" << std::endl;
        std::cout << "2. Eliminar ciudad por nombre" << std::endl;
        std::cout << "3. Eliminar ciudad por posicion" << std::endl;
        std::cout << "4. Mostrar ruta" << std::endl;
        std::cout << "0. Volver" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida." << std::endl;
            continue;
        }

        if (opcion == 1) {
            std::string nombre;
            std::cout << "Nombre de la ciudad: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            gestorRutas.obtenerRuta().agregarCiudadFinal(Ciudad(nombre));
            std::cout << "Ciudad agregada." << std::endl;
        } else if (opcion == 2) {
            std::string nombre;
            std::cout << "Nombre de la ciudad a eliminar: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            if (gestorRutas.obtenerRuta().eliminarCiudadPorNombre(nombre)) {
                std::cout << "Ciudad eliminada." << std::endl;
            } else {
                std::cout << "No se encontro la ciudad." << std::endl;
            }
        } else if (opcion == 3) {
            int posicion;
            std::cout << "Posicion a eliminar: ";
            std::cin >> posicion;
            if (gestorRutas.obtenerRuta().eliminarCiudadPorPosicion(posicion)) {
                std::cout << "Ciudad eliminada." << std::endl;
            } else {
                std::cout << "Posicion invalida." << std::endl;
            }
        } else if (opcion == 4) {
            gestorRutas.obtenerRuta().mostrarRuta();
        } else if (opcion != 0) {
            std::cout << "Opcion no valida." << std::endl;
        }
    }
}

void SistemaMensajeria::menuPaquetes() {
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n--- Gestion de Paquetes ---" << std::endl;
        std::cout << "1. Agregar paquete pendiente (cola)" << std::endl;
        std::cout << "2. Procesar paquete pendiente" << std::endl;
        std::cout << "3. Agregar paquete urgente (pila)" << std::endl;
        std::cout << "4. Procesar paquete urgente" << std::endl;
        std::cout << "5. Mostrar paquetes" << std::endl;
        std::cout << "0. Volver" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida." << std::endl;
            continue;
        }

        if (opcion == 1) {
            Paquete paquete = leerPaqueteDesdeConsola();
            gestorPaquetes.agregarPendiente(paquete);
            std::cout << "Paquete pendiente agregado." << std::endl;
        } else if (opcion == 2) {
            Paquete procesado;
            if (gestorPaquetes.procesarPendiente(procesado)) {
                std::cout << "Paquete pendiente procesado y asignado a ruta: ";
                procesado.mostrar();
                std::cout << std::endl;
            } else {
                std::cout << "No hay paquetes pendientes." << std::endl;
            }
        } else if (opcion == 3) {
            Paquete paquete = leerPaqueteDesdeConsola();
            gestorPaquetes.agregarUrgente(paquete);
            std::cout << "Paquete urgente agregado." << std::endl;
        } else if (opcion == 4) {
            Paquete procesado;
            if (gestorPaquetes.procesarUrgente(procesado)) {
                std::cout << "Paquete urgente procesado: ";
                procesado.mostrar();
                std::cout << std::endl;
            } else {
                std::cout << "No hay paquetes urgentes." << std::endl;
            }
        } else if (opcion == 5) {
            gestorPaquetes.mostrarPendientes();
            gestorPaquetes.mostrarUrgentes();
        } else if (opcion != 0) {
            std::cout << "Opcion no valida." << std::endl;
        }
    }
}

void SistemaMensajeria::menuCamion() {
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n--- Simulacion Camion (Cola Circular) ---" << std::endl;
        std::cout << "1. Cargar puntos de control" << std::endl;
        std::cout << "2. Simular avance" << std::endl;
        std::cout << "3. Mostrar posicion actual" << std::endl;
        std::cout << "0. Volver" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida." << std::endl;
            continue;
        }

        if (opcion == 1) {
            cargarPuntosControl();
        } else if (opcion == 2) {
            simularAvanceCamion();
        } else if (opcion == 3) {
            mostrarPosicionCamion();
        } else if (opcion != 0) {
            std::cout << "Opcion no valida." << std::endl;
        }
    }
}

void SistemaMensajeria::menuMatrices() {
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n--- Manejo de Matrices ---" << std::endl;
        std::cout << "1. Configurar matriz 1D (distancias)" << std::endl;
        std::cout << "2. Mostrar matriz 1D" << std::endl;
        std::cout << "3. Configurar matriz 2D (tiempos)" << std::endl;
        std::cout << "4. Mostrar matriz 2D" << std::endl;
        std::cout << "5. Agregar dato en matriz dispersa" << std::endl;
        std::cout << "6. Mostrar matriz dispersa" << std::endl;
        std::cout << "0. Volver" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida." << std::endl;
            continue;
        }

        if (opcion == 1) {
            int tam;
            std::cout << "Tamano de matriz 1D: ";
            std::cin >> tam;
            gestorRutas.configurarDistancias(tam);
            for (int i = 0; i < tam; i++) {
                int valor;
                std::cout << "Distancia [" << i << "]: ";
                std::cin >> valor;
                gestorRutas.setDistancia(i, valor);
            }
        } else if (opcion == 2) {
            gestorRutas.mostrarDistancias();
        } else if (opcion == 3) {
            int filas;
            int columnas;
            std::cout << "Filas: ";
            std::cin >> filas;
            std::cout << "Columnas: ";
            std::cin >> columnas;
            gestorRutas.configurarTiempos(filas, columnas);
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    int valor;
                    std::cout << "Tiempo [" << i << "][" << j << "]: ";
                    std::cin >> valor;
                    gestorRutas.setTiempo(i, j, valor);
                }
            }
        } else if (opcion == 4) {
            gestorRutas.mostrarTiempos();
        } else if (opcion == 5) {
            int fila;
            int columna;
            int valor;
            std::cout << "Fila: ";
            std::cin >> fila;
            std::cout << "Columna: ";
            std::cin >> columna;
            std::cout << "Valor prioridad: ";
            std::cin >> valor;
            gestorRutas.agregarPrioridad(fila, columna, valor);
        } else if (opcion == 6) {
            gestorRutas.mostrarMatrizDispersa();
        } else if (opcion != 0) {
            std::cout << "Opcion no valida." << std::endl;
        }
    }
}

void SistemaMensajeria::cargarPuntosControl() {
    int cantidad;
    std::cout << "Cantidad de puntos de control: ";
    std::cin >> cantidad;

    if (cantidad <= 0) {
        std::cout << "Cantidad invalida." << std::endl;
        return;
    }

    delete[] puntosControl;
    puntosControl = new std::string[cantidad];
    capacidadPuntos = cantidad;
    cantidadPuntos = cantidad;
    indiceActual = 0;

    std::cin.ignore();
    for (int i = 0; i < cantidadPuntos; i++) {
        std::cout << "Punto " << i << ": ";
        std::getline(std::cin, puntosControl[i]);
    }

    std::cout << "Puntos de control cargados." << std::endl;
}

void SistemaMensajeria::simularAvanceCamion() {
    if (puntosControl == 0 || cantidadPuntos == 0) {
        std::cout << "No hay puntos de control cargados." << std::endl;
        return;
    }

    indiceActual = (indiceActual + 1) % cantidadPuntos;
    std::cout << "Camion avanza a: " << puntosControl[indiceActual] << std::endl;
}

void SistemaMensajeria::mostrarPosicionCamion() const {
    if (puntosControl == 0 || cantidadPuntos == 0) {
        std::cout << "No hay puntos de control cargados." << std::endl;
        return;
    }

    std::cout << "Posicion actual del camion: " << puntosControl[indiceActual] << std::endl;
}

Paquete SistemaMensajeria::leerPaqueteDesdeConsola() {
    std::string destino;
    std::string descripcion;

    std::cout << "Destino del paquete: ";
    std::cin.ignore();
    std::getline(std::cin, destino);

    std::cout << "Descripcion del paquete: ";
    std::getline(std::cin, descripcion);

    Paquete paquete(contadorPaquetes, destino, descripcion);
    contadorPaquetes++;
    return paquete;
}

void SistemaMensajeria::mostrarResumenGeneral() const {
    std::cout << "\n===== RESUMEN GENERAL =====" << std::endl;

    std::cout << "\n[1] Ruta:" << std::endl;
    gestorRutas.obtenerRuta().mostrarRuta();

    std::cout << "\n[2] Paquetes:" << std::endl;
    gestorPaquetes.mostrarPendientes();
    gestorPaquetes.mostrarUrgentes();

    std::cout << "\n[3] Camion:" << std::endl;
    mostrarPosicionCamion();

    std::cout << "\n[4] Matrices:" << std::endl;
    gestorRutas.mostrarDistancias();
    gestorRutas.mostrarTiempos();
    gestorRutas.mostrarMatrizDispersa();
}
