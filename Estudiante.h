#pragma once
#include "Usuario.h"
#include "Prestamo.h"

class Estudiante : public Usuario {
private:
    std::string matricula;
    Prestamo prestamos[5];
    int cantidadPrestamos;
public:
    // Constructor
    Estudiante(const std::string &n = "N/A", const std::string &e = "N/A",
               const std::string &fr = "DD/MM/AAAA", const std::string &mat = "Al0000");

    // Setters y Getters
    void setMatricula(const std::string&);
    std::string getMatricula() const;
    int getCantidadPrestamos() const;

    // Métodos de estudiante para solicitar préstamos y devolver
    void solicitarPrestamo(int idLibro);
    void devolverLibro(int idLibro);
};
