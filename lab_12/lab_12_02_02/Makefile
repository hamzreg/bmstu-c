CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -fPIC

TARGET := libarray.so

LIB_DIR := ./lib
LIBS = $(wildcard $(LIB_DIR)/*.c)

OBJ_DIR := ./out
OBJS := $(LIBS:$(LIB_DIR)/%.c=$(OBJ_DIR)/%.o)


.PHONY: clean


$(TARGET): $(OBJS)
	$(CC) -o $@ -shared $^

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) -rf $(OBJ_DIR) $(LIB_DIR)/*.so
