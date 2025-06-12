#pragma once
#include "Usuario.h"
#include "Catalogo.h"

class Profesor : public Usuario {
private:
    std::string numeroEmpleado;
    std::string prestamos[10];  // Suponiendo que puede tener más préstamos que un estudiante
    int cantidadPrestamos;
public:
    // Constructor
    Profesor(const std::string &n = "N/A", const std::string &e = "N/A",
            const std::string &fr = "DD/MM/AAAA", const std::string &numEmp = "PR0000");

    // Setters y Getters
    void setNumeroEmpleado(const std::string &);
    std::string getNumeroEmpleado() const;
    int getCantidadPrestamos() const;
    std::string getID() const override; 
    std::string getCategoria() const override;
    int getCantidad() const override;
    
    // Métodos de estudiante para solicitar préstamos y devolver
    void mostrarPrestamos(const Catalogo&) const override;
    bool yaTienePrestado(const std::string&) const;
    void registrarPrestamo(const std::string&, Catalogo&) override;
    void removerPrestamo(const std::string&, Catalogo&) override;

    // Métodos para mostrar perfil de profesor
    std::string mostrarPerfil() const override;
    std::string mostrarPerfil(int) const override;
};