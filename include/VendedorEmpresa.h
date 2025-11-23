#ifndef VENDEDOR_EMPRESA_H
#define VENDEDOR_EMPRESA_H

#include "Vendedor.h"

class VendedorEmpresa : public Vendedor {
private:
    std::string sectorEmpresarial;
    int cuentasGrandes;

public:
    VendedorEmpresa(const std::string& nombre, const std::string& apellido, 
                   int documento, double salario);
    
    ~VendedorEmpresa();
    
    void trabajar() override;
    void mostrarInformacion() override;
};

#endif
