/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:38 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/17 16:25:41 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "GNL/get_next_line.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*=================== MANDATORY PART ===================*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *str, int value, size_t num);
void				*ft_bzero(void *str, size_t num);
void				*ft_memcpy(void *dest, const void *src, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
char				**ft_split(char const *s, char sep);
int					ft_count_word(char const *s, char sep);
char				*ft_unsplit(char **tab_to_unsplit, char *sep);
char				*ft_strcat(char *s1, char *s2, char *array);
void				free_2d_array(char **array);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_is_even(int nb);
int					ft_abs(int to_check);

/*===================== BONUS PART =====================*/
/*==================== BONUS STRUCT ====================*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*================== BONUS PROTOTYPE ===================*/
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
/*=================== PRINTF PART ===================*/
int					ft_printf_fd(int fd, const char *str, ...);
int					ft_printf(const char *str, ...);
int					ft_cputstr(int fd, char *str);
int					ft_cputnbr(int fd, int nb);
int					ft_cuputnbr(int fd, unsigned int nb);
int					ft_cputchar(int fd, char c);
int					ft_convert_to_hex(int fd, unsigned int nb, char type);
int					ft_point_to_hex(int fd, unsigned long long nb);

#endif
