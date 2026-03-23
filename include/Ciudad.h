#ifndef CIUDAD_H
#define CIUDAD_H

#include <string>

class Ciudad {
private:
    std::string nombre;

public:
    Ciudad();
    Ciudad(const std::string& nombreCiudad);

    void setNombre(const std::string& nombreCiudad);
    std::string getNombre() const;
};

#endif
