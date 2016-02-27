.PHONY: leaks

SRCS = t_opts.c \
	   ft_printf.c \
	   t_opts.c \
	   t_opts_tools.c \
	   t_opts_render.c \
	   ft_itoa_base.c \
	   tools.c \
	   addchar.c \
	   ft_wcs.c \
	   t_opts_analyse.c \
	   t_printf.c

NAME = libftprintf.a
GCC_FLAGS = -Wall -Werror -Wextra
CC = gcc #$(GCC_FLAGS)
SRCDIR = ./
OBJDIR = ./objs
AR = ar -cq
RM = rm -rf
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFT = ./libft/libft.a


all: clean $(NAME)

$(LIBFT):
	#@make -C libft
	@echo $(SRC_LIB_O)

$(NAME): $(OBJS) $(LIBFT)
	@$(AR) $@ $^ ./libft/*.o
	@#echo "Link $^"
	@ranlib $@
	@#echo "[$@] Complete"

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $^

clean:
	@$(RM) $(NAME)
	@$(RM) $(OBJDIR)

fclean: clean
	#@make -C libft fclean
	@$(RM) printf
	@$(RM) ./printf.dSYM

re: fclean all

test:
	$(RM) printf
	$(CC) main.c $(NAME) -o printf
	./printf

leaks:
	$(RM) leakstest
	$(CC) mainleaks.c $(NAME) -o leakstest
	./leakstest
