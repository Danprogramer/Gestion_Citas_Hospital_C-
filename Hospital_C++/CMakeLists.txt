﻿# CMakeList.txt: proyecto de CMake para Hospital_C++, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (Hospital_C++ "Hospital_C++.cpp" "Hospital_C++.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Hospital_C++ PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
