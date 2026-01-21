# Compilateur et options
CXX      = g++
CXXFLAGS = -ansi -pedantic -Wall -Iinclude

# les sous-repertoires
SRC_DIR  = src
OBJ_DIR  = obj

# liste des fichiers sources
SRCS = $(SRC_DIR)/main.cpp \
#      $(SRC_DIR)/ \


# création des fichiers objet
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Nom de l'exécutable
TARGET = analog
all: $(TARGET)

# Mode debugging  
debug: CXXFLAGS += -g -DMAP
debug: clean all

# Edition de liens
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

# Compilation des .cpp en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
