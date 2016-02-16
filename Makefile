SRCS = t_opts.c \
	   ft_printf.c \
	   ft_puts.c \
	   t_opts.c \
	   t_opts_tools.c \
	   ft_itoa_base.c \
	   t_printf.c

NAME = libftprintf.a
GCC_FLAGS = -Wall -Werror -Wextra
CC = gcc # $(GCC_FLAGS)
SRCDIR = ./
OBJDIR = ./objs
AR = ar -cq
RM = rm -rf
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFT = ./libft/libft.a


all: $(NAME) test

$(LIBFT):
	make -C libft
	echo $(SRC_LIB_O)

$(NAME): $(OBJS) $(LIBFT)
	@$(AR) $@ $^ ./libft/*.o
	@echo "Link $^"
	@ranlib $@
	@echo "[$@] Complete"

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $^
	@echo "[√]$^ "

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

test:
	$(CC) main.c $(NAME) -o printf
	./printf "Hello World"
