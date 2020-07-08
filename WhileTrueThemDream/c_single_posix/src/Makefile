C = gcc
TARGET = $(BIN_DIR)/app
OBJS = $(OBJ_DIR)/main.o
INC_DIR = ../inc
OBJ_DIR = ../obj
BIN_DIR = ../bin
SRC_DIR = .
CFLAGS = -Wall -I$(INC_DIR) -pthread

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(C) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(C) -c -MD $(CFLAGS)  $< -o $@

-include $(OBJ_DIR)/*.d

.PHONY: clean

clean:
	@rm -r $(OBJ_DIR) $(BIN_DIR)
