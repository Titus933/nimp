/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 06:49:16 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_wo_width(t_list *f)
{
	int	len;
	int	prec;

	prec = f->flags[0];
	len = ft_strlen(f->result);
	ft_space_plus_sharp(f);
	while (prec > len-- && len > 0)
		prec--;
	if (f->flags[0] > f->flags[1] + ft_strlen(f->result))
	{
		while (++len < prec)
			ft_buf('0', f);
	}
}

void	ft_precision_numb(t_list *f, int len_zero)
{
	int	len;

	len = ft_strlen(f->result);
	if (f->flags[5] == 1 || f->flags[6] == 1 || f->sign == '-'
			|| (f->flags[2] == 1 && f->flags[0] <= len && (f->spe == 'o'
					|| f->spe == 'O')))
		len_zero--;
	if (f->flags[2] == 1 && (f->spe == 'x' || f->spe == 'X'
				|| f->spe == 'p'))
		len_zero = len_zero - 2;
	while (f->flags[0] > len++)
		len_zero--;
	if (f->flags[0] < f->flags[1])
	{
		while (len_zero-- > 0)
		{
			if (f->flags[3] == 1 && f->flags[0] == 0)
				ft_buf('0', f);
			else
				ft_buf(' ', f);
		}
	}
}

void	ft_zero_numb(t_list *f)
{
	int		i;
	int		len;
	int		len_zero;

	i = -1;
	len = ft_strlen(f->result);
	len_zero = f->flags[1] - len;
	if (f->flags[3] == 1)
	{
		ft_space_plus_sharp(f);
		ft_precision_numb(f, len_zero);
	}
	else
	{
		ft_precision_numb(f, len_zero);
		ft_space_plus_sharp(f);
	}
	while (f->flags[0] > len++)
		ft_buf('0', f);
	while (f->result[++i] != '\0')
		ft_buf(f->result[i], f);
}

void	ft_minus_numb(t_list *f)
{
	int		i;
	int		len;
	int		len_zero;

	i = -1;
	len_zero = f->flags[1] - ft_strlen(f->result);
	len = ft_strlen(f->result);
	f->flags[3] = 0;
	ft_space_plus_sharp(f);
	while (f->flags[0] > len++)
		ft_buf('0', f);
	while (f->result[++i] != '\0')
		ft_buf(f->result[i], f);
	ft_precision_numb(f, len_zero);
}

void	ft_width_numb(t_list *f)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(f->result);
	if (len < f->flags[1])
	{
		if (f->flags[4] == 1)
			ft_minus_numb(f);
		else
			ft_zero_numb(f);
	}
	else
	{
		ft_space_plus_sharp(f);
		while (f->flags[0] > len++)
			ft_buf('0', f);
		while (f->result[++i] != '\0')
			ft_buf(f->result[i], f);
	}
}
