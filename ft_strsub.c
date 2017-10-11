/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/18 06:33:54 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*tmp;
	int		i;

	tmp = NULL;
	if (!s)
		return (NULL);
	s1 = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!s1)
		return (NULL);
	s1[len] = '\0';
	while (len > 0)
	{
		s1[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (s1);
}
