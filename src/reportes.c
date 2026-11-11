#include <stdio.h>

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