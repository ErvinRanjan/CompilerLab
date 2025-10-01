# Base directories
BASE := $(shell pwd)
SRC_DIR := $(BASE)/src
LEX_DIR := $(SRC_DIR)/lex
BIN_DIR := $(BASE)/bin
INCLUDE_DIR := $(BASE)/include   # Include path for constants.h
XSM_DIR := /mnt/c/Users/ervin/coding/compilerLab/xsm

# Lex file
LEX_FILE := $(LEX_DIR)/labelTranslation.l
LEX_C := $(SRC_DIR)/labeltranslation.yy.c

# Final binary
TARGET := $(BIN_DIR)/label_translator

# Compiler
CC := gcc
CFLAGS := -I$(INCLUDE_DIR) -g
LEX := flex

# Default target
all: $(TARGET)

# Generate lex.yy.c
$(LEX_C): $(LEX_FILE)
	@mkdir -p $(SRC_DIR)
	@$(LEX) -o $@ $<

# Compile the binary
$(TARGET): $(LEX_C)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $< -o $@

run_label: $(TARGET)
	@echo "=== Running label_translator ==="
	@$(TARGET) $(XSM_DIR)/test.xsmo $(XSM_DIR)/test.xsm

# Clean
clean:
	rm -f $(LEX_C) $(TARGET)

.PHONY: all clean run_label
