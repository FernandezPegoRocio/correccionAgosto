#include "VendedorParticular.h"
#include <iostream>

VendedorParticular::VendedorParticular(const std::string& nombre, 
                                       const std::string& apellido, 
                                       int documento, double salario)
    : Vendedor(nombre, apellido, documento, salario, "Ventas Minoristas", 
               "Particular"), clientesAsignados(50) {
}

VendedorParticular::~VendedorParticular() {
}

void VendedorParticular::trabajar() {
    std::cout << "\n[" << obtenerNombreCompleto() << " - Vendedor Particular]" << std::endl;
    std::cout << "Tareas del dia:" << std::endl;
    std::cout << "- Atender clientes individuales en el local" << std::endl;
    std::cout << "- Realizar seguimiento de " << clientesAsignados << " clientes asignados" << std::endl;
    std::cout << "- Gestionar ventas al por menor" << std::endl;
    std::cout << "- Asesorar sobre productos para uso personal" << std::endl;
}

void VendedorParticular::mostrarInformacion() {
    Vendedor::mostrarInformacion();
    std::cout << "Clientes Asignados: " << clientesAsignados << std::endl;
}