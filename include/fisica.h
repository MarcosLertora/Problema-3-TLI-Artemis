#ifndef FISICA_H
#define FISICA_H

/* Constantes adoptadas para completar el modelo Tierra-Luna. */
#define G_UNIVERSAL 6.67430e-11
#define MASA_TIERRA_KG 5.9722e24
#define MASA_LUNA_KG 7.342e22
#define RADIO_TIERRA_M 6371000.0
#define ALTITUD_LEO_M 192000.0
#define DISTANCIA_TIERRA_LUNA_M 384000000.0
#define MASA_ORION_KG 26000.0
#define VELOCIDAD_TLI_MS 10900.0

double calcular_energia_cinetica(double masa_kg, double velocidad_ms);
double calcular_distancia_equilibrio_m(double distancia_m);
double calcular_trabajo_minimo_por_kg(double radio_orbita_m,
                                      double distancia_equilibrio_m,
                                      double distancia_tierra_luna_m);
void mostrar_analisis_inercia(void);
void mostrar_resultados_fisicos(void);

#endif
