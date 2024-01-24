/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:29:22 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/12 17:25:17 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	int			basamak;
	long int	new;

	new = n;
	basamak = basamak_sayar(n);
	if (n < 0)
	{
		new = new * -1;
		basamak++;
	}
	str = (char *) malloc((basamak + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[basamak] = 0;
	while (basamak > 0)
	{
		str[basamak - 1] = new % 10 + '0';
		new /= 10;
		basamak--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/* int main()
{

	printf("%s",ft_itoa(0));

	return (0);
	 
} */