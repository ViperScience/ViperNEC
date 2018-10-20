# Makefile for building nec2dxs.c created by f2c.
# Dylan Crocker, Oct. 20, 2018
# (c) 2018 Viper Science LLC

CC := gcc-8
CFLAGS := -g

OBJECTS	:= nec2dxs.o second_.o
INCLUDE := libf2c

all: nec2dxs

nec2dxs: $(OBJECTS)
	$(CC) $(OBJECTS) -I$(INCLUDE) -L$(INCLUDE) -lf2c -o nec2dxs

nec2dxs.o: nec2dxs.c
	$(CC) $(CFLAGS) -c -I$(INCLUDE) nec2dxs.c -o nec2dxs.o

second_.o: second_.c
	$(CC) $(CFLAGS) -c second_.c -o second_.o

clean:
	rm -f nec2dxs *.o
