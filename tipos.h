#pragma once
struct fecha
{
    int dia;
    int mes;
    int anio;
};



struct choferes
{
    char dni[10];
    char apellido[50];
    char nombre[50];
    fecha fechaIng;
    char cuit[20];
    int tipoRegistro;
    fecha fechaVen;
    char telefono[15];
    bool propietario;
    bool estado;

};

struct viajes
{
    int id;
    char dni[10];
    int idCliente;
    fecha viaje;
    int hora;
    float km;
    float importe;
    char patente[10];
    int calificacion;
    bool viajeEstado;
};
struct medico {
    int dni;
    char nombre[30];
    char apellido[30];
    char email[40];
    char telefono[20];
    int cargo, especialidad, localidad;
    bool estado;
};
struct hospital {
    int numero;
    int especialidad, region, anio;
    char nombre[45];
    int dniDirector;
    bool estado;
};
struct contrato {
    int dniMédico;
    int numeroHospital;
    int tipoContrato;
    fecha fecha_contrato;
    bool estado;
};
