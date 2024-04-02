CPP = g++
TARGET = ../Practica_2



# all
all: $(TARGET)

$(TARGET): ./main.o
	$(CPP) $(objetos_construccion)/main.o -o $(TARGET)

./main.o: ./main.cpp  Log.h Nodo.h Arbol.h ArbolDate.h ArbolInt.h ArbolString.h ArbolChar.h   Grupo.h Grupos.h
	$(CPP) -c main.cpp -o $(objetos_construccion)/main.o

# clean
clean:
	rm -f $(objetos_construccion)/*.o $(TARGET)