// Primera Entrega Trabajo Practico Final - Lucas Jara y Guillermo Laguardia

#include <stdio.h>
#include <stdlib.h>

#define TAM_TABLERO 21
/*
Cada casilla es una estructura que almacena dos valores enteros para cada casilla: la existencia o ausencia de un barco y si fue atacada o no. 
*/
struct casilla {
	int existe_barco;
	int fue_atacada;
};

/* 
La funcion para colocar barcos por ahora recibe como parametro un tablero, en el cual el jugador selecciona el tipo de barco, 
su orientacion y ubicacion , verificando que no exceda los limites del tablero. Queda pendiente la implementacion del sistema de oro 
y una verificacion exhaustiva de cada casilla, posiblemente mediante otra funcion externa
*/

int colocar(struct casilla tablero[TAM_TABLERO][TAM_TABLERO]){
	printf("Elija el barco a colocar \n 1 para Portaaviones (2x7) \n 2 para Buque (1x7) \n 3 para Submarino (1x5) \n 4 para Crucero (1x5) \n 5 para Lancha (1x2): ");
    int seleccion, orientacion;
    scanf("%d", seleccion);
    printf("Elija la orientacion: 1 para horizontal, 2 para vertical:\n");
    scanf("%d", orientacion);
    printf("Ingrese las coordenadas (X,Y).\n El tablero es de 21x21.\n La casilla corresponde a la esquina superior izquierda del barco.");
    switch (seleccion){
        case 1:
            int fila, columna;
            scanf("Fila: %d", fila);
            fila -= 1;
            scanf("Columna: %d", columna);
            columna -= 1;
            if ((orientacion == 1)&&((columna > 14)||(fila < 19))){
                printf("El barco no puede ser colocado en estas coordenadas");
                return(-1);
            }else if((orientacion == 2)&&((columna > 19)||(fila > 14))){
                printf("El barco no puede ser colocado en estas coordenadas");
                return(-1);
            }
            if (orientacion == 1){
                for (int i = fila; i < fila + 2; i++){
                    for (int j = columna; j < columna + 7; j++){
                        tablero[i][j].existe_barco = 1;
                    };
                };
                return(0);
            }else if(orientacion == 2){
                for (int i = fila; i < fila + 7; i++){
                    for (int j = columna; j < columna + 2; j++){
                        tablero[i][j].existe_barco = 1;
                    }
                }
                return(0);
            }else{
                printf("Error, revisar las entradas");
                return(-1);
                };
            break;
        case 2:
            int fila, columna;
            scanf("Fila: %d", fila);
            fila -= 1;
            scanf("Columna: %d", columna);
            columna -= 1;
            if ((orientacion == 1)&&((columna > 14)||(fila < 20))){
                printf("El barco no puede ser colocado en estas coordenadas");
                return(-1);
            }else if((orientacion == 2)&&((columna > 20)||(fila > 14))){
                printf("El barco no puede ser colocado en estas coordenadas");
                return(-1);
            }
            if (orientacion == 1){
                for (int i = fila; i < fila + 1; i++){
                    for (int j = columna; j < columna + 7; j++){
                        tablero[i][j].existe_barco = 1;
                    };
                };
                return(0);
            }else if(orientacion == 2){
                for (int i = fila; i < fila + 1; i++){
                    for (int j = columna; j < columna + 2; j++){
                        tablero[i][j].existe_barco = 1;
                    }
                }
                return(0);
            }else{
                printf("Error, revisar las entradas");
                return(-1);
                };
            break;
        case 3:
            int fila, columna;
            scanf("Fila: %d", fila);
            fila -= 1;
            scanf("Columna: %d", columna);
            columna -= 1;
            if ((orientacion == 1)&&((columna > 16)||(fila < 20))){
                printf("El barco no puede ser colocado en estas coordenadas");
                return(-1);
            }else if((orientacion == 2)&&((columna > 20)||(fila > 16))){
                printf("El barco no puede ser colocado en estas coordenadas");
                return(-1);
            }
            if (orientacion == 1){
                for (int i = fila; i < fila + 1; i++){
                    for (int j = columna; j < columna + 5; j++){
                        tablero[i][j].existe_barco = 1;
                    };
                };
                return(0);
            }else if(orientacion == 2){
                for (int i = fila; i < fila + 1; i++){
                    for (int j = columna; j < columna + 5; j++){
                        tablero[i][j].existe_barco = 1;
                    }
                }
                return(0);
            }else{
                printf("Error, revisar las entradas");
                return(-1);
                };
            break;
        case 4:
            int fila, columna;
            scanf("Fila: %d", fila);
            fila -= 1;
            scanf("Columna: %d", columna);
            columna -= 1;
            if ((orientacion == 1)&&((columna > 16)||(fila < 20))){
                printf("El barco no puede ser colocado en estas coordenadas");
                return(-1);
            }else if((orientacion == 2)&&((columna > 20)||(fila > 16))){
                printf("El barco no puede ser colocado en estas coordenadas");
                return(-1);
            }
            if (orientacion == 1){
                for (int i = fila; i < fila + 1; i++){
                    for (int j = columna; j < columna + 5; j++){
                        tablero[i][j].existe_barco = 1;
                    };
                };
                return(0);
            }else if(orientacion == 2){
                for (int i = fila; i < fila + 1; i++){
                    for (int j = columna; j < columna + 5; j++){
                        tablero[i][j].existe_barco = 1;
                    }
                }
                return(0);
            }else{
                printf("Error, revisar las entradas");
                return(-1);
                };
            break;
        case 5:
            int fila, columna;
            scanf("Fila: %d", fila);
            fila -= 1;
            scanf("Columna: %d", columna);
            columna -= 1;
            if ((orientacion == 1)&&((columna > 19)||(fila < 20))){
                printf("El barco no puede ser colocado en estas coordenadas");
                return(-1);
            }else if((orientacion == 2)&&((columna > 20)||(fila > 19))){
                printf("El barco no puede ser colocado en estas coordenadas");
                return(-1);
            }
            if (orientacion == 1){
                for (int i = fila; i < fila + 1; i++){
                    for (int j = columna; j < columna + 2; j++){
                        tablero[i][j].existe_barco = 1;
                    };
                };
                return(0);
            }else if(orientacion == 2){
                for (int i = fila; i < fila + 1; i++){
                    for (int j = columna; j < columna + 2; j++){
                        tablero[i][j].existe_barco = 1;
                    }
                }
                return(0);
            }else{
                printf("Error, revisar las entradas");
                return(-1);
                };
            break;
        }
    };



int main(void) {
	struct casilla tablero[TAM_TABLERO][TAM_TABLERO]; // Este bloque de codigo genera un tablero vacio
	for (int i = 0; i < TAM_TABLERO; i++){
		for (int j = 0; i < TAM_TABLERO; j++){
			tablero[i][j].existe_barco = 0;
			tablero[i][j].fue_atacada = 0;
		}
	}
	return EXIT_SUCCESS;
}
