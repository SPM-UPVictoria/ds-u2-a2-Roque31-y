#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>

class Paquete {
private:
    int id;
    std::string destino;
    std::string descripcion;

public:
    Paquete();
    Paquete(int idPaquete, const std::string& destinoPaquete, const std::string& descripcionPaquete);

    int getId() const;
    std::string getDestino() const;
    std::string getDescripcion() const;

    void mostrar() const;
};

#endif
