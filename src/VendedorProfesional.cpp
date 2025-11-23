#include "VendedorProfesional.h"
#include <iostream>

VendedorProfesional::VendedorProfesional(const std::string& nombre, 
                                         const std::string& apellido, 
                                         int documento, double salario)
    : Vendedor(nombre, apellido, documento, salario, "Ventas Corporativas", 
               "Profesional"), especialidad("Soluciones B2B"), certificaciones(3) {
}

VendedorProfesional::~VendedorProfesional() {
}

void VendedorProfesional::trabajar() {
    std::cout << "\n[" << obtenerNombreCompleto() << " - Vendedor Profesional]" << std::endl;
    std::cout << "Tareas del dia:" << std::endl;
    std::cout << "- Gestionar cuentas de pequenas y medianas empresas" << std::endl;
    std::cout << "- Preparar propuestas tecnicas especializadas" << std::endl;
    std::cout << "- Realizar demostraciones de productos empresariales" << std::endl;
    std::cout << "- Negociar contratos con profesionales independientes" << std::endl;
}

void VendedorProfesional::mostrarInformacion() {
    Vendedor::mostrarInformacion();
    std::cout << "Especialidad: " << especialidad << std::endl;
    std::cout << "Certificaciones: " << certificaciones << std::endl;
}