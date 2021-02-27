#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "Choferes.h"
#include "viajes.h"
#include "validaciones.h"


void menuViaje() {
    int opc;
    do
    {
        setColor(BLUE);
        setBackgroundColor(WHITE);
        system("cls");

        locate(45, 7);
        cout << "-------------------------------------------" << endl;
        locate(45, 8);
        cout << "----------------MENU VIAJES----------------" << endl;
        locate(45, 9);
        cout << "-------------------------------------------" << endl;
        locate(52, 10);
        cout << "1) NUEVO VIAJE" << endl;
        locate(52, 11);
        cout << "2) LISTAR VIAJE POR ID VIAJE" << endl;
        locate(52, 12);
        cout << "3) LISTAR TODOS LOS VIAJES" << endl << endl;;
        locate(52, 13);
        cout << "4) ELIMINAR VIAJE" << endl;
        locate(45, 14);
        cout << "------------------------------------------" << endl;
        locate(52, 15);
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;
        locate(45, 16);
        cout << "------------------------------------------" << endl;
        locate(52, 17);
        cout << "INGRESE SU OPCION: >";
        locate(73, 17);
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1: altaViaje();
            break;
        case 2: listarPorIdViaje();
            break;
        case 3: listarViajes();
            break;
        case 4: bajaViaje();
            break;
        case 0:
            break;
        }
    } while (opc != 0);
}
/******************************************************************/
void altaViaje() {
    int pos;
    viajes reg;
    choferes chof;

    reg = cargarViaje();
    if (reg.viajeEstado == true) {
        pos = buscarDni(chof.dni);
        if (pos != -1) {
            cout << endl;
            setColor(RED);
            cout << "EL DNI YA EXISTE" << endl << endl;
            system("pause");
            setColor(BLUE);
            return;
        }
        guardarViaje(reg);
    }
}
/********************************************************************/
viajes cargarViaje() {
    viajes viaj;
    char DNI[10];
    int d;
    int comp;
    viaj.id= 1 + cantRegistroViaje();
    cout << "ID: "<<viaj.id<<endl;
    cin.ignore();
    do {
        cout << "INGRESE EL DNI DEL CHOFER: ";
        cargarCadena(DNI, 10);
        d = buscarDni(DNI);
        espaciosVac(DNI, 1);
        cout << endl;
        setColor(RED);
        if (d == -1) { cout << "NO SE ENCONTRO DNI DEL CHOFER" << endl; }
        setColor(BLUE);
    } while (d == -1);

    strcpy(viaj.dni, DNI);
    cout << "ID DE CLIENTE: ";
    cin >> viaj.idCliente;
    do {
        cout << "FECHA DE VIAJE: ";
        do {
            cout << "DIA: ";
            cin >> viaj.viaje.dia;
            cout << endl;
            setColor(RED);
            if (viaj.viaje.dia > 31 || viaj.viaje.dia < 1) { cout << "INGRESAR DIA ENTRE 1 Y 31" << endl; }
            setColor(BLUE);
        } while (viaj.viaje.dia > 31 || viaj.viaje.dia < 1);
        do {
            cout << "MES: ";
            cin >> viaj.viaje.mes;
            cout << endl;
            setColor(RED);
            if (viaj.viaje.mes > 12 || viaj.viaje.mes < 1) { cout << "INGRESAR MES ENTRE 1 Y 12" << endl; }
            setColor(BLUE);
        } while (viaj.viaje.mes > 12 || viaj.viaje.mes < 1);
        cout << "A" << (char)165 << "O: ";
        cin >> viaj.viaje.año;
        comp = compFecha(viaj.viaje.dia, viaj.viaje.mes, viaj.viaje.año);
        cout << endl;
        setColor(RED);
        if (comp == 1) { cout << "LA FECHA INGRESADA ES MAYOR A LA ACTUAL" << endl; }
        setColor(BLUE);
    } while (comp == 1);
    do {
        cout << "INGRESAR LA HORA: ";
        cin >> viaj.hora;
        cout << endl;
        setColor(RED);
        if (viaj.hora > 23 || viaj.hora < 0) { cout << "INGRESAR HORA ENTRE 0 Y 23" << endl; }
        setColor(BLUE);
    } while (viaj.hora > 23 || viaj.hora < 0);
    do
    {
        cout << "KILOMETROS: ";
        cin >> viaj.km;
        cout << endl;
        setColor(RED);
        if (viaj.km <= 0)cout << "LOS KILOMETROS DEBE SER MAYOR A 0" << endl;
        setColor(BLUE);
    } while (viaj.km<=0);
    do
    {
        cout << "IMPORTE: ";
        cin >> viaj.importe;
        cout << endl;
        setColor(RED);
        if (viaj.importe <= 0)cout << "EL IMPORTE DEBE SER MAYOR A $0" << endl;
        setColor(BLUE);
    } while (viaj.importe <=0);
    
    cin.ignore();
    do
    {
        cout << "PATENTE: ";
        cargarCadena(viaj.patente, 10);
    } while (espaciosVac(viaj.patente,6)==false);
    
    do {
        cout << "CALIFICACION: ";
        cin >> viaj.calificacion;
        cout << endl;
        setColor(RED);
        if (viaj.calificacion > 5 || viaj.calificacion < 0) { cout << "INGRESAR CALIFICACION ENTRE 0 ( PESIMO ) O 5 ( EXCELENTE )" << endl; }
        setColor(BLUE);
    } while (viaj.calificacion > 5 || viaj.calificacion < 0);

    viaj.viajeEstado = true;

    system("cls");

    return viaj;
}
/***********************************************************/
bool guardarViaje(viajes viaj) {

    FILE* p;
    p = fopen(archivoviajes, "ab");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO de viajes";
        system("pause");
        system("cls");
        return false;
    }
    if (fwrite(&viaj, sizeof(viaj), 1, p) == 1) {

        fclose(p);
        cout << "REGISTRO GUARDADO CON EXITO";
        system("pause");
        return true;
    }

    fclose(p);
    return false;
}/**************************************************************/
int cantRegistroViaje() {

    FILE* p;
    p = fopen(archivoviajes, "rb");
    if (p == NULL) {
        return 0;
    }
    int cant;
    viajes aux;
    fseek(p, 0, 2);
    //0 INICIO SEEK_SET
    //1 cursor SEEL_CUT
    //2 FIN SEEK_END
    cant = ftell(p);
    fclose(p);

    return cant / sizeof(aux);
}
/********************************************************************/
void listarViajes() {

    FILE* p;
    p = fopen(archivoviajes, "rb");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO";
        system("pause");
        system("cls");
        return;
    }
    viajes viaj;
    int cant;
    cant = cantRegistroViaje();
    for (int i = 0; i < cant; i++)
    {
        viaj = leerRegistroV(i);
        mostrarViajes(viaj);
    }
    system("pause");
    fclose(p);
}
/***********************************************************************/
viajes leerRegistroV(int pos) {

    FILE* p;
    p = fopen(archivoviajes, "rb");
    viajes aux;
    fseek(p, pos * sizeof(aux), SEEK_SET);
    fread(&aux, sizeof(aux), 1, p);
    fclose(p);

    return aux;
}
/****************************************************************************/
void mostrarViajes(viajes viaj) {

    if (viaj.viajeEstado == false) return;
    cout << "ID:" << viaj.id << endl;
    cout << "DNI CHOFER:" << viaj.dni << endl;
    cout << "ID CLIENTE: " << viaj.idCliente<< endl;
    cout << "FECHA DE VIAJE: " << viaj.viaje.dia << "/" << viaj.viaje.mes << "/" << viaj.viaje.año << endl;
    cout << "HORA: " <<viaj.hora << endl;
    cout << "KILOMETROS: " << viaj.km << endl;
    cout << "IMPORTE: " << viaj.importe << endl;
    cout << "PATENTE: " << viaj.patente << endl;
    cout << "CALIFICACION: " << viaj.calificacion << endl;
    cout << "--------------------------------------------------" << endl << endl;
}
/***********************************************************************************/
void listarPorIdViaje() {
    int pos;
    viajes aux;
    int id;
    cout << "INGRESE EL ID A LISTAR: ";
    cin >> id;
    pos=buscarID(id);
    aux = leerRegistroV(pos);
    mostrarViajes(aux);
    system("pause");
}
/*************************************************************************************/
int buscarID(int id) {
    FILE* p;
    int pos = 0;
    p = fopen(archivoviajes, "rb");
    if (p==NULL)
    {
        cout << "NO SE PUEDE ABRIR";
        return -1;
    }
    viajes viaj;
    while (fread(&viaj, sizeof(viajes), 1, p) == 1) {
        if (viaj.id== id) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
/*****************************************************************/
void bajaViaje() {
    FILE* p;
    int pos;
    int id;
    viajes viaj;
    p = fopen(archivoviajes, "rb+");
    if (p == NULL)
    {
        cout << "ERROR AL CARGAR ARCHIVO";
        system("pause");
        system("cls");
        return;
    }
    cout << "INGRESE EL ID DE VIAJE A DAR DE BAJA" << endl;
    cin >> id;
    pos = buscarID(id);
    if (pos != -1)
    {
        fseek(p, pos * sizeof(viaj), SEEK_SET);
        viaj.viajeEstado = false;
        fwrite(&viaj, sizeof(viaj), 1, p);
        fclose(p);
        cout << "EL VIAJE SE DIO DE BAJA CORRECTAMENTE" << endl;
        system("pause");
        return;
    }
    else
    {
        cout << "NO EXISTE EL ID" << endl;
        system("pause");
        return;
    }
}
