/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:49:07 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_setbuf(void)
{
	int				n;

	n = 0;
	while (n < 4096)
	{
		g_buf[n] = '\0';
		n++;
	}
	g_ibuf = 0;
}

void				ft_flags_init(t_list *f)
{
	int		i;

	i = 0;
	while (i < 14)
	{
		f->flags[i] = 0;
		i++;
	}
	f->flags[i] = '\0';
	f->index = 0;
}

void				ft_init_specifiers2(t_spec *specifiers)
{
	specifiers[11].c = 'x';
	specifiers[11].ptr = &ft_printf_x;
	specifiers[12].c = 'X';
	specifiers[12].ptr = &ft_printf_wx;
	specifiers[13].c = 'p';
	specifiers[13].ptr = &ft_printf_p;
	specifiers[14].c = 0;
	specifiers[14].ptr = NULL;
}

void				ft_init_specifiers(t_spec *specifiers)
{
	specifiers[0].c = 's';
	specifiers[0].ptr = &ft_printf_s;
	specifiers[1].c = 'S';
	specifiers[1].ptr = &ft_printf_ws;
	specifiers[2].c = 'c';
	specifiers[2].ptr = &ft_printf_c;
	specifiers[3].c = 'C';
	specifiers[3].ptr = &ft_printf_wc;
	specifiers[4].c = 'd';
	specifiers[4].ptr = &ft_printf_d;
	specifiers[5].c = 'D';
	specifiers[5].ptr = &ft_printf_wd;
	specifiers[6].c = 'i';
	specifiers[6].ptr = &ft_printf_d;
	specifiers[7].c = 'o';
	specifiers[7].ptr = &ft_printf_o;
	specifiers[8].c = 'O';
	specifiers[8].ptr = &ft_printf_wo;
	specifiers[9].c = 'u';
	specifiers[9].ptr = &ft_printf_u;
	specifiers[10].c = 'U';
	specifiers[10].ptr = &ft_printf_wu;
	ft_init_specifiers2(specifiers);
}

t_list				ft_init(void)
{
	t_list	new;

	ft_setbuf();
	ft_flags_init(&new);
	new.spe = '0';
	new.sign = '\0';
	new.ret = 0;
	new.wresult = NULL;
	new.result = NULL;
	new.frmt = NULL;
	return (new);
}
