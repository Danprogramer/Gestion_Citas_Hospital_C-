
#ifndef CITA_H
#define CITA_H

#include <string>

class Cita {
private:
    int idCita;
    int idMedico;
    std::string fecha;
    bool disponible;

public:
    Cita() = default;
    Cita(int idCita, int idMedico, const std::string& fecha, bool disponible);

    int getIdCita() const;
    int getIdMedico() const;
    std::string getFecha() const;
    bool isDisponible() const;

    void setDisponible(bool disp);
};

#endif 
