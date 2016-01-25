SRCS = ft_putchar.c \
	   ft_putstr.c \
	   ft_strlen.c \
	   ft_putnbr.c \
	   t_opts.c \
	   ft_printf.c

NAME = libftprintf.a
GCC_FLAGS = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAGS)
SRCDIR = ./
OBJDIR = ./
AR = ar -cq
RM = rm -rf
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: clean $(NAME) test
$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "Link $^"
	@ranlib $@
	@echo "[$@] Complete"

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $^
	@echo "[√]$^ "

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

test:
	$(CC) $(NAME) main.c -o exe
	./exe "toto"
