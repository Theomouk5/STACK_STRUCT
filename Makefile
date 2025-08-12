# --- variables ---
CC = clang
FLAGS = -Iinclude -Wall -Werror

# --- folders ---
SRC = src
BUILD = build
BIN = bin
LIB_DIR = lib

# --- files ---
# sources & objects
SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SOURCES))

# executable
EXECUTABLE = $(BIN)/prog

# dynamic library
LIB = $(LIB_DIR)/stack.so

# --- rules ---
all: $(EXECUTABLE)
lib: $(LIB)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(LIB_DIR)
	$(CC) $(FLAGS) $(OBJECTS) -o $@

$(LIB): $(OBJECTS)
	@mkdir -p $(LIB_DIR)
	$(CC) $(FLAGS) -fPIC -shared $(OBJECTS) -o $@

$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(BIN) $(BUILD) $(LIB_DIR)

.PHONY: clean all