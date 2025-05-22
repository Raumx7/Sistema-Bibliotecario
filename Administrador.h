#pragma once
#include "Usuario.h"

class Administrador : public Usuario {
private:
    int numeroEmp;
public:
    // Constructor
    Administrador(int noEmp = 0);
    
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
};