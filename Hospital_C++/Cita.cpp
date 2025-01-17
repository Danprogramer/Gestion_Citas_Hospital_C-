#include "Cita.h"

Cita::Cita(int idCita, int idMedico, const std::string& fecha, bool disponible)
    : idCita(idCita), idMedico(idMedico), fecha(fecha), disponible(disponible)
{
}

int Cita::getIdCita() const {
    return idCita;
}

int Cita::getIdMedico() const {
    return idMedico;
}

std::string Cita::getFecha() const {
    return fecha;
}

bool Cita::isDisponible() const {
    return disponible;
}

void Cita::setDisponible(bool disp) {
    disponible = disp;
}
