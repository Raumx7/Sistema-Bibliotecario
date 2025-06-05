// Catalogo.cpp
#include "Catalogo.h"
#include <iostream>
#include <iomanip>

Catalogo::Catalogo() : cantidad{0} {
    libros[cantidad++] = Libro("Cien anios de soledad", "Gabriel Garcia Marquez", "9780307474728", true);
    libros[cantidad++] = Libro("1984", "George Orwell", "9780451524935", true);
    libros[cantidad++] = Libro("Don Quijote de la Mancha", "Miguel de Cervantes", "9788491050260", true);
    libros[cantidad++] = Libro("Orgullo y prejuicio", "Jane Austen", "9780141439518", true);
    libros[cantidad++] = Libro("Crónica de una muerte anunciada", "Gabriel Garcia Marquez", "9781400034710", true);
    libros[cantidad++] = Libro("El Principito", "Antoine de Saint-Exupery", "9780156013987", true);
    libros[cantidad++] = Libro("Rayuela", "Julio Cortazar", "9788437603581", true);
    libros[cantidad++] = Libro("La sombra del viento", "Carlos Ruiz Zafon", "9780143126393", true);
    libros[cantidad++] = Libro("El amor en los tiempos del colera", "Gabriel Garcia Marquez", "9780307389732", true);
    libros[cantidad++] = Libro("Fahrenheit 451", "Ray Bradbury", "9781451673319", true);
}

void imprimirEncabezado() {
    std::cout << std::left
              << std::setw(5) << "N°"
              << std::setw(35) << "Título"
              << std::setw(25) << "Autor"
              << std::setw(15) << "ISBN"
              << std::setw(12) << "Disponible"
              << "\n";
    std::cout << std::string{92,'-'} << "\n";
}

bool Catalogo::marcarDisponible(const std::string &isbn){
    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getISBN() == isbn) {
            libros[i].marcarDisponible();
            return true;
        }
    }
        return false;
}

bool Catalogo::marcarPrestado(const std::string &isbn){
    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getISBN() == isbn) {
            libros[i].marcarPrestado();
            return true;
        }
    }
        return false;
}

void Catalogo::buscarPorTitulo(const std::string &tituloBuscado) const {
    imprimirEncabezado();
    bool encontrado = false;

    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getTitulo() == tituloBuscado) {
            std::cout << std::string{30,'-'};
            std::cout << libros[i].mostrar();
            encontrado = true;
        }
    }

    if (!encontrado)
        std::cout << "No se encontro ningun libro con ese titulo.\n";
}

void Catalogo::buscarPorAutor(const std::string& autorBuscado) const {
    imprimirEncabezado();
    bool encontrado = false;

    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getAutor() == autorBuscado) {
            std::cout << std::string{30,'-'};
            std::cout << libros[i].mostrar();
            encontrado = true;
        }
    }

    if (!encontrado)
        std::cout << "No se encontro ningun libro de ese autor.\n";
}

void Catalogo::mostrarDisponibles() const {
    imprimirEncabezado();
    int index = 1;
    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].estaDisponible()) {
            std::cout << libros[i].mostrar(index++);
        }
    }
}

void Catalogo::mostrarPrestados() const {
    imprimirEncabezado();
    int index = 1;
    for (int i = 0; i < cantidad; ++i) {
        if (!libros[i].estaDisponible()) {
            std::cout << libros[i].mostrar(index++);
        }
    }
}

void Catalogo::mostrarCatalogo() const {
    imprimirEncabezado();
    for (int i = 0; i < cantidad; ++i) {
        std::cout << libros[i].mostrar(i + 1);
    }
}

void Catalogo::agregarLibro(const Libro& libro) {
    if (cantidad < 1000) {
        libros[cantidad++] = libro;
    } else {
        std::cout << "No se pueden agregar mas libros. Catalogo lleno." << std::endl;
    }
}

void Catalogo::eliminarLibro(int posicion) {
    if (posicion < 1 || posicion > cantidad) {
        std::cout << "Posicion invalida.\n";
        return;
    }

    int index = posicion - 1;
    std::string tituloEliminado = libros[index].getTitulo();
    for (int i = index; i < cantidad - 1; ++i) {
        libros[i] = libros[i + 1];
    }
    cantidad--;
    std::cout << "El libro \"" << tituloEliminado << "\" se ha eliminado del catalogo" << std::endl;
}