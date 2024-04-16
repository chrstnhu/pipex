LIBFT_PATH = ./libft

SRCS_PATH = srcs_mandatory
#SRCS_BONUS_PATH = srcs_bonus

SRCS_MANDATORY = main.c utils.c free.c
#SRCS_WITH_BONUS = main_bonus.c utils_bonus.c free_bonus.c child_bonus.c


SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_MANDATORY))
OBJS = $(SRCS_MANDATORY:%.c=$(SRCS_PATH)/%.o)

#SRCS_BONUS = $(addprefix $(SRCS_BONUS_PATH)/, $(SRCS_WITH_BONUS))
#OBJS_BONUS = $(SRCS_WITH_BONUS:%.c=$(SRCS_BONUS_PATH)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_PATH)

NAME = pipex
#NAME_BONUS = pipex_bonus

all: $(NAME)
# bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft

#$(NAME_BONUS): $(OBJS_BONUS)
#	$(MAKE) -C $(LIBFT_PATH)
#	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBFT_PATH) -lft

%.o: srcs_m/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re


