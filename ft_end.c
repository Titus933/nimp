/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:38:48 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_end(t_list *f)
{
	if (f->flags[0] >= 0 && f->result != NULL && f->result[0] != '\0' &&
		f->result[0] != '0')
	{
		if (f->spe == 'x' || f->spe == 'X' || f->spe == 'o'
		|| f->spe == 'O' || f->spe == 'u' || f->spe == 'U'
		|| f->spe == 'd' || f->spe == 'D' || f->spe == 'p'
		|| f->spe == 'S' || f->spe == 'i' || (f->spe == 's'
		&& f->flags[0] < ft_strlen(f->result) && f->flags[0] > 0)
		|| f->spe == 'C' || (f->spe == 'c' && f->flags[10] == 1))
			free(f->result);
	}
}
