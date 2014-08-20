TARGET = easypay
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)
CC = arm-linux-gcc

easypay : $(OBJS)
	$(CC) $^ -o $@ -I ./include  -liconv -lgsmd -lqrencode -lcurl -lexpat -L ./libs/
%.o : %.c
	$(CC) -c $<
clean:
	@rm -vf $(TARGET) *.o *~

