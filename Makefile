# Base directories
BASE := /mnt/c/Users/ervin/coding/compilerLab
SRC_DIR := $(BASE)/src
INCLUDE_DIR := $(BASE)/include
BIN_DIR := $(BASE)/bin
YACC_DIR := $(PWD)/src/yacc
LEX_DIR := $(PWD)/src/lex
XSM_DIR := $(BASE)/xsm
XSM_EXPL_DIR := $(BASE)/xsm_expl
INPUT_FILE := $(PWD)/input.txt 
OUTPUT_FILE := $(PWD)/output.txt
CURRENT_INCLUDE_DIR := $(PWD)/include

# Source files
SRC_FILES := $(filter-out $(SRC_DIR)/lex.yy.c $(SRC_DIR)/y.tab.c, $(wildcard $(SRC_DIR)/*.c))

# Compiler and flags
CC := gcc
CFLAGS := -I$(INCLUDE_DIR) -I$(CURRENT_INCLUDE_DIR) -g
LEX := flex
YACC := yacc
LDFLAGS := -lfl

# Yacc and Lex files
YACC_FILE := $(YACC_DIR)/generateExpTree.y
LEX_FILE := $(LEX_DIR)/generateExpTree.l
LABEL_LEX_FILE := $(BASE)/labelTranslator/src/lex/labelTranslation.l

# Generated files
Y_TAB_C := $(SRC_DIR)/y.tab.c
Y_TAB_H := $(INCLUDE_DIR)/y.tab.h
LEX_C := $(SRC_DIR)/lex.yy.c
LABEL_LEX_C := $(SRC_DIR)/labeltranslation.yy.c

# Final binaries
PARSER := $(BIN_DIR)/parser_program
LABEL_BIN := $(BASE)/labelTranslator/bin/label_translator

# Default target
all: $(PARSER) $(LABEL_BIN)

# --- Build parser ---
$(PARSER): $(SRC_FILES) $(Y_TAB_C) $(LEX_C)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Generate y.tab.c and y.tab.h from yacc
$(Y_TAB_C) $(Y_TAB_H): $(YACC_FILE)
	$(YACC) -d -o $(Y_TAB_C) $(YACC_FILE)
	@mv -f y.tab.h $(Y_TAB_H) || true

# Generate lex.yy.c from lex
$(LEX_C): $(LEX_FILE)
	$(LEX) -o $(LEX_C) $(LEX_FILE)

# --- Build label translator ---
$(LABEL_BIN):
	$(MAKE) -C $(BASE)/labelTranslator

run_parser: $(PARSER)
	@echo "=== Running parser_program ==="
	@$(PARSER) $(INPUT_FILE) $(OUTPUT_FILE)
	@cp $(BASE)/output.txt $(XSM_DIR)/test.xsmo

run_label: $(LABEL_BIN) run_parser
	@echo "=== Running label_translator ==="
	@$(LABEL_BIN) $(XSM_DIR)/test.xsmo $(XSM_DIR)/test.xsm

run_xsm: run_label
	@echo "=== Running XSM emulator ==="
	@cd $(XSM_EXPL_DIR) && bash ./xsm -l ../lib/library.lib -e ../xsm/test.xsm

run: run_xsm
	@echo "=== Full flow completed ==="


# Clean
clean:
	rm -f $(SRC_DIR)/lex.yy.c $(SRC_DIR)/y.tab.c $(Y_TAB_H) $(PARSER)
	$(MAKE) -C $(BASE)/labelTranslator clean

.PHONY: all clean run run_parser run_label run_xsm
