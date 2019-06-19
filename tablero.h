//
// Created by Ivan Mamani on 04/06/2019.
//

#ifndef PROYECTOC_TABLERO_H
#define PROYECTOC_TABLERO_H

#include <iostream>
#include <iomanip>
using namespace std;
int elegirTablero(int &tipo);
void llenarTablero(int tipo, char matriz[][8], int &cantidadFichas);
void llenarTablero1(char matriz[][8], int &cantidadFichas);
void llenarTablero2(char matriz[][8], int &cantidadFichas);
void llenarTablero3(char matriz[][8], int &cantidadFichas);
void imprimirTablero(char matriz[][8], int &cantidadFichas);
void jugar(char matriz[][8], int &cantidadFichas, int &fila, int &columna, int &fila2, int &columna2);
void verificarCantidadFichas(char matriz[][8]);
void finJuego();
//class tablero {

//};


#endif //PROYECTOC_TABLERO_H
