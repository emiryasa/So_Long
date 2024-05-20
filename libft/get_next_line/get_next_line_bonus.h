/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:04:31 by eyasa             #+#    #+#             */
/*   Updated: 2024/05/18 16:46:13 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef SOFT_LIM
#  define SOFT_LIM 4096
# endif

int		ft_strchr_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *str);
char	*ft_strcpy_gnl(char *s1, char *s2, int n);
char	*get_next_line(int fd);
#endif
