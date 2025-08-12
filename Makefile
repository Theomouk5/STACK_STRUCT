# --- variables ---
CC = clang
FLAGS = -Iinclude -Wall -Werror

# --- folders ---
SRC = src
BUILD = build
BIN = bin

# --- files ---
# sources & objects
SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SOURCES))

# executable
EXECUTABLE = $(BIN)/prog

# --- rules ---
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p bin
	$(CC) $(FLAGS) $(OBJECTS) -o $@

$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p build
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(BIN) $(BUILD)

.PHONY: clean all