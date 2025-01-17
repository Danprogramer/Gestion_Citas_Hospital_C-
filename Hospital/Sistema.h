#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

// El Sistema centraliza la gesti�n de:
// - Pacientes (Pacientes.csv)
// - M�dicos (Medicos.csv) (5 predefinidos)
// - Citas (Citas.csv)

class Sistema {
private:
    std::vector<Paciente> pacientes;
    std::vector<Medico> medicos;
    std::vector<Cita> citas;

public:
    Sistema();

    // Carga y guarda de archivos CSV
    void cargarPacientesCSV(const std::string& ruta);
    void guardarPacientesCSV(const std::string& ruta);

    void cargarMedicosCSV(const std::string& ruta);
    void guardarMedicosCSV(const std::string& ruta);

    void cargarCitasCSV(const std::string& ruta);
    void guardarCitasCSV(const std::string& ruta);

    // Operaciones sobre Pacientes
    void registrarUsuario();   // Pide datos por consola
    void eliminarUsuario();    // Pide DNI (o NSS) y elimina

    // Operaciones sobre Citas
    void consultarHorasDisponibles();
    void registrarCita();
    void eliminarCita();

    // M�todos de acceso a vectores, si necesitas
    const std::vector<Paciente>& getPacientes() const { return pacientes; }
    const std::vector<Medico>& getMedicos() const { return medicos; }
    const std::vector<Cita>& getCitas() const { return citas; }

    // Men� principal
    void menuPrincipal();
};

#endif
