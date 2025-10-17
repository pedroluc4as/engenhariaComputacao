clean:
	@echo "\n#Excluindo os programas (executáveis) e os arquivos intermediários..."
	rm -rf ./obj/1.o
	rm -rf ./obj/2.o
	rm -rf ./obj/3.o
	rm -rf ./ec_imprime.o
	@echo "\n#Compilação dos Aplicativos (Executáveis)..."
	rm -rf ./bin/main.c
	
tads:
	@echo "\n#Compilação dos TADS (Tipos abstratos de dados)..."
	gcc -c ./src/1.c -I ./include/ -o ./obj/1.o
	gcc -c ./src/2.c -I ./include/ -o ./obj/2.o
	gcc -c ./src/2.c -I ./include/ -o ./obj/3.o
	gcc -c ./src/ec_imprime.c -I ./include/ -o ./obj/ec_imprime.o
