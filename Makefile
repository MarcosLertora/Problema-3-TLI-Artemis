CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Iinclude
LDLIBS = -lm

SRC = src/main.c src/artemis.c src/fisica.c src/validaciones.c src/interfaz.c src/reportes.c src/animacion.c
OBJ = $(SRC:.c=.o)
TARGET = artemis_tli

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) artemis_tli.exe

.PHONY: all clean
