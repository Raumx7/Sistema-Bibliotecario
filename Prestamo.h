#pragma once

class Prestamo {
private:
    int idLibro;
public:
    Prestamo(int idL = 0) : idLibro{idL}{}

    // Solo getter para libro, no se debe modificar el id desde aquí
    int getIdLibro() const {return idLibro;}
};