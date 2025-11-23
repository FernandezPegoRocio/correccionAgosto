#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <iostream>

class Empleado {
protected:
    std::string nombre;
    std::string apellido;
    int documento;
    double salario;
    std::string area;

public:
    Empleado(const std::string& nombre, const std::string& apellido, int documento, 
             double salario, const std::string& area) 
        : nombre(nombre), apellido(apellido), documento(documento), 
          salario(salario), area(area) {}
    
    virtual ~Empleado() {}
    
  
    virtual void trabajar() = 0;
    
 
    virtual void mostrarDatosPersonales() {
        std::cout << "Nombre: " << nombre << " " << apellido << std::endl;
        std::cout << "Documento: " << documento << std::endl;
    }
    
    double obtenerSalario() const { return salario; }
    std::string obtenerArea() const { return area; }
    std::string obtenerNombreCompleto() const { return nombre + " " + apellido; }
};

#endif