#pragma once
#include "tipos.h"
const char archivoChoferes[] = ("choferes.dat");
void menuChoferes();
void altaChofer();
bool guardarChofer(choferes chof);
choferes cargarChofer();
choferes leerRegistro(int pos);
int buscarDni(char *chof);
int buscarCuit(char* chof);
void listarChoferes();
void mostrarChoferes (choferes chof);
int cantRegistro();
void bajaChofer();
void modificarchofer();
void listarPorDni();
bool guardar(choferes chof, int pos); 