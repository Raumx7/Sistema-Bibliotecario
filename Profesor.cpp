// Profesor.cpp
#include "Profesor.h"
#include <iostream>
#include <sstream>
#include <iomanip>

// Constructor
Profesor::Profesor(const std::string &n, const std::string &e,
                   const std::string &fr, int numEmp)
    : Usuario{n, e, fr}, cantidadPrestamos{0} {
    setNumeroEmpleado(numEmp);
}

// Setters y Getters
void Profesor::setNumeroEmpleado(int num) {
    numeroEmpleado = (num > 0) ? num : 0;
}

int Profesor::getNumeroEmpleado() const {
    return numeroEmpleado;
}

int Profesor::getCantidadPrestamos() const {
    return cantidadPrestamos;
}

std::string Profesor::getCategoria() const {
    return "Profesor";
}

// Registrar préstamo
void Profesor::registrarPrestamo(const std::string &isbn, Catalogo &cat) {
    if (cantidadPrestamos >= 10) {
        std::cout << "Límite de préstamos alcanzado para el profesor.\n";
        return;
    }
    if (cat.marcarPrestado(isbn)) {
        prestamos[cantidadPrestamos++] = isbn;
        std::cout << "Préstamo registrado exitosamente.\n";
    }
}

// Remover préstamo
void Profesor::removerPrestamo(const std::string &isbn, Catalogo &cat) {
    if (cantidadPrestamos == 0) {
        std::cout << "No tiene préstamos activos.\n";
        return;
    }

    int pos = -1;
    for (int i = 0; i < cantidadPrestamos; ++i) {
        if (prestamos[i] == isbn) {
            pos = i;
            break;
        }
    }

    if (cat.marcarDisponible(isbn) && pos != -1) {
        for (int j = pos; j < cantidadPrestamos - 1; ++j) {
            prestamos[j] = prestamos[j + 1];
        }
        --cantidadPrestamos;
        std::cout << "Libro devuelto correctamente.\n";
    } else {
        std::cout << "No se encontró ese préstamo.\n";
    }
}

// Perfil detallado
std::string Profesor::mostrarPerfil() const {
    std::ostringstream oss;
    oss << "Nombre: " << nombre << "\n"
        << "Email: " << email << "\n"
        << "Fecha de registro: " << fechaRegistro << "\n"
        << "Número de empleado: " << numeroEmpleado << "\n"
        << "Cantidad de préstamos: " << cantidadPrestamos << "\n";
    return oss.str();
}

// Perfil en formato tabla
std::string Profesor::mostrarPerfil(int indice) const {
    std::ostringstream oss;
    oss << std::left
        << std::setw(5)  << indice
        << std::setw(25) << nombre
        << std::setw(30) << email
        << std::setw(15) << fechaRegistro
        << std::setw(10) << numeroEmpleado
        << std::setw(8)  << cantidadPrestamos
        << std::setw(12) << getCategoria();
    return oss.str();
}