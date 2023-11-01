CC = gcc
CFLAGS = -Wall

TARGET = main
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main $(OBJ)

run: $(TARGET)
	./$(TARGET)

