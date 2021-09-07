CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic
UFLAGS := -lcheck -lpthread -lrt


TARGET := app.exe
UNIT_TARGET := unit_tests.exe
STAT_TARGET := stat_app.exe
DYN_TARGET := dyn_app.exe
LOAD_TARGET := load_app.exe


SRC_DIR := ./src
CFILES := $(wildcard $(SRC_DIR)/*.c)

HDRS_DIR := ./inc
HDRS := $(wildcard $(HDRS_DIR)/*.h)

OBJ_DIR := ./out
OBJS := $(CFILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

UNIT_DIR := ./unit_tests
UFILES := $(wildcard $(UNIT_DIR)/*.c)
UNIT_OBJS := $(UFILES:$(UNIT_DIR)/%.c=$(OBJ_DIR)/%.o)
UNIT_OBJS += $(filter-out $(OBJ_DIR)/main.o, $(OBJS))

LIB_DIR := ./libs
LIBS = $(wildcard $(LIB_DIR)/*.c)
STAT_LIBS = $(LIBS:$(LIB_DIR)/%.c=$(LIB_DIR)/lib%.a)
DYN_LIBS = $(LIBS:$(LIB_DIR)/%.c=$(LIB_DIR)/lib%.so)

DYN_SRC_DIR := ./dyn_src
DYN_OBJ_DIR := ./dyn_out
LFILES := $(wildcard $(DYN_SRC_DIR)/*.c)
DYN_OBJS := $(LFILES:$(DYN_SRC_DIR)/%.c=$(DYN_OBJ_DIR)/%.o)


.PHONY: unit clean


$(STAT_TARGET): $(OBJS) $(STAT_LIBS)
	$(CC) $^ -o $@

$(LIB_DIR)/lib%.a: $(OBJ_DIR)/%.o
	ar rc $@ $<


$(DYN_TARGET): $(OBJS) $(DYN_LIBS)
	$(CC) $^ -o $@

$(LIB_DIR)/lib%.so: $(OBJ_DIR)/%.o
	$(CC) -shared $< -o $@

$(LOAD_TARGET): $(DYN_OBJS) $(LIB_DIR)/lib_array.so
	$(CC) $(DYN_OBJS) -ldl -o $@

$(LIB_DIR)/lib_array.so: $(OBJ_DIR)/array.o $(OBJ_DIR)/numbers.o
	$(CC) -shared $^ -o $@

$(DYN_OBJ_DIR):
	@mkdir -p $@

$(DYN_OBJ_DIR)/%.o: $(DYN_SRC_DIR)/%.c $(HDRS) $(DYN_OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@


$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c $(HDRS) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(UFLAGS) -c $< -o $@

$(UNIT_TARGET): $(UNIT_OBJS) $(STAT_LIBS)
	$(CC) $^ -o $@ $(UFLAGS)


$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDRS) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(UFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UNIT_DIR)/%.c $(HDRS) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(UFLAGS) -c $< -o $@ 


unit: $(UNIT_TARGET)
	./$^

clean:
	$(RM) -rf $(OBJ_DIR) *.exe $(LIB_DIR)/*.a $(LIB_DIR)/*.so