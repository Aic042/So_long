/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:27:08 by aingunza          #+#    #+#             */
/*   Updated: 2024/10/21 12:37:26 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handleptr(va_list args)
{
	void	*ptr;
	int		i;

	i = 0;
	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		i += ft_putstr("(nil)");
	}
	else
	{
		ft_putstr("0x");
		i += 2 + ft_puthex((unsigned long)ptr, "0123456789abcdef");
	}
	return (i);
}
