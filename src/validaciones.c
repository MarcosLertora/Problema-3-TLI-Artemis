#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "validaciones.h"

static void quitar_salto(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

int leer_entero_rango(const char *mensaje, int minimo, int maximo) {
    char linea[128], *fin;
    long valor;

    for (;;) {
        printf("%s", mensaje);
        if (!fgets(linea, sizeof(linea), stdin)) {
            clearerr(stdin);
            puts("No se pudo leer la entrada. Intente nuevamente.");
            continue;
        }
        quitar_salto(linea);
        errno = 0;
        valor = strtol(linea, &fin, 10);
        while (isspace((unsigned char)*fin)) fin++;
        if (linea[0] != '\0' && *fin == '\0' && errno == 0 &&
            valor >= minimo && valor <= maximo) {
            return (int)valor;
        }
        printf("Entrada invalida. Ingrese un entero entre %d y %d.\n",
               minimo, maximo);
    }
}

double leer_real_rango(const char *mensaje, double minimo, double maximo) {
    char linea[128], *fin;
    double valor;

    for (;;) {
        printf("%s", mensaje);
        if (!fgets(linea, sizeof(linea), stdin)) {
            clearerr(stdin);
            puts("No se pudo leer la entrada. Intente nuevamente.");
            continue;
        }
        quitar_salto(linea);
        errno = 0;
        valor = strtod(linea, &fin);
        while (isspace((unsigned char)*fin)) fin++;
        if (linea[0] != '\0' && *fin == '\0' && errno == 0 &&
            isfinite(valor) && valor >= minimo && valor <= maximo) {
            return valor;
        }
        printf("Valor invalido. Rango permitido: %.2f a %.2f.\n", minimo, maximo);
    }
}

void esperar_enter(void) {
    char linea[8];
    printf("\nPresione ENTER para continuar...");
    (void)fgets(linea, sizeof(linea), stdin);
}