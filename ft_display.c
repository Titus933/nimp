/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 06:13:18 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_result(t_list *f)
{
	int		i;
	size_t	len;

	if ((i = -1) && ((f->spe == 's' && f->flags[10] == 1)
				|| f->spe == 'S' ||
		(f->spe == 'c' && f->flags[10] == 1) || f->spe == 'C'))
	{
		if (f->result != NULL)
		{
			if (f->result[0] == '\0' && (f->spe == 'C' ||
				(f->spe == 'c' && f->flags[10] == 1)))
				ft_buf('\0', f);
			len = ft_strlen(f->result);
			while (len-- > 0)
				ft_buf(f->result[++i], f);
		}
		else if (f->flags[0] != -1)
			ft_buf_null(f);
	}
	else
	{
		while (f->result[++i] != '\0')
			ft_buf(f->result[i], f);
	}
	ft_end(f);
}
