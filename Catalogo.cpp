#include "Catalogo.h"
#include <iostream>
#include <iomanip>

// Constructor de catálogo, crea por default 10 libros
Catalogo::Catalogo() : cantidad{0} {
    libros[cantidad++] = Libro("Cien anios de soledad", "Gabriel Garcia Marquez", "9780307474728", true);
    libros[cantidad++] = Libro("1984", "George Orwell", "9780451524935", true);
    libros[cantidad++] = Libro("Don Quijote de la Mancha", "Miguel de Cervantes", "9788491050260", true);
    libros[cantidad++] = Libro("Orgullo y prejuicio", "Jane Austen", "9780141439518", true);
    libros[cantidad++] = Libro("Cronica de una muerte anunciada", "Gabriel Garcia Marquez", "9781400034710", true);
    libros[cantidad++] = Libro("El Principito", "Antoine de Saint-Exupery", "9780156013987", true);
    libros[cantidad++] = Libro("Rayuela", "Julio Cortazar", "9788437603581", true);
    libros[cantidad++] = Libro("La sombra del viento", "Carlos Ruiz Zafon", "9780143126393", true);
    libros[cantidad++] = Libro("El amor en los tiempos del colera", "Gabriel Garcia Marquez", "9780307389732", true);
    libros[cantidad++] = Libro("Fahrenheit 451", "Ray Bradbury", "9781451673319", true);
}

// Imprime encabezadp para libros, con opción de mostrar la disponibilidad
void Catalogo::imprimirEncabezado(bool disponibilidad) const {
    std::cout << std::left
              << std::setw(6) << "N°"
              << std::setw(44) << "Titulo"
              << std::setw(30) << "Autor"
              << std::setw(20) << "ISBN";

    if (disponibilidad) {
        std::cout << "Disponible";
    }

    std::cout << "\n";

    int anchoTotal = 92 + (disponibilidad ? 17 : 0);
    std::cout << std::string(anchoTotal, '-') << "\n";
}

// Método que marca disponible un libro
bool Catalogo::marcarDisponible(const std::string &isbn) {
    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getISBN() == isbn && !libros[i].estaDisponible()) {
            libros[i].marcarDisponible();
            return true;
        }
    }
    return false;
}

// Método que marca prestado un libro
bool Catalogo::marcarPrestado(const std::string &isbn) {
    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getISBN() == isbn && libros[i].estaDisponible()) {
            libros[i].marcarPrestado();
            return true;
        }
    }
    return false;
}

// Método que busca libros por título
void Catalogo::buscarPorTitulo(const std::string &tituloBuscado) const {
    bool encontrado = false;

    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getTitulo() == tituloBuscado) {
            std::cout << std::string(25,'-') << std::endl;
            std::cout << libros[i].mostrar();
            encontrado = true;
        }
    }

    if (!encontrado)
        std::cout << "No se encontro ningun libro con ese titulo.\n";
}

// Método que busca libros por autor
void Catalogo::buscarPorAutor(const std::string &autorBuscado) const {
    bool encontrado = false;

    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getAutor() == autorBuscado) {
            std::cout << std::string(25,'-') << std::endl;
            std::cout << libros[i].mostrar();
            encontrado = true;
        }
    }

    if (!encontrado)
        std::cout << "No se encontro ningun libro de ese autor.\n";
}

// Método que busca un libro por ISBN
void Catalogo::buscarPorISBN(const std::string &isbn) const {
    bool encontrado = false;

    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getISBN() == isbn) {
            std::cout << std::endl << libros[i].mostrar();
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        std::cout << "No se encontro ningun libro con ISBN: " << isbn << std::endl;
}

// Método que busca un libro por ISBN (devuelve la dirección de memoria del libro en catálogo)
const Libro* Catalogo::buscarLibroPorISBN(const std::string &isbn) const {
    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getISBN() == isbn) {
            return &libros[i];
        }
    }
    return nullptr;
}

// Método que muestra libros disponibles
void Catalogo::mostrarDisponibles() const {
    std::cout << "==================================== LIBROS DISPONIBLES ====================================\n\n";
    imprimirEncabezado(false);
    int index = 1;
    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].estaDisponible()) {
            std::cout << libros[i].mostrar(index++, false);
        }
    }
}

// Método que muestra libros prestados
void Catalogo::mostrarPrestados() const {
    std::cout << "==================================== LIBROS EN PRESTAMO ====================================\n\n";
    imprimirEncabezado(false);
    int index = 1;
    for (int i = 0; i < cantidad; ++i) {
        if (!libros[i].estaDisponible()) {
            std::cout << libros[i].mostrar(index++, false);
        }
    }
}

// Método que muestra todos los libros
void Catalogo::mostrarCatalogo() const {
    std::cout << "================================================ CATALOGO ===================================================\n\n";
    imprimirEncabezado(true);
    for (int i = 0; i < cantidad; ++i) {
        std::cout << libros[i].mostrar(i + 1, true);
    }
}

// Método que agrega libros al catálogo
void Catalogo::agregarLibro(const Libro& libro) {
    if (cantidad < 1000) {
        libros[cantidad++] = libro;
        std::cout << "Libro agregado con exito" << std::endl;
        std::cout << "ISBN asignado: " << libro.getISBN() << std::endl;

    } else {
        std::cout << "No se pueden agregar mas libros. Catalogo lleno.";
    }
}

// Método para eliminar libros por ISBN
void Catalogo::eliminarLibroPorISBN(const std::string& isbn) {
    int index = -1;

    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].getISBN() == isbn) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cout << "No se encontró ningún libro con ISBN: " << isbn << "\n";
        return;
    }

    std::string tituloEliminado = libros[index].getTitulo();
    std::string autirEliminado = libros[index].getAutor();

    for (int i = index; i < cantidad - 1; ++i) {
        libros[i] = libros[i + 1];
    }
    --cantidad;

    std::cout << "\n";
    std::cout << "Titulo: " << tituloEliminado << std::endl;
    std::cout << "Autor: " << autirEliminado << std::endl;
    std::cout << "\nLibro eliminado del catalogo\n";
}