//Trabajo Practico Final - Lucas Jara y Guillermo Laguardia

#include <stdio.h>
#include <stdlib.h>

#define STARTING_GOLD 115
#define STARTING_AMMO 100

/*Cada casilla  es un stuct que contiene un valor que indica si hay un barco o no y su tipo, y un valor que indica si la casilla ha sido bombardeada o no*/

struct square{
	int is_ship;
	int bombed;
};

/*
Para referencia: (valor asignado;tipo;area)(la mina a efectos practicos es un barco mas)
1;Portaaviones;2x7
2;Buque;1x7
3;Submarino;1x5
4;Crucero;1x5
5;Lancha;1x2
6;Mina;1x1
*/

/*Funcion que coloca un barco, recibe como parametros el tablero, el tipo de barco, la orientacion y las coordenadas (x,y)
Devuelve un valor que indica la validez de la colocacion
Notar que el barco siempre sera colocado a la derecha o abajo de la coordenada (x,y)*/
//***Esta funcion puede ir a un archivo de cabecera en el futuro***
//***PENDIENTE: Expandir los errores, colocar mensajes en la terminal***
int placement(struct square board[21][21], int type, int rotation, int x, int y){
	int i, j, length, width;
    switch(type){ // -1 si no se puede colocar, -2 si excede el tablero, -3 si ya hay un barco en esa casilla, -4 si el tipo de barco no existe, 0 si se coloca correctamente
        case 1:
            length = 7;
            width = 2;
            if ((rotation != 1) && (rotation != 2)) return -1;
            if (rotation == 1){
                if (((x+length) >= 21) || ((y+width) >= 21)) return -2;
                for (i = x; i < x+length; i++){
                    for (j = y; j < y+width; j++){
                        if (board[i][j].is_ship != 0) return -3;
                    }
                }
                for (i = x; i < x+length; i++){
                    for (j = y; j < y+width; j++){
                        board[i][j].is_ship = 1;
                    }
                }
            } else {
                if (((x+width) >= 21) || ((y+length) >= 21)) return -2;
                for (i = x; i < x+width; i++){
                    for (j = y; j < y+length; j++){
                        if (board[i][j].is_ship != 0) return -3;
                    }
                }
                for (i = x; i < x+width; i++){
                    for (j = y; j < y+length; j++){
                        board[i][j].is_ship = 1;
                    }
                }
            }
            return 0;
            break;
        case 2:
            length = 7;
            width = 1;
            if ((rotation != 1) && (rotation != 2)) return -1;
            if (rotation == 1){
                if (((x+length) >= 21) || ((y+width) >= 21)) return -2;
                for (i = x; i < x+length; i++){
                    for (j = y; j < y+width; j++){
                        if (board[i][j].is_ship != 0) return -3;
                    }
                }
                for (i = x; i < x+length; i++){
                    for (j = y; j < y+width; j++){
                        board[i][j].is_ship = 1;
                    }
                }
            } else {
                if (((x+width) >= 21) || ((y+length) >= 21)) return -2;
                for (i = x; i < x+width; i++){
                    for (j = y; j < y+length; j++){
                        if (board[i][j].is_ship != 0) return -3;
                    }
                }
                for (i = x; i < x+width; i++){
                    for (j = y; j < y+length; j++){
                        board[i][j].is_ship = 1;
                    }
                }
            }
            return 0;
            break;
        case 3:
            length = 5;
            width = 1;
            if ((rotation != 1) && (rotation != 2)) return -1;
            if (rotation == 1){
                if (((x+length) >= 21) || ((y+width) >= 21)) return -2;
                for (i = x; i < x+length; i++){
                    for (j = y; j < y+width; j++){
                        if (board[i][j].is_ship != 0) return -3;
                    }
                }
                for (i = x; i < x+length; i++){
                    for (j = y; j < y+width; j++){
                        board[i][j].is_ship = 1;
                    }
                }
            } else {
                if (((x+width) >= 21) || ((y+length) >= 21)) return -2;
                for (i = x; i < x+width; i++){
                    for (j = y; j < y+length; j++){
                        if (board[i][j].is_ship != 0) return -3;
                    }
                }
                for (i = x; i < x+width; i++){
                    for (j = y; j < y+length; j++){
                        board[i][j].is_ship = 1;
                    }
                }
            }
            return 0;
            break;
        case 4:
            length = 5;
            width = 1;
            if ((rotation != 1) && (rotation != 2)) return -1;
            if (rotation == 1){
                if (((x+length) >= 21) || ((y+width) >= 21)) return -2;
                for (i = x; i < x+length; i++){
                    for (j = y; j < y+width; j++){
                        if (board[i][j].is_ship != 0) return -3;
                    }
                }
                for (i = x; i < x+length; i++){
                    for (j = y; j < y+width; j++){
                        board[i][j].is_ship = 1;
                    }
                }
            } else {
                if (((x+width) >= 21) || ((y+length) >= 21)) return -2;
                for (i = x; i < x+width; i++){
                    for (j = y; j < y+length; j++){
                        if (board[i][j].is_ship != 0) return -3;
                    }
                }
                for (i = x; i < x+width; i++){
                    for (j = y; j < y+length; j++){
                        board[i][j].is_ship = 1;
                    }
                }
            }
            return 0;
            break;
        case 5:
            length = 2;
            width = 1;
            if ((rotation != 1) && (rotation != 2)) return -1;
            if (rotation == 1){
                if (((x+length) >= 21) || ((y+width) >= 21)) return -2;
                for (i = x; i < x+length; i++){
                    for (j = y; j < y+width; j++){
                        if (board[i][j].is_ship != 0) return -3;
                    }
                }
                for (i = x; i < x+length; i++){
                    for (j = y; j < y+width; j++){
                        board[i][j].is_ship = 1;
                    }
                }
            } else {
                if (((x+width) >= 21) || ((y+length) >= 21)) return -2;
                for (i = x; i < x+width; i++){
                    for (j = y; j < y+length; j++){
                        if (board[i][j].is_ship != 0) return -3;
                    }
                }
                for (i = x; i < x+width; i++){
                    for (j = y; j < y+length; j++){
                        board[i][j].is_ship = 1;
                    }
                }
            }
            return 0;
            break;
        default:
            return -4;
            break;
        }
}


int main()
{
    struct square myboard[21][21]; //Inicializacion del tablero del usuario
    int i, j;
    for (i = 0; i < 21; i++){
        for (j = 0; j < 21; j++){
            myboard[i][j].is_ship = 0;
            myboard[i][j].bombed = 0;
        }
    }
    int player1gold = STARTING_GOLD;
    int player1ammo = STARTING_AMMO;
    int finishedplacing = 0;
    int finishedloop = 0;
    while(((player1gold > 5) || (finishedplacing == 0))&&(finishedloop == 2)){ //El loop se completa por lo menos dos veces, debido a la bandera finishedloop
        int type, x, y, rotation;
        printf("Ingrese el tipo de barco (1-5), 0 para terminar, si ya ha colocado un barco: ");
        scanf("%d", &type);
        switch(type){
            case 0:
                finishedplacing = 0;
                break;
            case 1:
                if(player1gold < 30) printf("Oro insuficiente\n");
                break;
            case 2:
                if(player1gold < 20) printf("Oro insuficiente\n");
                break;
            case 3:
                if(player1gold < 50) printf("Oro insuficiente\n");
                break;
            case 4:
                if(player1gold < 10) printf("Oro insuficiente\n");
                break;
            case 5:
                if(player1gold < 5) printf("Oro insuficiente\n");
                break;
            default:
                printf("Tipo de barco no valido\n");
                break;
        }
        printf("Inserte la coordenada x donde desea colocar el barco: \n");
        scanf("%d", &x);
        printf("Inserte la coordenada y donde desea colocar el barco: \n");
        scanf("%d", &y);
        printf("Inserte la orientacion del barco (1=Horizontal, 2=Vertical): \n");
        scanf("%d", &rotation);
        finishedplacing = placement(myboard, type, x, y, rotation); //No es necesario verificar aqui los valores de entrada, ya que placement devuelve valores de error en esos casos
        finishedloop++;
    }
    
    struct square theirboard[21][21]; //Inicializacion del tablero del rival
    for (i = 0; i < 21; i++){
        for (j = 0; j < 21; j++){
            theirboard[i][j].is_ship = 0;
            theirboard[i][j].bombed = 0;
        }
    }

    

    return 0;
}
