/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ou.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:39:54 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_modifier_u_o(t_list *f, va_list *ap)
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
		data = (uintmax_t)(unsigned short)va_arg(*ap, unsigned int);
	else if (f->flags[7] == 1)
		data = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else
		data = (uintmax_t)va_arg(*ap, unsigned int);
	if (f->spe == 'u')
		return (ft_itoa_base(data, 10));
	if (f->spe == 'o')
		return (ft_itoa_base(data, 8));
	return (NULL);
}

int			ft_printf_u(t_list *f, va_list *ap)
{
	static int	mask_u[13] = {0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	ft_apply_mask(f, mask_u);
	f->result = ft_modifier_u_o(f, ap);
	ft_printf_numb(f);
	return (0);
}

int			ft_printf_o(t_list *f, va_list *ap)
{
	static int	mask_o[13] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	ft_apply_mask(f, mask_o);
	f->result = ft_modifier_u_o(f, ap);
	if (f->flags[0] == -1 && f->result[0] != '0' && f->flags[2] == 1)
		f->flags[0] = 0;
	ft_printf_numb(f);
	return (0);
}
