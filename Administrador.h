#pragma once
#include "Usuario.h"

class Administrador : public Usuario {
private:
    int numeroEmp;
public:
    // Constructor
    Administrador(const std::string &n = "N/A", const std::string &e = "N/A", 
        const std::string &fr = "DD/MM/AAAA", int noEmp = 0);
    
    // Setters y Getters
    void setNumeroEmp(int);
    int getNumeroEmp() const;

    // Metodos de Administrador
    void agregarLibro() const;
    void eliminarLibro() const;
    void registrarUsuario() const;
    void elmiminarUsuario() const;
    void consultarUsuarios() const;
    void consultarPrestamos() const;

    void mostrarPerfil() const override;
};