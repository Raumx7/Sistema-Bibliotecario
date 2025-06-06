// Estudiante.cpp
#include "Estudiante.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <regex>

// Constructor
Estudiante::Estudiante(const std::string &n, const std::string &e,
                       const std::string &fr, const std::string &mat)
    : Usuario(n, e, fr), cantidadPrestamos{0}{
    setMatricula(mat);
}

// Setters y Getters
void Estudiante::setMatricula(const std::string &mat) {
    static const std::regex formato("^Al\\d{4}$"); // "Al" seguido de 4 dígitos
    matricula = (std::regex_match(mat, formato))? mat : std::string{"Al0000"};
}

std::string Estudiante::getMatricula() const {return matricula;}
int Estudiante::getCantidadPrestamos() const {return cantidadPrestamos;}

// Método para solicitar prestado un libro
void Estudiante::registrarPrestamo(const std::string &isbn, Catalogo &cat) {
    if (cantidadPrestamos >= 5) {
        std::cout << "No puedes solicitar mas prestamos. Limite alcanzado." << std::endl;
        return;
    }
    if(cat.marcarPrestado(isbn)){
        std::string nuevoPrestamo{isbn};
        prestamos[cantidadPrestamos++] = nuevoPrestamo;
        std::cout << "Prestamo registrado con exito." << std::endl;
    }
}

// Método para devolver libro
void Estudiante::removerPrestamo(const std::string &isbn, Catalogo &cat) {
    if (cantidadPrestamos == 0) {
        std::cout << "No tienes libros en préstamo." << std::endl;
        return;
    }

    int pos = -1;
    for (int i = 0; i < cantidadPrestamos; ++i) {
        if (prestamos[i] == isbn) {
            pos = i;
            break;
        }
    }

    if (pos != -1 && cat.marcarDisponible(isbn)) {
        for (int j = pos; j < cantidadPrestamos - 1; ++j) {
            prestamos[j] = prestamos[j + 1];
        }
        --cantidadPrestamos;
        std::cout << "Libro con ISBN: " << isbn << " devuelto con exito" << std::endl;
    } else {
        std::cout << "No se encontro el prestamo con ese ISBN o no tienes el libro en prestamo." << std::endl;
    }
}

std::string Estudiante::getCategoria() const {
    return "Estudiante";
}

// Perfil detallado
std::string Estudiante::mostrarPerfil() const {
    std::ostringstream oss;
    oss << "Nombre: " << nombre << "\n"
        << "Email: " << email << "\n"
        << "Fecha de registro: " << fechaRegistro << "\n"
        << "Matricula: " << matricula << "\n"
        << "Cantidad de prestamos: " << cantidadPrestamos << "\n";
    return oss.str();
}

// Perfil en formato tabla
std::string Estudiante::mostrarPerfil(int indice) const {
    std::ostringstream oss;
    oss << std::left
        << std::setw(5)  << indice
        << std::setw(25) << nombre
        << std::setw(30) << email
        << std::setw(15) << fechaRegistro
        << std::setw(10) << matricula
        << std::setw(8)  << cantidadPrestamos
        << std::setw(12) << getCategoria();
    return oss.str();
}