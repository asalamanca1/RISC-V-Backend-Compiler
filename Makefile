CC = cc
OBJS = check_pow_two.o backend.o build_tree.o main.o
CFLAGS = -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings -Wconversion

all: compile

%o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

compile: $(OBJS)
	$(CC) -o $@ $^

run: compile
	./compile

testPowTwo: powTwoCompiler
	./powTwoExe

powTwoCompiler: check_pow_two.o test_pow_two.o
	$(CC) -o powTwoExe check_pow_two.o test_pow_two.o

clean:
	rm -rf *.o compile

check_pow_two.o: check_pow_two.c check_pow_two.h
test_pow_two.o: test_pow_two.c test_pow_two.h check_pow_two.h
build_tree.o: build_tree.c build_tree.h
backend.o: backend.c build_tree.h check_pow_two.h
main.o: main.c build_tree.h
