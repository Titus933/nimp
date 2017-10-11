/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_in_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 00:33:55 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwchar_in_char(wchar_t wchar, char *str, int i)
{
	int		size;

	size = ft_wcharlen(wchar);
	if (size == 1)
		str[i++] = wchar;
	else if (size == 2)
	{
		str[i++] = (wchar >> 6) + 0xC0;
		str[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		str[i++] = (wchar >> 12) + 0xE0;
		str[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		str[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		str[i++] = (wchar >> 18) + 0xF0;
		str[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		str[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		str[i++] = (wchar & 0x3F) + 0x80;
	}
	return (i);
}

char	*ft_wchar_in_char(wchar_t *ws)
{
	char	*str;
	int		i;
	int		k;
	int		len;

	if (!ws)
		return (0);
	i = 0;
	k = 0;
	len = ft_wbytelen(ws);
	str = (char*)malloc(sizeof(char) * len);
	str[len] = '\0';
	while (ws[k])
	{
		i = ft_putwchar_in_char(ws[k], str, i);
		k++;
	}
	return (str);
}
