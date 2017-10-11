/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wowu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:39:47 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_modifier_wu_wo(t_list *f, va_list *ap)
{
	intmax_t	data;

	if (f->flags[12] == 1)
		data = (uintmax_t)va_arg(*ap, size_t);
	else if (f->flags[11] == 1)
		data = va_arg(*ap, uintmax_t);
	else if (f->flags[9] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (f->flags[10] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long);
	else if (f->flags[8] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned int);
	else if (f->flags[7] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned int);
	else
		data = (uintmax_t)va_arg(*ap, unsigned long);
	if (f->spe == 'U')
		return (ft_itoa_base(data, 10));
	if (f->spe == 'O')
		return (ft_itoa_base(data, 8));
	return (NULL);
}

int			ft_printf_wu(t_list *f, va_list *ap)
{
	static int	mask_wu[13] = {0, 0, 2, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1};

	ft_apply_mask(f, mask_wu);
	f->result = ft_modifier_wu_wo(f, ap);
	ft_printf_numb(f);
	return (0);
}

int			ft_printf_wo(t_list *f, va_list *ap)
{
	static int	mask_wo[13] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	ft_apply_mask(f, mask_wo);
	f->result = ft_modifier_wu_wo(f, ap);
	if (f->flags[0] == -1 && f->result[0] != '0' && f->flags[2] == 1)
		f->flags[0] = 0;
	ft_printf_numb(f);
	return (0);
}
