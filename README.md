# ARTEMIS – Simulador TLI (Escenario 3)

Proyecto académico en lenguaje C para Algoritmos y Estructuras de Datos. Representa de forma interactiva la maniobra de Inyección Translunar (TLI), el apagado de motores y el movimiento de Orion en trayectoria libre.

## Información del grupo

Grupo A11 - Comisión 1.1
Integrantes del grupo:
    - Arévalo, Maximiliano Agustin. Legajo Nº 27416
    - Iguich, Thiago Bautista. Legajo Nº 31511
    - Insaurralde, Laila Candela. Legajo Nº 31501
    - Guillén, Alexis de Jesús. Legajo Nº 27938
    - Lértora, Marcos Gabriel. Legajo Nº 27884

## Escenario asignado: Inyección Translunar (TLI) e inercia en Trayectoria Libre

El proyecto se basa en el Escenario 3: Inyección Translunar (TLI) e Inercia en Trayectoria Libre, correspondiente al programa Artemis de exploración lunar.

La situación plantea el traslado de la nave espacial Orion desde la órbita terrestre hacia la Luna. La nave posee una masa de 26.000 kg y alcanza una velocidad inicial de 10.900 m/s mediante la maniobra de Inyección Translunar (TLI).

Una vez realizado el impulso de inyección, el módulo de propulsión ICPS se desacopla y los motores se apagan. A partir de ese momento, la nave continúa su trayectoria sin propulsión propia, debido a la inercia, mientras la gravedad terrestre y lunar influyen sobre su movimiento.

El escenario permite aplicar conceptos fundamentales de Física, principalmente la Primera Ley de Newton (Ley de Inercia), la energía cinética y el principio de conservación de la energía mecánica.

## Objetvio de la misión

El objetivo es comprender y representar el comportamiento de la nave Orion durante su trayectoria translunar, teniendo en cuenta las condiciones iniciales de velocidad, masa y distancia, así como la influencia de la gravedad y la energía necesaria para realizar el viaje.

## Datos principales del escenario

- Nave espacial: Orion.
- Masa de la nave: 26.000 kg.
- Velocidad inicial luego de la maniobra TLI: 10.900 m/s.
- Distancia media entre la Tierra y la Luna: 384.000.000 m.
- Altura de la órbita terrestre baja (LEO): 192.000 m.
- Condición posterior a la maniobra TLI: motores apagados y módulo ICPS desacoplado.

## Reglas y consideraciones físicas

1. La nave recibe el impulso inicial necesario para iniciar su trayectoria translunar.
2. Una vez completada la maniobra TLI, la nave continúa desplazándose sin utilizar sus motores.
3. El movimiento posterior se explica mediante el principio de inercia y la acción gravitatoria de los cuerpos celestes.
4. La energía cinética inicial se determina a partir de la masa y la velocidad de la nave.
5. El análisis energético considera el trabajo necesario para trasladar la nave desde la órbita terrestre baja hasta el punto de equilibrio gravitatorio Tierra-Luna.
6. Se considera la diferencia energética entre los trayectos Tierra-Luna y Luna-Tierra para comprender por qué el consumo de combustible requerido no es equivalente en ambos sentidos.

## Estructura del código

artemis_tli_final/
├── include/
│   ├── animacion.h
│   ├── artemis.h
│   ├── colores.h
│   ├── fisica.h
│   ├── interfaz.h
│   ├── reportes.h
│   └── validaciones.h
├── src/
│   ├── animacion.c
│   ├── artemis.c
│   ├── fisica.c
│   ├── interfaz.c
│   ├── main.c
│   ├── reportes.c
│   └── validaciones.c
├── Makefile
└── README.md