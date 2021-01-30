/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 00:06:04 by manuel            #+#    #+#             */
/*   Updated: 2021/01/30 04:37:59 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
/*
void	ft_foreach(t_app *self)
{
	while (*(self->paths))
	{
		ft_display_file(self, *(self->paths));
		self->paths++;
	}
}*/

void	hexdump(t_app *self, char *buf)
{
	(void)self;
	ft_putstr(buf);
}

t_bool	is_c_flag(char *flag)
{
	return (*flag && *flag == '-' && *(++flag) == 'C');
}

int		main(int argc, char **argv)
{
	t_app	self;

	self = (t_app) { .name = *argv++, .error = false, .cflag = false };
	if (argc > 1 && is_c_flag(*argv))
		self.cflag = true;
	if (argc == 1 || (argc == 2 && self.cflag))
	{
		ft_stdin(); // send self here to vary stdin
		return (0);
	}
	//self.paths = argv;
	//ft_foreach(&self);
	return (self.error);
}
