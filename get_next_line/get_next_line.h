/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:15:57 by juhaamid          #+#    #+#             */
/*   Updated: 2024/01/28 16:57:47 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_reading(int fd, char *text);
char	*ft_strchrr(char *s, int c);
size_t	ft_strlenn(char *str);
void	*ft_memmovee(void *dst, const void *src, size_t len);
char	*ft_strjoinn(char *s1, char *s2);
// <=== ADDED FUNCTIONS
char	*ft_strdupp(char *s1);
char	*ft_strnndup(const char *src, int n);

#endif