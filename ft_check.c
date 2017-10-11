/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 07:30:44 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_flags(t_list *f)
{
	if (f->frmt[f->index] == '#')
		f->flags[2] = 1;
	else if (f->frmt[f->index] == '0')
		f->flags[3] = 1;
	else if (f->frmt[f->index] == '-')
		f->flags[4] = 1;
	else if (f->frmt[f->index] == '+')
		f->flags[5] = 1;
	else if (f->frmt[f->index] == ' ')
		f->flags[6] = 1;
	f->index++;
}

void		ft_check_precision(t_list *f)
{
	int		i;
	char	*str;

	if (f->frmt[f->index] == '.')
	{
		f->flags[0] = 0;
		i = ++f->index;
		while (ft_isdigit(f->frmt[f->index]))
			f->index++;
		if (f->index - i > 0)
		{
			str = ft_strsub(f->frmt, i, f->index - i);
			f->flags[0] = ft_atoi((const char*)str);
			free(str);
		}
		if (f->flags[0] == 0)
			f->flags[0] = -1;
	}
}

void		ft_check_width(t_list *f)
{
	int		i;
	char	*str;

	i = f->index;
	while (ft_isdigit(f->frmt[f->index]))
		f->index++;
	if (f->index - i > 0)
	{
		f->flags[1] = 0;
		str = ft_strsub(f->frmt, i, f->index - i);
		f->flags[1] = ft_atoi((const char*)str);
		free(str);
	}
}

void		ft_check_modifier(t_list *f)
{
	while (f->frmt[f->index] == 'h' || f->frmt[f->index] == 'l' ||
			f->frmt[f->index] == 'j' || f->frmt[f->index] == 'z')
	{
		if (f->frmt[f->index] == 'h' && f->frmt[f->index + 1] == 'h')
		{
			f->flags[7] = 1;
			f->index++;
		}
		else if (f->frmt[f->index] == 'h')
			f->flags[8] = 1;
		if (f->frmt[f->index] == 'l' && f->frmt[f->index + 1] == 'l')
		{
			f->flags[9] = 1;
			f->index++;
		}
		else if (f->frmt[f->index] == 'l')
			f->flags[10] = 1;
		if (f->frmt[f->index] == 'j')
			f->flags[11] = 1;
		if (f->frmt[f->index] == 'z')
			f->flags[12] = 1;
		f->index++;
	}
}

int			ft_check(t_list *f)
{
	ft_flags_init(f);
	while (f->frmt[f->index] == '#' || f->frmt[f->index] == '0'
			|| f->frmt[f->index] == '-' || f->frmt[f->index] == '+'
			|| f->frmt[f->index] == ' ' || f->frmt[f->index] == 'h'
			|| f->frmt[f->index] == 'l' || f->frmt[f->index] == 'j'
			|| f->frmt[f->index] == 'z' || f->frmt[f->index] == '.'
			|| ft_isdigit(f->frmt[f->index]))
	{
		if (f->frmt[f->index] == '#' || f->frmt[f->index] == '0'
				|| f->frmt[f->index] == '-' || f->frmt[f->index] == '+'
				|| f->frmt[f->index] == ' ')
			ft_check_flags(f);
		if (ft_isdigit(f->frmt[f->index]) && f->frmt[f->index] != '0')
			ft_check_width(f);
		if (f->frmt[f->index] == '.')
			ft_check_precision(f);
		ft_check_modifier(f);
	}
	if (f->index == ft_strlen(f->frmt))
		return (-1);
	return (0);
}
