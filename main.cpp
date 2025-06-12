#include <iostream>
#include <cstdlib>
#include "Biblioteca.h"
using namespace std;

// Función para limpiar la consola
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Linux y Mac
    #endif
}

// Función para pausar el programa
void pausar() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore(100 , '\n');
}

int main() {
    Biblioteca biblioteca;  // Creamos una biblioteca
    int opcion;
    limpiarPantalla();

    // Opciones del menu
    do {
        cout << "========= MENU BIBLIOTECA =========\n";
        cout << "1.  Consultar catalogo\n";
        cout << "2.  Consultar libros disponibles\n";
        cout << "3.  Consultar libros prestados\n";
        cout << "4.  Buscar libro por titulo\n";
        cout << "5.  Buscar libro por autor\n";
        cout << "6.  Buscar libro por ISBN\n";
        cout << "7.  Agregar libro\n";
        cout << "8.  Eliminar libro\n";
        cout << "9.  Mostrar usuarios\n";
        cout << "10. Mostrar estudiantes\n";
        cout << "11. Mostrar profesores\n";
        cout << "12. Buscar usuario\n";
        cout << "13. Mostrar prestamos de un usuario\n";
        cout << "14. Registrar prestamo\n";
        cout << "15. Registrar devolucion\n";
        cout << "16. Agregar usuario\n";
        cout << "17. Eliminar usuario\n";
        cout << "18. Salir\n";
        cout << "Seleccione una opcion (1-18): ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

        string entrada, isbn, id;

        switch (opcion) {
            case 1:
                limpiarPantalla();
                biblioteca.mostrarCatalogo();  // Muestra el catalogo
                pausar();
                limpiarPantalla();
                break;
            case 2:
                limpiarPantalla();
                biblioteca.mostrarDisponibles();  // Filtra los libros disponibles
                pausar();
                limpiarPantalla();
                break;
            case 3:
                limpiarPantalla();
                biblioteca.mostrarPrestados();  // Filtra los libros prestados
                pausar();
                limpiarPantalla();
                break;
            case 4:
                limpiarPantalla();
                cout << "\nIngrese el titulo: ";
                getline(cin, entrada);
                biblioteca.buscarLibroPorTitulo(entrada);  // Busca por titulo
                pausar();
                limpiarPantalla();
                break;
            case 5:
                limpiarPantalla();
                cout << "Ingrese el autor: ";
                getline(cin, entrada);
                biblioteca.buscarLibroPorAutor(entrada);  // Busca por autor
                pausar();
                limpiarPantalla();
                break;
            case 6:
                limpiarPantalla();
                cout << "Ingrese el ISBN: ";
                getline(cin, entrada);
                biblioteca.buscarLibroPorISBN(entrada);  // Busca por ISBN
                pausar();
                limpiarPantalla();
                break;
            case 7: {
                limpiarPantalla();
                string titulo, autor;
                cout << "Titulo: ";
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);
                cout << endl;
                Libro nuevo{titulo, autor, true};  // Crea libro
                biblioteca.agregarLibro(nuevo);  // Añade el libro al catálogo
                pausar();
                limpiarPantalla();
                break;
            }
            case 8:
                limpiarPantalla();
                cout << "Ingrese el ISBN del libro a eliminar: ";
                getline(cin, isbn);
                biblioteca.eliminarLibroPorISBN(isbn);  // Elimina un libro por ISBN
                pausar();
                limpiarPantalla();
                break;
            case 9:
                limpiarPantalla();
                biblioteca.mostrarUsuarios();  // Muestra todos los usuarios
                pausar();
                limpiarPantalla();
                break;
            case 10:
                limpiarPantalla();
                biblioteca.mostrarEstudiantes();  // Filtra por estudiantes
                pausar();
                limpiarPantalla();
                break;
            case 11:
                limpiarPantalla();
                biblioteca.mostrarProfesores();  // Filtra por profesores
                pausar();
                limpiarPantalla();
                break;
            case 12:
                limpiarPantalla();
                cout << "Ingrese el ID del usuario: ";
                getline(cin, id);
                if (Usuario* u = biblioteca.buscarUsuarioPorID(id)) {
                    cout << "\n" << u->mostrarPerfil() << "\n";  // Muestra perfil de un usuario si existe
                } else {
                    cout << "Usuario no encontrado.\n";
                }
                pausar();
                limpiarPantalla();
                break;
            case 13:
                limpiarPantalla();
                cout << "Ingrese el ID del usuario: ";
                getline(cin, id);
                biblioteca.mostrarPrestamosUsuario(id, biblioteca.getCatalogo());  // Muestra los préstamos de un usuario
                pausar();
                limpiarPantalla();
                break;
            case 14:
                limpiarPantalla();
                cout << "Ingrese ID del usuario: ";
                getline(cin, id);
                cout << "Ingrese ISBN del libro: ";
                getline(cin, isbn);
                biblioteca.prestarLibro(id, isbn, biblioteca.getCatalogo());  // Registra un préstamo
                pausar();
                limpiarPantalla();
                break;
            case 15:
                limpiarPantalla();
                cout << "Ingrese ID del usuario: ";
                getline(cin, id);
                cout << "Ingrese ISBN del libro a devolver: ";
                getline(cin, isbn);
                biblioteca.devolverLibro(id, isbn, biblioteca.getCatalogo());  // Registra una devolución
                pausar();
                limpiarPantalla();
                break;
            case 16: {
                limpiarPantalla();
                int op;
                string nombre, email,fecha;
                cout << "Seleccione la categoria del usuario:\n";
                cout << "1. Profesor\n2. Estudiante\n(1-2): ";  // Muestra opciones para registrar usuario
                cin >> op;
                cin.ignore();
                if(op < 1 || op > 2){
                    cout << "Opcion no valida" << endl;
                }
                else if(op == 1){
                    limpiarPantalla();
                    cout << "Ingrese el nombre: ";
                    getline(cin, nombre);
                    cout << "Ingrese el email: (usuario@dominio.com): ";
                    getline(cin, email);
                    cout << "Ingrese la fecha actual (DD/MM/AAAA): ";
                    getline(cin, fecha);
                    cout << "Ingrese el numero de empleado: (PR0000): ";
                    getline(cin, id);
                    Usuario* nuevo = new Profesor{nombre, email, fecha, id};  // Opción 1 registra profesor
                    biblioteca.agregarUsuario(nuevo);
                }
                else{
                    limpiarPantalla();
                    cout << "Ingrese el nombre: ";
                    getline(cin, nombre);
                    cout << "Ingrese el email: (usuario@dominio.com): ";
                    getline(cin, email);
                    cout << "Ingrese la fecha de registro (DD/MM/AAAA): ";
                    getline(cin, fecha);
                    cout << "Ingrese la matricula: (Al0000): ";
                    getline(cin, id);
                    Usuario* nuevo = new Estudiante{nombre, email, fecha, id};  // Opción 2 registra estudiante
                    biblioteca.agregarUsuario(nuevo);
                }
                pausar();
                limpiarPantalla();
                break;
            }
            case 17:
                limpiarPantalla();
                cout << "Ingrese el ID del usuario a eliminar: ";
                getline(cin, id);
                biblioteca.eliminarUsuarioPorID(id);  // Elimina usuario si no tiene libros en préstamo
                pausar();
                limpiarPantalla();
                break;
            case 18:
                limpiarPantalla();
                cout << "Saliendo del programa...\n";  // Opción para salir del programa
                break;
            default:
                limpiarPantalla();
                cout << "Opcion invalida. Intente de nuevo.\n";  // Muestra mensaje de error
                pausar();
                limpiarPantalla();
        }

    } while (opcion != 18);

    return 0;
}