#include "Profesor.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <regex>

// Constructor
Profesor::Profesor(const std::string &n, const std::string &e,
    const std::string &fr, const std::string &numEmp)
: Usuario(n, e, fr), cantidadPrestamos{0} {
setNumeroEmpleado(numEmp);
}

// Setters y Getters
void Profesor::setNumeroEmpleado(const std::string &num) {
static const std::regex formato("^PR\\d{4}$"); // "PR" seguido de 4 dígitos
numeroEmpleado = (std::regex_match(num, formato)) ? num : std::string{"PR0000"};
}

std::string Profesor::getNumeroEmpleado() const {return numeroEmpleado;}
int Profesor::getCantidadPrestamos() const {return cantidadPrestamos;}
std::string Profesor::getID() const {return numeroEmpleado;}
std::string Profesor::getCategoria() const {return "Profesor";}
int Profesor::getCantidad() const {return cantidadPrestamos;}

// Método para mostrar los préstamos del profesor
void Profesor::mostrarPrestamos(const Catalogo& cat) const {
    std::cout << "Usuario: " << nombre << std::endl
              << "No. empleado: " << numeroEmpleado << " - " << getCategoria() << std::endl;

    if (cantidadPrestamos == 0) {
        std::cout << "El usuario no cuenta con prestamos activos.\n";
        return;
    }

    cat.imprimirEncabezado(false);
    int index = 1;

    for (int i = 0; i < cantidadPrestamos; ++i) {
        const Libro* libro = cat.buscarLibroPorISBN(prestamos[i]);
        if (libro && !libro->estaDisponible()) {
            std::cout << libro->mostrar(index++, false);
        }
    }
    std::cout << "Prestamos activos: " << cantidadPrestamos << std::endl;
}

// Método para saber si ya tiene prestado un libro
bool Profesor::yaTienePrestado(const std::string &isbn) const {
    for (int i = 0; i < cantidadPrestamos; ++i) {
        if (prestamos[i] == isbn) {
            return true;
        }
    }
    return false;
}

// Método para solicitar prestado un libro
void Profesor::registrarPrestamo(const std::string &isbn, Catalogo &cat) {
    if (cantidadPrestamos >= 10) {
        std::cout << "No se pueden solicitar mas prestamos. Limite alcanzado." << std::endl;
        return;
    }

    if (yaTienePrestado(isbn)) {
        std::cout << "Ya tienes este libro en prestamo." << std::endl;
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
        std::cout << "Prestamo registrado con exito." << "\n"
                    << "Libro: " << "\"" << libro->getTitulo() << "\"\n"
                    << "Autor: " << libro->getAutor() << "\n";
    }
}

// Remover préstamo
void Profesor::removerPrestamo(const std::string &isbn, Catalogo &cat) {
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
        std::cout << "Libro devuelto con exito:" << "\n"
                    << "Libro: " << "\"" << libro->getTitulo() << "\"\n"
                    << "Autor: " << libro->getAutor() << "\n";
    } else {
        std::cout << "Ocurrio un error al intentar devolver el libro. Intenta nuevamente." << std::endl;
    }
}

// Perfil detallado
std::string Profesor::mostrarPerfil() const {
    std::ostringstream oss;
    oss << "Nombre: " << nombre << "\n"
        << "Email: " << email << "\n"
        << "Fecha de registro: " << fechaRegistro << "\n"
        << "Número de empleado: " << numeroEmpleado << "\n"
        << "Prestamos activos: " << cantidadPrestamos << "\n";
    return oss.str();
}

// Perfil en formato tabla
std::string Profesor::mostrarPerfil(int indice) const {
    std::ostringstream oss;
    oss << std::left
        << std::setw(5)  << indice
        << std::setw(24) << nombre
        << std::setw(30) << email
        << std::setw(15) << fechaRegistro
        << std::setw(14) << numeroEmpleado
        << std::setw(10)  << cantidadPrestamos
        << std::setw(10) << getCategoria();
    return oss.str();
}