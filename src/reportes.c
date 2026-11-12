#include <stdio.h>
#include "reportes.h"

void mostrar_historial(const EstadoJuego *juego) {
    size_t i;
    puts("\n================ HISTORIAL DE MISION ================");
    if (juego->cantidad_eventos == 0) {
        puts("No hay eventos registrados.");
        return;
    }
    for (i = 0; i < juego->cantidad_eventos; i++) {
        printf("%02zu. [Turno %d] %s\n", i + 1,
               juego->historial[i].turno,
               juego->historial[i].descripcion);
    }
}

void mostrar_reporte_final(const EstadoJuego *juego) {
    puts("\n================ INFORME FINAL ======================");
    printf("Estado: %s\n", juego->mision.estado == 2 ? "COMPLETADA" : "ABORTADA");
    printf("Turnos realizados: %d\n", juego->mision.turno);
    printf("Puntos: %d\n", juego->mision.puntos);
    printf("Eventos atendidos: %d\n", juego->mision.eventos_resueltos);
    printf("Integridad de sistemas: %d%%\n", juego->nave.integridad);
    printf("Energia cinetica inicial: %.6e J\n", juego->nave.energia_cinetica_j);
    puts("=====================================================");
}