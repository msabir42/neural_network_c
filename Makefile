# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = neural_network

# Source files
SRCS = main.c parse.c matrix.c init.c simulation.c addition.c subtraction.c \
       multiplication.c transpose.c activation.c element_op.c helpers.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lm

# Compile source files to object files
%.o: %.c neural.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re