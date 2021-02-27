#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "tipos.h"

using namespace std;

struct fecha {
    int dia, mes, anio;
};
struct musico {
    int dni;
    char nombreMusico[30];
    char apellidoMusico[30];
    char email[40];
    char telefono[20];
    int claustro, instrumento, tipoMusica;
    fecha fechaInscripcion;
    bool estado;
};
struct sesion {
    int numeroSesion;
    fecha fechaSesion;
    int horaInicio, horaFin;
    int instrumento;
    char url[45];
    int dniCoordinador;
    bool estado;
};
struct inscripcion {
    int dni;
    int numeroSesion;
    int tipoParticipacion;
    bool estado;
};
struct puntob
{
    int DNImúsico;
    char Nombre[30], apellido[30];
    int cantidadsesiones;
};
int cantidad_inscrip(int dni) {
    FILE* p;
    inscripcion reg;
    int cant=0;
    p = fopen("intrucciones.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    while (fread(&reg,sizeof(inscripcion),1,p)==1)
    {
        if (reg.dni==dni)
        {
            cant++;
        }
    }
    return cant;
}
for (int i = 0; i < cantidadregistto(); i++)
{
    reg = leerregistro(i);
    if (true)
    {

    }
}



void puntob2() {
    musico reg;
    puntob aux;
    int cant = 0;
    for (int i = 0; i < cantRegistro(); i++)
    {
        reg = leerRegistro(i);
        cant=cantidad_inscrip(reg.dni);

        if (cant > 0)
        {
            strcpy(aux.Nombre, reg.nombreMusico);
            strcpy(aux.apellido, reg.apellidoMusico);
            aux.cantidadsesiones = cant;
            if (grabar(aux) == true) {
                cout << "grabo";
            }
            else
            {
                cout << "no grabo";
            }
        }
    }

}
bool grabar(puntob aux) {
    FILE* p;
    bool grabo;
    p = fopen("puntob.dat", "ab");
    if (p==NULL)
    {
        return false;
    }
    grabo = fwrite(&aux, sizeof(puntob), 1, p);
    
    fclose(p);
    return grabo;
    
}
void puntoa() {
    sesion reg;
    int Instrumentos[16] = {};
    int cont = 0;
    int cant = cantRegistro();
    int pos = 0;
    
    for (int i = 0; i < cantRegistro(); i++)
    {
        reg = leerRegistro(i);

        if (reg.fechaSesion.mes == 8) {
        
            if (reg.instrumento != 0)
            {
                Instrumentos[reg.instrumento]++;
            }
            else
            {
                Instrumentos[0]++;
            }
    
        }
    }
    for (int i = 0; i < 16; i++)
    {
        cout << "cantidad de sesiones en el mes de agosto para el instrumento"<<i+1<< Instrumentos[i+1];
    }
    cout << "CANT SESIONES TODOS LOS instrumento" << Instrumentos[0];

}

int cantRegistro() {

    FILE* p;
    p = fopen("sesion.dat", "rb");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO" << endl;
        system("pause");
        system("cls");
        return -1;
    }
    int cant;
    choferes aux;
    fseek(p, 0, 2);
    //0 INICIO SEEK_SET
    //1 MITAD SEEL_CUT
    //2 FIN SEEK_END
    cant = ftell(p);
    fclose(p);

    return cant / sizeof(aux);
}
sesion leerRegistro(int pos) {

    FILE* p;
    p = fopen(archivoChoferes, "rb");
    choferes aux;
    fseek(p, pos * sizeof(aux), SEEK_SET);
    fread(&aux, sizeof(aux), 1, p);
    fclose(p);

    return aux;
}

bool leerRegistro2(int pos) {
    bool leyo;
    FILE* p;
    p = fopen("sesiones.dat", "rb");
    if (p==NULL)
    {
        return false;
    }
    sesion aux;
    fseek(p, pos * sizeof(aux), SEEK_SET);
    fread(&aux, sizeof(aux), 1, p);
    fclose(p);
    return true;
}
/************************************************************
FUNCIONES QUE VOY A NECESIT
*/
void guardar(punto2 B) {

    FILE* p;
    p = fopen("punto2.dat", "ab");
    if (p == NULL) {
    
        cout << "ERROR AL CARGAR ARCHIVO" << endl;
        system("pause");
        system("cls");
        return;
    }
    if (fwrite(&aca, sizeof(aca), 1, p) == 1) {

        fclose(p);
        cout << "REGISTRO GUARDADO CON EXITO" << endl;
        system("pause");
        return;
    }

    fclose(p);
    return;
}
int cantRegistro() {

    FILE* p;
    p = fopen("punto2.dat", "rb");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO" << endl;
        system("pause");
        system("cls");
        return -1;
    }
    int cant;
    choferes aux;
    fseek(p, 0, 2);
    cant = ftell(p);
    fclose(p);

    return cant / sizeof(aux);
}
hospital leerRegistro(int pos) {

    FILE* p;
    p = fopen(archivoChoferes, "rb");
    choferes aux;
    fseek(p, pos * sizeof(aux), SEEK_SET);
    fread(&aux, sizeof(aux), 1, p);
    fclose(p);

    return aux;
}
contratos leerRegistrocont(int pos) {

    FILE* p;
    p = fopen(archivoChoferes, "rb");
    choferes aux;
    fseek(p, pos * sizeof(aux), SEEK_SET);
    fread(&aux, sizeof(aux), 1, p);
    fclose(p);

    return aux;
}
/*******************************************/




*/