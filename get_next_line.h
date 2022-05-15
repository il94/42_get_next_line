/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:58:34 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/15 04:27:44 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

char	*ft_strjoin(char *stock, char const *buffer, int size_buffer);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
