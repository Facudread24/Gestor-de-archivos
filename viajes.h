#pragma once
const char archivoviajes[] = ("viajes.dat");
void menuViaje();
void altaViaje();
void listarPorIdViaje();
void listarViajes();
void bajaViaje();
viajes cargarViaje();
bool guardarViaje(viajes reg);
viajes leerRegistroV(int pos);
void mostrarViajes(viajes viaj);
int cantRegistroViaje();
int buscarID(int id);