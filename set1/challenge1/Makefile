# Especifica o compilador
CC = g++

# Especifica as flags do compilador
CFLAGS = -Wall -std=c++11 

# Especifica o nome do executável
TARGET = main_program

OBJS = chall1.o ../cryptopals.o
# Regra padrão executada ao rodar 'make'
all: $(TARGET)

# Linka o objeto main.o para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compila o arquivo main.cpp para criar o objeto main.o
chall1.o: chall1.cpp ../cryptopals.h
	$(CC) $(CFLAGS) -I../ -c chall1.cpp

cryptopals.o: ../cryptopals.cpp ../cryptopals.h
	$(CC) $(CFLAGS) -c ../cryptopals.cpp

# Limpa os arquivos criados durante a compilação
clean:
	rm -f *.o ../cryptopals.o $(TARGET)

# Executa o programa
run: $(TARGET)
	./$(TARGET)