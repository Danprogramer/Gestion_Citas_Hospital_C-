#include "Medico.h"

// Constructor
Medico::Medico(int id, const std::string& nombre, const std::string& especialidad)
    : id(id), nombre(nombre), especialidad(especialidad)
{
}

// Getters
int Medico::getId() const {
    return id;
}

std::string Medico::getNombre() const {
    return nombre;
}

std::string Medico::getEspecialidad() const {
    return especialidad;
}

// Setters
void Medico::setNombre(const std::string& nom) {
    nombre = nom;
}

void Medico::setEspecialidad(const std::string& esp) {
    especialidad = esp;
}
