CC = gcc
CFLAGS = -Wall -Wextra

SRCS = main.c source.c
OBJS = $(SRCS:.c=.o)
HEADERS = header.h
TARGET = random

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
