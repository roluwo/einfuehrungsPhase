# Makefile für das Projekt "aufgabe3"

# Compiler und Compiler-Optionen
CC = gcc  # Verwende gcc als C Compiler
CFLAGS = -Wall -std=c99  # Compiler-Optionen, -Wall aktiviert alle Warnungen

# Dateinamen
SRC = aufgabe3.c  # Liste der Quelldateien
TARGET = aufgabe3  # Name der ausführbaren Datei

# Standardziel: Erstelle das ausführbare Programm
all: $(TARGET)

# Regel zur Erstellung der ausführbaren Datei
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Lösche erstellte Dateien
clean:
	rm -f $(TARGET)

# Phony-Ziele
.PHONY: all clean
