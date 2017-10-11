/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_undefined.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:39:38 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_undefined(t_list *f)
{
	static int	mask_und[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};
	char		c[2];

	f->flags[0] = 0;
	if (f->spe == 0)
	{
		f->ret = 0;
		return (f->ret);
	}
	c[0] = f->spe;
	c[1] = '\0';
	f->result = c;
	ft_apply_mask(f, mask_und);
	return (ft_printf_char(f));
}
