#include "Hospital_C++.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class Cita{
private:
    int idCita;
    int idPaciente;
    int idMedico;
    string fecha;
    bool esUrgente;

public:
    Cita(int idCita, int idPaciente, int idMedico, const string& fecha, bool esUrgente) : idCita(idCita), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), esUrgente(esUrgente){
    }

    int getId() const {return idCita;}
    string getFecha() const {return fecha;}
    bool getUrgencia() const {return esUrgente;}
};


class Paciente{
private:
    int id;
    string nombre;
    string fechaIngreso;
    string historialClinico;
    vector<weak_ptr<Cita>> citas;

public:
    Paciente(int id, const string& nombre, const string& fechaIngreso)
        : id(id), nombre(nombre), fechaIngreso(fechaIngreso){
    }

    void registrarHistorial(const string& historial){
        historialClinico += historial + "\n";
    }

    void agregarCita(shared_ptr<Cita> cita){
        citas.push_back(cita);
    }

    void eliminarCita(int idCita){
        auto it = remove_if(citas.begin(), citas.end(), [idCita](weak_ptr<Cita> citaPtr){
            if (auto cita = citaPtr.lock()){
                return cita->getId() == idCita;
            }
            return false;
            });
        if (it != citas.end()){
            citas.erase(it, citas.end());
            cout << "Cita con ID " << idCita << " Eliminada exitosamente." << endl;
        }
        else {
            cout << "Cita con ID " << idCita << " No encontrada." << endl;
        }
    }

    int getId() const {return id;}
    string getNombre() const {return nombre;}
};


class Medico{
private:
    int id;
    string nombre;
    string especialidad;
    bool disponibilidad;

public:
    Medico(int id, const string& nombre, const string& especialidad)
        : id(id), nombre(nombre), especialidad(especialidad), disponibilidad(true){
    }

    void setDisponibilidad(bool disponible) {disponibilidad = disponible;}
    bool estaDisponible() const {return disponibilidad;}

    int getId() const {return id;}
    string getNombre() const {return nombre;}
};








    
int main(int argc, char* argv[]){

        if (argc < 2) {
            cerr << "Uso: " << argv[0] << " <modo> <opciones>\n";
            cerr << "Modos disponibles:\n";
            cerr << "  agregar: Agrega una nueva cita.\n";
            cerr << "  eliminar <ID>: Elimina una cita existente por su ID.\n";
            cerr << "  consultar: Genera un archivo con el listado de citas ordenadas por fecha.\n";
            return 1;
        }

        string modo = argv[1];

        shared_ptr<Paciente> paciente = make_shared<Paciente>(1, "Juan Perez", "2023-01-01");
        shared_ptr<Medico> medico = make_shared<Medico>(1, "Dr. Gomez", "Cardiologia");

        if (modo == "agregar"){
            cout << "Ejecutando modo: Agregar cita." << endl;
            shared_ptr<Cita> cita = make_shared<Cita>(1, paciente->getId(), medico->getId(), "2023-12-10", false);
            paciente->agregarCita(cita);
            cout << "Cita agregada exitosamente." << endl;
        }
        else if (modo == "eliminar"){
            if (argc < 3){
                cerr << "Debe especificar el ID de la cita a eliminar." << endl;
                return 1;
            }
            int idCita = stoi(argv[2]);
            cout << "Ejecutando modo: Eliminar cita con ID " << idCita << endl;
            paciente->eliminarCita(idCita);
        }
        else if (modo == "consultar"){
            cout << "Ejecutando modo: Consultar citas." << endl;
            ofstream archivo("citas.txt");
            if (!archivo.is_open()){
                cerr << "Error al abrir el archivo para escribir." << endl;
                return 1;
            }

            vector<shared_ptr<Cita>> citas; // Simulando el listado de citas del paciente
            citas.push_back(make_shared<Cita>(1, paciente->getId(), medico->getId(), "2023-12-10", false));
            citas.push_back(make_shared<Cita>(2, paciente->getId(), medico->getId(), "2023-12-05", true));

            sort(citas.begin(), citas.end(), [](shared_ptr<Cita> a, shared_ptr<Cita> b){
                return a->getFecha() < b->getFecha();
                });

            for (const auto& cita : citas){
                archivo << "Cita ID: " << cita->getId() << ", Fecha: " << cita->getFecha() << ", Urgente: " << (cita->getUrgencia() ? "Sí" : "No") << endl;
            }

            archivo.close();
            cout << "Listado de citas guardado en 'citas.txt'." << endl;
        }
        else{
            cerr << "Modo no reconocido. Use: agregar, eliminar o consultar." << endl;
            return 1;
        }

        return 0;
}
