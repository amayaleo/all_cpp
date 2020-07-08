CC = gcc
TARGET = $(BIN_DIR)/write_fifo
TARGET_FIFO = $(BIN_DIR)/read_fifo
#DEPENDENCY := main.cpp
OBJS =  	$(OBJ_DIR)/read_fifo.o
OBJS_FIFO=	$(OBJ_DIR)/write_fifo.o


FOLDER_TMP = ../folder
INC_DIR = ../inc
OBJ_DIR = ../obj
BIN_DIR = ../bin
SRC_DIR = .

#minimiza errores
CFLAGS = -Wall -I$(INC_DIR) -pthread

$(TARGET): $(OBJS) $(OBJS_FIFO)
	mkdir -p $(BIN_DIR) $(FOLDER_TMP)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	$(CC) $(CFLAGS) $(OBJS_FIFO) -o $(TARGET_FIFO)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR) $(FOLDER_TMP)
	$(CC) -c -MD $(CFLAGS) $< -o $@
#	$(CC) -c -MD $(CFLAGS) $< -o $@

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

