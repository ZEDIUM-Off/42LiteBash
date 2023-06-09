/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:50:15 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/09 12:00:09 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

size_t		ft_strlen(const char *s);
size_t		ft_strlen_line(char *str);
size_t		ft_strlen_int(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

ssize_t		ft_cont_word(char const *s, char c);

void		ft_free_tab(char **strs);
void		ft_putnbr_fd(int n, int fd);
void		ft_bzero(void *s, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_free_tab_len(char **strs, int len);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isspace(int c);

char		*ft_itoa(int n);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strfjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
char		*ft_strrchr(const char *s, int c);
char		**ft_split_space_tab(char const *s);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

long long	ft_atoll(const char *str);

#endif
