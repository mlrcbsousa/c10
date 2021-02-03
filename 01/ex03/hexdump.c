/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 02:14:34 by manuel            #+#    #+#             */
/*   Updated: 2021/02/03 23:30:51 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include <stdio.h>

void	dec_to_hex(int nbr)
{
	if (nbr > 15)
		dec_to_hex(nbr / 16);
	ft_putchar(HEX[nbr % 16]);
}

void	put_hex(int digits, int nbr)
{
	while (ft_recursive_power(16, --digits) > nbr && digits > 0)
		ft_putchar('0');
	dec_to_hex(nbr);
}

int		is_printable(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

void	put_printables(char *str)
{
	int	i;

	i = 0;
	while (i < 16 && *str)
	{
		if (is_printable(*str))
			ft_putchar(*str);
		else
			ft_putchar('.');
		str++;
		i++;
	}
}

void	hexdump(t_app *self, char *buf)
{
	int	counter;
	int	aux;

	if (self->cflag)
	{
		counter = 0;
		while (*buf)
		{
			if (counter % 16 == 0)
				put_hex(8, counter);
			if (counter % 8 == 0)
				ft_putstr("  ");
			else
				ft_putchar(' ');
			put_hex(2, *buf);
			if (counter % 16 == 15)
			{
				ft_putstr("  ");
				ft_putchar('|');
				put_printables(buf - 15);
				ft_putchar('|');
				ft_putchar('\n');
			}
			buf++;
			counter++;
		}
		if (counter % 16 != 15)
		{
			aux = counter;
			while (aux % 16 < 15)
			{
				if (aux++ % 8 == 0)
					ft_putstr("  ");
				else
					ft_putchar(' ');
				ft_putstr("  ");
			}
			ft_putstr("     ");
			ft_putchar('|');
			put_printables(buf - counter % 16);
			ft_putchar('|');
			ft_putchar('\n');
		}
		put_hex(8, counter);
		ft_putchar('\n');
	}
	else
	{
		counter = 0;
		while (*buf)
		{
			if (counter % 16 == 0)
				put_hex(7, counter);
			if (counter % 2 == 0)
			{
				ft_putchar(' ');
				put_hex(2, *(buf + 1));
			}
			else
				put_hex(2, *(buf - 1));
			if (counter % 16 == 15)
				ft_putchar('\n');
			buf++;
			counter++;
		}
		if (counter % 16 != 15)
		{
			aux = counter;
			while (aux % 16 < 15)
			{
				ft_putstr("  ");
				if (aux++ % 2 == 0)
					ft_putchar(' ');
			}
			ft_putstr("  ");
			ft_putchar('\n');
		}
		put_hex(7, counter);
		ft_putchar('\n');
	}
}

