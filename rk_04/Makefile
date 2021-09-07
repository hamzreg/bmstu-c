CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic

TARGET := app.exe

SRC_DIR := ./src
CFILES := $(wildcard $(SRC_DIR)/*.c)

HDRS_DIR := ./inc
HDRS := $(wildcard $(HDRS_DIR)/*.h)

OBJ_DIR := ./out
OBJS := $(CFILES: $(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR):
	@ mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDRS) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: build run clean

build:
	$(CC) $(CFLAGS) -c $(CFILES)
	$(CC) $(OBJS) -o $(TARGET)

run:
	./$(TARGET) in.txt out.txt

clean:
	$(RM) -rf $(OBJ_DIR) *.exe
