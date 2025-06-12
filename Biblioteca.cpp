#include "Biblioteca.h"
#include <iostream>
#include <iomanip>

// Constructor
Biblioteca::Biblioteca() : cantidadUsuarios{0} {
    // Estudiantes
    usuarios[cantidadUsuarios++] = new Estudiante("Ana Lopez", "ana@correo.com", "12/03/2022", "Al1001");
    usuarios[cantidadUsuarios++] = new Estudiante("Luis Perez", "luis@correo.com", "15/04/2022", "Al1002");
    usuarios[cantidadUsuarios++] = new Estudiante("Marta Gomez", "marta@correo.com", "18/05/2022", "Al1003");
    usuarios[cantidadUsuarios++] = new Estudiante("Pedro Sanchez", "pedro@correo.com", "20/06/2022", "Al1004");
    usuarios[cantidadUsuarios++] = new Estudiante("Lucia Torres", "lucia@correo.com", "22/07/2022", "Al1005");

    // Profesores
    usuarios[cantidadUsuarios++] = new Profesor("Javier Montoya", "javier@edu.mx", "10/01/2020", "PR2001");
    usuarios[cantidadUsuarios++] = new Profesor("Carmen Ruiz", "carmen@edu.mx", "14/02/2020", "PR2002");
}

// Destructor, libera la memoria para cada usuario creado
Biblioteca::~Biblioteca() {
    for (int i = 0; i < cantidadUsuarios; ++i) {
        delete usuarios[i];
    }
}

// Imprime el encabezado con opción de mostrar la categoría de los usuarios (profesor o estudiante)
void Biblioteca::imprimirEncabezadoUsuarios(bool mostrarCategoria) const {
    std::cout << std::left
              << std::setw(6)  << "N°"
              << std::setw(24) << "Nombre"
              << std::setw(30) << "Email"
              << std::setw(15) << "Registro"
              << std::setw(10) << "ID"
              << std::setw(14) << "Prestamos";

    if (mostrarCategoria) {
        std::cout << "Categoria";
    }

    std::cout << "\n";

    int ancho = 93 + (mostrarCategoria ? 15 : 0);
    std::cout << std::string(ancho, '-') << "\n";
}

// Getters
Catalogo& Biblioteca::getCatalogo(){return catalogo;}
int Biblioteca::getCantidadUsuarios() const {return cantidadUsuarios;}

// Método para agregar usuarios
void Biblioteca::agregarUsuario(Usuario* usuario) {
    if (cantidadUsuarios < 1000) {
        usuarios[cantidadUsuarios++] = usuario;
        std::cout << "Usuario agregado exitosamente.\n";
    } else {
        std::cout << "No se pueden agregar mas usuarios. Capacidad maxima alcanzada.\n";
    }
}

// Método para eliminar usuarios
void Biblioteca::eliminarUsuarioPorID(const std::string& id) {
    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i]->getID() == id) {
            if (usuarios[i]->getCantidad() > 0) {
                std::cout << "No se puede eliminar al usuario con ID '" << id 
                          << "' porque tiene libros en prestamo.\n";
                return;
            }
            delete usuarios[i];
            for (int j = i; j < cantidadUsuarios - 1; ++j) {
                usuarios[j] = usuarios[j + 1];
            }
            --cantidadUsuarios;
            std::cout << "Usuario con ID '" << id << "' eliminado exitosamente.\n";
            return;
        }
    }
    std::cout << "No se encontro ningun usuario con ID: '" << id << "'.\n";
}

// Muestra usuarios (profesores y estudiantes)
void Biblioteca::mostrarUsuarios() const {
    std::cout << "================================================ USUARIOS ==================================================\n\n";
    imprimirEncabezadoUsuarios(true);
    for (int i = 0; i < cantidadUsuarios; ++i) {
        std::cout << usuarios[i]->mostrarPerfil(i + 1) << "\n";
    }
}

// Muestra perfil de estudiantes
void Biblioteca::mostrarEstudiantes() const {
    std::cout << "======================================= ESTUDIANTES =========================================\n\n";
    imprimirEncabezadoUsuarios(false);
    int index = 1;
    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i]->getCategoria() == "Estudiante") {
            std::cout << std::left
                      << std::setw(5)  << index++
                      << std::setw(24) << usuarios[i]->getNombre()
                      << std::setw(30) << usuarios[i]->getEmail()
                      << std::setw(15) << usuarios[i]->getFechaRegistro()
                      << std::setw(14) << usuarios[i]->getID()
                      << std::setw(10) << usuarios[i]->getCantidad()
                      << "\n";
        }
    }
}

// Muestra perfil de profesores
void Biblioteca::mostrarProfesores() const {
    std::cout << "======================================== PROFESORES =========================================\n\n";
    imprimirEncabezadoUsuarios(false);
    int index = 1;
    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i]->getCategoria() == "Profesor") {
            std::cout << std::left
                      << std::setw(5)  << index++
                      << std::setw(24) << usuarios[i]->getNombre()
                      << std::setw(30) << usuarios[i]->getEmail()
                      << std::setw(15) << usuarios[i]->getFechaRegistro()
                      << std::setw(14) << usuarios[i]->getID()
                      << std::setw(10) << usuarios[i]->getCantidad()
                      << "\n";
        }
    }
}

// Método para buscar un usuario por su id (matrícula o no. empleado)
Usuario* Biblioteca::buscarUsuarioPorID(const std::string& id) const {
    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i]->getID() == id) {
            return usuarios[i];
        }
    }
    return nullptr;
}

// Método para ver los préstamos de un usuario
void Biblioteca::mostrarPrestamosUsuario(const std::string &idUsuario, const Catalogo &cat) const {
    Usuario* usuario = buscarUsuarioPorID(idUsuario);
    
    if (!usuario) {
        std::cout << "Usuario con ID '" << idUsuario << "' no encontrado.\n";
        return;
    }
    usuario->mostrarPrestamos(cat);
}

// Método para registrar préstamos
void Biblioteca::prestarLibro(const std::string& idUsuario, const std::string& isbn, Catalogo &cat) {
    Usuario* usuario = buscarUsuarioPorID(idUsuario);
    if (!usuario) {
        std::cout << "Usuario no encontrado.\n";
        return;
    }
    usuario->registrarPrestamo(isbn, cat);
}

// Método para registrar devoluciones
void Biblioteca::devolverLibro(const std::string& idUsuario, const std::string& isbn, Catalogo &cat) {
    Usuario* usuario = buscarUsuarioPorID(idUsuario);
    if (!usuario) {
        std::cout << "Usuario no encontrado.\n";
        return;
    }
    usuario->removerPrestamo(isbn, cat);
}

// Método que muestra el catálogo completo
void Biblioteca::mostrarCatalogo() const {
    catalogo.mostrarCatalogo();
}

// Método que muestra sólo los libros disponibles
void Biblioteca::mostrarDisponibles() const {
    catalogo.mostrarDisponibles();
}

// Método que muestra los libros en préstamo
void Biblioteca::mostrarPrestados() const {
    catalogo.mostrarPrestados();
}

// Método que busca un libro por su titulo
void Biblioteca::buscarLibroPorTitulo(const std::string &titulo) const {
    catalogo.buscarPorTitulo(titulo);
}

// Método que busca un libro por su autor
void Biblioteca::buscarLibroPorAutor(const std::string &autor) const {
    catalogo.buscarPorAutor(autor);
}

// Método que busca un libro por su ISBN
void Biblioteca::buscarLibroPorISBN(const std::string &isbn) const {
    catalogo.buscarPorISBN(isbn);
}

// Método para agregar libro 
void Biblioteca::agregarLibro(const Libro &libro) {
    catalogo.agregarLibro(libro);
}

// Método para eliminar libro por posición (1-n)
void Biblioteca::eliminarLibroPorISBN(const std::string &isbn) {
    catalogo.eliminarLibroPorISBN(isbn);
}