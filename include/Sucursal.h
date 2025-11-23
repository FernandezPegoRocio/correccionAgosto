#ifndef SUCURSAL_H
#define SUCURSAL_H

#include <vector>
#include <string>
#include "Vendedor.h"

class Sucursal {
private:
    std::string nombreSucursal;
    std::string direccion;
    std::vector<Vendedor*> vendedores;

public:
    Sucursal(const std::string& nombre, const std::string& direccion);
    ~Sucursal();
    
    void agregarVendedor(Vendedor* vendedor);
    void listarVendedores();
    void enviarNotificacionATodos(const std::string& mensaje);
    std::string obtenerNombre() const { return nombreSucursal; }
};

#endif