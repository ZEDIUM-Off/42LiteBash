/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:50:15 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/15 13:24:32 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <minish.h>

size_t		ft_strlen(const char *s);
size_t		ft_strlen_line(char *str);
size_t		ft_strlen_int(const char *s);
size_t		ft_strlen_to_char(const char *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

ssize_t		ft_cont_word(char const *s, char c);

void		ft_free_tab(t_sh_context *shx, char **strs);
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
int			ft_isspace(int c);
int			ft_atoi(const char *str);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);

char		*ft_itoa(t_sh_context *shx, int n);
char		*ft_strdup(t_sh_context *shx, const char *str);
char		*ft_strjoin(t_sh_context *shx, char *s1, char *s2);
char		*ft_strfjoin(t_sh_context *shx, char *s1, char *s2);
char		*ft_strnjoin(t_sh_context *shx, char *s1, char *s2, ssize_t n);
char		*ft_strchr(const char *s, int c);
char		**ft_split(t_sh_context *shx, char const *s, char c);
char		*ft_strrchr(const char *s, int c);
char		**ft_split_space_tab(char const *s);
char		*ft_strdup_char(t_sh_context *shx, const char *str, char c);
char		*ft_strtrim(t_sh_context *shx, char const *s1, char const *set);
char		*ft_substr(t_sh_context *shx, char const *s,
				unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strcspn(const char *s, const char *reject);

long long	ft_atoll(const char *str);
long long	ft_strtoll(const char *str);

#endif
