#pragma once
#include <iostream>
#include "Libro.h"

class Catalogo{
private:
    Libro libros[1000];
    int cantidad;
public:
    // Constructor
    Catalogo();

    // Getter para la obtener la cantidad de libros
    int getCantidadLibros() const;

    // Setters para marcar disponible un libro por su ISBN
    bool marcarDisponible(const std::string&);
    bool marcarPrestado(const std::string&);

    // Métodos de catálogo
    void imprimirEncabezado(bool) const;
    void buscarPorTitulo(const std::string&) const;
    void buscarPorAutor(const std::string&) const;
    void buscarPorISBN(const std::string&) const;
    const Libro* buscarLibroPorISBN(const std::string& isbn) const;
    void mostrarCatalogo() const;
    void mostrarDisponibles() const;
    void mostrarPrestados() const;
    void agregarLibro(const Libro&);
    void eliminarLibroPorISBN(const std::string&);
};