C = gcc
CC = g++
TARGET = $(BIN_DIR)/app

#DEPENDENCY := main.cpp
OBJS =  	$(OBJ_DIR)/main.o
#		$(OBJ_DIR)/libs.o


FOLDER_TMP = ../folder
INC_DIR = ../inc
OBJ_DIR = ../obj
BIN_DIR = ../bin
SRC_DIR = .

#minimiza errores
CFLAGS = -Wall -I$(INC_DIR) -pthread

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR) $(FOLDER_TMP)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR) $(FOLDER_TMP)
	$(C) -c -MD $(CFLAGS)  $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR) $(FOLDER_TMP)
	$(CC) -c -MD $(CFLAGS)  $< -o $@

-include $(OBJ_DIR)/*.d
# "target" : "prerequisites"
#TAB	"recipe"

.PHONY: clean
clean:
	@rm -r $(OBJ_DIR) $(BIN_DIR) 

#preprocessor g++ -E
#compiler g++ -s
#assembler g++ -C-
#linker  .o

