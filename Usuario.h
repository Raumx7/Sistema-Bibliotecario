// Usuario.h
#pragma once
#include <string>

class Catalogo;

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
    virtual std::string getID() const = 0;
    virtual std::string getCategoria() const = 0;
    virtual int getCantidad() const = 0;

    // Metodos de Usuario
    virtual void mostrarPrestamos(const Catalogo&) const = 0;
    virtual void registrarPrestamo(const std::string&, Catalogo&) = 0;
    virtual void removerPrestamo(const std::string&, Catalogo&) = 0;
    virtual std::string mostrarPerfil() const = 0;
    virtual std::string mostrarPerfil(int) const = 0;
    virtual ~Usuario() = default;
};