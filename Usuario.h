// Usuario.h
#pragma once
#include <string>

class Usuario {
protected:
    std::string nombre;
    std::string email;
    std::string fechaRegistro;
public:
    // Constructor default y con parámetros
    Usuario(const std::string &n = "N/A", const std::string &e = "N/A", const std::string &fr = "DD/MM/AAAA");

    // Setters y Getters
    void setNombre(const std::string&);
    void setEmail(const std::string&);
    void setFechaRegistro(const std::string&);

    std::string getNombre() const;
    std::string getEmail() const;
    std::string getFechaRegistro() const;

    // Metodos de Usuario
    virtual void mostrarPerfil() const = 0;
    virtual ~Usuario() = default;
};