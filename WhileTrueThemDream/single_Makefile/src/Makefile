CC = g++
TARGET = $(BIN_DIR)/app

#DEPENDENCY := main.cpp
OBJS =  	$(OBJ_DIR)/main.o \
		$(OBJ_DIR)/libs.o
#CFLAGS := 
INC_DIR = ../inc
OBJ_DIR = ../obj
BIN_DIR = ../bin
SRC_DIR = .

#minimiza errores
CFLAGS = -Wall -I$(INC_DIR)

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
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

