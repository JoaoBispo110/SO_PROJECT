CC:=gcc

CFLAGS:=-Iinclude/ -O0
ifdef DEBUG
	CFLAGS+= -g
endif

EXEC_NAME:=hello_world
EXEC_DIR:=./

EXEC_PATH:=$(EXEC_DIR)$(EXEC_NAME)

SRC:= $(shell find src -name '*.c')

OBJS:=$(SRC:%.c=%.o)

all: $(EXEC_PATH)

$(EXEC_PATH): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(EXEC_PATH)

$(OBJS):

clean:
	rm $(EXEC_PATH)
	rm src/*.o