/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 02:14:34 by manuel            #+#    #+#             */
/*   Updated: 2021/02/04 02:20:50 by manuel           ###   ########.fr       */
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
