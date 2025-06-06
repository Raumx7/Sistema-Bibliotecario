// Estudiante.h
#pragma once
#include "Usuario.h"
#include "Catalogo.h"

class Estudiante : public Usuario {
private:
    std::string matricula;
    std::string prestamos[5];
    int cantidadPrestamos;
public:
    // Constructor
    Estudiante(const std::string &n = "N/A", const std::string &e = "N/A",
               const std::string &fr = "DD/MM/AAAA", const std::string &mat = "Al0000");

    // Setters y Getters
    void setMatricula(const std::string&);
    std::string getMatricula() const;
    int getCantidadPrestamos() const;
    std::string getCategoria() const override;

    // Métodos de estudiante para solicitar préstamos y devolver
    void registrarPrestamo(const std::string&, Catalogo&) override;
    void removerPrestamo(const std::string&, Catalogo&) override;

    std::string mostrarPerfil() const override;
    std::string mostrarPerfil(int) const override;
};