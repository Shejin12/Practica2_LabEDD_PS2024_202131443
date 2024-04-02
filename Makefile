CPP = g++
TARGET = ../Practica_2
objetos_construccion = ./obj


# all
all: $(TARGET)

$(TARGET): $(objetos_construccion)/main.o
	$(CPP) $(objetos_construccion)/main.o -o $(TARGET)

$(objetos_construccion)/Main.o: main.cpp  Log.h Nodo.h Arbol.h ArbolDate.h ArbolInt.h ArbolString.h ArbolChar.h   Grupo.h Grupos.h
	$(CPP) -c main.cpp -o $(objetos_construccion)/main.o

# clean
clean:
	rm -f $(objetos_construccion)/*.o $(TARGET)