/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:17:20 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/06 17:40:57 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_OPEN_FILES
#  define MAX_OPEN_FILES 1024
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*extract_line(char *backup);
char	*update_backup(char *backup);
char	*ft_strchr(char const *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*read_to_backup(int fd, char *backup);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);

#endif