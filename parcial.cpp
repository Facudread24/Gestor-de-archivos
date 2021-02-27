#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#include "tipos.h"

void guardar(punto2 b) {

	FILE* p;
	p = fopen("punto2.dat", "ab");
	if (p == NULL) {
		cout << "ERROR AL CARGAR ARCHIVO" << endl;
		system("pause");
		system("cls");
		return;
	}
	if (fwrite(&b, sizeof(b), 1, p) == 1) {
		fclose(p);
		cout << "REGISTRO GUARDADO CON EXITO" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << " EL REGISTRO NO FUE GUARDADO " << endl;
		system("pause");
	}
	fclose(p);
}

int cantRegistro() {

	FILE* p;
	p = fopen("medico.dat", "rb"); //<----------- CAMBIAR POR .DAT QUE USO
	if (p == NULL) {
		cout << "ERROR AL CARGAR ARCHIVO" << endl;
		system("pause");
		system("cls");
		return -1;
	}
	int cant;
	medico aux;              //<----------- CAMBIAR POR STRUCT QUE USO
	fseek(p, 0, 2);
	cant = ftell(p);
	fclose(p);

	return cant / sizeof(aux);
}

hospital leerRegistro(int pos) { //<----------- CAMBIAR EL DATO QUE DEVUELVE POR STRUCT QUE USO

	FILE* p;
	p = fopen(archivoChoferes, "rb"); //<----------- CAMBIAR POR .DAT QUE USO
	choferes aux;					  //<----------- CAMBIAR POR STRUCT QUE VOY A LEER 
	fseek(p, pos * sizeof(aux), SEEK_SET);
	fread(&aux, sizeof(aux), 1, p);
	fclose(p);

	return aux;
}
medico leerRegistrocont(int pos) {

	FILE* p;
	p = fopen("medico.dat", "rb");
	medico aux;
	fseek(p, pos * sizeof(aux), SEEK_SET);
	fread(&aux, sizeof(aux), 1, p);
	fclose(p);

	return aux;
}

struct punto2
{

	int NúmeroHospital;
	int cantidadcont;

};

/*******************************************/

    /*La cantidad de médicos de cargo subdirector de especialidad angiología */

void puntoa() {
	medico reg;
	int cant=0;
	for (int i = 0;i < cantRegistro();i++) {
	
		reg = leerRegistrocont(i);
		if (reg.cargo == 2 && reg.especialidad==4 ) {
			cant++;
		}
	}
	cout << "hay" << cant << "medicos de especialidad angiologia" << endl;

}

/*2. Generar un archivo con los hospitales de la región sanitaria 4 y 5 con el siguiente formato:
Número de hospital, cantidad de contratos realizados en el año 2019*/
int cantidadcontratos(int numero) {
	FILE* p;
	p = fopen("contrato.dat", "rb");
	if (p == NULL) {
		return -1;
	}
	contrato reg;
	int cant = 0;
	while (fread(&reg, sizeof(contrato), 1, p) == 1) {
		if (reg.numeroHospital == numero && reg.fecha_contrato.anio==2019) {
			cant++;
		}
	}
	fclose(p);
	return cant;
}
void puntob() {
	hospital reg;
	punto2 aux;
	int cant = 0;
	for (int i = 0;i < cantRegistrohosp();i++) {
	
		reg = leerRegistro(i);
		if (reg.region == 4 || reg.region == 5) {
			aux.NúmeroHospital = reg.numero;
			cant = cantidadcontratos(reg.numero);
			if (cant >= 0) {
				aux.cantidadcont = cant;
			}
			else {
				
				cout << "Hubo un error en el archivo de contratos no pudo guardarse la cantidad se le asignara -1";
				aux.cantidadcont = cant;
			}
			guardar(aux);
		}
	}
}
/********************************************/
int main() {

	int opc;
	do
	{
		cout << "1. PUNTO 1" << endl;
		cout << "2. PUNTO 2" << endl;
		cout << "0. SALIR" << endl;
		cout << "OPCION :" << endl;
		cin >> opc;

		switch (opc)
		{
		case 1: puntoa();
			break;
		case 2: puntob();
			break;
		}

	} while (opc != 0);

	return 0;
}






