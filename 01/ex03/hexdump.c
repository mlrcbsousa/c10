/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 02:14:34 by manuel            #+#    #+#             */
/*   Updated: 2021/02/04 01:34:44 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	hexdump(t_app *self, char *buf)
{
	int	counter;

	counter = 0;
	while (*buf)
	{
		if (counter % 16 == 0)
			put_hex(self->count_d, counter);
		self->body(buf++, counter++);
	}
	if (counter % 16 != 15)
		self->fill(buf, counter);
	put_hex(self->count_d, counter);
	ft_putchar('\n');
}

void	body_(char *buf, int counter)
{
	if (counter % 2 == 0)
	{
		ft_putchar(' ');
		put_hex(2, *(buf + 1));
	}
	else
		put_hex(2, *(buf - 1));
	if (counter % 16 == 15)
		ft_putchar('\n');
}

void	fill_(char *buf, int counter)
{
	(void)buf;

	while (counter % 16 < 15)
	{
		ft_putstr("  ");
		if (counter++ % 2 == 0)
			ft_putchar(' ');
	}
	ft_putstr("  ");
	ft_putchar('\n');
}

void	extra_c(char *buf, int counter)
{
	ft_putchar('|');
	put_printables(buf - counter % 16);
	ft_putchar('|');
	ft_putchar('\n');
}

void	body_c(char *buf, int counter)
{
	if (counter % 8 == 0)
		ft_putstr("  ");
	else
		ft_putchar(' ');
	put_hex(2, *buf);
	if (counter % 16 == 15)
	{
		ft_putstr("  ");
		extra_c(buf, counter);
	}
}

void	fill_c(char *buf, int counter)
{
	int	aux;

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
	extra_c(buf, counter);
}
