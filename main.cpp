#include <iostream>
#include "Biblioteca.h"
using namespace std;

int main() {

    Biblioteca biblioteca;

    // Creamos profesores
    Usuario* u1 = new Profesor{"Juan Rodriguez","juan@edu.mx","23/01/2020",3400};

    // Creamos estudiantes
    Usuario* u2 = new Estudiante{"Raul Chavez","raul@gmail.com","05/06/25","Al0000"};
    Usuario* u3 = new Estudiante{"Carlos Quintana","carlos@gmal.com","11/09/2019","Al2370"};

    biblioteca.agregarUsuario(u1);
    biblioteca.agregarUsuario(u2);
    biblioteca.agregarUsuario(u3);

    biblioteca.mostrarUsuarios();
    biblioteca.mostrarCatalogo();

    // No se requiere liberar memoria para u1, u2 ... el destructor de Biblioteca lo hace

    return 0;
}