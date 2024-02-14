OBJS := $(wildcard src/*.c)
OBJ_NAME = prose

${OBJ_NAME}: ${OBJS}
	gcc -o ${OBJ_NAME} -g ${OBJS}

.PHONY: ${OBJ_NAME} clean

clean:
	rm -f ${OBJ_NAME} *.o *.s out

test: ${OBJ_NAME} tests/files/input01 tests/files/input02

	./${OBJ_NAME} tests/files/input01
	nasm -f elf64 out.s
	gcc -no-pie -o out out.o -z noexecstack
	./out

	./${OBJ_NAME} tests/files/input02
	nasm -f elf64 out.s
	gcc -no-pie -o out out.o -z noexecstack
	./out
