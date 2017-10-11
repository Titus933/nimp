/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 04:43:56 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 07:23:26 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_match_specifier(t_list *f, va_list *ap)
{
	int		i;
	t_spec	specifiers[16];

	i = 0;
	if (ft_check(f) == -1)
		return (-1);
	ft_init_specifiers(specifiers);
	f->spe = f->frmt[f->index];
	while (specifiers[i].c != f->spe && specifiers[i].c != 0)
		i++;
	if (specifiers[i].c == 0)
		return (ft_printf_undefined(f));
	return (specifiers[i].ptr(f, ap));
}
