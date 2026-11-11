#include <stdlib.h>
#include <time.h>
#include "artemis.h"
#include "interfaz.h"
#include "validaciones.h"
#include "fisica.h"
#include "reportes.h"

int main(void) {
    int opcion;
    EstadoJuego juego;

    activar_colores_terminal();
    srand((unsigned int)time(NULL));
    inicializar_juego(&juego);

    do {
        limpiar_pantalla();
        mostrar_portada();
        mostrar_menu_principal();
        opcion = leer_entero_rango("Seleccione una opcion: ", 1, 4);

        switch (opcion) {
            case 1:
                inicializar_juego(&juego);
                ejecutar_mision(&juego);
                break;
            case 2:
                mostrar_analisis_inercia();
                mostrar_resultados_fisicos();
                break;
            case 3:
                mostrar_historial(&juego);
                break;
            case 4:
                break;
        }
        if (opcion != 4) esperar_enter();
    } while (opcion != 4);

    return 0;
}
