# GRUPO A11 - ARTEMIS – SIMULADOR TLI (ESCENARIO 3)

Proyecto académico en lenguaje C para Algoritmos y Estructuras de Datos. Representa de forma interactiva la maniobra de Inyección Translunar (TLI), el apagado de motores y el movimiento de Orion en trayectoria libre.

## INFORMACIÓN DEL GRUPO

Grupo A11 - Comisión 1.1
Integrantes del grupo:
- Arévalo, Maximiliano Agustin. Legajo Nº 27416
- Iguich, Thiago Bautista. Legajo Nº 31511
- Insaurralde, Laila Candela. Legajo Nº 31501
- Guillén, Alexis de Jesús. Legajo Nº 27938
- Lértora, Marcos Gabriel. Legajo Nº 27884

## ESCENARIO ASIGNADO: INYECCIÓN TRANSLUNAR (TLI) E INERCIA EN TRAYECTORIA LIBRE

El proyecto se basa en el Escenario 3: Inyección Translunar (TLI) e Inercia en Trayectoria Libre, correspondiente al programa Artemis de exploración lunar.

La situación plantea el traslado de la nave espacial Orion desde la órbita terrestre hacia la Luna. La nave posee una masa de 26.000 kg y alcanza una velocidad inicial de 10.900 m/s mediante la maniobra de Inyección Translunar (TLI).

Una vez realizado el impulso de inyección, el módulo de propulsión ICPS se desacopla y los motores se apagan. A partir de ese momento, la nave continúa su trayectoria sin propulsión propia, debido a la inercia, mientras la gravedad terrestre y lunar influyen sobre su movimiento.

El escenario permite aplicar conceptos fundamentales de Física, principalmente la Primera Ley de Newton (Ley de Inercia), la energía cinética y el principio de conservación de la energía mecánica.

## OBJETIVO DE LA MISIÓN

El objetivo es comprender y representar el comportamiento de la nave Orion durante su trayectoria translunar, teniendo en cuenta las condiciones iniciales de velocidad, masa y distancia, así como la influencia de la gravedad y la energía necesaria para realizar el viaje.

## DATOS PRINCIPALES DEL ESCENARIO

- Nave espacial: Orion.
- Masa de la nave: 26.000 kg.
- Velocidad inicial luego de la maniobra TLI: 10.900 m/s.
- Distancia media entre la Tierra y la Luna: 384.000.000 m.
- Altura de la órbita terrestre baja (LEO): 192.000 m.
- Condición posterior a la maniobra TLI: Motores apagados y módulo ICPS desacoplado.

## REGLAS Y CONSIDERACIONES FÍSICAS

1. La nave recibe el impulso inicial necesario para iniciar su trayectoria translunar.
2. Una vez completada la maniobra TLI, la nave continúa desplazándose sin utilizar sus motores.
3. El movimiento posterior se explica mediante el principio de inercia y la acción gravitatoria de los cuerpos celestes.
4. La energía cinética inicial se determina a partir de la masa y la velocidad de la nave.
5. El análisis energético considera el trabajo necesario para trasladar la nave desde la órbita terrestre baja hasta el punto de equilibrio gravitatorio Tierra-Luna.
6. Se considera la diferencia energética entre los trayectos Tierra-Luna y Luna-Tierra para comprender por qué el consumo de combustible requerido no es equivalente en ambos sentidos.

## FUNCIONAMIENTO DEL PROGRAMA

El sistema consiste en un simulador interactivo desarrollado en lenguaje C que se ejecuta mediante una terminal o consola de comandos. Su finalidad es representar la misión translunar de la nave Orion, permitiendo al usuario interactuar con el programa y consultar información relacionada con el escenario físico asignado.

El funcionamiento general se organiza mediante un menú principal, desde el cual el usuario puede acceder a las distintas funcionalidades disponibles.

El programa se encuentra dividido en diferentes módulos para organizar el código y separar las responsabilidades de cada parte del sistema:

- animacion.c: Contiene las funciones encargadas de mostrar animaciones y efectos visuales en la consola, haciendo que la interfaz del simulador sea más dinámica y atractiva.
- artemis.c: Contiene la lógica principal del simulador Artemis, implementando los procedimientos y operaciones relacionados con el desarrollo de la misión.
- fisica.c: Contiene las operaciones y procedimientos relacionados con los cálculos físicos del escenario.
- interfaz.c: Se encarga de los elementos de interacción y presentación de información en la consola.
- main.c: Contiene la función principal y coordina el flujo general de ejecución del programa.
- reportes.c: Contiene las funcionalidades destinadas a presentar los resultados y la información final del programa.
- validaciones.c: Reúne los procedimientos destinados a validar los datos ingresados por el usuario y evitar entradas incorrectas.
- Makefile: Automatiza el proceso de compilación del proyecto, indicando qué archivos deben compilarse y cómo generar el programa ejecutable.

Los archivos de cabecera (.h) contienen las declaraciones y los prototipos necesarios para comunicar los distintos módulos.

La organización modular facilita el mantenimiento, la comprensión y la ampliación del programa.

## ESTRUCTURA DEL CÓDIGO

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

## COMPILACIÓN Y EJECUCIÓN

REQUISITOS PREVIOS

Para compilar y ejecutar el programa se necesita:
- Sistema operativo Windows.
- Compilador de lenguaje C, como GCC.
- Terminal de comandos, como CMD, PowerShell o la terminal de VS Code.

PASOS PARA COMPILAR

1. Descargar o clonar el repositorio de GitHub.
2. Abrir una terminal dentro de la carpeta que contiene los archivos fuente del proyecto.
3. Ejecutar el siguiente comando para compilar: gcc -std=c11 -Wall -Wextra -Wpedantic -Iinclude src/*.c -o artemis_tli -lm

Este comando genera el archivo ejecutable artemis_tli.exe.

PASOS PARA EJECUTAR

Una vez finalizada la compilación correctamente, ejecutar: ./artemis_tli.exe (en VS Code) o artemis_tli.exe (en CMD).

## USO DE INTELIGENCIA ARTIFICIAL

Durante el desarrollo del proyecto se utilizó ChatGPT (OpenAI) como herramienta de asistencia para resolver dudas, analizar problemas y orientar distintas decisiones relacionadas con el diseño y la implementación del simulador.

La inteligencia artificial fue utilizada como apoyo al trabajo de los integrantes, sin reemplazar el análisis, la implementación ni la comprensión del código desarrollado por el equipo.

TAREAS EN LAS QUE SE UTILIZÓ IA

- Diseño inicial del proyecto: Consulta de ideas para desarrollar un simulador interactivo en consola, buscando una implementación relativamente sencilla, pero con una presentación visual atractiva.

- Modularización del programa: Orientación sobre la separación de responsabilidades entre los módulos principales, como la lógica del simulador, la interfaz, las animaciones, las validaciones, los reportes, etc.

- Organización de la interfaz: orientación sobre posibles diseños de menús, presentación de información y recursos visuales para la terminal.

- Resolución de dudas sobre C y compilación: Consultas sobre la ejecución de programas en Windows, el uso de GCC y los comandos necesarios para compilar múltiples archivos fuente.

- Depuración de errores: Análisis de mensajes de error del compilador, especialmente aquellos relacionados con la ubicación de archivos .c y .h y las rutas de inclusión.

- Control de versiones: Consultas sobre la organización del repositorio GitHub, la creación de ramas (feature branches) y la utilización de Pull Requests.