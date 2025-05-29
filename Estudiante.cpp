#include "Estudiante.h"
#include <iostream>
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

std::string Estudiante::getMatricula() const {
    return matricula;
}

int Estudiante::getCantidadPrestamos() const {
    return cantidadPrestamos;
}

// Método para solicitar prestado un libro
void Estudiante::solicitarPrestamo(int idLibro) {
    if (cantidadPrestamos >= 5) {
        std::cout << "No puedes solicitar más préstamos. Límite alcanzado." << std::endl;
        return;
    }

    Prestamo nuevoPrestamo{idLibro};
    prestamos[cantidadPrestamos] = nuevoPrestamo;
    cantidadPrestamos++;

    std::cout << "Préstamo registrado con éxito." << std::endl;
}

// Método para devolver libro
void Estudiante::devolverLibro(int idLibro) {
    if (cantidadPrestamos == 0) {
        std::cout << "No tienes libros en préstamo." << std::endl;
        return;
    }

    bool encontrado = false;
    for (int i = 0; i < cantidadPrestamos; ++i) {
        if (prestamos[i].getIdLibro() == idLibro) {
            prestamos[i] = prestamos[cantidadPrestamos - 1];    // Reemplaza el préstamo devuelto con el último de la lista
            cantidadPrestamos--;
            encontrado = true;
            std::cout << "Libro devuelto correctamente." << std::endl;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontró el préstamo con ese ID." << std::endl;
    }
}

void Estudiante::mostrarPerfil() const {
    std::cout << "=== Perfil de Estudiante ===\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Fecha de registro: " << fechaRegistro << "\n";
    std::cout << "Matrícula: " << matricula << "\n";
    std::cout << "Préstamos activos: " << cantidadPrestamos << "\n";
}