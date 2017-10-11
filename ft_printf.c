/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 07:33:10 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_list		f;
	int			i;

	i = -1;
	f = ft_init();
	va_start(ap, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			f.frmt = (char*)&format[++i];
			if (ft_match_specifier(&f, &ap) == -1)
				break ;
			i = i + f.index;
		}
		else if (format[i] != '\0' && format[i] != '%')
			ft_buf(format[i], &f);
	}
	if (g_ibuf > 0)
		ft_display(&f);
	va_end(ap);
	return (f.ret);
}
