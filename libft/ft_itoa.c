/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:31:36 by apodader          #+#    #+#             */
/*   Updated: 2023/01/23 14:27:03 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long long nbr)
{
	int			len;

	len = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*arr;
	int			len;
	long int	num;

	num = n;
	len = ft_nbrlen(n);
	if (n < 0)
	{
		len++;
		num *= -1;
	}
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	arr[len] = '\0';
	while (len--)
	{
		arr[len] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		arr[0] = '-';
	return (arr);
}
