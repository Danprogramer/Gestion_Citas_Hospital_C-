#include <iostream>

#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

class Paciente {
private:
    std::string nombre;
    std::string apellidos;
    std::string dni;
    std::string numeroSeguridadSocial;

public:
    
    Paciente() = default;
    Paciente(const std::string& nombre,
        const std::string& apellidos,
        const std::string& dni,
        const std::string& nss);

    
    std::string getNombre() const;
    std::string getApellidos() const;
    std::string getDNI() const;
    std::string getNSS() const;

    
    void setNombre(const std::string& nom);
    void setApellidos(const std::string& ape);
    void setDNI(const std::string& dni);
    void setNSS(const std::string& nss);
};

#endif

