/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:31:52 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_s(t_list *f, va_list *ap)
{
	static int	mask_s[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};

	ft_apply_mask(f, mask_s);
	if (f->flags[10] == 1)
	{
		f->wresult = va_arg(*ap, wchar_t*);
		ft_printf_char(f);
		return (0);
	}
	else
		f->result = va_arg(*ap, char*);
	if (f->result == 0)
		f->result = "(null)";
	ft_printf_char(f);
	return (0);
}

int			ft_printf_ws(t_list *f, va_list *ap)
{
	static int	mask_s[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};

	ft_apply_mask(f, mask_s);
	f->wresult = va_arg(*ap, wchar_t*);
	ft_printf_char(f);
	return (0);
}
