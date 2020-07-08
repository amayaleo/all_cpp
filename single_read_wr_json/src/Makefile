CC = g++
C = gcc

TARGET = $(BIN_DIR)/app

OBJS_c = $(OBJ_DIR)/pid.o

OBJS = $(OBJ_DIR)/main.o \
#		$(OBJ_DIR)/libs.o \
#		$(PHJ_DIR)/picojson.o
		
INC_DIR = ../inc
OBJ_DIR = ../obj
BIN_DIR = ../bin
TMP_DIR = ../tmp
SRC_DIR = .

CFLAGS = -Wall  -pthread -std=c++17 -I$(INC_DIR)
CFLAGS_c =  -I$(INC_DIR)

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR) $(TMP_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR) $(TMP_DIR)
	$(CC) -c -MD $(CFLAGS)  $< -o $@
	 
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR) $(TMP_DIR)
	$(C) -c -MD $(CFLAGS_c)  $< -o $@


-include $(OBJ_DIR)/*.d

.PHONY: clean
clean:
	@rm  $(OBJ_DIR)/* $(BIN_DIR)/* 
