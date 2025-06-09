#pragma once
#include <iostream>
#include "Libro.h"

class Catalogo{
private:
    Libro libros[1000];
    int cantidad;
public:
    Catalogo();

    int getCantidadLibros() const;

    bool marcarDisponible(const std::string&);
    bool marcarPrestado(const std::string&);

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