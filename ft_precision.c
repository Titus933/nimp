/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 04:39:20 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_str(t_list *f)
{
	if (f->flags[0] == -1)
		f->result = "\0";
	else if (f->spe == 'S' || (f->spe == 's' && f->flags[10] == 1))
		f->result = ft_wstrsub(f->wresult, 0, f->flags[0]);
	else if (f->spe == 's')
		f->result = ft_strsub(f->result, 0, f->flags[0]);
}
