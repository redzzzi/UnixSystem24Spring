CC = gcc
OBJS = add.o calculator.o divide.o minus.o multi.o
all: calchw
%.o: %.c
	$(CC) -c $^
calchw: $(OBJS)
	$(CC) -o calchw $(OBJS)
clean:
	rm calchw $(OBJS)
