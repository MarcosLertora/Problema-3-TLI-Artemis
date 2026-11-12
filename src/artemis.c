#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artemis.h"
#include "animacion.h"
#include "fisica.h"
#include "interfaz.h"
#include "reportes.h"
#include "validaciones.h"

void inicializar_juego(EstadoJuego *juego) {
    memset(juego, 0, sizeof(*juego));
    juego->nave.masa_kg = MASA_ORION_KG;
    juego->nave.velocidad_tli_ms = VELOCIDAD_TLI_MS;
    juego->nave.energia_cinetica_j =
        calcular_energia_cinetica(juego->nave.masa_kg,
                                  juego->nave.velocidad_tli_ms);
    juego->nave.integridad = 100;
    juego->mision.estado = 1;
}

void registrar_evento(EstadoJuego *juego, const char *descripcion) {
    size_t i = juego->cantidad_eventos;
    if (i >= MAX_EVENTOS) return;
    juego->historial[i].turno = juego->mision.turno;
    snprintf(juego->historial[i].descripcion, MAX_TEXTO, "%s", descripcion);
    juego->cantidad_eventos++;
}

void avanzar_turno(EstadoJuego *juego) {
    if (juego->mision.turno < MAX_TURNOS) {
        juego->mision.turno++;
        juego->nave.distancia_m =
            (DISTANCIA_TIERRA_LUNA_M * juego->mision.turno) / MAX_TURNOS;
        juego->mision.puntos += 20;
        registrar_evento(juego, "Etapa de trayectoria registrada en el simulador.");
        animar_tramo_orion(juego->mision.turno, MAX_TURNOS,
                           juego->nave.distancia_m / 1000.0,
                           juego->nave.velocidad_tli_ms,
                           juego->nave.energia_cinetica_j);
        printf("\nEtapa %d completada.\n", juego->mision.turno);
        mostrar_barra_progreso(juego->mision.turno, MAX_TURNOS);
        printf("Distancia representada en el recorrido: %.1f km\n",
               juego->nave.distancia_m / 1000.0);
    }
    if (juego->mision.turno == MAX_TURNOS) {
        juego->mision.estado = 2;
        registrar_evento(juego, "Se completaron las etapas didacticas del recorrido translunar.");
    }
}

void procesar_evento_aleatorio(EstadoJuego *juego) {
    int evento = rand() % 3;
    int decision;
    const char *descripcion;

    puts("\n*** MENSAJE DEL CENTRO DE CONTROL ***");
    if (evento == 0) {
        puts("Sensor secundario: lectura fuera del rango nominal.");
        puts("1. Ejecutar diagnostico (+15 puntos)  2. Continuar (-5 integridad)");
        decision = leer_entero_rango("Decision: ", 1, 2);
        if (decision == 1) {
            juego->mision.puntos += 15;
            descripcion = "Diagnostico del sensor realizado correctamente.";
        } else {
            juego->nave.integridad -= 5;
            descripcion = "Se continuo con una lectura de sensor pendiente.";
        }
    } else if (evento == 1) {
        puts("Comunicacion con Tierra intermitente.");
        puts("1. Activar canal de respaldo (+15 puntos)  2. Esperar");
        decision = leer_entero_rango("Decision: ", 1, 2);
        if (decision == 1) {
            juego->mision.puntos += 15;
            descripcion = "Canal de comunicaciones de respaldo activado.";
        } else {
            descripcion = "Se espero la recuperacion del enlace de comunicaciones.";
        }
    } else {
        puts("Centro de control solicita un reporte de estado.");
        puts("1. Enviar reporte detallado (+15 puntos)  2. Enviar reporte breve");
        decision = leer_entero_rango("Decision: ", 1, 2);
        if (decision == 1) {
            juego->mision.puntos += 15;
            descripcion = "Reporte detallado enviado a control de mision.";
        } else {
            descripcion = "Reporte breve enviado a control de mision.";
        }
    }
    if (juego->nave.integridad < 0) juego->nave.integridad = 0;
    juego->mision.eventos_resueltos++;
    registrar_evento(juego, descripcion);
}

void ejecutar_mision(EstadoJuego *juego) {
    int opcion;
    registrar_evento(juego, "Mision TLI iniciada. ICPS ejecuta la inyeccion y se desacopla.");
    puts("\nORION ha alcanzado la velocidad TLI de 10.900 m/s.");
    puts("Los motores principales estan apagados: comienza la trayectoria libre.");
    printf("Energia cinetica inicial calculada: %.6e J\n",
           juego->nave.energia_cinetica_j);

    while (juego->mision.estado == 1) {
        mostrar_menu_mision(juego->mision.turno,
                            juego->mision.puntos,
                            juego->nave.integridad);
        opcion = leer_entero_rango("Seleccione: ", 1, 5);
        switch (opcion) {
            case 1:
                avanzar_turno(juego);
                if (juego->mision.turno == 2 || juego->mision.turno == 4)
                    procesar_evento_aleatorio(juego);
                break;
            case 2:
                mostrar_analisis_inercia();
                mostrar_resultados_fisicos();
                break;
            case 3:
                procesar_evento_aleatorio(juego);
                break;
            case 4:
                mostrar_historial(juego);
                break;
            case 5:
                juego->mision.estado = 3;
                registrar_evento(juego, "Mision abortada por decision del usuario.");
                break;
        }
    }
    mostrar_reporte_final(juego);
}
