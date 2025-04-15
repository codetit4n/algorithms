# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Ilib

# Directories
SRC_DIR = src
BIN_DIR = bin

# Default target: show help
all:
	@echo "Usage: make <filename> (without .c)"
	@echo "Example: make test    # builds src/test.c -> bin/test"

# Pattern rule to build src/<file>.c into bin/<file>
%: $(SRC_DIR)/%.c | $(BIN_DIR)
	@echo "Compiling $< -> $(BIN_DIR)/$@"
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@

# Ensure bin/ exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean build output
clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean

