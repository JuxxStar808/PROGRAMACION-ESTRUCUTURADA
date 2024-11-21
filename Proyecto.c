#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h> 

void menu() {
    int opcion;  
    do {
    	system("cls");
    	printf("   -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. ");
        printf("\n\n\n             M E N U    P R I N C I P A L \n     ");
        printf("\n   -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. ");
        printf("\n      1. Registrar Jugadores.                          ");
        printf("\n      2. Verificar las puntuaciones.                   ");
        printf("\n      3. Jugar.\n                                      ");
        printf("\n      4. Salir del Juego.                              ");
        
        printf("\n\n    Ingresa tu opcion disponible: ");
        scanf("%i", &opcion); 
        getchar();  

        switch (opcion) { 
            case 1:  
//                registrar_jugador();
                break;

            case 2:  
//                puntuaciones();
                break;

            case 3:  
//                jugar();
                break;

            case 4:  
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
