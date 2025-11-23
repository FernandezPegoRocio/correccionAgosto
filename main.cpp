#include <iostream>
#include <vector>
#include <string>
#include "../include/Empleado.h"
#include "../include/Vendedor.h"
#include "../include/VendedorParticular.h"
#include "../include/VendedorProfesional.h"
#include "../include/VendedorEmpresa.h"
#include "../include/Sucursal.h"

using namespace std;

void mostrarMenu();
Vendedor* crearVendedor(int tipoVendedor);
void registrarVendedores(vector<Empleado*>& empleados, Sucursal* sucursal);
void mostrarActividadesDiarias(vector<Empleado*>& empleados);
void generarReporteEmpleados(vector<Empleado*>& empleados);
void liberarMemoria(vector<Empleado*>& empleados, Sucursal* sucursal);

int main() {
    cout << "========================================" << endl;
    cout << "   SISTEMA DE GESTION DE VENDEDORES" << endl;
    cout << "        APP DE PEDIDOS EMPRESARIAL" << endl;
    cout << "========================================" << endl;
    
    Sucursal* sucursalPrincipal = new Sucursal("Sucursal Centro", "Av. Principal 123");
    
    vector<Empleado*> empleados;
    
    registrarVendedores(empleados, sucursalPrincipal);
    
    cout << "\n\n*** OPERACIONES DEL SISTEMA ***" << endl;
    
    sucursalPrincipal->listarVendedores();
    
    string mensajeNotificacion = "Nueva promocion disponible: 20% de descuento en todos los productos";
    sucursalPrincipal->enviarNotificacionATodos(mensajeNotificacion);
    
    mostrarActividadesDiarias(empleados);
    
    generarReporteEmpleados(empleados);
    
    liberarMemoria(empleados, sucursalPrincipal);
    
    cout << "\n*** PROGRAMA FINALIZADO EXITOSAMENTE ***" << endl;
    
    return 0;
}

void mostrarMenu() {
    cout << "\nSeleccione el tipo de vendedor:" << endl;
    cout << "1. Vendedor Particular" << endl;
    cout << "2. Vendedor Profesional" << endl;
    cout << "3. Vendedor Empresa" << endl;
    cout << "Opcion: ";
}

Vendedor* crearVendedor(int tipoVendedor) {
    string nombre, apellido;
    int documento;
    double salario;
    
    cout << "\n--- Ingrese los datos del vendedor ---" << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Apellido: ";
    cin >> apellido;
    cout << "Documento: ";
    cin >> documento;
    cout << "Salario: ";
    cin >> salario;
    
    Vendedor* nuevoVendedor = nullptr;
    
    switch(tipoVendedor) {
        case 1:
            nuevoVendedor = new VendedorParticular(nombre, apellido, documento, salario);
            cout << "Vendedor Particular creado exitosamente!" << endl;
            break;
        case 2:
            nuevoVendedor = new VendedorProfesional(nombre, apellido, documento, salario);
            cout << "Vendedor Profesional creado exitosamente!" << endl;
            break;
        case 3:
            nuevoVendedor = new VendedorEmpresa(nombre, apellido, documento, salario);
            cout << "Vendedor Empresa creado exitosamente!" << endl;
            break;
        default:
            cout << "Opcion invalida. Creando Vendedor Particular por defecto." << endl;
            nuevoVendedor = new VendedorParticular(nombre, apellido, documento, salario);
    }
    
    return nuevoVendedor;
}

void registrarVendedores(vector<Empleado*>& empleados, Sucursal* sucursal) {
    cout << "\n*** REGISTRO DE VENDEDORES ***" << endl;
    cout << "Por favor, registre 3 vendedores para el sistema" << endl;
    
    for (int i = 0; i < 3; i++) {
        cout << "\n========== Vendedor " << (i + 1) << " de 3 ==========" << endl;
        mostrarMenu();
        
        int opcion;
        cin >> opcion;
        
        Vendedor* vendedor = crearVendedor(opcion);
        
        empleados.push_back(vendedor);

        sucursal->agregarVendedor(vendedor);
    }
}

void mostrarActividadesDiarias(vector<Empleado*>& empleados) {
    cout << "\n\n========================================" << endl;
    cout << "   ACTIVIDADES DIARIAS DE VENDEDORES" << endl;
    cout << "========================================" << endl;
    
    cout << "\nAsignacion de tareas para hoy:" << endl;
    cout << "----------------------------------------------" << endl;
    
    for (Empleado* empleado : empleados) {
        empleado->trabajar();
    }
}

void generarReporteEmpleados(vector<Empleado*>& empleados) {
    cout << "\n\n========================================" << endl;
    cout << "      REPORTE DE RECURSOS HUMANOS" << endl;
    cout << "========================================" << endl;
    
    cout << "\nInformacion detallada del personal:" << endl;
    cout << "----------------------------------------------" << endl;
    
    double totalSalarios = 0;
    
    for (size_t i = 0; i < empleados.size(); i++) {
        cout << "\n*** Empleado #" << (i + 1) << " ***" << endl;
        
        empleados[i]->mostrarDatosPersonales();
        
        double salario = empleados[i]->obtenerSalario();
        cout << "Salario: $" << salario << endl;
        cout << "Area: " << empleados[i]->obtenerArea() << endl;
        
        totalSalarios += salario;
        
        Vendedor* vendedor = dynamic_cast<Vendedor*>(empleados[i]);
        if (vendedor != nullptr) {
            cout << "Categoria: " << vendedor->obtenerCategoria() << endl;
        }
    }
    
    cout << "\n----------------------------------------------" << endl;
    cout << "RESUMEN:" << endl;
    cout << "Total de empleados: " << empleados.size() << endl;
    cout << "Total en salarios: $" << totalSalarios << endl;
    cout << "Promedio salarial: $" << (totalSalarios / empleados.size()) << endl;
    cout << "========================================" << endl;
}

void liberarMemoria(vector<Empleado*>& empleados, Sucursal* sucursal) {
    for (Empleado* empleado : empleados) {
        delete empleado;
    }
    empleados.clear();
    
    delete sucursal;
}