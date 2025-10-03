CC = gcc
C_FLAGS = -Iinclude --std=c99 -c

SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))

EXE = bin/morpion

all: $(EXE)
run: all
	./$(EXE)

$(EXE): $(OBJS)
	@mkdir -p bin
	$(CC) $(OBJS) -o $@

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(C_FLAGS) $< -o $@

clean:
	rm -rf build bin