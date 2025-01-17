


# Nombre del proyecto
project(Hospital VERSION 1.0)


add_executable(HospitalApp
    Main.cpp
    Paciente.cpp
    Medico.cpp
    Cita.cpp
    Sistema.cpp
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET HospitalApp PROPERTY CXX_STANDARD 20)
endif()
