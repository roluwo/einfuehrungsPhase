# Makefile für ein C-Projekt mit mehreren Quelldateien und separaten ausführbaren Dateien

# Compiler und Compiler-Optionen
CC = gcc
CFLAGS = -Wall -std=c99

# Liste der Quelldateien
SOURCES = aufgabe2.c aufgabe3.c aufgabe4.c

# Erstelle separate ausführbare Dateien für jede Quelldatei
EXECUTABLES = $(SOURCES:.c=)

# Standardziel: Erstelle alle ausführbaren Dateien
all: $(EXECUTABLES)

# Regel zur Erstellung der ausführbaren Dateien
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Lösche erstellte ausführbare Dateien
clean:
	rm -f $(EXECUTABLES)

# Phony-Ziele
.PHONY: all clean

