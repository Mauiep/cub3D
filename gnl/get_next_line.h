/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:38:27 by rovillar          #+#    #+#             */
/*   Updated: 2022/01/18 16:38:29 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*ft_xstrchr(char *str, int c);
char	*ft_xstrjoin(char *save, char *buff);
size_t	ft_xstrlen(char *str);

#endif
