# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Ilib

# Directories
SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin

# Find all source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
LIB_FILES = $(wildcard $(LIB_DIR)/**/*.c)

# How each src file maps to a bin executable
BIN_FILES = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SRC_FILES))

# Default target: build all binaries
all: $(BIN_FILES)

# Rule to build each binary
$(BIN_DIR)/%: $(SRC_DIR)/%.c $(LIB_FILES) | $(BIN_DIR)
	@echo "Building $@"
	$(CC) $(CFLAGS) $< $(LIB_FILES) -o $@

# Ensure bin/ exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean build
clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean

