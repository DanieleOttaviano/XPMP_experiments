CC = gcc
CFLAGS = -Wall -Wextra

SRCS = main.c grt.c
OBJS = $(SRCS:.c=.o)

TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
