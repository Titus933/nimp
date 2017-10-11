/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:39:30 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_modifier_d(t_list *f, va_list *ap)
{
	intmax_t	data;
	uintmax_t	data_max;

	data = 0;
	if (f->flags[12] == 1)
		data = (intmax_t)(va_arg(*ap, ssize_t));
	else if (f->flags[11] == 1)
		data = (va_arg(*ap, intmax_t));
	else if (f->flags[9] == 1)
		data = (intmax_t)(va_arg(*ap, long long));
	else if (f->flags[10] == 1)
		data = (intmax_t)(va_arg(*ap, long));
	else if (f->flags[8] == 1)
		data = (intmax_t)((short)va_arg(*ap, int));
	else if (f->flags[7] == 1)
		data = (intmax_t)((char)va_arg(*ap, int));
	else if (f->spe == 'D')
		data = (intmax_t)(va_arg(*ap, long));
	else if (f->spe == 'd' || f->spe == 'i')
		data = (intmax_t)(va_arg(*ap, int));
	data_max = ft_sign(f, data);
	return (ft_itoa_base(data_max, 10));
}

int		ft_printf_d(t_list *f, va_list *ap)
{
	static int	mask_d[13] = {0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	ft_apply_mask(f, mask_d);
	f->result = ft_modifier_d(f, ap);
	ft_printf_numb(f);
	return (0);
}

int		ft_printf_wd(t_list *f, va_list *ap)
{
	static int	mask_wd[13] = {0, 0, 2, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1};

	ft_apply_mask(f, mask_wd);
	f->result = ft_modifier_d(f, ap);
	ft_printf_numb(f);
	return (0);
}
