OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -g -w -O3
EXE 	 := trab1
PROJETO  := main

# Cria objetos de todos os arquivos de código-fonte para então linká-los no programa final
main: clean $(OBJ)/utils.o  $(OBJ)/grafo.o $(OBJ)/$(PROJETO).o
	gcc -g $(OBJ)/*.o -o $(EXE) $(CFLAGS)

$(OBJ)/grafo.o: $(SRC)/grafo.c $(INC)/grafo.h
	gcc -c $(CFLAGS) "$(SRC)/grafo.c" -o "$(OBJ)/grafo.o"

$(OBJ)/utils.o: $(SRC)/utils.c $(INC)/utils.h
	gcc -c $(CFLAGS) "$(SRC)/utils.c" -o "$(OBJ)/utils.o"

$(OBJ)/$(PROJETO).o: $(PROJETO).c
	gcc -c $(CFLAGS) $(PROJETO).c -o "$(OBJ)/$(PROJETO).o"

# Roda o programa com entrada 1
run_1:
	./$(EXE) entradas/1.txt 2 saida.txt

# Roda o programa com entrada 2
run_2:
	./$(EXE) entradas/2.txt 4 saida.txt


# Roda o programa com entrada 3
run_3:
	./$(EXE) entradas/3.txt 5 saida.txt


# Roda o programa com entrada 4
run_4:
	./$(EXE) entradas/4.txt 5 saida.txt


# Roda o programa com entrada 5
run_5:
	./$(EXE) entradas/5.txt 10 saida.txt

# Roda o programa com valgrind e flags úteis (entrada 3)
val:
	valgrind --leak-check=full -v --track-origins=yes \
	--show-leak-kinds=all ./$(EXE) entradas/3.txt 5 saida.txt

# Roda o programa com valgrind sem flags (entrada 3)
valzin:
	valgrind ./$(EXE)

# Roda o programa com valgrind e salva resultados num .txt (entrada 3)
valtxt:
	valgrind --leak-check=full -v --show-leak-kinds=all --track-origins=yes --verbose --log-file="valgrind-out.txt" ./$(EXE)

# Limpa objetos e o executável do programa
clean:
	-rm $(OBJ)/*.o
	-rm $(EXE)
