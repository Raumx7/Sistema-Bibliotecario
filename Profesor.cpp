// Profesor.cpp
#include <iostream>
#include "Profesor.h"

#include "Profesor.h"
#include <iostream>

Profesor::Profesor(const std::string &n, const std::string &e,
                   const std::string &fr, int numEmp)
    : Usuario(n, e, fr), numeroEmpleado(numEmp), cantidadPrestamos(0) {}

void Profesor::setNumeroEmpleado(int numEmp) {
    numeroEmpleado = numEmp;
}

int Profesor::getNumeroEmpleado() const {return numeroEmpleado;}

int Profesor::getCantidadPrestamos() const {return cantidadPrestamos;}

// Método para solicitar prestado un libro
void Profesor::registrarPrestamo(const std::string &isbn, Catalogo &cat) {
    if (cantidadPrestamos >= 10) {
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
void Profesor::removerPrestamo(const std::string &isbn, Catalogo &cat) {
    if (cantidadPrestamos == 0) {
        std::cout << "No tienes libros en prestamo." << std::endl;
        return;
    }

    if(cat.marcarDisponible(isbn)){
        int pos;
        for(int i = 0; i < cantidadPrestamos; ++i){
            if(isbn == prestamos[i]){
                pos = i;
            }
        }
        for(int j = pos; j < cantidadPrestamos - 1; ++j){
            prestamos[j] = prestamos[j + 1];
        }
        std::cout << "Libro devuelto con exito" << std::endl;
        return;
    }
        std::cout << "No se encontro el prestamo con ese ISBN." << std::endl;
}

void Profesor::mostrarPerfil() const {
    std::cout << "=== Perfil de Profesor ===\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Fecha de registro: " << fechaRegistro << "\n";
    std::cout << "Número de empleado: " << numeroEmpleado << "\n";
    std::cout << "Préstamos activos: " << cantidadPrestamos << "\n";
}