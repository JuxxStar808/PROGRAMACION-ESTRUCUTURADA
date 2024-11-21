#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<windows.h> 
#include<time.h>

#define MAXIMO_JUGADORES 50
#define CARAC_DE_LOS_NOMBRES 25
#define NUM_PREGUNTAS 10
#define MAX_RESPUESTA 256


//Declaración de  los arreglos, funciones y variables globales

char jugadores[MAXIMO_JUGADORES][CARAC_DE_LOS_NOMBRES];
int puntuacion[MAXIMO_JUGADORES];
int numero_jugadores = 0;
char nombreJugador[CARAC_DE_LOS_NOMBRES]; 
int indiceJugadorActual = -1; // Guardar el índice del jugador actual

void registrar_jugador();
void verificarJugador(char listaJugadores[][CARAC_DE_LOS_NOMBRES], int numero_jugadores);
void puntuaciones();
void jugar();

char letras[NUM_PREGUNTAS];
char preguntas[NUM_PREGUNTAS][256];
char respuestas[NUM_PREGUNTAS][256];
int respondidas[NUM_PREGUNTAS];
char colores[NUM_PREGUNTAS][8];
int pasapalabras;

//---------------------------------------------------------------------------------------------------

void pasaFetiche() {
    letras[0] = 'A';
    strcpy(preguntas[0], "Fetichismo que involucra a personas que realizan poses sugestivas o desarrollan actividad sexual en o debajo del agua.");
    strcpy(respuestas[0], "Acuafilia");
    respondidas[0] = 0;
    strcpy(colores[0], "\033[0m");

    letras[1] = 'B';
    strcpy(preguntas[1], "Filia de personas que disfrutan de ser atadas, mientras que otras disfrutan atando a su pareja y a otras les gustan ambos. .");
    strcpy(respuestas[1], "Bondage");
    respondidas[1] = 0;
    strcpy(colores[1], "\033[0m");

    letras[2] = 'C';
    strcpy(preguntas[2], "Es una parafilia, tener atracción por las piernas, el cual se puede dar en hombres y mujeres.");
    strcpy(respuestas[2], "Crurofilia");
    respondidas[2] = 0;
    strcpy(colores[2], "\033[0m");

    letras[3] = 'D';
    strcpy(preguntas[3], "Es la obtencion del placer sexual al tomar el control y la pareja sumisa obtiene placer al permitirles hacerlo.");
    strcpy(respuestas[3], "Dominio");
    respondidas[3] = 0;
    strcpy(colores[3], "\033[0m");

    letras[4] = 'E';
    strcpy(preguntas[4], "El mostrar los genitales a personas desconocidas para excitarse sexualmente");
    strcpy(respuestas[4], "Exhibicionismo");
    respondidas[4] = 0;
    strcpy(colores[4], "\033[0m");

    letras[5] = 'F';
    strcpy(preguntas[5], "Es el fetiche al sentir placer al rozar los genitales contra otra persona");
    strcpy(respuestas[5], "Froteurismo");
    respondidas[5] = 0;
    strcpy(colores[5], "\033[0m");

    letras[6] = 'G';
    strcpy(preguntas[6], "Es la atracción sexual hacia las personas de edad avanzada.");
    strcpy(respuestas[6], "Gerontofilia");
    respondidas[6] = 0;
    strcpy(colores[6], "\033[0m");

    letras[7] = 'H';
    strcpy(preguntas[7], "Es la excitación sexual que le provoca a ciertos individuos el usar ropa típica de su propio género.");
    strcpy(respuestas[7], "Homeovestismo");
    respondidas[7] = 0;
    strcpy(colores[7], "\033[0m");

    letras[8] = 'I';
    strcpy(preguntas[8], "Es cuando te excita la idea de que tu pareja se acueste con otras personas.");
    strcpy(respuestas[8], "Infieles");
    respondidas[8] = 0;
    strcpy(colores[8], "\033[0m");

    letras[9] = 'J';
    strcpy(preguntas[9], "Excitación por el relato de las propias hazañas sexuales.");
    strcpy(respuestas[9], "Jactitafilia");
    respondidas[9] = 0;
    strcpy(colores[9], "\033[0m");
}

void pasaFobia() {
    letras[0] = 'A';
    strcpy(preguntas[0], "Miedo a los hombres.");
    strcpy(respuestas[0], "Androfobia");
    respondidas[0] = 0;
    strcpy(colores[0], "\033[0m");

    letras[1] = 'B';
    strcpy(preguntas[1], "Miedo a los lugares profundos. .");
    strcpy(respuestas[1], "Batofobia");
    respondidas[1] = 0;
    strcpy(colores[1], "\033[0m");

    letras[2] = 'C';
    strcpy(preguntas[2], "Miedo a los perros.");
    strcpy(respuestas[2], "Corofobia");
    respondidas[2] = 0;
    strcpy(colores[2], "\033[0m");

    letras[3] = 'D';
    strcpy(preguntas[3], "Miedo a los arboles.");
    strcpy(respuestas[3], "Dendrofobia");
    respondidas[3] = 0;
    strcpy(colores[3], "\033[0m");

    letras[4] = 'E';
    strcpy(preguntas[4], "Miedo a los espejos.");
    strcpy(respuestas[4], "Espectrofobia");
    respondidas[4] = 0;
    strcpy(colores[4], "\033[0m");

    letras[5] = 'F';
    strcpy(preguntas[5], "Miedo a Francia, los franceses y la cultura francesa.");
    strcpy(respuestas[5], "Francofobia");
    respondidas[5] = 0;
    strcpy(colores[5], "\033[0m");

    letras[6] = 'G';
    strcpy(preguntas[6], "Miedo a las mujeres.");
    strcpy(respuestas[6], "Ginefobia");
    respondidas[6] = 0;
    strcpy(colores[6], "\033[0m");

    letras[7] = 'H';
    strcpy(preguntas[7], "Miedo a dormir.");
    strcpy(respuestas[7], "Hipnofobia");
    respondidas[7] = 0;
    strcpy(colores[7], "\033[0m");

    letras[8] = 'I';
    strcpy(preguntas[8], "Miedo a las ideas.");
    strcpy(respuestas[8], "Ideofobia");
    respondidas[8] = 0;
    strcpy(colores[8], "\033[0m");

    letras[9] = 'J';
    strcpy(preguntas[9], "Miedo a los Japoneses.");
    strcpy(respuestas[9], "Japanofobia");
    respondidas[9] = 0;
    strcpy(colores[9], "\033[0m");
}


void mostrarEstado() {
    printf("Estado del juego:\n");
    printf("                   %s%c\033[0m %s%c \033[0m\n", colores[0], letras[0], colores[1], letras[1]);
    printf("              %s   %c \033[0m    %s%c \033[0m\n", colores[9], letras[9], colores[2], letras[2]);
    printf("               %s %c \033[0m  ?   %s%c \033[0m\n", colores[8], letras[8], colores[3], letras[3]);
    printf("               %s  %c \033[0m   %s %c \033[0m\n", colores[7], letras[7], colores[4], letras[4]);
    printf("                  %s %c\033[0m %s%c \033[0m\n", colores[6], letras[6], colores[5], letras[5]);
}

int procesarRespuesta(int index, char respuesta[MAX_RESPUESTA]) {
    if (strcmp(respuesta, "Pasapalabra") == 0) {
        if (pasapalabras > 0) {
            respondidas[index] = 3;
            //Color azul
            strcpy(colores[index], "\033[1;34m");
            pasapalabras--;
            return 0;
        } else {
            respondidas[index] = 2;
            //Color Rojo
            strcpy(colores[index], "\033[1;31m");
            return -1;
        }
    } else if (strcasecmp(respuesta, respuestas[index]) == 0) {
        respondidas[index] = 1;
        //Color Verde
        strcpy(colores[index], "\033[1;32m");
        return 1;
    } else {
        respondidas[index] = 2;
        //Color Rojo
        strcpy(colores[index], "\033[1;31m");
        return -1;
    }
}

void juegoReglas() {
    int puntaje = 0;
    int respuestasCorrectas = 0;
    pasapalabras = 3;
    int pasapalabrasUsados = 0;
    int i;
    int quedanPreguntas = 1;

    while (quedanPreguntas) {
        quedanPreguntas = 0;
        for (i = 0; i < NUM_PREGUNTAS; i++) {
            if (respondidas[i] == 0 || respondidas[i] == 3) {
                system("cls");
                mostrarEstado();
                printf("Con la letra %c, %s\n", letras[i], preguntas[i]);
                printf("Respuesta: ");
                char respuesta[MAX_RESPUESTA];
                scanf("%s", respuesta);

                int resultado = procesarRespuesta(i, respuesta);

                if (resultado == 1) {
                    printf("Correcto, has ganado 15 puntos.\n");
                    puntaje += 15; // Sumar 15 puntos por respuesta correcta
                    respuestasCorrectas++;
                } else if (resultado == -1) {
                    printf("Tu respuesta no es correcta, es %s.\n", respuestas[i]);
                } else if (resultado == 0) {
                    printf("Pasapalabra aplicado.\n");
                    pasapalabrasUsados++;
                    quedanPreguntas = 1;
                }

                // Pausa
                printf("Presiona Enter para continuar...\n");
                getchar(); // Captura el Enter adicional después de la respuesta
                getchar(); // Captura el Enter adicional después de la respuesta
            }
        }
    }

    // Reglas adicionales 
    if (respuestasCorrectas == NUM_PREGUNTAS && pasapalabrasUsados == 0) {
        puntaje *= 2; // Duplicar puntaje si todas las respuestas fueron correctas y no se usaron pasapalabras
    } else if (respuestasCorrectas == NUM_PREGUNTAS && pasapalabrasUsados > 0) {
        puntaje += 30; // Sumar 30 puntos si todas las respuestas fueron correctas y se usaron pasapalabras
    }

    puntaje -= 3 * pasapalabrasUsados; // Restar puntos por cada pasapalabra usado

    // Actualización de la puntuación
    if (puntaje > puntuacion[indiceJugadorActual]) {
        puntuacion[indiceJugadorActual] = puntaje;
        printf("¡Nuevo puntaje más alto! Puntuación actualizada.\n");
    } else {
        printf("No superaste tu puntaje más alto anterior de %d puntos. \n", puntuacion[indiceJugadorActual]);
    }

    printf("¡Partida terminada!\n Puntuacion: %d puntos.\n", puntaje);
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("..");
    Sleep(5000);
    printf("...");
    system("cls");
}

void registrar_jugador() {
    system("cls");
    char jugador_nuevo[CARAC_DE_LOS_NOMBRES];
    int i;
    printf("   ------------------------------------ ");
    printf("\n     Ingresa el nombre del Jugador: ");
    fgets(jugador_nuevo, CARAC_DE_LOS_NOMBRES, stdin);
     printf("\n   ------------------------------------ ");
    size_t len = strlen(jugador_nuevo);
    if (len > 0 && jugador_nuevo[len - 1] == '\n') {
        jugador_nuevo[len - 1] = '\0';
    }

    // Verificar si el jugador ya está registrado
    for (i = 0; i < numero_jugadores; i++) {
        if (strcmp(jugadores[i], jugador_nuevo) == 0) {
            printf("\n    El nombre %s ya esta registrado, por favor ingresa otro nombre.\n", jugador_nuevo);
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf("..");
            Sleep(1000);
            printf("...");
            system("cls");
            return;
        }
    }

    // Registrar nuevo jugador
    strcpy(jugadores[numero_jugadores], jugador_nuevo);
    puntuacion[numero_jugadores] = 0;
    numero_jugadores++;

    printf("\n    Registro de %s exitoso.\n", jugador_nuevo);
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("..");
    Sleep(1000);
    printf("...");
    system("cls");
}

void pasaPalabras() {
    int categoria;

    system("cls");
    printf("   S e l e c c i o n a   u n a   c a t e g o r i a: \n\n");
    printf("   1. Pasapalabra de fetiches \n");
    printf("   2. Pasapalabra de fobias \n");
    printf("   Respuesta: ");
    scanf("%d", &categoria);
    getchar();  // Consumir el salto de línea restante del buffer

    switch (categoria) {
        case 1:
            printf("    ¡Bienvenido al pasapalabra de FETICHES! Iniciamos…\n");
            pasaFetiche();  // Inicializa las preguntas y respuestas de animales
            juegoReglas();
            break;
         case 2:
            printf("    ¡Bienvenido al pasapalabra de  FOBIAS! Iniciamos…\n");
            pasaFobia();  // Inicializa las preguntas y respuestas de animales
            juegoReglas();
            break;
        // Aquí se podrían agregar más categorías
        default:
            printf("    Categoria no valida.\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf("..");
            Sleep(1000);
            printf("...");
            system("cls");
            break;
    }
}

void verificarJugador(char listaJugadores[][CARAC_DE_LOS_NOMBRES], int numero_jugadores) {
    system("cls");
    int i;

    printf("\n\n    Escribe tu usuario: ");
    fgets(nombreJugador, sizeof(nombreJugador), stdin);

    size_t len = strlen(nombreJugador);
    if (len > 0 && nombreJugador[len - 1] == '\n') {
        nombreJugador[len - 1] = '\0';
    }

    for (i = 0; i < numero_jugadores; i++) {
        if (strcmp(listaJugadores[i], nombreJugador) == 0) {
            printf("Bienvenido, %s!\n", nombreJugador);
            indiceJugadorActual = i; 
			pasaPalabras();
            return; 
        }
    }
    printf("\n    No estas registrado!\n");
    Sleep(2000);
    system("cls");
    
}


void verificarJugadorPuntuacion(char listaJugadores[][CARAC_DE_LOS_NOMBRES], int numero_jugadores) {
    system("cls");
    int i;

    printf("\n\n    Escribe tu usuario: ");
    fgets(nombreJugador, sizeof(nombreJugador), stdin);

    size_t len = strlen(nombreJugador);
    if (len > 0 && nombreJugador[len - 1] == '\n') {
        nombreJugador[len - 1] = '\0';
    }

    for (i = 0; i < numero_jugadores; i++) {
        if (strcmp(listaJugadores[i], nombreJugador) == 0) {
            return; // Añadir return para salir del bucle si el usuario es encontrado
        }
    }
    printf("    ¡No estas registrado!\n"); // Mover fuera del bucle para mostrar solo una vez si no se encuentra el usuario
}

void puntuaciones() {
    system("cls");
    int i, j;
    
    // Preguntar el nombre del usuario y verificar si está registrado
    verificarJugadorPuntuacion(jugadores, numero_jugadores);

    // Verificar si el usuario está registrado
    if (indiceJugadorActual != -1) {
        // Mostrar la puntuación del jugador actual y su posición
        printf("   Tu puntuación actual es: %d puntos.\n", puntuacion[indiceJugadorActual]);
        for (i = 0; i < numero_jugadores - 1; i++) {
            for (j = 0; j < numero_jugadores - i - 1; j++) {
                if (puntuacion[j] < puntuacion[j + 1]) {
                    // Intercambiar puntuaciones
                    int temp_puntuacion = puntuacion[j];
                    puntuacion[j] = puntuacion[j + 1];
                    puntuacion[j + 1] = temp_puntuacion;
                    
                    // Intercambiar nombres de jugadores
                    char temp_nombre[CARAC_DE_LOS_NOMBRES];
                    strcpy(temp_nombre, jugadores[j]);
                    strcpy(jugadores[j], jugadores[j + 1]);
                    strcpy(jugadores[j + 1], temp_nombre);
                }
            }
        }

        // Encontrar la posición del jugador actual
        int posicion = -1;
        for (i = 0; i < numero_jugadores; i++) {
            if (strcmp(jugadores[i], nombreJugador) == 0) {
                posicion = i + 1;
                break;
            }
        }

        printf("\n   Tu posición actual en la tabla es: %d\n", posicion);
    }

    printf("\n    Puntuaciones de los jugadores registrados:\n");
    for (i = 0; i < numero_jugadores; i++) {
        printf("%d. %s: %d puntos\n", i + 1, jugadores[i], puntuacion[i]);
    }
    
    printf("\n\n Presiona Enter para continuar...\n");
    getchar(); // Captura el Enter adicional después de la respuesta
    system("cls");
}


void jugar() {
    verificarJugador(jugadores, numero_jugadores);
}

void menu() {
    system("cls");
    int opcion;  // La opción nos va ayudar para que escojan el camino que quieran tomar
    do {
    	printf("   -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. ");
        printf("\n\n\n             M E N U    P R I N C I P A L \n     ");
        printf("\n   -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. ");
        printf("\n\n    1. Registrar Jugadores.                          ");
        printf("\n      2. Verificar las puntuaciones.                   ");
        printf("\n      3. Jugar.\n                                      ");
        printf("\n      4. Salir del Juego.                              ");
        printf("\n\n    Ingresa tu opcion: ");
        scanf("%d", &opcion);  // Aquí se guarda la variable opción
        getchar();  // Consumir el salto de línea restante del buffer

        switch (opcion) {  // Aquí se usó un switch para cada opción del menú
            case 1:  // Aquí el caso 1, Registro de los jugadores
                registrar_jugador();
                break;

            case 2:  // Aquí el caso 2, Las puntuaciones
                puntuaciones();
                break;

            case 3:  // Aquí el caso 3, Jugar
                jugar();
                break;

            case 4:  // Aquí el caso 4, la salida de juego
                system("cls");
			    printf("\n Gracias por jugar PasaPalabra!\n");
                break;

            default:  // Y por último el default, que es cuando selecciona una opción que no está en el menú
                printf("\n Opcion no válida, por favor inténtalo de nuevo con el número de opciones mostradas :)\n");
                break;
        }
    } while (opcion != 4);  // Aquí se usó un bucle, para que puedan viajar en el menú sin salir del programa
}

void portada(){
	printf("\n\n\n");
	printf("       ¦¦¦¦¦¦+  ¦¦¦¦¦+ ¦¦¦¦¦¦¦+ ¦¦¦¦¦+ ¦¦¦¦¦¦+  ¦¦¦¦¦+ ¦¦+      ¦¦¦¦¦+ ¦¦¦¦¦¦+ ¦¦¦¦¦¦+  ¦¦¦¦¦+ \n");
    printf("       ¦¦+--¦¦+¦¦+--¦¦+¦¦+----+¦¦+--¦¦+¦¦+--¦¦+¦¦+--¦¦+¦¦¦     ¦¦+--¦¦+¦¦+--¦¦+¦¦+--¦¦+¦¦+--¦¦+\n");
    printf("       ¦¦¦¦¦¦++¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦+¦¦¦¦¦¦¦¦¦¦¦¦¦¦++¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦++¦¦¦¦¦¦++¦¦¦¦¦¦¦¦\n");
    printf("       ¦¦+---+ ¦¦+--¦¦¦+----¦¦¦¦¦+--¦¦¦¦¦+---+ ¦¦+--¦¦¦¦¦¦     ¦¦+--¦¦¦¦¦+--¦¦+¦¦+--¦¦+¦¦+--¦¦¦\n");
    printf("       ¦¦¦     ¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦     ¦¦¦  ¦¦¦¦¦¦¦¦¦¦+¦¦¦  ¦¦¦¦¦¦¦¦¦++¦¦¦  ¦¦¦¦¦¦  ¦¦¦\n");
    printf("       +-+     +-+  +-++------++-+  +-++-+     +-+  +-++------++-+  +-++-----+ +-+  +-++-+  +-+\n");
    printf("\n                                         B I E N V E N I D O                                   ");                                        
	Sleep(1000);
    printf("                                                 .");
    Sleep(1000);
    printf("                                    .");
    Sleep(1000);
    printf("                             .");
    printf("\n\n         Presiona Enter para continuar...\n");
	getchar(); // Captura el Enter adicional después de la respuesta
}


int main() {
	portada();
    menu();
    return 0;
}
