// Profesor.h
#pragma once
#include "Usuario.h"
#include "Catalogo.h"

class Profesor : public Usuario {
private:
    int numeroEmpleado;
    std::string prestamos[10];  // Suponiendo que puede tener más préstamos que un estudiante
    int cantidadPrestamos;
public:
    Profesor(const std::string &n = "N/A", const std::string &e = "N/A",
             const std::string &fr = "DD/MM/AAAA", int numEmp = 0);

    void setNumeroEmpleado(int);
    int getNumeroEmpleado() const;
    int getCantidadPrestamos() const;
    std::string getCategoria() const override;

    void registrarPrestamo(const std::string&, Catalogo&) override;
    void removerPrestamo(const std::string&, Catalogo&) override;

    std::string mostrarPerfil() const override;
    std::string mostrarPerfil(int) const override;
};