/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 00:06:04 by manuel            #+#    #+#             */
/*   Updated: 2021/02/03 01:41:03 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_foreach(t_app *self)
{
	while (*(self->paths))
	{
		ft_display_file(self, *(self->paths));
		self->paths++;
	}
}

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

void	hexdump(t_app *self, char *buf)
{
	int		counter;
	int		aux;

	if (self->cflag)
		ft_putstr(buf);
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

t_bool	is_c_flag(char *flag)
{
	return (*flag && *flag++ == '-' && *flag == 'C');
}

int		main(int argc, char **argv)
{
	t_app	self;

	self = (t_app) { .name = *argv++, .error = false, .cflag = false };
	if (argc > 1 && is_c_flag(*argv))
	{
		self.cflag = true;
		argv++;
	}
	if (argc == 1 || (argc == 2 && self.cflag))
	{
		ft_stdin(); // pass self here to vary stdin
		return (0);
	}
	self.paths = argv;
	ft_foreach(&self);
	return (self.error);
}
