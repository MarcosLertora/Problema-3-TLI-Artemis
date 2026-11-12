#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

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