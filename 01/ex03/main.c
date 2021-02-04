/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 00:06:04 by manuel            #+#    #+#             */
/*   Updated: 2021/02/04 01:17:53 by manuel           ###   ########.fr       */
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

t_bool	is_c_flag(char *flag)
{
	return (*flag && *flag++ == '-' && *flag == 'C');
}

int		main(int argc, char **argv)
{
	t_app	self;

	self = (t_app) { 
		.name = *argv++, 
		.error = false, 
		.cflag = false,
		.body = body_,
		.fill = fill_,
		.count_d = 7
	};
	if (argc > 1 && is_c_flag(*argv))
	{
		self = (t_app) { .cflag = true, .body = body_c, .fill = fill_c, .count_d = 8 }; 
		argv++;
	}
	if (argc == 1 || (argc == 2 && self.cflag))
	{
		ft_stdin(&self);
		return (0);
	}
	self.paths = argv;
	ft_foreach(&self);
	return (self.error);
}
