CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic

TARGET := app.exe

CFILES := main.c \
	matrix.c

HDRS := matrix.h \
	matrix_t.h

OBJS := main.o \
	matrix.o


.PHONY: build run clean


build: $(CFILES) $(HDRS)
	$(CC) $(CFLAGS) -c $(CFILES)
	$(CC) -o $(TARGET) $(OBJS)
	


run: $(TARGET)
	./$^ in.txt out.txt

clean:
	$(RM) *.o *.exe
