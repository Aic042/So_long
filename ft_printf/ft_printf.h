/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:01:30 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/19 15:05:46 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_handleptr(va_list args);

int	ft_putunsigned(unsigned int nb);

int	ft_puthex(unsigned long nb, char *base);

int	ft_putchar(char c);

int	ft_putnbr(int c);

int	ft_putstr(char *str);

int	ft_printf(const char *format, ...);

#endif