#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>
#include <limits>


Sistema::Sistema() {

    cargarPacientesCSV("Pacientes.csv");
    cargarMedicosCSV("Medicos.csv");
    cargarCitasCSV("Citas.csv");

    medicos.push_back(Medico(1, "Dr. Rodrigo Gonzalez", "Cardiologia"));
    medicos.push_back(Medico(2, "Dr. Miguel Gomez", "Neumologia"));
    medicos.push_back(Medico(3, "Dr. Juan Ortega", "Dermatologia"));
    medicos.push_back(Medico(4, "Dr. Alex Perez", "Pediatria"));
    medicos.push_back(Medico(5, "Dr. Oscar Suarez", "Traumatologia"));
}

//================= Carga y guarda de CSV =================

void Sistema::cargarPacientesCSV(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir " << ruta << " para lectura." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        std::string nombre, apellidos, dni, nss;

        if (std::getline(ss, nombre, ',') &&
            std::getline(ss, apellidos, ',') &&
            std::getline(ss, dni, ',') &&
            std::getline(ss, nss, ','))
        {
            Paciente p(nombre, apellidos, dni, nss);
            pacientes.push_back(p);
        }
    }
    archivo.close();
}

void Sistema::guardarPacientesCSV(const std::string& ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir " << ruta << " para escritura." << std::endl;
        return;
    }

    for (const auto& p : pacientes) {
        archivo << p.getNombre() << ","
            << p.getApellidos() << ","
            << p.getDNI() << ","
            << p.getNSS() << "\n";
    }
    archivo.close();
}

void Sistema::cargarMedicosCSV(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir " << ruta << " para lectura." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        int id;
        std::string nom, especialidad;

        if (ss >> id) {
            if (std::getline(ss, nom, ',') &&
                std::getline(ss, especialidad, ',')){
            }
        }
    }
    archivo.close();
}

void Sistema::guardarMedicosCSV(const std::string& ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir " << ruta << " para escritura." << std::endl;
        return;
    }
    for (auto& m : medicos) {
        archivo << m.getId() << ","
            << m.getNombre() << ","
            << m.getEspecialidad() << "\n";
    }
    archivo.close();
}

void Sistema::cargarCitasCSV(const std::string& ruta) {

    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir " << ruta << " para lectura." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        int idCita, idMed;
        std::string fecha;
        bool disp;
    }
    archivo.close();
}

void Sistema::guardarCitasCSV(const std::string& ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir " << ruta << " para escritura." << std::endl;
        return;
    }

    for (auto& c : citas) {
        archivo << c.getIdCita() << ","
            << c.getIdMedico() << ","
            << c.getFecha() << ","
            << (c.isDisponible() ? 1 : 0) << "\n";
    }
    archivo.close();
}

//================= Operaciones sobre Pacientes =================

void Sistema::registrarUsuario() {
    std::string nombre, apellidos, dni, nss;
    bool datosValidos = false;

    while (!datosValidos) {
        std::cout << "=== Registrar Usuario ===\n";
        std::cout << "Por favor, introduzca los datos en el siguiente formato:\n";
        std::cout << "Nombre (solo letras), Apellidos (solo letras), DNI (8 digitos y 1 letra), NSS (ejemplo: 1234567890)\n\n";


        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);

        std::cout << "Apellidos: ";
        std::getline(std::cin, apellidos);

        std::cout << "DNI (p.e. 12345678A): ";
        std::getline(std::cin, dni);

        std::cout << "NSS (solo numeros): ";
        std::getline(std::cin, nss);


        bool nombreOK = std::regex_match(nombre, std::regex("^[A-Za-z]+( [A-Za-z]+)*$"));
        bool apellidosOK = std::regex_match(apellidos, std::regex("^[A-Za-z]+( [A-Za-z]+)*$"));
        bool dniOK = std::regex_match(dni, std::regex("^\\d{8}[A-Za-z]$"));
        bool nssOK = std::regex_match(nss, std::regex("^\\d+$"));


        if (!nombreOK) {
            std::cout << "\n[ERROR] El nombre solo puede contener letras (y espacios intermedios opcionalmente).\n";
        }
        if (!apellidosOK) {
            std::cout << "\n[ERROR] Los apellidos solo pueden contener letras (y espacios intermedios opcionalmente).\n";
        }
        if (!dniOK) {
            std::cout << "\n[ERROR] El DNI debe tener 8 dígitos seguido de 1 letra, por ejemplo: 12345678A.\n";
        }
        if (!nssOK) {
            std::cout << "\n[ERROR] El NSS debe ser solo números.\n";
        }

        datosValidos = (nombreOK && apellidosOK && dniOK && nssOK);

        if (!datosValidos) {
            std::cout << "\nPor favor, vuelva a introducir los datos.\n\n";
        }
    }

    Paciente nuevo(nombre, apellidos, dni, nss);
    pacientes.push_back(nuevo);


    guardarPacientesCSV("Pacientes.csv");
    std::cout << "Usuario registrado correctamente y guardado en Pacientes.csv\n\n";
}

void Sistema::eliminarUsuario() {
    std::cout << "=== Eliminar Usuario ===\n";
    std::cout << "Ingrese DNI del usuario a eliminar: ";
    std::string dni;
    std::getline(std::cin, dni);

    auto it = std::remove_if(pacientes.begin(), pacientes.end(),
        [&dni](const Paciente& p) {
            return p.getDNI() == dni;
        });
    if (it != pacientes.end()) {
        pacientes.erase(it, pacientes.end());
        guardarPacientesCSV("Pacientes.csv");
        std::cout << "Usuario eliminado y cambios guardados.\n\n";
    }
    else {
        std::cout << "No se encontró un usuario con DNI " << dni << "\n\n";
    }
}

//================= Operaciones sobre Citas =================

void Sistema::consultarHorasDisponibles() {

    std::cout << "\n=== Consultar Citas ===\n";

    cargarCitasCSV("Citas.csv");

    if (citas.empty()) {
        std::cout << "No hay citas registradas.\n";
        return;
    }

    for (auto& c : citas) {
        int    idC = c.getIdCita();
        int    idMed = c.getIdMedico();
        std::string f = c.getFecha();
        bool   d = c.isDisponible();

        std::cout << "Cita ID: " << idC
            << " | Medico: " << idMed
            << " | Fecha/Hora: " << f
            << " | " << (d ? "[Libre]" : "[Ocupada]")
            << "\n";
    }
    std::cout << std::endl;
}

void Sistema::registrarCita() {
    bool datosValidos = false;

    while (!datosValidos) {
        std::cout << "=== Registrar Cita ===\n";
        std::cout << "Por favor, introduzca los datos en el siguiente formato:\n";
        std::cout << "ID del medico (1..5)\n";
        std::cout << "Fecha y hora en formato YYYY-MM-DD HH:MM (p.e. 2023-12-10 09:00)\n";

        int idCita;
        int idMed;
        std::string fecha;
        bool disp = false;

        std::string strIdMed;
        std::cout << "ID del medico: ";
        std::getline(std::cin, strIdMed);

        std::cout << "Fecha (YYYY-MM-DD HH:MM): ";
        std::getline(std::cin, fecha);

        bool medicoOK = true;
        try {
            idMed = std::stoi(strIdMed);
            if (idMed < 1 || idMed > 5) {
                medicoOK = false;
            }
        }
        catch (...) {
            medicoOK = false;
        }

        static const std::regex fechaRegex("^\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}$");
        bool fechaOK = std::regex_match(fecha, fechaRegex);


        if (!medicoOK) {
            std::cout << "\n[ERROR] El ID del medico debe ser un numero entre 1 y 5.\n";
        }
        if (!fechaOK) {
            std::cout << "\n[ERROR] La fecha/hora deben tener formato YYYY-MM-DD HH:MM.\n";
        }

        if (!medicoOK || !fechaOK) {
            std::cout << "\nPor favor, vuelva a introducir los datos.\n\n";
            continue;
        }

        bool horaDisponible = true;
        for (auto& c : citas) {
            if (c.getIdMedico() == idMed && c.getFecha() == fecha) {
                std::cout << "[ERROR] El medico " << idMed
                    << " ya tiene una cita el " << fecha << ".\n";
                horaDisponible = false;
                break;
            }
        }
        if (!horaDisponible) {
            std::cout << "Por favor, seleccione otra fecha/hora.\n\n";
            continue;
        }

        idCita = static_cast<int>(citas.size()) + 1;

        Cita nuevaCita(idCita, idMed, fecha, disp);
        citas.push_back(nuevaCita);

        guardarCitasCSV("Citas.csv");

        std::cout << "\nCita creada con exito:\n"
            << "  idCita = " << idCita << "\n"
            << "  idMed = " << idMed << "\n"
            << "  fecha = " << fecha << "\n"
            << "  disp  = " << (disp ? "Libre" : "Ocupada") << "\n\n";

        datosValidos = true;
    }
}

void Sistema::eliminarCita() {

    std::cout << "=== Eliminar Cita ===\n";
    std::cout << "Introduzca el ID de la cita a eliminar: ";

    std::string input;
    std::getline(std::cin, input);

    int idCitaABorrar = 0;

    try {
        idCitaABorrar = std::stoi(input);
    }
    catch (...) {
        std::cout << "[ERROR] El ID de la cita debe ser un numero entero.\n";
        return;
    }

    bool citaEncontrada = false;

    auto it = std::remove_if(citas.begin(), citas.end(),
        [idCitaABorrar](const Cita& c) {
            return c.getIdCita() == idCitaABorrar;
        }
    );

    if (it != citas.end()) {
        citaEncontrada = true;
        citas.erase(it, citas.end());
    }

    if (!citaEncontrada) {
        std::cout << "No se encontró ninguna cita con ID " << idCitaABorrar << ".\n";
    }
    else {
        guardarCitasCSV("Citas.csv");
        std::cout << "Cita con ID " << idCitaABorrar << " eliminada exitosamente.\n";
    }
}

//================= Menú Principal =================

void Sistema::menuPrincipal() {
    while (true) {
        std::cout << "======== MENU PRINCIPAL ========\n";
        std::cout << "1. Registrar usuario\n";
        std::cout << "2. Eliminar usuario\n";
        std::cout << "3. Mostrar medicos (predefinidos)\n";
        std::cout << "4. Consultar horas disponibles\n";
        std::cout << "5. Registrar una cita\n";
        std::cout << "6. Eliminar cita\n";
        std::cout << "7. Salir\n";
        std::cout << "Elija una opcion: ";

        int opcion;
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (opcion) {
        case 1:
            registrarUsuario();
            break;
        case 2:
            eliminarUsuario();
            break;
        case 3: {
            std::cout << "=== Lista de medicos ===\n";
            for (auto& m : medicos) {
                std::cout << m.getId() << " - " << m.getNombre()
                    << " (" << m.getEspecialidad() << ")\n";
            }
            std::cout << std::endl;
        } break;
        case 4:
            consultarHorasDisponibles();
            break;
        case 5:
            registrarCita();
            break;
        case 6:
            eliminarCita();
            break;
        case 7:
            std::cout << "Saliendo...\n";
            
            guardarPacientesCSV("Pacientes.csv");
            guardarCitasCSV("Citas.csv");
            guardarMedicosCSV("Medicos.csv");
            return;
        default:
            std::cout << "Opción inválida.\n\n";
            break;
        }
    }
}
