/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:28:30 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/08 16:04:18 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;
size_t					ft_strnchr_index(const char *str, char c, size_t n);
size_t					ft_strchr_index(const char *str, char c);
void					free_double(char ***tab);
unsigned int			ft_getchr(void);
int						ft_strccmp(const char *str, const char *s2, char c);
char					*ft_strndup(const char *str, size_t size);
char					*ft_strcdup(const char *str, char c);
char					*ft_remplacer_str(char *chn, char *change, char *nchn);
int						ft_skip_lensep(char const *str, char *sp);
int						ft_skip_sep(const char *str, char *sep);
int						ft_is_separ(char const *str, char c);
char					*ft_reverse(char const *chaine);
int						ft_change_chr_to_nwchr(char *chaine,
		char *chr, char nwchr);
int						ft_sqrt(int nb);
t_list					*ft_new_lst(t_list *lst, char *str);
void					ft_print_list(t_list *list);
int						ft_count_char(char const *str);
int						ft_ret_start(char const *str);
int						ft_count_to_find(char *str, char *to_find);
void					ft_rev(char *str);
char					*ft_strccpy(char *dest, char const *src, char c);
int						ft_wordlen(char const *s, char c);
int						ft_count_word(char *s, char c);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstdelone(t_list **alst, void (*del)(void *,
			size_t));
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_putchar(char c);
void					ft_putstr(char const *str);
void					ft_putstr_fd(const char *s, int fd);
void					ft_memdel(void **ap);
void					ft_putchar_fd(char c, int fd);
void					*ft_memalloc(size_t size);
int						ft_atoi(const char *str);
int						ft_isalnum(int argument);
int						ft_isalpha(int argument);
int						ft_isascii(int arg);
int						ft_isdigit(int arg);
int						ft_isprint(int arg);
char					*ft_itoa(int n);
void					*ft_memccpy(void *restrict s1,
		const void *restrict s2, int c, size_t n);
void					*ft_memchr(const void *str, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *restrict str1,
		const void *restrict str2, size_t n);
void					ft_memdel(void **st);
void					*ft_memmove(void *str1, const void *str2, size_t n);
void					*ft_memset(void *str, int arg, size_t nb);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int i);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strcat(char *restrict etr, const char *restrict s2);
char					*ft_strchr(const char *str, int c);
void					ft_strclr(char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
void					ft_strdel(char **as);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char*));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char *str, char *str2);
size_t					ft_strlen(const char *str);
char					*ft_strmap(char const *str, char (*f)(char));
char					*ft_strmapi(char const *str, char (*f)(unsigned int i,
			char c));
char					*ft_strncat(char *restrict str, const char *restrict
		str2, size_t nb);
int						ft_strncmp(const char *str, const char *s2, size_t n);
char					*ft_strncpy(char *dest, const char *str, size_t nb);
int						ft_strnequ(char *s1, char *s2, size_t n);
char					**ft_strsplit(char const *s, char c);
char					*ft_strtrim(char const *s);
char					*ft_strnew(size_t size);
char					*ft_strsub(char const *s, unsigned int start,
		size_t len);
int						ft_tolower(int arg);
int						ft_toupper(int c);
char					*ft_strstr(const char *str, const char *to_find);
char					*ft_strnstr(const char *s, const char *to_,
		size_t n);
char					*ft_strrchr(const char *str, int c);
char					*ft_strdup(const char *str);
size_t					ft_strlcat(char *restrict dst, const char *restrict src,
		size_t size);
void					ft_bzero(void *s, size_t n);
char					*ft_pathjoin(char *path, char *dossier);
char					*ft_strsubdel(char *str, int start, int end);
#endif
