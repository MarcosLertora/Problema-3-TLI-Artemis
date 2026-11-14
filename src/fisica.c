#include <stdio.h>
#include <math.h>
#include "fisica.h"

double calcular_energia_cinetica(double masa_kg, double velocidad_ms) {
    return 0.5 * masa_kg * velocidad_ms * velocidad_ms;
}

/* Igualando las aceleraciones gravitatorias de Tierra y Luna:
   x = D / (1 + sqrt(M_luna / M_tierra)). */
double calcular_distancia_equilibrio_m(double distancia_m) {
    return distancia_m / (1.0 + sqrt(MASA_LUNA_KG / MASA_TIERRA_KG));
}

/* Diferencia de potencial gravitatorio específico entre LEO y el punto
   de equilibrio. Es el trabajo externo mínimo por unidad de masa si
   se considera el cambio cuasiestático y se ignora la energía cinética
   residual y otras perturbaciones. */
double calcular_trabajo_minimo_por_kg(double radio_orbita_m,
                                      double distancia_equilibrio_m,
                                      double distancia_tierra_luna_m) {
    double potencial_inicial, potencial_final;
    potencial_inicial = -G_UNIVERSAL * MASA_TIERRA_KG / radio_orbita_m
                      -G_UNIVERSAL * MASA_LUNA_KG /
                       (distancia_tierra_luna_m - radio_orbita_m);
    potencial_final = -G_UNIVERSAL * MASA_TIERRA_KG / distancia_equilibrio_m
                    -G_UNIVERSAL * MASA_LUNA_KG /
                     (distancia_tierra_luna_m - distancia_equilibrio_m);
    return potencial_final - potencial_inicial;
}

void mostrar_analisis_inercia(void) {
    puts("\nPRIMERA LEY DE NEWTON - INERCIA");
    puts("Al apagarse los motores, Orion no se detiene: conserva su velocidad");
    puts("instantanea. Sin embargo, el sistema Tierra-Luna ejerce gravedad");
    puts("sobre la nave; esa fuerza externa cambia gradualmente el vector");
    puts("velocidad (modulo y direccion). Por eso no es un movimiento rectilineo");
    puts("uniforme perfecto: la trayectoria se curva y la nave puede desacelerar");
    puts("en la componente dirigida alejandose de la Tierra.");
}

void mostrar_resultados_fisicos(void) {
    const double radio_leo = RADIO_TIERRA_M + ALTITUD_LEO_M;
    const double xeq = calcular_distancia_equilibrio_m(DISTANCIA_TIERRA_LUNA_M);
    const double energia = calcular_energia_cinetica(MASA_ORION_KG, VELOCIDAD_TLI_MS);
    const double wkg = calcular_trabajo_minimo_por_kg(
        radio_leo, xeq, DISTANCIA_TIERRA_LUNA_M);

    puts("\n================ ANALISIS FISICO TLI ================");
    printf("Masa Orion:                         %.1f kg\n", MASA_ORION_KG);
    printf("Velocidad de inyeccion TLI:         %.1f m/s\n", VELOCIDAD_TLI_MS);
    printf("Energia cinetica inicial K_i:       %.6e J\n", energia);
    printf("Radio inicial aproximado de LEO:    %.1f m\n", radio_leo);
    printf("Punto de equilibrio Tierra-Luna:    %.3f km desde la Tierra\n", xeq / 1000.0);
    printf("Trabajo externo minimo especifico:  %.6e J/kg\n", wkg);
    printf("Trabajo externo para Orion:         %.6e J (modelo potencial)\n",
           wkg * MASA_ORION_KG);
    puts("\nNota: se usan masas medias Tierra/Luna y G estandar como constantes");
    puts("adicionales, porque el enunciado no las repite explicitamente.");
    puts("El punto de equilibrio se estima igualando campos gravitatorios;");
    puts("no es una solucion completa de dinamica orbital de tres cuerpos.");
    puts("=====================================================");
}
