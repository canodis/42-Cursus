SRCS		= so_long.c srcs/ft_read_map.c srcs/ft_split_fs.c srcs/ft_init_map.c \
srcs/wall_controller.c srcs/ft_init_xpm.c srcs/ft_create_map.c srcs/ft_key_events.c\
srcs/ft_animator.c
NAME		= so_long
minilibx	= mlbx/libmlx.a
OBJS_DIR	= objs/
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra
MLB_FLAGS	= -I -g -L /usr/X11/lib -Lincludes -L./mlbx -lmlx -Imlx -lXext -lX11 -lm libft/libft.a ft_printf/libftprintf.a

$(OBJS_DIR)%.o : %.c includes/so_long.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED) maker
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(MLB_FLAGS)

all: $(NAME)

maker:
	@make -C mlbx
	@make -C libft
	@make -C ft_printf

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C libft
	@make clean -C ft_printf

fclean: clean
	@make clean -C mlbx
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
