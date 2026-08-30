CC      = clang
CFLAGS  = -Wall -Wextra -g -O0 -Isrc -fsanitize=address -fno-omit-frame-pointer
LDFLAGS = -fsanitize=address
TARGET  = cmpx

SRCS := $(shell find src -name '*.c')
OBJS := $(SRCS:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	ASAN_SYMBOLIZER_PATH=/usr/bin/llvm-symbolizer ./$(TARGET)
