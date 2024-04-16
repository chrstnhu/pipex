/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:12:06 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/30 16:45:46 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1042
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}		t_list;

//Number
int		ft_atoi(const char *nptr);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);

//Allocation
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

//Memory
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//String
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char *start, char *buff);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strstr(char *str, char *to_find);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//Split
char	**ft_split(char const *s, char c);
char	**ft_split_ps(char *s, char c);

//Write
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//Link list
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

//Double link list
void	ft_dbl_lstadd_back(t_list **lst, t_list *new);
void	ft_dbl_lstadd_front(t_list **lst, t_list *new);
void	ft_dbl_lstclear(t_list **lst);
t_list	*ft_dbl_lstnew(int content);

//PRINTF
int		ft_printf(const char *s, ...);
int		ft_printf_char(char c);
int		ft_printf_str(char *str);
int		ft_printf_ptr(void const *p);
int		ft_printf_dec(int num);
int		ft_printf_dec_uns(unsigned int num);
int		ft_printf_hex_min(unsigned int num);
int		ft_printf_hex_max(unsigned int num);

//GET NEXT LINE
// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 42
// # endif
char	*get_next_line(int fd);

#endif
