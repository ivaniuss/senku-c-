#include <iostream>
#include <iomanip>
#include "tablero.h"
using namespace std;
int main() {

    char matriz[8][8];
    int cantidadFichas = 0, fila1, columna1, fila2, columna2, tipo;

    elegirTablero(tipo);
    llenarTablero(tipo, matriz, cantidadFichas);
    imprimirTablero(matriz, cantidadFichas);
    jugar(matriz, cantidadFichas, fila1, columna1, fila2, columna2);
    verificarCantidadFichas(matriz);
    finJuego();

    return 0;
}