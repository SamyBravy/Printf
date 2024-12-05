/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:11:47 by alborghi          #+#    #+#             */
/*   Updated: 2024/12/04 14:22:47 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include "external.h"
# include "libft.h"

char	*till_new_line(char *buf, int fd);
char	*get_new_line(char *buf, char *line);
char	*get_rest(char *buf);
char	*get_next_line(int fd);

#endif