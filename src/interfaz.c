#include <stdio.h>
#include <stdlib.h>
#include "interfaz.h"
#include "colores.h"
#ifdef _WIN32
#include <windows.h>
#endif


void activar_colores_terminal(void) {
#ifdef _WIN32
    HANDLE salida = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD modo;
    if (salida != INVALID_HANDLE_VALUE && GetConsoleMode(salida, &modo))
        SetConsoleMode(salida, modo | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
}

void limpiar_pantalla(void) {
#ifdef _WIN32
    (void)system("cls");
#else
    printf("\033[2J\033[H");
#endif
}

void mostrar_portada(void) {
    printf(C_TITULO);
    puts("==============================================================");
    puts("              ARTEMIS // ORION - MISSION CONTROL              ");
    puts("                 INYECCION TRANSLUNAR (TLI)                   ");
    puts("==============================================================");
    printf(C_RESET C_VERDE "                 SISTEMAS DE CONTROL: ONLINE\n" C_RESET);
}

void mostrar_menu_principal(void) {
    printf(C_TEXTO "\n  1. Iniciar simulacion TLI\n  2. Centro de informacion / simulacion\n  3. Historial (disponible al finalizar una mision)\n  4. Salir\n" C_RESET);
}

void mostrar_menu_mision(int turno, int puntos, int integridad) {
    printf(C_TITULO "\n------------------- VUELO TRANSLUNAR -------------------\n" C_RESET);
    printf(C_TEXTO "Turno: %d/5 | Puntos: %d | Integridad de sistemas: %d%%\n" C_RESET,
           turno, puntos, integridad);
    printf(C_TEXTO "  1. Avanzar una etapa de vuelo\n  2. Consultar analisis fisico\n  3. Recibir mensaje del centro de control\n  4. Consultar historial\n  5. Finalizar mision\n" C_RESET);
}

void mostrar_barra_progreso(int actual, int total) {
    int llenos;
    int i;
    if (total <= 0) return;
    llenos = (actual * 20) / total;
    printf(C_VERDE "[");
    for (i = 0; i < 20; i++) putchar(i < llenos ? '#' : '-');
    printf("] %d%%\n" C_RESET, (actual * 100) / total);
}
