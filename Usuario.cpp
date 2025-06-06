// Usuario.cpp
#include <iostream>
#include <regex>
#include "Usuario.h"

// Constructor default y con parámetros
Usuario::Usuario(const std::string &n, const std::string &e, const std::string &fr) : nombre{n}{
    setEmail(e);
    setFechaRegistro(fr);
}

// Setters y Getters
void Usuario::setNombre(const std::string &n){
    nombre = n;
}

void Usuario::setEmail(const std::string &e){
    static const std::regex formato(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)"); // Formato usuario@dominio.com
    email = (std::regex_match(e, formato)) ? e : std::string{"usuario@dominio.com"};
}

void Usuario::setFechaRegistro(const std::string &fr){
    static const std::regex formato("^\\d{2}/\\d{2}/\\d{4}$");  // Se valida que el formato sea DD/MM/AAAA
    fechaRegistro = (std::regex_match(fr, formato))? fr : std::string{"DD/MM/AAAA"};
}

std::string Usuario::getNombre() const {return nombre;}
std::string Usuario::getEmail() const {return email;}
std::string Usuario::getFechaRegistro() const {return fechaRegistro;}