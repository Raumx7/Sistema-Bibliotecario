#include "Usuario.h"
#include "Estudiante.h"
#include "Administrador.h"

int main() {

    Usuario *usuario2 = new Estudiante("Luis", "luis@mail.com", "02/02/2024", "Al1234");
    Usuario *usuario3 = new Administrador("Dr. Ramírez", "admin@uni.edu", "03/03/2022", 101);

    usuario2->mostrarPerfil();  // Estudiante
    usuario3->mostrarPerfil();  // Administrador

    delete usuario2;
    delete usuario3;
    return 0;
}
