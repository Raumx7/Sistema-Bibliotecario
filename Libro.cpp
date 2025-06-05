// Libro.cpp
#include "Libro.h"
#include <random>
#include <sstream>
#include <iomanip>

// Función privada para generar un ISBN aleatorio de 13 dígitos
std::string Libro::generarISBN() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9);

    std::ostringstream oss;
    for (int i = 0; i < 13; ++i) {
        oss << dis(gen);
    }
    return oss.str();
}

// Constructor sin parámetros
Libro::Libro() : Libro{"N/A","N/A","0000000000",false} {}

// Constructor con parámetros
Libro::Libro(const std::string &t, const std::string &a, const std::string &i, bool d)
    : titulo{t}, autor{a}, disponible{d} {
    setISBN(i); 
}

std::string Libro::getTitulo() const { return titulo; }
std::string Libro::getAutor() const { return autor; }
std::string Libro::getISBN() const { return isbn; }
bool Libro::estaDisponible() const { return disponible; }

void Libro::setTitulo(const std::string &t) { titulo = t; }
void Libro::setAutor(const std::string &a) { autor = a; }

void Libro::setISBN(const std::string &i) {
    if (i.length() >= 10 && i.length() <= 13) {
        isbn = i;
    } else {
        isbn = generarISBN();
        std::cout << "ISBN invalido para \"" << titulo << "\"" << std::endl
                    << "Se ha asignado el siguiente ISBN: " << isbn << std::endl;
    }
}

void Libro::marcarDisponible() { disponible = true; }
void Libro::marcarPrestado() { disponible = false; }

std::string Libro::mostrar() const {
    std::ostringstream oss;
    oss << "Título: " << titulo << "\n"
        << "Autor: " << autor << "\n"
        << "ISBN: " << isbn << "\n"
        << "Disponible: " << (disponible ? "Si" : "No") << "\n";
    return oss.str();
}

std::string Libro::mostrar(int indice) const {
    std::ostringstream oss;

    oss << std::left
        << std::setw(5) << indice
        << std::setw(35) << titulo
        << std::setw(25) << autor
        << std::setw(15) << isbn
        << std::setw(12) << (disponible ? "Si" : "No")
        << std::endl;

    return oss.str();
}