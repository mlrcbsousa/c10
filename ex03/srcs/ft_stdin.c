/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 03:20:25 by manuel            #+#    #+#             */
/*   Updated: 2021/02/03 02:24:05 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_stdin(t_app *self)
{
	int		size;
	char	buf[BUF_SIZE + 1];

	while ((size = read(STDIN, buf, BUF_SIZE)))
	{
		buf[size] = 0;
		hexdump(self, buf);
	}
}
