/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:41:15 by cgaspart          #+#    #+#             */
/*   Updated: 2018/04/30 08:26:55 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buffer
{
	char			buffer[5000];
	struct s_buffer	*next;
}					t_buffer;

void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
void				ft_putnbr(int n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *str);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrealloc(char *line, int len);
size_t				ft_strlcat(char *dest, const char *src, size_t count);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_str_fjoin(char *s1, char *s2, int i);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				**ft_tabascii(char **tab);
char				**ft_tabrev_ascii(char **tab);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_puttab(char **tab);
void				ft_print_space(int maxspace, int len);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_issame(char *first, char *second);
int					ft_skip_flag(int argc, char **argv);
int					ft_tablen(char **tab);
char				*ft_add_str_path(char *str, char *dirname);
char				**ft_add_tab_path(char **tab, char *dirname);
char				*ft_rm_str_path(char *str);
char				**ft_rm_tab_path(char **tab);
void				ft_swap(char **str1, char **str2);
int					ft_intlen(int nbr);
void				ft_free_tab(char **tab);
t_buffer			*ft_newbuffer(void);
int					ft_putstr_b(t_buffer *my_buffer, char *str);
int					ft_addstr_b(t_buffer *my_buffer, char *str);
void				rm_lastpath_b(t_buffer *path);
void				ft_rm_b_path(t_buffer *my_buffer);
int					get_nbr_word(char *str);
char				ft_type(char *dirname);
char				**ft_split_whitespaces(char *s);
void				ft_fatal(char *error_mess, char *this);
#endif
