#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace rlutil;
using namespace std;
#include "Choferes.h"
#include "viajes.h"
#include "validaciones.h"
#include "reportes.h"


void menuReportes() {
	int opc;
	do
	{
		setColor(BLUE);
		setBackgroundColor(WHITE);
		system("cls");

		locate(45, 7);
		cout << "-------------------------------------------" << endl;
		locate(45, 8);
		cout << "----------------MENU REPORTES--------------" << endl;
		locate(45, 9);
		cout << "-------------------------------------------" << endl;
		locate(52, 10);
		cout<<"1)REPORTE 1" << endl;
		locate(52, 11);
		cout<<"2)REPORTE 2" << endl;
		locate(52, 12);
		cout<<"3)REPORTE 3" << endl;
		locate(45, 13);
		cout << "-------------------------------------------" << endl;
		locate(52, 14);
		cout<<"0) VOLVER AL MENU PRINCIPAL" << endl <<endl;
		locate(45, 15);
		cout << "-------------------------------------------" << endl;
		locate(52, 16);
		cout<<"INGRESE LA OPCION >";
		locate(73, 16);
		cin >> opc;
		system("cls");
		switch (opc)
		{
		case 1:punto1();
			break;
		case 2:punto2();
			break;
		case 3:punto3();
			break;
		}
	} while (opc!=0);
}
/*Viajes
Informar la cantidad de km entre todos los viajes realizados para cada uno de los meses del año actual.*/
//
void punto1() {

	viajes aux;
	int cantviaje;
	float v[12] = {0};
	cantviaje=cantRegistroViaje();

	for (int i = 0; i < cantviaje; i++)
	{
		aux = leerRegistroV(i);
		if (aux.viaje.año==2020)
		{
			v[aux.viaje.mes - 1] = v[aux.viaje.mes - 1]+aux.km;

		}
	}
	for (int y = 0; y < 12; y++)
	{
		cout << "PARA EL MES " << y + 1 << " DEL AÑO 2020 HUBO " << v[y] << " KILOMETROS" << endl<<endl;
		system("pause");
	}

}
/*Dado un DNI de un chofer que se ingresa por teclado, informar el promedio de calificaciones para ese chofer.*/

void punto2() {

	viajes aux;
	char DNI[10];
	int contotal = 0, acu = 0;
	float prom;
	int pos;
	cout << " INGRESE EL DNI DEL CHOFER : ";
	cin.ignore();
	cargarCadena(DNI, 11);
	pos = buscarDni(DNI);
	if (pos != -1)
	{
		for (int i = 0; i < cantRegistroViaje(); i++)
		{
			aux = leerRegistroV(i);
			if (strcmp(aux.dni, DNI) == 0)
			{
				contotal++;
				acu += aux.calificacion;
			}

		}
		if (contotal == 0)
		{
			cout << "El chofer no tiene viajes";
			system("pause");
			return;
		}
		else prom = acu / contotal;

		cout << "EL CHOFER CON DNI: " << DNI << " TUVO UN PROMEDIO DE CALIFICACIONES DEL " << prom << endl;
		system("pause");
	}
	else
	{
		cout << "El dni no existe"<<endl;
		system("pause");
	}
}
/*Generar un archivo con los choferes con tipo de registro 3 que no hayan recibido nunca una calificación mayor a 3 en el año actual.

Los registros del archivo deben tener el mismo formato del archivo de choferes.*/
void punto3() {
	int pos3;
	reporte3 aux;
	choferes chof;
	viajes viaj;
	int contmas3=0;
	for (int i = 0; i < cantRegistro(); i++)
	{
		contmas3 = 0;
		
			for (int y = 0; y < cantRegistroViaje(); y++)
			{
				chof = leerRegistro(i);
				if (chof.tipoRegistro == 3) {
					viaj = leerRegistroV(y);
					if (strcmp(chof.dni, viaj.dni) == 0)
					{
						if (viaj.calificacion <= 3 && viaj.viaje.año == 2020)
						{
							contmas3++;

						}

					}
				}
			}
		if (contmas3!=0)
		{
			pos3=buscardnireporte3(aux.chof.dni);
			if (pos3==-1)
			{
				guardarReporte3(chof);
			}
			
		}
	}
	for (int x = 0; x < cantRegistro3(); x++)
	{
		aux = leerReporte3(x);
		mostrarreporte3(aux);
		system("pause");
	}
	
}
int buscardnireporte3(char *chof) {
	FILE* p;
	reporte3 reg;
	int pos = 0;
	p = fopen(archivoReporte3, "rb");
	if (p == NULL) return -1;
	while (fread(&reg, sizeof(reporte3), 1, p) == 1) {
		if (strcmp(reg.chof.dni, chof) == 0) {
			fclose(p);
			return pos;
		}
		pos++;
	}
	fclose(p);
	return -1;
}
reporte3 leerReporte3(int pos) {

	FILE* p;
	p = fopen(archivoReporte3, "rb");
	reporte3 aux;
	fseek(p, pos * sizeof(aux), SEEK_SET);
	fread(&aux, sizeof(aux), 1, p);
	fclose(p);

	return aux;
}
int cantRegistro3() {

	FILE* p;
	p = fopen(archivoReporte3, "ab");
	if (p == NULL) {
		return 0;
	}
	int cant;
	reporte3 aux;
	fseek(p, 0, 2);
	//0 INICIO SEEK_SET
	//1 cursor SEEL_CUT
	//2 FIN SEEK_END
	cant = ftell(p);
	fclose(p);

	return cant / sizeof(aux);
}
void guardarReporte3(choferes aux) {
	FILE* p;

	p = fopen(archivoReporte3, "ab");
	if (p == NULL)
	{
		return;
	}
	if (fwrite(&aux, sizeof(reporte3), 1, p) == 1) {
		fclose(p);
		//cout << "REPORTE GUARDADO CON EXITO";
		//system("pause");
		return;
	}
	fclose(p);
}
void mostrarreporte3(reporte3 aux) {


	cout << "DNI:" << aux.chof.dni << endl;
	cout << "APELLIDO: " << aux.chof.apellido << endl;
	cout << "NOMBRE: " << aux.chof.nombre << endl;
	cout << "FECHA DE INGRESO: " << aux.chof.fechaIng.dia << "/" << aux.chof.fechaIng.mes << "/" << aux.chof.fechaIng.año << endl;
	cout << "CUIT: " << aux.chof.cuit << endl;
	cout << "TIPO DE REGISTRO: " << aux.chof.tipoRegistro << endl;
	cout << "FECHA DE VENCIMIENTO: " << aux.chof.fechaVen.dia << "/" << aux.chof.fechaVen.mes << "/" << aux.chof.fechaVen.año << endl;
	cout << "TELEFONO: " << aux.chof.telefono << endl;
	if (aux.chof.propietario == true) {
		cout << "PROPIETARIO DEL AUTO : S" << endl;
	}
	else
	{
		cout << "PROPIETARIO DEL AUTO : N" << endl;
	}
	cout << "--------------------------------------------------" << endl << endl;

}
