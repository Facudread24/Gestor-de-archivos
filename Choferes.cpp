#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "Choferes.h"
#include "validaciones.h"

void menuChoferes() {
    int opc;

    do
    {
        setColor(BLUE);
        setBackgroundColor(WHITE);
        system("cls");
        
        locate(45, 7);
        cout << "-------------------------------------------" << endl;
        locate(45, 8);
        cout << "--------------MENU CHOFERES----------------" << endl;
        locate(45, 9);
        cout << "-------------------------------------------" << endl;
        locate(52, 10);
        cout << "1) NUEVO CHOFER" << endl;
        locate(52, 11);
        cout << "2) MODIFICAR CHOFER" << endl;
        locate(52, 12);
        cout << "3) LISTAR CHOFER POR DNI" << endl;
        locate(52, 13);
        cout << "4) LISTAR TODOS LOS CHOFERES" << endl << endl;;
        locate(52, 14);
        cout << "5) ELIMINAR CHOFER" << endl;
        locate(45, 15);
        cout << "-------------------------------------------" << endl;
        locate(52, 16);
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;
        locate(45, 17);
        cout << "-------------------------------------------" << endl;
        locate(52, 18);
        cout << "INGRESE SU OPCION: >";
        locate(73, 18);
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1: altaChofer();
            break;
        case 2: modificarchofer();
            break;
        case 3: listarPorDni();
            break;
        case 4: listarChoferes();
            break;
        case 5: bajaChofer();
            break;
        case 0:
            break;
        }
    } while (opc != 0);
}
 /*********************************************************************/
choferes cargarChofer() {
    int a;
    int comp;
    char aux;
    choferes chof;
    cin.ignore();
    do
    {
        cout << "CARGAR DNI: ";
        cargarCadena(chof.dni,11);   ///hasta 8 espacio y no vacios 
        a = buscarDni(chof.dni);
        if (a!=-1)
        {
            cout << endl;
            setColor(RED);
            cout<<"EL DNI YA EXISTE"<<endl;
            setColor(BLUE);
            system("pause");
            system("cls");
        }
    } while (espaciosVac(chof.dni,1) == false ||a!=-1);
    do{
        cout << "CARGAR APELLIDO: ";
        cargarCadena(chof.apellido,50); //50 limite no vacia
    } while (espaciosVac(chof.apellido, 2) == false);
    //cin.ignore();
    do{
    cout<<"CARGAR NOMBRE: ";
    cargarCadena(chof.nombre,50); // 50 limite no vacia
    } while (espaciosVac(chof.nombre, 3) == false);

    do {
        cout << "FECHA DE INGRESO: ";
        do {
            cout << "DIA: ";
            cin >> chof.fechaIng.dia;
            cout << endl;
            setColor(RED);
            if (chof.fechaIng.dia > 31 || chof.fechaIng.dia < 1) { cout << "INGRESAR DIA ENTRE 1 Y 31" << endl; }
            setColor(BLUE);
        } while (chof.fechaIng.dia > 31 || chof.fechaIng.dia < 1);
        do {
            cout << "MES: ";
            cin >> chof.fechaIng.mes;
            cout << endl;
            setColor(RED);
            if (chof.fechaIng.mes > 12 || chof.fechaIng.mes < 1) { cout << "INGRESAR MES ENTRE 1 Y 12" << endl; }
            setColor(BLUE);
        } while (chof.fechaIng.mes > 12 || chof.fechaIng.mes < 1);
        cout << "A" << (char) 165 << "O: ";
        cin >> chof.fechaIng.año;
        comp = compFecha(chof.fechaIng.dia, chof.fechaIng.mes, chof.fechaIng.año);
        cout << endl;
        setColor(RED);
        if (comp == 1) { cout << "LA FECHA DE INGRESO ES MAYOR A LA ACTUAL" << endl; }
        setColor(BLUE);
    } while (comp == 1);

    cin.ignore();
    do{
    cout << "INGRESAR EL CUIT: ";
    cargarCadena(chof.cuit,51);
    a = buscarCuit(chof.cuit);
    if (a != -1)
    {
        cout << endl;
        setColor(RED);
        cout << "EL CUIT YA EXISTE" << endl;
        setColor(BLUE);
        system("pause");
        system("cls");
    }
    } while (espaciosVac(chof.cuit,4)==false || a!=-1);
    //cuit hasta 20 valor unico y que no sea vacio
    do
    {
        cout << "TIPO DE REGISTRO (1)(2)(3): ";
        cin >> chof.tipoRegistro; //entre 1 y 3
    } while (chof.tipoRegistro <1 || chof.tipoRegistro > 3);

    do {
        cout << "FECHA DE VENCIMIENTO: ";
        do {
            cout << "DIA: ";
            cin >> chof.fechaVen.dia;
            cout << endl;
            setColor(RED);
            if (chof.fechaVen.dia > 31 || chof.fechaVen.dia < 1) { cout << "INGRESAR DIA ENTRE 1 Y 31" << endl; }
            setColor(BLUE);
        } while (chof.fechaVen.dia > 31 || chof.fechaVen.dia < 1);
        do {
            cout << "MES: ";
            cin >> chof.fechaVen.mes;
            cout << endl;
            setColor(RED);
            if (chof.fechaVen.mes > 12 || chof.fechaVen.mes < 1) { cout << "INGRESAR MES ENTRE 1 Y 12" << endl; }
            setColor(BLUE);
        } while (chof.fechaVen.mes > 12 || chof.fechaVen.mes < 1);
        cout << "A" << (char)165 << "O: ";
        cin >> chof.fechaVen.año;
        comp = compFecha(chof.fechaVen.dia, chof.fechaVen.mes, chof.fechaVen.año);
        cout << endl;
        setColor(RED);
        if (comp != 1) { cout << "LA FECHA DE VENCIMIENTO ES MENOR QUE LA FECHA ACTUAL" << endl; }
        setColor(BLUE);
    } while (comp != 1);
    
    cin.ignore();
    do{
    cout << "TELEFONO: ";
    cargarCadena(chof.telefono, 16); // sea de 15
    } while (espaciosVac(chof.telefono, 5) == false);
    
    cout << "PROPIETARIO DEL AUTO (S/N):";
    cin >> aux;

    if (aux == 'S' || aux == 's') {
        chof.propietario = true;
    }
    else
    {
        chof.propietario = false;
    }
    chof.estado = true;

    system("cls");
    
    return chof;
}

void  dinamico() {

    choferes* v;

    int cant, i;

    cin >> cant;

    v = (choferes*)malloc(cant * sizeof(choferes));

    if (v == NULL) return;

    for (i = 0;i < cant;i++) v[i] = cargarChofer();

    for (i = 0;i < cant;i++) mostrarChoferes(v[i]);

    free(v);

}
/****************************************************************************/
bool guardarChofer(choferes chof) {

    FILE* p;
        p = fopen(archivoChoferes, "ab");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO" << endl;
        system("pause");
        system("cls");
        return false;
    }
    if (fwrite(&chof, sizeof(chof), 1, p) == 1) {
        
        fclose(p);
        cout << "REGISTRO GUARDADO CON EXITO"<<endl;
        system("pause");
        return true;
    }

    fclose(p);
    return false;
}
/***********************************************************************/
void altaChofer() {
    int pos;
    choferes reg;

    reg=cargarChofer();
    if (reg.estado == true) {
        pos = buscarDni(reg.dni);
        if (pos != -1) {
            cout << endl;
            cout << "EL DNI YA EXISTE" << endl << endl;
            system("pause");
            return;
        }
        guardarChofer(reg);
    }
}
/**********************************************************************/
int buscarDni(char* chof) {

    FILE* p;
    choferes reg;
    int pos = 0;
    p = fopen(archivoChoferes, "rb");
    if (p == NULL) return -1;
    while (fread(&reg, sizeof(choferes), 1, p) == 1) {
        if (strcmp(reg.dni, chof) == 0) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
/**************************************************************************/
int buscarCuit(char* chof) {
    FILE* p;
    choferes reg;
    int pos = 0;
    p = fopen(archivoChoferes, "rb");
    if (p == NULL) return -1;
    while (fread(&reg, sizeof(choferes), 1, p) == 1) {
        if (strcmp(reg.cuit, chof) == 0) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
/***********************************************************/
void listarChoferes() {
    
    FILE* p;
    p = fopen(archivoChoferes, "rb");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO" << endl;
        system("pause");
        system("cls");
        return;
    }
    choferes aux;
    int cant;
    cant = cantRegistro();
    for (int i = 0; i < cant; i++)
    {
        aux = leerRegistro(i);
        mostrarChoferes(aux);
    }
        system("pause");
    fclose(p);
}

/*******************************************************************/
void mostrarChoferes(choferes chof) {

    if (chof.estado == false) return;
    
        cout << "DNI:" << chof.dni << endl;
        cout << "APELLIDO: "<<chof.apellido << endl;
        cout << "NOMBRE: "<<chof.nombre << endl;
        cout << "FECHA DE INGRESO: "<< chof.fechaIng.dia <<"/"<< chof.fechaIng.mes << "/" << chof.fechaIng.año << endl;
        cout << "CUIT: "<<chof.cuit << endl;
        cout << "TIPO DE REGISTRO: "<<chof.tipoRegistro << endl;
        cout << "FECHA DE VENCIMIENTO: " << chof.fechaVen.dia << "/" << chof.fechaVen.mes << "/" << chof.fechaVen.año << endl;
        cout << "TELEFONO: "<<chof.telefono << endl;
        if (chof.propietario == true) {
            cout << "PROPIETARIO DEL AUTO : S" << endl;
        }
        else
        {
            cout << "PROPIETARIO DEL AUTO : N" << endl;
        }
        cout << "--------------------------------------------------" << endl << endl;
    
}
/******************************************************************************/
int cantRegistro() {

    FILE* p;
    p = fopen(archivoChoferes, "rb");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO"<<endl;
        system("pause");
        system("cls");
        return -1;
    }
    int cant;
    choferes aux;
    fseek(p,0,2);
    //0 INICIO SEEK_SET
    //1 MITAD SEEL_CUT
    //2 FIN SEEK_END
    cant = ftell(p);
    fclose(p);
    
    return cant / sizeof(aux);
}
/****************************************************************************/
void modificarchofer() {

    char dni[10];

    cout << "INGRESE EL DNI A MODIFICAR: ";
    cin >> dni;
    //int cant = cantRegistro();
    int dia, mes, año;
    int pos;
    int comp;
    pos = buscarDni(dni);
    if (pos != -1) {
        //mostrar
        choferes chof;
        chof = leerRegistro(pos);
        mostrarChoferes(chof);
        do {
            cout << "INGRESE NUEVA FECHA DE VENCIMIENTO: ";
            do {
                cout << "DIA: ";
                cin >> dia;
                if (dia < 1 || dia>31) { cout << "INGRESAR DIA ENTRE 1 Y 31" << endl; }
            } while (dia < 1 || dia>31);
            do {
                cout << "MES: ";
                cin >> mes;
                if (mes < 1 || mes >12) { cout << "INGRESAR MES ENTRE 1 Y 12" << endl; }
            } while (mes < 1 || mes >12);
            cout << "A" << (char)165 << "O: ";
            cin >> año;
            comp = compFecha(dia, mes, año);
            if (comp == -1 || comp == 0) {
                cout << "LA FECHA INGRESADA ES MENOR A LA ACTUAL" << endl;
                system("pause");
                system("cls");
            }
        } while (comp == -1 || comp == 0);
        chof.fechaVen.dia = dia;
        chof.fechaVen.mes = mes;
        chof.fechaVen.año = año;
        if (guardar(chof, pos) == true) {
            cout << "EL ARCHIVO SE SOBREESCRIBIO EXITOSAMENTE" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "NO SE ENCONTRO EL REGISTRO" << endl;
    system("pause");
    system("cls");
}
/*******************************************************/
void bajaChofer() {
    FILE* p;
    int pos;
    char DNI[10];
    choferes chof;
    p = fopen(archivoChoferes, "rb+");
    if (p==NULL)
    {
        cout << "ERROR AL CARGAR ARCHIVO" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "INGRESE EL DNI A DAR DE BAJA" << endl;
    cin >> DNI;
    pos = buscarDni(DNI);
    if (pos!=-1)
    {
        fseek(p, pos*sizeof(chof), SEEK_SET);
        chof.estado = false;
        fwrite(&chof,sizeof(chof),1,p);
        fclose(p);
        cout << "EL CHOFER SE DIO DE BAJA CORRECTAMENTE" << endl;
        system("pause");
        return;
    }
    else
    {
        cout << "NO EXISTE EL DNI" << endl;
        system("pause");
        return;
    }
}
/**************************************************************/
choferes leerRegistro(int pos) {

    FILE* p;
    p = fopen(archivoChoferes, "rb");
    choferes aux;
    fseek(p, pos*sizeof(aux), SEEK_SET);
    fread(&aux, sizeof(aux), 1, p);
    fclose(p);
    
    return aux;
}
/*********************************************************/
void listarPorDni() {
    char DNI[10];
    int pos;
    choferes chof;
    cout << "INGRESE EL DNI: ";
    cin >> DNI;
    pos = buscarDni(DNI);
    if (pos != -1)
    {
        chof = leerRegistro(pos);
        mostrarChoferes(chof);
    }
    else { cout << "NO SE ENCONTRO EL CHOFER SOLICITADO" << endl; }

    system("pause");
}
/************************************************************/

/**********************************************/
bool guardar(choferes chof, int pos) {
    bool grabo;
    FILE* p;
    p = fopen(archivoChoferes, "rb+");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO" << endl;
        system("pause");
        system("cls");
        return false;
    }
    fseek(p,pos*sizeof(chof),0);
    grabo = fwrite(&chof, sizeof(chof), 1, p);

        fclose(p);
        cout << "REGISTRO GUARDADO CON EXITO";
        system("pause");
        return grabo;
}
/******************************************************/
