// Libro.h
#pragma once
#include <iostream>
#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    bool disponible;

    std::string generarISBN();

public:
    // Constructores
    Libro();
    Libro(const std::string&, const std::string&, const std::string&, bool);

    // Getters
    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getISBN() const;
    bool estaDisponible() const;

    // Setters
    void setTitulo(const std::string&);
    void setAutor(const std::string&);
    void setISBN(const std::string&);
    void marcarDisponible();
    void marcarPrestado();

    // Metodos de Libro
    std::string mostrar() const;
    std::string mostrar(int indice) const;
};