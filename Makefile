OBJS := $(wildcard src/*.c)
OBJ_NAME = xese

${OBJ_NAME}: ${OBJS}
	gcc -o ${OBJ_NAME} -g ${OBJS}

.PHONY: ${OBJ_NAME} clean

clean:
	rm -f ${OBJ_NAME} *.o *.s out

test: ${OBJ_NAME} tests/files/input01
	./${OBJ_NAME} tests/files/input01
	nasm -f elf64 out.s
	gcc -no-pie -o out out.o
	./out
