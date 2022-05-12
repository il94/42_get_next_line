/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:58:34 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/11 10:16:09 by ilandols         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char const *s2, int size2);
char	*get_next_line(int fd);

#endif
