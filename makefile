# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
INCLUDES = -Iinclude


# Executable
TARGET = shell


# Source files
SOURCE = src/main.c \
	src/parser.c \
	src/executor.c \
	src/builtins.c \
	src/redirection.c \
	src/pipeline.c \
	src/jobs.c \
	src/signals.c


# Object files
OBJECTS = $(SOURCE:.c=.o)


# Build
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "build complete"


# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


# Remove generated files
clean:
	rm -f $(OBJECTS) $(TARGET)


# Rebuild everything
rebuild: clean all


# Run
run: $(TARGET)
	./$(TARGET)


.PHONY: all clean rebuild run

