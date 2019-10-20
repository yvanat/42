/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:29:28 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/12 14:50:08 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	if (!s || start > ft_strlen(s))
		return (NULL);
	i = 0;
	while ((i < len) && s[start + i])
		i++;
	if (!(new = malloc(sizeof(*new) * (i + 1))))
		return (NULL);
	i = 0;
	while ((i < len) && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
