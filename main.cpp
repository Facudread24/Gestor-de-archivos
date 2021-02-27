#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

#include "Choferes.h"
#include "viajes.h"
#include "reportes.h"
#include "configuracion.h"
#include "validaciones.h"
#include "herramientas.h"

const int X = 33;
const int Y = 3;
const int COLOR_PANTALLA = DARKGREY;
const int LETRA = WHITE;
const int FONDO = LIGHTBLUE;
int main() {
    int opc;
    const int ANCHO_MENU = 30;
    const int ALTO_MENU = 11;
    int key, cursorX, cursorY;
    cursorX = X + 6;
    cursorY = Y + 3;
    do
    {
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        opc = 1;
        setColor(LETRA);
        setBackgroundColor(FONDO);
 
        recuadro(X+4, Y, ANCHO_MENU, ALTO_MENU, LETRA, FONDO);
        separadorH(X+4, Y + 2, ANCHO_MENU, LETRA, FONDO);
        separadorH(X + 4, Y + 8, ANCHO_MENU, LETRA, FONDO);

        locate(X + 13, Y + 1);
        cout << "MENU PRINCIPAL";
        locate(X + 10, Y + 3);
        cout << "1) CHOFERES" << endl;
        locate(X + 10, Y + 4);
        cout << "2) VIAJES" << endl;
        locate(X + 10, Y + 5);
        cout << "3) REPORTES" << endl;
        locate(X + 10, Y + 6);
        cout << "4) CONFIGURACION" << endl << endl;;
        
        locate(X + 10, Y + 7);
        cout << "0) SALIR DEL PROGRAMA" << endl << endl;
        locate(X + 10, Y + 10);
        cout << "SELECCIONE UNA OPCION "<<endl;
        hidecursor();
        locate(cursorX, cursorY);
        cout << ">";
        key = getkey();
        while (key != KEY_ENTER) {
            locate(cursorX, cursorY);
            cout << " ";
            switch (key) {
            case KEY_DOWN:
                if (opc < 4) {
                    opc++;
                }
                else {
                    opc = 0;
                }
                break;
            case KEY_UP:
                if (opc > 0) {
                    opc--;
                }
                else {
                    opc = 4;
                }
                break;
            }
            if (opc != 0) {
                cursorY = opc + Y + 2;
            }
            else {
                cursorY = Y + 7;
            }
            locate(cursorX, cursorY);
            cout << ">";
            key = getkey();
        }
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        showcursor();
        switch (opc)
        {
            system("cls");
        case 1: menuChoferes();
            break;
        case 2: menuViaje();
            break;
        case 3: menuReportes();
            break;
        case 4: configuracion();
            break;
        case 0:
            break;
        }
        system("cls");
    } while (opc != 0);
return 0;
}
