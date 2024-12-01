#include "Hospital_C++.h"
#include "iostream"
#include "vector"


using namespace std;

class Cita;

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
            cout << "Cita con ID " << idCita << " eliminada exitosamente." << endl;
        }
        else {
            cout << "Cita con ID " << idCita << " no encontrada." << endl;
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
	
}
