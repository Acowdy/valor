.POSIX:
.PHONY: format clean

CC	= cc
CFLAGS	= -std=c99 -Wall -pedantic -O2
LDLIBS	= -lm

RM	= rm -f

BIN 		= valorc
BIN_OBJS	= main.o

all: $(BIN)

$(BIN): $(BIN_OBJS)
	$(CC) $(LDFLAGS) -o $(BIN) $(BIN_OBJS) $(LDLIBS)

format:
	@for f in *.c ; do indent $$f ; done

clean:
	$(RM) $(BIN) $(BIN_OBJS)


###############################################################################
# DO NOT EDIT
#
# Automatically made with 'clang -MM *.c'

main.o: main.c
