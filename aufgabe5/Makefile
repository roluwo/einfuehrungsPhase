# Makefile für main.c

# Compiler und Compiler-Flags
CC = gcc
CFLAGS = -Wall -std=c11

# Dateinamen
TARGET = main
SOURCE = main.c

# Build-Regel
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Standardziel
all: $(TARGET)

# Aufräumen
clean:
	rm -f $(TARGET)

# "make run" um das Programm auszuführen
run: $(TARGET)
	./$(TARGET)
