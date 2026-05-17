CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -g
TARGET  = campeonato
SRCS    = main.c time.c bdtimes.c partida.c bdpartidas.c
OBJS    = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
