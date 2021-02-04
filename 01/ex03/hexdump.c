/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 02:14:34 by manuel            #+#    #+#             */
/*   Updated: 2021/02/04 02:37:40 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	hexdump(t_app *self, char *buf)
{
	while (*buf)
	{
		if (self->count % 16 == 0)
			put_hex(self->count_d, self->count);
		self->body(buf++, self->count++);
	}
	if (!*(self->paths + 1))
	{
		if (self->count % 16 != 15)
			self->fill(buf, self->count);
		put_hex(self->count_d, self->count);
		ft_putchar('\n');
	}
}
