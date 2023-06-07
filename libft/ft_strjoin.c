/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:14:13 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/17 19:14:24 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char				*str;
	size_t				len1;
	size_t				len2;
	unsigned long long	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2 != 0)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = 0;
	free(s1);
	return (str);
}
