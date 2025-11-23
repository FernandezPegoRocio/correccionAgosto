#include "Sucursal.h"
#include <iostream>

Sucursal::Sucursal(const std::string& nombre, const std::string& direccion)
    : nombreSucursal(nombre), direccion(direccion) {
}

Sucursal::~Sucursal() {
   
}

void Sucursal::agregarVendedor(Vendedor* vendedor) {
    vendedores.push_back(vendedor);
    std::cout << "Vendedor " << vendedor->obtenerNombreCompleto() 
              << " agregado a la sucursal " << nombreSucursal << std::endl;
}

void Sucursal::listarVendedores() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "LISTADO DE VENDEDORES - SUCURSAL: " << nombreSucursal << std::endl;
    std::cout << "Direccion: " << direccion << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (vendedores.empty()) {
        std::cout << "No hay vendedores en esta sucursal." << std::endl;
    } else {
        for (size_t i = 0; i < vendedores.size(); i++) {
            std::cout << "\nVendedor #" << (i + 1) << ":" << std::endl;
            vendedores[i]->mostrarInformacion();
        }
    }
    std::cout << "========================================" << std::endl;
}

void Sucursal::enviarNotificacionATodos(const std::string& mensaje) {
    std::cout << "\n*** ENVIANDO NOTIFICACION A TODOS LOS VENDEDORES ***" << std::endl;
    for (Vendedor* vendedor : vendedores) {
        vendedor->recibirNotificacion(mensaje);
    }
}