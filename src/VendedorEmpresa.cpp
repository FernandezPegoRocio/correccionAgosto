#include "VendedorEmpresa.h"
#include <iostream>

VendedorEmpresa::VendedorEmpresa(const std::string& nombre, 
                                 const std::string& apellido, 
                                 int documento, double salario)
    : Vendedor(nombre, apellido, documento, salario, "Grandes Cuentas", 
               "Empresa"), sectorEmpresarial("Corporativo"), cuentasGrandes(10) {
}

VendedorEmpresa::~VendedorEmpresa() {
}

void VendedorEmpresa::trabajar() {
    std::cout << "\n[" << obtenerNombreCompleto() << " - Vendedor Empresa]" << std::endl;
    std::cout << "Tareas del dia:" << std::endl;
    std::cout << "- Administrar " << cuentasGrandes << " cuentas empresariales grandes" << std::endl;
    std::cout << "- Coordinar con equipos de implementacion corporativa" << std::endl;
    std::cout << "- Desarrollar estrategias de ventas a nivel enterprise" << std::endl;
    std::cout << "- Negociar contratos de alto volumen y largo plazo" << std::endl;
}

void VendedorEmpresa::mostrarInformacion() {
    Vendedor::mostrarInformacion();
    std::cout << "Sector Empresarial: " << sectorEmpresarial << std::endl;
    std::cout << "Cuentas Grandes: " << cuentasGrandes << std::endl;
}