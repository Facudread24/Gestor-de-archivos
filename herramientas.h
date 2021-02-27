#pragma once
void recuadro(int iniX, int iniY, int ancho, int alto, short colorLinea = WHITE, short colorFondo = CYAN) {
    setlocale(LC_ALL, "C");
    int i, j;
    for (i = iniX; i <= iniX + ancho; i++) {
        for (j = iniY; j <= iniY + alto; j++) {
            locate(i, j);
            setColor(colorLinea);
            setBackgroundColor(colorFondo);
            //Arriba izquierda
            if (i == iniX && j == iniY) {
                cout << (char)201;
            }
            //Arriba derecha
            else if (i == iniX + ancho && j == iniY) {
                cout << (char)187;
            }
            //Abajo izquierda
            else if (i == iniX && j == iniY + alto) {
                cout << (char)200;
            }
            //Abajo derecha
            else if (i == iniX + ancho && j == iniY + alto) {
                cout << (char)188;
            }
            //Lineas arriba y abajo
            else if (j == iniY || j == iniY + alto) {
                cout << (char)205;
            }
            //Lineas izquierda y derecha
            else if (i == iniX || i == iniX + ancho) {
                cout << (char)186;
            }
            //Dentro del recuadro
            else {
                cout << " ";
            }
        }
    }
    setlocale(LC_ALL, "spanish");
}
void separadorH(short iniX, short iniY, short ancho, short colorLinea = WHITE, short colorFondo = BLACK) {
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX, iniY);
    cout << (char)204;
    for (i = 1; i < ancho; i++) {
        cout << (char)205;
    }
    cout << (char)185;
    setlocale(LC_ALL, "spanish");
}