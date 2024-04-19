//Trabajo Practico Final - Lucas Jara y Guillermo Laguardia

/*
Para referencia: (valor asignado;tipo;area)(la mina a efectos practicos es un barco mas)
1;Portaaviones;2x7
2;Buque;1x7
3;Submarino;1x5
4;Crucero;1x5
5;Lancha;1x2
6;Mina;1x1
*/

#include <stdio.h>
#include <stdlib.h>

#define STARTING_GOLD 115
#define STARTING_AMMO 100

/*Cada casilla  es un stuct que contiene un valor que indica si hay un barco o no y su tipo, y un valor que indica si la casilla ha sido bombardeada o no*/

struct square{
	int is_ship;
	int bombed;
};

struct pivot{
    int x;
    int y;
    int type;
    int rotation;
};

struct pivot pivots[1] = {{0,0,0,0}};

void addship(struct pivot* pivotvector, int x, int y, int type, int rotation){
    pivotvector = realloc(pivotvector, 1 * sizeof(struct pivot));
    if(pivots == NULL){
        exit(1);
    }
    int i = (sizeof pivotvector)/(sizeof pivotvector[0]);
    pivotvector[i].x = x;
    pivotvector[i].y = y;
    pivotvector[i].type = type;
    pivotvector[i].rotation = rotation;
}
int shipregistry[7] = {0,0,0,0,0,0,0}; //Vector que registra cuantos barcos hay de cada tipo, la posicion 0 no es usada

/*Vector de letras para convertir coordenadas a caracteres*/
char letras[21] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'}; 

/*Funcion para convertir los caracteres a numeros*/
int letranumero(char letra){
    int i;
    for (i=0; i<21; i++){
        if (letra == letras[i]){
            return i+1;
        }
    }
    return -1;
}

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

/*Funcion que permite disparar, recibe como parametro el tablero rival y las coordenadas (x,y)
Devuelve un valor que indica la validez del disparo: 0 si el disparo no ha sido exitoso, 1 si el disparo ha sido exitoso, 
-1 si ya se ha disparado en esa casilla
Pensado para que pueda usarse tambien con los misiles*/
int shoot(struct square board[21][21], int x, int y){
    if (board[x][y].bombed == 1) return -1; //La casilla ya ha sido disparada
    board[x][y].bombed = 1;
    if (board[x][y].is_ship == 1) return 1; //Acierto
    return 0; //Fallo
}

/*Funcion que permite lanzar la bomba atomica, recibe como parametro un tablero y las coordenadas centrales (x,y), pero cubre un rango de 5x5
No puede ser lanzada en una casilla ya bombardeada o en las 2 filas y columnas mas externas de cada borde*/
int nuke(struct square board[21][21], int x, int y){
    if ((x-2)<0 || (y-2)<0 || (x+2)>=21 || (y+2)>=21) return -2; // Fuera de rango
    if (board[x][y].bombed == 1) return -1; // Ya bombardeada
    for (int i = x-2; i <= x+2; i++){
        for (int j = y-2; j <= y+2; j++){
            if ((i >= 0) && (j >= 0) && (i < 21) && (j < 21)) board[i][j].is_ship = 1;
        }
    }
    return 0; // Disparo exitoso
}

/*Funcion que realiza un ataque aereo en 7 casillas arriba de la coordenada (x,y). Devuelve 0 si no hubo impacto, 1 si hubo impacto */
int airstrike(struct square board[21][21], int x, int y){
    int excess = 0;
    int hit;
    for (int j = (y - 1) ; j = (y - 7) ; j--){
        if(j < 0) break; //Si se sale del rango del tablero, se rompe el loop
        board[x][j].bombed = 1;
        if(board[x][j].is_ship == 1) hit = 1;    
    }
    if(hit == 1) return 0; // Hubo impacto
    return 1; // No hubo impacto
};

/*Funcion que lanza 3 misiles, recibe como parametro un tablero*/
int missile(struct square board[21][21]){
    int missilesuccess = 0; //Bandera para saber si el disparo ha sido exitoso
    for (int i = 0; i<3; i++){ //Se dispara 3 veces
        while(missilesuccess != 1){ //Mientras el disparo no sea exitoso, se repite
            printf("Ingrese las coordenadas del disparo: ");
            int x, y;
            scanf("%d %d", &x, &y);
            missilesuccess = shoot(board, x, y); //Uso de la funcion shoot para disparar
            if(missilesuccess == -1){
                printf("La casilla ya ha sido disparada\n");
            }else if(missilesuccess == 1){
                printf("Disparo exitoso\n");
            } else {
                printf("Disparo fallido\n");
            }
        }
    }
}

/*Funcion para colocar minas, recibe como parametro un tablero y las coordenadas (x,y)*/
int mine(struct square board[21][21], int x, int y){
    if(board[x][y].is_ship != 0) return -1; //La casilla ya esta ocupada
    board[x][y].is_ship = 6;
    return 0; //Colocado con exito
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
    while(((player1gold > 5) || (finishedplacing == 1))&&(finishedloop == 2)){ //El loop se completa por lo menos dos veces, debido a la bandera finishedloop
        int type, x, y, rotation;
        printf("Ingrese el tipo de barco (1-5), 0 para terminar, si ya ha colocado un barco: ");
        scanf("%d", &type);
        switch(type){
            case 0:
                finishedplacing = 1;
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
                printf("Tipo de barco no valido, o error en la entrada\n");
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
    if (player1gold < 0){
        printf("Desea convertir el oro restante en municion? (Y/N)\n");
        char answer;
        scanf("%c", &answer);
        if (answer == 'Y'){
            player1ammo = player1ammo + player1gold;
            player1gold = 0;
        }
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
