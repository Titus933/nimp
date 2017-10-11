/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:31:36 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_p(t_list *f, va_list *ap)
{
	static int	mask_p[13] = {0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

	f->flags[2] = 1;
	ft_apply_mask(f, mask_p);
	f->result = ft_strlwr(ft_itoa_base((uintmax_t)va_arg(*ap, void*), 16));
	if (f->flags[0] == -1 && f->result[0] == '0')
	{
		ft_buf('0', f);
		ft_buf('x', f);
	}
	else
		ft_printf_numb(f);
	return (0);
}
