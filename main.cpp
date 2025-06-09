#include <iostream>
#include "Biblioteca.h"
using namespace std;

int main() {
    Biblioteca biblioteca;
    int opcion;

    do {
        cout << "\n===== MENU BIBLIOTECA =====\n";
        cout << "1. Mostrar todos los libros\n";
        cout << "2. Mostrar libros disponibles\n";
        cout << "3. Mostrar libros prestados\n";
        cout << "4. Buscar libro por titulo\n";
        cout << "5. Buscar libro por autor\n";
        cout << "6. Buscar libro por ISBN\n";
        cout << "7. Agregar libro\n";
        cout << "8. Eliminar libro por ISBN\n";
        cout << "9. Mostrar todos los usuarios\n";
        cout << "10. Mostrar estudiantes\n";
        cout << "11. Mostrar profesores\n";
        cout << "12. Buscar usuario por ID\n";
        cout << "13. Mostrar prestamos de un usuario\n";
        cout << "14. Registrar prestamo\n";
        cout << "15. Devolver libro\n";
        cout << "16. Eliminar usuario por ID\n";
        cout << "17. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

        string entrada, isbn, id;

        switch (opcion) {
            case 1:
                biblioteca.mostrarCatalogo();
                break;
            case 2:
                biblioteca.mostrarDisponibles();
                break;
            case 3:
                biblioteca.mostrarPrestados();
                break;
            case 4:
                cout << "Ingrese el titulo: ";
                getline(cin, entrada);
                biblioteca.buscarLibroPorTitulo(entrada);
                break;
            case 5:
                cout << "Ingrese el autor: ";
                getline(cin, entrada);
                biblioteca.buscarLibroPorAutor(entrada);
                break;
            case 6:
                cout << "Ingrese el ISBN: ";
                getline(cin, entrada);
                biblioteca.buscarLibroPorISBN(entrada);
                break;
            case 7: {
                string titulo, autor, isbn;
                cout << "Titulo: ";
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);
                cout << "ISBN: ";
                getline(cin, isbn);
                Libro nuevo{titulo, autor, isbn, true};
                biblioteca.agregarLibro(nuevo);
                break;
            }
            case 8:
                cout << "Ingrese el ISBN del libro a eliminar: ";
                getline(cin, isbn);
                biblioteca.eliminarLibroPorISBN(isbn);
                break;
            case 9:
                biblioteca.mostrarUsuarios();
                break;
            case 10:
                biblioteca.mostrarEstudiantes();
                break;
            case 11:
                biblioteca.mostrarProfesores();
                break;
            case 12:
                cout << "Ingrese el ID del usuario: ";
                getline(cin, id);
                if (Usuario* u = biblioteca.buscarUsuarioPorID(id)) {
                    cout << u->mostrarPerfil() << "\n";
                } else {
                    cout << "Usuario no encontrado.\n";
                }
                break;
            case 13:
                cout << "Ingrese el ID del usuario: ";
                getline(cin, id);
                biblioteca.mostrarPrestamosUsuario(id, biblioteca.getCatalogo());
                break;
            case 14:
                cout << "Ingrese ID del usuario: ";
                getline(cin, id);
                cout << "Ingrese ISBN del libro: ";
                getline(cin, isbn);
                biblioteca.prestarLibro(id, isbn, biblioteca.getCatalogo());
                break;
            case 15:
                cout << "Ingrese ID del usuario: ";
                getline(cin, id);
                cout << "Ingrese ISBN del libro a devolver: ";
                getline(cin, isbn);
                biblioteca.devolverLibro(id, isbn, biblioteca.getCatalogo());
                break;
            case 16:
                cout << "Ingrese el ID del usuario a eliminar: ";
                getline(cin, id);
                biblioteca.eliminarUsuarioPorID(id);
                break;
            case 17:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 17);

    return 0;
}