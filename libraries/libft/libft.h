/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:23:20 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 19:27:00 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <stdio.h>
# include <stddef.h>

size_t	ft_strlen(const char *trs);

int	ft_strcmp(const char *s1, const char *s2);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memdel(void *ptr);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strcat(char *dst, const char *src);

#endif
