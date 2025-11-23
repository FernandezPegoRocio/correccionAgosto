#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Empleado.h"
#include <string>

class Vendedor : public Empleado {
protected:
    std::string categoria;
    int numeroVentas;

public:
    Vendedor(const std::string& nombre, const std::string& apellido, int documento,
             double salario, const std::string& area, const std::string& categoria);
    
    virtual ~Vendedor();
    
    void recibirNotificacion(const std::string& mensaje);
    virtual void mostrarInformacion();
    std::string obtenerCategoria() const { return categoria; }
};

#endif