TARGET = easypay
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)
CC = arm-linux-gcc

easypay : $(OBJS)
	$(CC) $^ -o $@ -I ./include  -lpthread -liconv -lgsmd -lqrencode -lcurl -lexpat -L ./libs/ ./libs/libmsg.a
%.o : %.c
	$(CC) -c $<
clean:
	@rm -vf $(TARGET) *.o *~

