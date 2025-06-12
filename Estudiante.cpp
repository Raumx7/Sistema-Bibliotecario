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
std::string Estudiante::getID() const {return matricula;}
std::string Estudiante::getCategoria() const {return "Estudiante";}
int Estudiante::getCantidad() const {return cantidadPrestamos;}

// Método para mostrar los pŕestamos del estudiante
void Estudiante::mostrarPrestamos(const Catalogo& cat) const {
    std::cout << "Usuario: " << nombre << " - " << getCategoria() << "\n\n";

    if (cantidadPrestamos == 0) {
        std::cout << "El usuario no cuenta con prestamos activos.\n";
        return;
    }

    std::cout << "==================================== PRESTAMOS ACTIVOS =====================================\n\n"; 
    cat.imprimirEncabezado(false);
    int index = 1;

    for (int i = 0; i < cantidadPrestamos; ++i) {
        const Libro* libro = cat.buscarLibroPorISBN(prestamos[i]);
        if (libro && !libro->estaDisponible()) {
            std::cout << libro->mostrar(index++, false);
        }
    }
}

// Método para saber si ya tiene prestado un libro
bool Estudiante::yaTienePrestado(const std::string &isbn) const {
    for (int i = 0; i < cantidadPrestamos; ++i) {
        if (prestamos[i] == isbn) {
            return true;
        }
    }
    return false;
}

// Método para solicitar prestado un libro
void Estudiante::registrarPrestamo(const std::string &isbn, Catalogo &cat) {
    if (cantidadPrestamos >= 5) {
        std::cout << "No se pueden solicitar mas prestamos. Limite alcanzado." << std::endl;
        return;
    }

    if (yaTienePrestado(isbn)) {
        std::cout << "El usuario ya tiene este libro en prestamo." << std::endl;
        return;
    }

    const Libro* libro = cat.buscarLibroPorISBN(isbn);

    if (!libro) {
        std::cout << "No se encontro ningun libro con ese ISBN." << std::endl;
        return;
    }

    if (!libro->estaDisponible()) {
        std::cout << "El libro ya esta prestado." << std::endl;
        return;
    }

    if (cat.marcarPrestado(isbn)) {
        prestamos[cantidadPrestamos++] = isbn;
        std::cout << "\nPrestamo registrado con exito\n\n"
                    << "Usuario: " << nombre << " - " << getCategoria() << "\n"
                    << "Libro: " << libro->getTitulo() << "\n"
                    << "Autor: " << libro->getAutor() << "\n";
    }
}

// Método para devolver un libro
void Estudiante::removerPrestamo(const std::string &isbn, Catalogo &cat) {
    if (cantidadPrestamos == 0) {
        std::cout << "El usuario no tiene libros en prestamo." << std::endl;
        return;
    }

    // Buscar el ISBN en el arreglo de préstamos del estudiante
    int pos = -1;
    for (int i = 0; i < cantidadPrestamos; ++i) {
        if (prestamos[i] == isbn) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        std::cout << "El usuario no cuenta con este libro en prestamo. Verifica el ISBN." << std::endl;
        return;
    }

    // Validar que el libro realmente esté registrado como no disponible antes de marcarlo como disponible
    const Libro* libro = cat.buscarLibroPorISBN(isbn);
    if (!libro) {
        std::cout << "El ISBN ingresado no existe en el catalogo." << std::endl;
        return;
    }

    // Si se marca externamente un libro como disponible (caso en el que el programa falla)
    if (libro->estaDisponible()) {
        std::cout << "Este libro ya aparece como disponible en el catalogo. No se realizo la devolucion." << std::endl;
        return;
    }

    // Marcar como disponible
    if (cat.marcarDisponible(isbn)) {
        for (int j = pos; j < cantidadPrestamos - 1; ++j) {
            prestamos[j] = prestamos[j + 1];
        }
        --cantidadPrestamos;
        std::cout << "\nLibro devuelto con exito\n\n"
                    << "Usuario: " << nombre << " - " << getCategoria() << "\n"
                    << "Libro: " << libro->getTitulo() << "\n"
                    << "Autor: " << libro->getAutor() << "\n";
    } else {
        std::cout << "Ocurrio un error al intentar devolver el libro. Intenta nuevamente." << std::endl;
    }
}

// Perfil detallado
std::string Estudiante::mostrarPerfil() const {
    std::ostringstream oss;
    oss << "Nombre: " << nombre << " - " << getCategoria() << "\n"
        << "Email: " << email << "\n"
        << "Fecha de registro: " << fechaRegistro << "\n"
        << "Matricula: " << matricula << " - " << getCategoria() << "\n"
        << "Prestamos activos: " << cantidadPrestamos << "\n";
    return oss.str();
}

// Perfil en formato tabla
std::string Estudiante::mostrarPerfil(int indice) const {
    std::ostringstream oss;
    oss << std::left
        << std::setw(5)  << indice
        << std::setw(24) << nombre
        << std::setw(30) << email
        << std::setw(15) << fechaRegistro
        << std::setw(14) << matricula
        << std::setw(10)  << cantidadPrestamos
        << std::setw(10) << getCategoria();
    return oss.str();
}