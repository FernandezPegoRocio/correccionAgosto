#ifndef VENDEDOR_PARTICULAR_H
#define VENDEDOR_PARTICULAR_H

#include "Vendedor.h"

class VendedorParticular : public Vendedor {
private:
    int clientesAsignados;

public:
    VendedorParticular(const std::string& nombre, const std::string& apellido, 
                      int documento, double salario);
    
    ~VendedorParticular();
    
    void trabajar() override;
    void mostrarInformacion() override;
};

#endif