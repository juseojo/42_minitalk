/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:27:15 by seongjch          #+#    #+#             */
/*   Updated: 2022/08/05 07:58:52 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
int		ft_puthexlow_fd(unsigned int ln, int fd);
int		ft_puthexup_fd(unsigned int ln, int fd);
int		ft_putpoint_fd(unsigned long long ln, int fd);

#endif
