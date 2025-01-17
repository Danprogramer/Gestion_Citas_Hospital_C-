#include "Paciente.h"


Paciente::Paciente(const std::string& nombre,
    const std::string& apellidos,
    const std::string& dni,
    const std::string& nss)
    : nombre(nombre), apellidos(apellidos), dni(dni), numeroSeguridadSocial(nss)
{
}


std::string Paciente::getNombre() const {
    return nombre;
}

std::string Paciente::getApellidos() const {
    return apellidos;
}

std::string Paciente::getDNI() const {
    return dni;
}

std::string Paciente::getNSS() const {
    return numeroSeguridadSocial;
}


void Paciente::setNombre(const std::string& nom) {
    nombre = nom;
}

void Paciente::setApellidos(const std::string& ape) {
    apellidos = ape;
}

void Paciente::setDNI(const std::string& d) {
    dni = d;
}

void Paciente::setNSS(const std::string& nss) {
    numeroSeguridadSocial = nss;
}
