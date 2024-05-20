/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:54:29 by eyasa             #+#    #+#             */
/*   Updated: 2024/05/18 16:45:55 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strchr_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *str);
char	*ft_strcpy_gnl(char *s1, char *s2, int n);
char	*get_next_line(int fd);
#endif
