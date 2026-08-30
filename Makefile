CC      = clang
CFLAGS  = -Wall -Wextra -g -Isrc -fsanitize=address -fno-omit-frame-pointer
LDFLAGS = -fsanitize=address
TARGET  = cmpx

SRCS := $(shell find src -name '*.c')
OBJS := $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
