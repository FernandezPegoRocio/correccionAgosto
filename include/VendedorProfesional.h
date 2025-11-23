#ifndef VENDEDOR_PROFESIONAL_H
#define VENDEDOR_PROFESIONAL_H

#include "Vendedor.h"

class VendedorProfesional : public Vendedor {
private:
    std::string especialidad;
    int certificaciones;

public:
    VendedorProfesional(const std::string& nombre, const std::string& apellido, 
                       int documento, double salario);
    
    ~VendedorProfesional();
    
    void trabajar() override;
    void mostrarInformacion() override;
};

#endif
