# Sistema Bibliotecario

Este proyecto está diseñado para representar el funcionamiento básico de una biblioteca escolar o local que aún no cuenta con un sistema digital de gestión. Permite administrar libros, usuarios (profesores y estudiantes), así como los préstamos y devoluciones que estos realizan.

---

## Funcionalidad

El programa permite las siguientes operaciones desde una interfaz en consola:

- Consultar el catálogo completo de libros
- Buscar libros por título, autor o ISBN
- Ver libros disponibles o prestados
- Registrar nuevos libros y eliminar libros existentes
- Registrar usuarios (profesores o estudiantes)
- Consultar información de usuarios y sus préstamos
- Realizar préstamos y devoluciones de libros

---

## Consideraciones

- Si se crean varios usuarios con datos incompletos o se ignoran validaciones, se llamará al **constructor por defecto**, lo cual puede generar usuarios con **el mismo ID**. Esto puede causar errores en operaciones como préstamos o búsquedas.
- El sistema corre **exclusivamente por consola** y está implementado en **C++ estándar**, por lo que es compatible con **Linux, Windows y macOS** si se compila adecuadamente.
- No utiliza bases de datos; todos los datos se almacenan en memoria mientras el programa se ejecuta.

---

## Compilación

### En Linux o macOS

```bash
g++ Usuario.cpp Profesor.cpp Estudiante.cpp Libro.cpp Catalogo.cpp Biblioteca.cpp main.cpp -o output/main
./output/main

g++ Usuario.cpp Profesor.cpp Estudiante.cpp Libro.cpp Catalogo.cpp Biblioteca.cpp main.cpp -o output.exe
output.exe
'''