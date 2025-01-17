#ifndef MEDICO_H
#define MEDICO_H

#include <string>

class Medico {
private:
    int id;                
    std::string nombre;    
    std::string especialidad;

public:
    
    Medico() = default;
    Medico(int id, const std::string& nombre, const std::string& especialidad);

    
    int getId() const;
    std::string getNombre() const;
    std::string getEspecialidad() const;

    
    void setNombre(const std::string& nom);
    void setEspecialidad(const std::string& esp);
};

#endif 
