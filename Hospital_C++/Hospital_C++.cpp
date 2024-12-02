#include "Hospital_C++.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Cita {
private:
    int idCita;
    int idPaciente;
    int idMedico;
    string fecha;
    bool esUrgente;

public:
    Cita(int idCita, int idPaciente, int idMedico, const string& fecha, bool esUrgente)
        : idCita(idCita), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), esUrgente(esUrgente) {
    }

    int getId() const { return idCita; }
    string getFecha() const { return fecha; }
    bool getUrgencia() const { return esUrgente; }
};


class Paciente {
private:
    int id;
    string nombre;
    string fechaIngreso;
    string historialClinico;
    vector<weak_ptr<Cita>> citas;

public:
    Paciente(int id, const string& nombre, const string& fechaIngreso)
        : id(id), nombre(nombre), fechaIngreso(fechaIngreso) {
    }

    void registrarHistorial(const string& historial) {
        historialClinico += historial + "\n";
    }

    void agregarCita(shared_ptr<Cita> cita) {
        citas.push_back(cita);
    }

    void eliminarCita(int idCita) {
        auto it = remove_if(citas.begin(), citas.end(), [idCita](weak_ptr<Cita> citaPtr) {
            if (auto cita = citaPtr.lock()) {
                return cita->getId() == idCita;
            }
            return false;
            });
        if (it != citas.end()) {
            citas.erase(it, citas.end());
            cout << "Cita con ID " << idCita << " Eliminada exitosamente." << endl;
        }
        else {
            cout << "Cita con ID " << idCita << " No encontrada." << endl;
        }
    }

    int getId() const { return id; }
    string getNombre() const { return nombre; }
};


class Medico {
private:
    int id;
    string nombre;
    string especialidad;
    bool disponibilidad;

public:
    Medico(int id, const string& nombre, const string& especialidad)
        : id(id), nombre(nombre), especialidad(especialidad), disponibilidad(true) {
    }

    void setDisponibilidad(bool disponible) { disponibilidad = disponible; }
    bool estaDisponible() const { return disponibilidad; }

    int getId() const { return id; }
    string getNombre() const { return nombre; }
};







int main()
{
    shared_ptr<Paciente> paciente = make_shared<Paciente>(1, "Juan Perez", "2023-01-01");
    shared_ptr<Medico> medico = make_shared<Medico>(1, "Dr. Gomez", "Cardiologia");
    shared_ptr<Cita> cita = make_shared<Cita>(1, paciente->getId(), medico->getId(), "2023-12-10", false);

    paciente->agregarCita(cita);
    paciente->registrarHistorial("Paciente ingresado por chequeo de rutina.");
    paciente->eliminarCita(1);

    return 0;
}
