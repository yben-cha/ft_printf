CC = cc
CFLAGS = -Wall -Wextra -Werror

# List all the source files here that implement the print_* functions
SRCS = ft_printf.c print_hex.c print_pointer.c print_string.c print_char.c print_int.c print_precent.c

# Generate object files from source files
OBJS = $(SRCS:.c=.o)

# Header file location
HEADER = ft_printf.h

# The name of the static library
NAME = libftprintf.a

# The default target is to create the static library
all: $(NAME)

# Create the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up object files and the static library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

