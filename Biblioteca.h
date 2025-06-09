#pragma once
#include "Catalogo.h"
#include "Estudiante.h"
#include "Profesor.h"

class Biblioteca {
private:
    Usuario* usuarios[1000];
    int cantidadUsuarios;
    Catalogo catalogo;

public:
    // Constructor y destructor
    Biblioteca();
    ~Biblioteca();

    // Getters
    Catalogo& getCatalogo();
    int getCantidadUsuarios() const;

    // Gestión de usuarios
    void imprimirEncabezadoUsuarios(bool) const;
    void agregarUsuario(Usuario*);
    void eliminarUsuarioPorID(const std::string& id);
    void mostrarUsuarios() const;
    void mostrarEstudiantes() const;
    void mostrarProfesores() const;
    Usuario* buscarUsuarioPorID(const std::string&) const;

    // Gestión de préstamos
    void mostrarPrestamosUsuario(const std::string&, const Catalogo&) const;
    void prestarLibro(const std::string&, const std::string&, Catalogo&);
    void devolverLibro(const std::string&, const std::string&, Catalogo&);

    // Gestión del catálogo
    void mostrarCatalogo() const;
    void mostrarDisponibles() const;
    void mostrarPrestados() const;
    void buscarLibroPorTitulo(const std::string&) const;
    void buscarLibroPorAutor(const std::string&) const;
    void buscarLibroPorISBN(const std::string&) const;
    void agregarLibro(const Libro&);
    void eliminarLibroPorISBN(const std::string&);
};