CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = aoc
SOURCES = aoc.c days/utils.c days/visited.c days/day01.c days/day02.c days/day03.c days/day04.c days/day05.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean
