#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h> 
#include <string.h>


#define FILAS 4
#define COLUMNAS 10
#define MAX_PASAJEROS 40


struct Pasajero {
    char nombre[50];
    int asientoFila;
    int asientoColumna;
};

// Prototipos de funciones
void inicializarAsientos(int asientos[FILAS][COLUMNAS]);
void mostrarAsientos(int asientos[FILAS][COLUMNAS]);
void reservarAsiento(int asientos[FILAS][COLUMNAS], struct Pasajero pasajeros[], int *contadorPasajeros);
void guardarReservaciones(struct Pasajero pasajeros[], int contadorPasajeros);
void cargarReservaciones(int asientos[FILAS][COLUMNAS], struct Pasajero pasajeros[], int *contadorPasajeros);

// Inicializa la matriz de asientos a 0 (disponibles)
void inicializarAsientos(int asientos[FILAS][COLUMNAS]) {
	int i,j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            asientos[i][j] = 0;
        }
    }
}

// Muestra los asientos disponibles y ocupados
void mostrarAsientos(int asientos[FILAS][COLUMNAS]) {
	int i,j;
    printf("\nAsientos del autobús (0 = Disponible, 1 = Ocupado):\n");
    for ( i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("[%d] ", asientos[i][j]);
        }
        printf("\n");
    }
    getchar(); 
}

// Reserva un asiento y guarda los datos del pasajero
void reservarAsiento(int asientos[FILAS][COLUMNAS], struct Pasajero pasajeros[], int *contadorPasajeros) {
    int fila, columna,confirmar = 0;
    char nombre[50];

    printf("\nIngrese su nombre: ");
    scanf(" %[^\n]", nombre);
    printf("Ingrese el número de fila (1-%d): ", FILAS);
    scanf("%d", &fila);
    printf("Ingrese el número de columna (1-%d): ", COLUMNAS);
    scanf("%d", &columna);

    // Validar que el asiento esté disponible
    if (fila < 1 || fila > FILAS || columna < 1 || columna > COLUMNAS || asientos[fila - 1][columna - 1] == 1) {
        printf("El asiento seleccionado no está disponible. Intente nuevamente.\n");
        return;
    }

    // Marcar el asiento como ocupado
    asientos[fila - 1][columna - 1] = 1;

    // Guardar los datos del pasajero
    strcpy(pasajeros[*contadorPasajeros].nombre, nombre);
    pasajeros[*contadorPasajeros].asientoFila = fila - 1;
    pasajeros[*contadorPasajeros].asientoColumna = columna - 1;
    (*contadorPasajeros)++;
    
    while(confirmar == 0){
    	 printf("\n Confirma tu reservacion digitando 1: ");
         scanf("%i", &confirmar);
    
        if(confirmar == 1){
        	confirmar = 1;
            printf("¡Reservación exitosa para %s en el asiento (%d, %d)!\n", nombre, fila, columna);
        	guardarReservaciones(pasajeros, contadorPasajeros);
     	}else{
     		confirmar = 2;
		 }
	}
    
    getchar(); 
}

// Guarda las reservaciones en un archivo
void guardarReservaciones(struct Pasajero pasajeros[], int contadorPasajeros) {
    FILE *archivo = fopen("reservaciones.txt", "a");
    int i;
    if (archivo == NULL) {
        printf("Error al guardar las reservaciones.\n");
        return 1;
    }

    for (i = 0; i < contadorPasajeros; i++) {
        fprintf(archivo, "%s %d %d\n", pasajeros[i].nombre, pasajeros[i].asientoFila, pasajeros[i].asientoColumna);
    }

    fclose(archivo);
}

// Carga las reservaciones desde un archivo
void cargarReservaciones(int asientos[FILAS][COLUMNAS], struct Pasajero pasajeros[], int *contadorPasajeros) {
    FILE *archivo = fopen("reservaciones.txt", "r");
    if (archivo == NULL) {
        printf("No se encontró un archivo previo de reservaciones. Iniciando en blanco.\n");
        return;
    }

    while (fscanf(archivo, " %49s %d %d", pasajeros[*contadorPasajeros].nombre, 
                  &pasajeros[*contadorPasajeros].asientoFila, 
                  &pasajeros[*contadorPasajeros].asientoColumna) == 3) {
        int fila = pasajeros[*contadorPasajeros].asientoFila;
        int columna = pasajeros[*contadorPasajeros].asientoColumna;
        asientos[fila][columna] = 1; // Marcar asiento como ocupado
        (*contadorPasajeros)++;
    }

    fclose(archivo);
    
}


void menu() {
	
	int asientos[FILAS][COLUMNAS];
    struct Pasajero pasajeros[MAX_PASAJEROS];
    int contadorPasajeros = 0;

    // Inicializar asientos y cargar reservaciones previas
    inicializarAsientos(asientos);
    cargarReservaciones(asientos, pasajeros, &contadorPasajeros);
    
    int opcion;  
    do {
    	system("cls");
    	printf("   -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. ");
        printf("\n\n\n             M E N U    P R I N C I P A L \n     ");
        printf("\n   -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. \n\n");
        printf("1. Mostrar asientos disponibles\n");
        printf("2. Reservar un asiento\n");
        printf("3. Salir. \n");
        printf("\n\n    Ingresa tu opcion disponible: ");
        scanf("%i", &opcion); 
        getchar();  

        switch (opcion) { 
            case 1:  
            mostrarAsientos(asientos);
                break;

            case 2:  
            reservarAsiento(asientos, pasajeros, &contadorPasajeros);
                break;

            case 3:  
                system("cls");
			    printf("\n Gracias por jugar PasaPalabra!\n");
                break;
            default:  
                printf("\n Esta opcion no esta disponible.\n");
                printf("   .");
                Sleep(1000);
                printf("   .");
                Sleep(1000);
                printf("   .");
                Sleep(1000);
                break;
        }
    } while (opcion != 4);  
}


int main(){
	
	printf("\n\n                      CENTRO UNIVERSITARIO DE CIENCIAS EXACTAS E INGENIERIAS  ");  
	printf("\n\n\n");

    printf("\n\n    Creado por: Cristian Javier Garcia Covarrubias.");
    printf("\n\n    Materia: Programacion Estructurada.");
    printf("\n\n    Meestra: Veronica Camacho Santillan.\n");
    
     printf("\n                                              MOTOR DE RESERVACIONES                                    ");                                        
	Sleep(1000);
    printf("                                      BIENVEINDO ");
    Sleep(1000);
    printf("                       A ");
    Sleep(1000);
    printf("                 BALAAM VIAJES ");
    printf("\n\n         Presiona Enter para continuar...\n");
	getchar(); 
	
	menu();
	

	
	
	return 0;
}
