#include "Vendedor.h"
#include <iostream>

Vendedor::Vendedor(const std::string& nombre, const std::string& apellido, 
                   int documento, double salario, const std::string& area, 
                   const std::string& categoria)
    : Empleado(nombre, apellido, documento, salario, area), 
      categoria(categoria), numeroVentas(0) {
}

Vendedor::~Vendedor() {
}

void Vendedor::recibirNotificacion(const std::string& mensaje) {
    std::cout << "\n[NOTIFICACION para " << obtenerNombreCompleto() 
              << " - " << categoria << "]" << std::endl;
    std::cout << "Mensaje: " << mensaje << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void Vendedor::mostrarInformacion() {
    std::cout << "\n--- Informacion del Vendedor ---" << std::endl;
    mostrarDatosPersonales();
    std::cout << "Categoria: " << categoria << std::endl;
    std::cout << "Area: " << area << std::endl;
    std::cout << "Salario: $" << salario << std::endl;
}