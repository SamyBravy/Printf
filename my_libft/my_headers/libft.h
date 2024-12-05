/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:36:46 by alborghi          #+#    #+#             */
/*   Updated: 2024/12/05 17:35:48 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "external.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// my_lst
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

// my_mem
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_free_mat(void **mat);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);

// my_nbr
int				ft_abs(int nb);
long			ft_labs(long nb);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_no_sign(int n);
int				ft_log(int nb, int base);
int				ft_ulog(unsigned int nb, unsigned int base);
size_t			ft_stlog(size_t nb, size_t base);
long			ft_llog(long nb, long base);
//int				ft_ullog(unsigned long nb, int base);
int				ft_pow(int nb, int power);
unsigned int	ft_upow(unsigned int nb, unsigned int power);
size_t			ft_stpow(size_t nb, size_t power);
long			ft_lpow(long nb, long power);
int				ft_sqrt(int nb);
unsigned int	ft_usqrt(unsigned int nb);
size_t			ft_stsqrt(size_t nb);
long			ft_lsqrt(long nb);

// my_put
int				ft_putchar(char c);
int				ft_putchar_fd(char c, int fd);
int				ft_putendl(char *s);
int				ft_putendl_fd(char *s, int fd);
int				ft_putnbr(int n);
int				ft_putnbr_fd(int n, int fd);
int				ft_putstr(char *s);
int				ft_putstr_fd(char *s, int fd);

// my_str
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_pend_char(char *str, int n, char c, int append);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strnchr(const char *s, int c, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s, size_t len);
char			*str_dup_till_charset(const char *str, const char *charset);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strlen_int(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif