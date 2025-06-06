#include "Biblioteca.h"
#include <iostream>
#include <iomanip>

Biblioteca::Biblioteca() : cantidadUsuarios{0} {}

Biblioteca::~Biblioteca() {
    for (int i = 0; i < cantidadUsuarios; ++i) {
        delete usuarios[i];
    }
}

void encabezadoUsuarios(){
    std::cout << std::left
              << std::setw(5)  << "N°"
              << std::setw(30) << "Nombre"
              << std::setw(30) << "Email"
              << std::setw(15) << "Categoria"
              << "\n";
    std::cout << std::string(80, '-') << "\n";
}

void imprimirEncabezadoUsuarios(){
    std::cout << std::left
    << std::setw(5)  << "N°"
    << std::setw(30) << "Nombre"
    << std::setw(30) << "Email"
    << "\n";
std::cout << std::string(65, '-') << "\n";
}

void Biblioteca::agregarUsuario(Usuario* usuario) {
    if (cantidadUsuarios < 1000) {
        usuarios[cantidadUsuarios++] = usuario;
        std::cout << "Usuario agregado exitosamente.\n";
    } else {
        std::cout << "No se pueden agregar mas usuarios. Capacidad maxima alcanzada.\n";
    }
}

void Biblioteca::mostrarUsuarios() const {
    std::cout << "Usuarios:\n";
    encabezadoUsuarios();
    for (int i = 0; i < cantidadUsuarios; ++i) {
        std::cout << usuarios[i]->mostrarPerfil(i + 1) << "\n";
    }
}

void Biblioteca::mostrarEstudiantes() const {
    std::cout << "\nEstudiantes:\n";
    imprimirEncabezadoUsuarios();
    int index = 1;
    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i]->getCategoria() == "Estudiante") {
            std::cout << std::left
                      << std::setw(5)  << index++
                      << std::setw(30) << usuarios[i]->getNombre()
                      << std::setw(30) << usuarios[i]->getEmail()
                      << "\n";
        }
    }
}

void Biblioteca::mostrarProfesores() const {
    std::cout << "\nProfesores:\n";
    imprimirEncabezadoUsuarios();
    int index = 1;
    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i]->getCategoria() == "Profesor") {
            std::cout << std::left
                      << std::setw(5)  << index++
                      << std::setw(30) << usuarios[i]->getNombre()
                      << std::setw(30) << usuarios[i]->getEmail()
                      << "\n";
        }
    }
}

Usuario* Biblioteca::buscarUsuarioPorNombre(const std::string& nombre) const {
    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i]->getNombre() == nombre) {
            return usuarios[i];
        }
    }
    return nullptr;
}

void Biblioteca::prestarLibro(const std::string& nombreUsuario, const std::string& isbn, Catalogo &cat) {
    Usuario* usuario = buscarUsuarioPorNombre(nombreUsuario);
    if (!usuario) {
        std::cout << "Usuario no encontrado.\n";
        return;
    }
    usuario->registrarPrestamo(isbn,cat);
}

void Biblioteca::devolverLibro(const std::string& nombreUsuario, const std::string& isbn, Catalogo &cat){
    Usuario* usuario = buscarUsuarioPorNombre(nombreUsuario);
    if (!usuario) {
        std::cout << "Usuario no encontrado.\n";
        return;
    }
    usuario->removerPrestamo(isbn,cat);
}

// Métodos del catálogo
void Biblioteca::mostrarCatalogo() const {
    catalogo.mostrarCatalogo();
}

void Biblioteca::mostrarDisponibles() const {
    catalogo.mostrarDisponibles();
}

void Biblioteca::mostrarPrestados() const {
    catalogo.mostrarPrestados();
}

void Biblioteca::buscarLibroPorTitulo(const std::string &titulo) const {
    catalogo.buscarPorTitulo(titulo);
}

void Biblioteca::buscarLibroPorAutor(const std::string &autor) const {
    catalogo.buscarPorAutor(autor);
}

void Biblioteca::buscarLibroPorISBN(const std::string &isbn) const {
    catalogo.buscarPorISBN(isbn);
}

void Biblioteca::agregarLibro(const Libro &libro) {
    catalogo.agregarLibro(libro);
}

void Biblioteca::eliminarLibro(int posicion) {
    catalogo.eliminarLibro(posicion);
}