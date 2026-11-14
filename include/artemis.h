#ifndef ARTEMIS_H
#define ARTEMIS_H

#include <stddef.h>

#define MAX_EVENTOS 20
#define MAX_TEXTO 160
#define MAX_TURNOS 5

typedef struct {
    double masa_kg;
    double velocidad_tli_ms;
    double energia_cinetica_j;
    double distancia_m;
    int integridad;
} Nave;

typedef struct {
    int turno;
    int puntos;
    int eventos_resueltos;
    int estado; /* 0 sin iniciar, 1 en curso, 2 completada, 3 abortada */
} Mision;

typedef struct {
    int turno;
    char descripcion[MAX_TEXTO];
} EventoRegistro;

typedef struct {
    Nave nave;
    Mision mision;
    EventoRegistro historial[MAX_EVENTOS];
    size_t cantidad_eventos;
} EstadoJuego;

void inicializar_juego(EstadoJuego *juego);
void ejecutar_mision(EstadoJuego *juego);
void registrar_evento(EstadoJuego *juego, const char *descripcion);
void avanzar_turno(EstadoJuego *juego);
void procesar_evento_aleatorio(EstadoJuego *juego);

#endif
