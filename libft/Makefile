# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 10:08:42 by chrhu             #+#    #+#              #
#    Updated: 2023/11/16 16:26:38 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALLOCATION_DIRS = allocation/ft_bzero.c allocation/ft_calloc.c

CONVERT_DIRS = convert/ft_atol.c convert/ft_atoi.c convert/ft_free_split.c \
		convert/ft_itoa.c convert/ft_split_ps.c convert/ft_split.c

DBL_LINK_LIST_DIRS = double_link_list/ft_dbl_lstadd_back.c double_link_list/ft_dbl_lstaddfront.c \
			double_link_list/ft_dbl_lstclear.c double_link_list/ft_dbl_lstnew.cc

PRINTF_DIRS = ft_printf/ft_printf_char.c ft_printf/ft_printf_dec.c ft_printf/ft_printf_hex.c \
		ft_printf/ft_printf_ptr.c ft_printf/ft_printf_str.c ft_printf/ft_printf.c

GNL_DIRS = gnl/get_next_line_utils.c  gnl/get_next_line.c

LINK_LIST_DIRS =  link_list/ft_lstadd_back.c link_list/ft_lstadd_front.c \
			link_list/ft_lstclear.c link_list/ft_lstdelone.c \
			link_list/ft_lstiter.c link_list/ft_lstlast.c \
			link_list/ft_lstmap.c link_list/ft_lstnew.c \
			link_list/ft_lstsize.c

MEMORY_DIRS = memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c \
		memory/ft_memmove.c memory/ft_memset.c

PUT_DIRS = put/ft_putchar_fd.c put/ft_putendl_fd.c put/ft_putnbr_fd.c \
		put/ft_putstr_fd.c

STRING_DIRS = string/ft_strcat.c string/ft_strchr.c string/ft_strcmp.c \
		string/ft_strcpy.c string/ft_strdup.c string/ft_striteri.c \
		string/ft_strjoin.c string/ft_strlcat.c string/ft_strlcpy.c \
		string/ft_strlen.c string/ft_strmapi.c string/ft_strncat.c \
		string/ft_strncmp.c string/ft_strnstr.c string/ft_strrchr.c \
		string/ft_strstr.c string/ft_strtrim.c string/ft_substr.c

VERIFY_IS_DIRS = verify_is/ft_isalnum.c verify_is/ft_isalpha.c verify_is/ft_isascii.c \
		verify_is/ft_isdigit.c verify_is/ft_isprint.c verify_is/ft_tolower.c verify_is/ft_toupper.c

SRCS = $(ALLOCATION_DIRS) $(CONVERT_DIRS) $(PRINTF_DIRS) $(MEMORY_DIRS) $(PUT_DIRS) $(VERIFY_IS_DIRS) $(LINK_LIST_DIRS) $(DBL_LINK__LIST_DIRS) $(GNL_DIRS) $(STRING_DIRS)

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
