#include <stdio.h>
#include <time.h>
#include "animacion.h"
#include "colores.h"

#define ANCHO 54
#define CUADRO 24

static void pausa_ms(long milisegundos) {
    clock_t inicio = clock();
    double espera = (double)milisegundos / 1000.0;
    while ((double)(clock() - inicio) / CLOCKS_PER_SEC < espera) {
        /* Espera breve y portable en C estandar. */
    }
}

static void dibujar(int posicion, int etapa, int total, double km,
                    double velocidad, double energia, int cuadro) {
    int i;
    printf("\033[H\033[J");
    printf(C_TITULO "================ ARTEMIS - SEGUIMIENTO DE ORION ================\n" C_RESET);
    printf(C_SEC "                 VISTA ESQUEMATICA DE TRAYECTORIA              \n" C_RESET);
    puts("");
    printf(C_TIERRA "   TIERRA" C_RESET C_SEC "                                                   " C_LUNA "LUNA\n" C_RESET);
    printf(C_TIERRA "    .--.                                                     " C_LUNA ".-.-.\n" C_RESET);
    printf(C_TIERRA "   (    )" C_RESET);
    for (i = 0; i < ANCHO; ++i) {
        if (i == posicion) printf(C_NAVE "<O>" C_RESET);
        else if (i == ANCHO - 1) printf(C_DORADO "*" C_RESET);
        else printf(C_SEC "-" C_RESET);
    }
    printf(C_LUNA " (  )\n    '--'                                                     '-'\n" C_RESET);
    puts("");
    printf(C_VERDE "  ETAPA %d/%d     Avance representado: %3d%%\n" C_RESET, etapa, total,
           (etapa * 100) / total);
    printf(C_TEXTO "  Distancia representada: %.1f km\n  Velocidad TLI de referencia: %.0f m/s\n  Energia cinetica inicial: %.3e J\n" C_RESET, km, velocidad, energia);
    puts("");
    printf(C_VERDE "  ESTADO: motores apagados - desplazamiento por inercia y gravedad\n" C_RESET);
    printf(C_SEC "  Nota: animacion didactica; no calcula una orbita numerica real.\n" C_RESET);
    fflush(stdout);
    (void)cuadro;
}

void animar_tramo_orion(int etapa, int total_etapas, double distancia_km,
                        double velocidad_ms, double energia_j) {
    int cuadro;
    int destino;
    if (total_etapas <= 0) return;
    destino = (etapa * (ANCHO - 1)) / total_etapas;
    for (cuadro = 0; cuadro <= CUADRO; ++cuadro) {
        int posicion = (destino * cuadro) / CUADRO;
        dibujar(posicion, etapa, total_etapas, distancia_km,
                velocidad_ms, energia_j, cuadro);
        pausa_ms(55);
    }
}
