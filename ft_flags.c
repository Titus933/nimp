/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 04:23:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 06:28:25 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sharp(t_list *f)
{
	if ((f->flags[2] == 1 && f->result[0] != '0' && f->flags[0] != -1)
			|| f->spe == 'p')
	{
		if (f->spe == 'o' || f->spe == 'O' || f->spe == 'x' || f->spe == 'X' ||
				f->spe == 'p')
		{
			if ((f->spe == 'x' && f->result[0] != '0') || f->spe == 'p')
			{
				ft_buf('0', f);
				ft_buf('x', f);
			}
			else if (f->spe == 'X' && f->result[0] != '0')
			{
				ft_buf('0', f);
				ft_buf('X', f);
			}
			else if ((f->spe == 'o' || f->spe == 'O')
					&& f->flags[0] <= ft_strlen(f->result))
				ft_buf('0', f);
			else if ((f->spe == 'o' || f->spe == 'O')
					&& f->flags[0] == -1)
				ft_buf('0', f);
		}
	}
}

void	ft_space_plus_sharp(t_list *f)
{
	if (f->flags[5] == 1 || f->flags[6] == 1)
	{
		if (f->spe == 'd' || f->spe == 'D' || f->spe == 'i')
		{
			if (f->flags[6] == 1 && f->flags[5] == 0 && f->sign != '-')
				ft_buf(' ', f);
			if (f->flags[5] == 1 && ft_isdigit(f->result[0]) && f->sign == '+')
				ft_buf('+', f);
		}
	}
	if (f->sign == '-')
		ft_buf('-', f);
	ft_sharp(f);
}
