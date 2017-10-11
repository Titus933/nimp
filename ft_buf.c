/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:50:15 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_display(t_list *f)
{
	f->ret += write(1, g_buf, g_ibuf);
	ft_setbuf();
}

void				ft_buf(char c, t_list *f)
{
	g_buf[g_ibuf] = c;
	g_ibuf++;
	if (g_ibuf == 4096)
		ft_display(f);
}

void				ft_buf_null(t_list *f)
{
	static char		*str;
	int				i;

	i = 0;
	str = "(null)";
	while (str[i] != '\0')
	{
		ft_buf(str[i], f);
		i++;
	}
}
