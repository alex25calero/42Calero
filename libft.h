/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:18:55 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/09 12:46:19 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_h
# include <stdio.h>
# include <unistd.h>
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);
int		ft_isascii(char c);
int		ft_isprint(char c);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	*ft_memset(void *s, int c, unsigned int n);
char	ft_toupper(char c);
char	ft_tolower(char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);





# endif