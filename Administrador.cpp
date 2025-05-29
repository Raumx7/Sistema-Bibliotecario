#include <iostream>
#include "Administrador.h"

Administrador::Administrador(const std::string &n, const std::string &e, 
                             const std::string &fr, int noEmp)
    : Usuario(n, e, fr), numeroEmp(noEmp) {}

void Administrador::setNumeroEmp(int noEmp) {
    numeroEmp = noEmp;
}

int Administrador::getNumeroEmp() const {
    return numeroEmp;
}

void Administrador::mostrarPerfil() const {
    std::cout << "=== Perfil de Administrador ===\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Fecha de registro: " << fechaRegistro << "\n";
    std::cout << "Número de empleado: " << numeroEmp << "\n";
}