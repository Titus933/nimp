/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/18 06:33:54 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len)
{
	int		real_len;
	int		i;
	char	*s1;

	real_len = 0;
	i = 0;
	while (ws[i] != '\0' && (int)len >= ft_wcharlen(ws[i]))
	{
		len -= ft_wcharlen(ws[i]);
		real_len += ft_wcharlen(ws[i]);
		i++;
	}
	s1 = ft_wchar_in_char(ws);
	return (ft_strsub_with_free(s1, start, real_len));
}

char		*ft_strsub_with_free(char const *s, unsigned int start,
	size_t len)
{
	char	*s1;
	char	*tmp;
	int		i;

	tmp = NULL;
	if (!s)
		return (NULL);
	tmp = (char*)s;
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
	free(tmp);
	return (s1);
}
