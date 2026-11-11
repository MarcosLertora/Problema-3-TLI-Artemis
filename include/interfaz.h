#ifndef INTERFAZ_H
#define INTERFAZ_H

void activar_colores_terminal(void);
void limpiar_pantalla(void);
void mostrar_portada(void);
void mostrar_menu_principal(void);
void mostrar_menu_mision(int turno, int puntos, int integridad);
void mostrar_barra_progreso(int actual, int total);

#endif
