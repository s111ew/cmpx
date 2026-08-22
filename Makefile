CC      = clang
CFLAGS  = -Wall -Wextra -g -Isrc
TARGET  = cmpx

SRCS := $(shell find src -name '*.c')
OBJS := $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
