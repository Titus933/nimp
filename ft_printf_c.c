/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:29:55 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_modifier_wc(t_list *f, va_list *ap)
{
	wchar_t		wc;
	wchar_t		ws[2];

	wc = va_arg(*ap, wchar_t);
	ws[0] = wc;
	ws[1] = '\0';
	if (ws[0] < 0 && ws[0] > 55295 && ws[0] < 57344 && ws[0] > 1114111)
	{
		f->ret = -1;
		return (0);
	}
	f->wresult = ws;
	ft_printf_char(f);
	return (0);
}

int		ft_printf_c(t_list *f, va_list *ap)
{
	static int	mask_c[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};
	char		c;
	char		s[2];

	ft_apply_mask(f, mask_c);
	if (f->flags[10] == 1)
		return (ft_modifier_wc(f, ap));
	else
	{
		c = (char)va_arg(*ap, int);
		if (c == 0 && f->flags[0] == -1)
			f->flags[0] = 0;
		s[0] = c;
		s[1] = '\0';
		f->result = s;
		ft_printf_char(f);
	}
	if (f->result[0] == 0)
		ft_buf('\0', f);
	return (0);
}

int		ft_printf_wc(t_list *f, va_list *ap)
{
	static int	mask_c[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};

	ft_apply_mask(f, mask_c);
	return (ft_modifier_wc(f, ap));
}
