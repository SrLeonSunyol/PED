.PHONY= doc clean

CC=g++
OPTIONS= -g 
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tcalendario.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

tcalendario:    src//tcalendario/*.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad01.cpp $(OBJ) -o Salida/tcalendario/tad01
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad02.cpp $(OBJ) -o Salida/tcalendario/tad02
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad03.cpp $(OBJ) -o Salida/tcalendario/tad03
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad04.cpp $(OBJ) -o Salida/tcalendario/tad04
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad05.cpp $(OBJ) -o Salida/tcalendario/tad05
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad06.cpp $(OBJ) -o Salida/tcalendario/tad06
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad07.cpp $(OBJ) -o Salida/tcalendario/tad07
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad08.cpp $(OBJ) -o Salida/tcalendario/tad08
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad09.cpp $(OBJ) -o Salida/tcalendario/tad09
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad10.cpp $(OBJ) -o Salida/tcalendario/tad10
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad11.cpp $(OBJ) -o Salida/tcalendario/tad11
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad12.cpp $(OBJ) -o Salida/tcalendario/tad12
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad13.cpp $(OBJ) -o Salida/tcalendario/tad13
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad14.cpp $(OBJ) -o Salida/tcalendario/tad14
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad15.cpp $(OBJ) -o Salida/tcalendario/tad15
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad16.cpp $(OBJ) -o Salida/tcalendario/tad16
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad17.cpp $(OBJ) -o Salida/tcalendario/tad17
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad18.cpp $(OBJ) -o Salida/tcalendario/tad18
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad19.cpp $(OBJ) -o Salida/tcalendario/tad19
	#$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tcalendario/tad20.cpp $(OBJ) -o Salida/tcalendario/tad20


$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<
	
doc:
	doxygen

clean:
	rm -f $(OBJ) && rm -r Salida/tcalendario/* 