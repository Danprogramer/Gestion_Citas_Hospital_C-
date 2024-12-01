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
    vector<shared_ptr<Cita>> citas;

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

    void eliminarCita(int idCita);

    int getId() const { return id; }
    string getNombre() const { return nombre; }
};

int main()
{
	
}
