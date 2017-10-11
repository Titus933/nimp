/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 04:22:08 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 05:06:19 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_apply_mask(t_list *f, int *mask)
{
	int		i;

	i = 2;
	while (i < 14)
	{
		f->flags[i] = f->flags[i] * mask[i];
		i++;
	}
}

int			ft_printf_char(t_list *f)
{
	if (f->flags[0] != 0 && (f->spe != 'C' ||
				(f->spe == 'c' && f->flags[10] == 1)))
		ft_precision_str(f);
	else if (f->spe == 'S' || (f->spe == 's' && f->flags[10] == 1)
		|| f->spe == 'C' || (f->spe == 'c' && f->flags[10] == 1))
		f->result = ft_wchar_in_char(f->wresult);
	if (f->flags[1] > 0)
		ft_width_char(f);
	if (f->flags[1] == 0)
		ft_display_result(f);
	return (1);
}

int			ft_printf_numb(t_list *f)
{
	int	i;

	i = -1;
	if (f->flags[0] == -1 && f->result[0] == '0' && !(f->flags[2] == 1 &&
		(f->spe == 'o' || f->spe == 'O' || f->spe == 'p')))
		f->result = "\0";
	if (f->flags[1] > 0)
		ft_width_numb(f);
	else if (f->flags[1] == 0 && f->flags[0] > 0)
		ft_precision_wo_width(f);
	if (f->flags[0] <= 0 && f->flags[1] == 0)
		ft_space_plus_sharp(f);
	while (f->result[++i] != '\0' && f->flags[1] == 0)
		ft_buf(f->result[i], f);
	ft_end(f);
	return (1);
}
