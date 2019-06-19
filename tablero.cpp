//
// Created by Ivan Mamani on 04/06/2019.
//

#include "tablero.h"
int elegirTablero(int &tipo){
    do{
        cout << "\n\t\tMenu - Juego Senku\n";
        cout << "--------------------------------------------------\n\n";
        cout << "[1] Tablero Ingles.\n";
        cout << "[2] Tablero Frances.\n";
        cout << "[3] Tablero Diamante.\n\n";
        cout << "----------------------------------------------------\n";

        cout << setw(20) << "Seleccionar opcion: ";cin >> tipo;



    }while(tipo < 0 || tipo > 3);

    return tipo;
}


void llenarTablero(int tipo,char matriz[][8], int &cantidadFichas){

    switch (tipo){
        case 1: llenarTablero1(matriz, cantidadFichas);
            break;
        case 2: llenarTablero2(matriz, cantidadFichas);
            break;
        case 3: llenarTablero3(matriz, cantidadFichas);
            break;
    }
}

void llenarTablero1(char matriz[][8], int &cantidadFichas){


    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){

            if (i == 0 && j < 9)
                matriz[i][j] = char(j + 48);
            else if (i > 0 && j == 0 )
                matriz[i][j] = char(i + 48);


            else if ((i>0 && (i<3 || i>5)) && (j<3 || j>5))
                matriz[i][j]= ' ';
            else if (i==4 && j==4)
                matriz[i][j]='+';
            else{
                matriz[i][j]='o';
                cantidadFichas++;
            }
        }
    }
}

void llenarTablero2(char matriz[][8], int &cantidadFichas){


    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){

            if (i == 0 && j < 9)
                matriz[i][j] = char(j + 48);
            else if (i > 0 && j == 0 )
                matriz[i][j] = char(i + 48);
            else if ((i > 0 && (i < 3 ||i > 5)) && (j < 3  || j > 5))
                matriz[i][j] = ' ';
            else if (i ==  3 && j == 4)
                matriz[i][j] = '+';
            else{
                matriz[i][j] ='o';
                matriz[2][2] ='o';
                matriz[6][2] ='o';
                matriz[2][6] ='o';
                matriz[6][6] ='o';

                cantidadFichas ++;
            }
        }
    }
}
void llenarTablero3(char matriz[][8], int &cantidadFichas) {


    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){

            if (i == 0 && j < 9)
                matriz[i][j] = char(j + 48);
            else if (i > 0 && j == 0 )
                matriz[i][j] = char(i + 48);

            else if ((i < 2 || i > 6) && (j != 4))
                matriz[i][j] = ' ';

            else if (((i < 3 || i > 5)) && (j < 3  || j > 5))
            matriz[i][j] = ' ';

            else if (((i !=4)) && (j < 2  || j > 6))
            matriz[i][j] = ' ';

            else if (i ==  4 && j == 4)
                matriz[i][j] = '+';

            else{

                matriz[i][j] ='o';

                cantidadFichas ++;


            }

        }
    }


}

void imprimirTablero(char matriz[][8], int &cantidadFichas){

    cout<<"\n\n";

    for(int i = 0;  i < 8;  i++){
        for(int j = 0;  j < 8; j++)
            cout << setw(4) << matriz[i][j];
        cout << "\n";
    }
    cout << "\n";

}


void verificarCantidadFichas(char matriz[][8]){

    int fichasrestantes = 0;
    for(int i = 0;  i < 8;  i++){
        for(int j = 0;  j < 8; j++)
            if (matriz[i][j] == 'o'){
               fichasrestantes++;
            }

    }
    if (fichasrestantes==1){

        finJuego();
        exit(0);

    }


}


void moverFichas(char matriz[][8], int &cantidadFichas, int fila1, int columna1, int fila2, int columna2){


    if((fila2 - fila1 == 2  && columna1 == columna2) && matriz[fila1+1][columna1] == 'o'){
        matriz[fila1][columna1] = '+';
        matriz[fila2-1][columna1] = '+';
        matriz[fila2][columna2] = 'o';
        imprimirTablero(matriz, cantidadFichas);
        verificarCantidadFichas(matriz);
        jugar(matriz, cantidadFichas, fila1, columna1, fila2, columna2);

    }
    else if((fila2 - fila1 == -2 && columna1 == columna2) && matriz[fila1-1][columna1] == 'o'){
        matriz[fila1][columna1] = '+';
        matriz[fila1-1][columna1] = '+';
        matriz[fila2][columna2] = 'o';
        imprimirTablero(matriz, cantidadFichas);
        verificarCantidadFichas(matriz);
        jugar(matriz, cantidadFichas, fila1, columna1, fila2, columna2);
    }
    else if ((columna2 - columna1 == 2 && fila1 == fila2) && matriz[fila1][columna1+1] == 'o'){

        matriz[fila1][columna1] = '+';
        matriz[fila1][columna2-1] = '+';
        matriz[fila2][columna2] = 'o';
        imprimirTablero(matriz, cantidadFichas);
        verificarCantidadFichas(matriz);
        jugar(matriz, cantidadFichas, fila1, columna1, fila2, columna2);
    }
    else if ((columna2 - columna1 == -2 && fila1 == fila2) && matriz[fila1][columna1-1] == 'o'){

        matriz[fila1][columna1] = '+';
        matriz[fila1][columna1-1] = '+';
        matriz[fila2][columna2] = 'o';
        imprimirTablero(matriz, cantidadFichas);
        verificarCantidadFichas(matriz);
        jugar(matriz, cantidadFichas, fila1, columna1, fila2, columna2);

    } else{
        cout << "\n¡No se puede realizar este movimiento!\n\n";
        cout << "Intentalo de nuevo.";
        imprimirTablero(matriz, cantidadFichas);
        verificarCantidadFichas(matriz);
        jugar(matriz, cantidadFichas, fila1, columna1, fila2, columna2);

    }
}


void jugar(char matriz[][8], int &cantidadFichas, int &fila1, int &columna1, int &fila2, int &columna2){



    verificarCantidadFichas(matriz);


        cout << "Ingrese coordenadas de ficha a mover:" << "\n";
        cout << setw(20) <<"Fila      : "; cin >> fila1;
        cout << setw(20) <<"Columna   : "; cin >> columna1;
        if (matriz[fila1][columna1] == 'o'){

            cout << "Ingrese posicion final:\n";
            cout << setw(20) <<"Fila      : "; cin >> fila2;
            cout << setw(20) <<"Columna   : "; cin >> columna2;
            if(matriz[fila2][columna2] == '+'){
                moverFichas(matriz, cantidadFichas, fila1, columna1, fila2, columna2);

            }
            else{
                cout << "\nEse movimiento  no es valido. Intente de nuevo.\n\n";
                imprimirTablero(matriz, cantidadFichas);
                jugar(matriz, cantidadFichas, fila1, columna1, fila2, columna2);

            }
        }

        else{

            cout << "\nEse movimiento  no es valido. Intente de nuevo.\n\n";
            imprimirTablero(matriz, cantidadFichas);
            jugar(matriz, cantidadFichas, fila1, columna1, fila2, columna2);

        }


    }




void finJuego(){

        cout << "GANASTE"<<endl;


}
