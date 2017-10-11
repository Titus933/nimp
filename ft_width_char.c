/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 04:35:35 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:40:16 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_zero_char(t_list *f)
{
	int		nb_space;

	nb_space = f->flags[1] - ft_strlen(f->result);
	if ((f->spe == 'c' && f->result[0] == 0) ||
			(f->spe == 'C' && f->result[0] == 0))
		nb_space--;
	while (nb_space-- > 0)
	{
		if (f->flags[3] == 1 && f->flags[0] <= 0)
			ft_buf('0', f);
		else
			ft_buf(' ', f);
	}
	ft_display_result(f);
}

void		ft_minus_char(t_list *f)
{
	int		nb_space;

	nb_space = f->flags[1] - ft_strlen(f->result);
	if ((f->spe == 'c' && f->result[0] == 0) ||
			(f->spe == 'C' && f->result[0] == 0))
		nb_space--;
	ft_display_result(f);
	while (nb_space-- > 0)
		ft_buf(' ', f);
}

void		ft_width_char(t_list *f)
{
	int		i;

	i = 0;
	if (f->result)
		i = ft_strlen(f->result);
	if (i < f->flags[1])
	{
		if (f->flags[4] == 1)
			ft_minus_char(f);
		else
			ft_zero_char(f);
	}
	else
		ft_display_result(f);
}
