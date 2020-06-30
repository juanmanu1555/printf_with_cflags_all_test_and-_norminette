/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivas-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/31 10:00:49 by jrivas-z          #+#    #+#             */
/*   Updated: 2020/06/30 19:56:36 by jrivas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strinv(char *s1)
{
	long long int	len;
	char			*s2;
	size_t			j;

	j = 0;
	len = ft_strlen(s1);
	if (!(s2 = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (len > 0)
	{
		s2[j] = s1[len - 1];
		j++;
		len--;
	}
	s2[j] = 0;
	return (s2);
}

char	*ft_utohex(unsigned long int numb, char flag)
{
	char *s1;
	char *s2;
	char *hexa_array;

	s1 = NULL;
	if (numb == 0)
		return (create_malloc_char_pointer_null(s1));
	if (!(s1 = (char *)malloc((8 + 1) * sizeof(char))))
		return (NULL);
	hexa_array = create_hexa_array(flag);
	convert_to_hexa(s1, hexa_array, numb);
	s2 = ft_strinv(s1);
	free(s1);
	return (s2);
}

char	*create_malloc_char_pointer_null(char *s1)
{
	s1 = malloc(2);
	s1[0] = '0';
	s1[1] = '\0';
	return (s1);
}

char	*create_hexa_array(char flag)
{
	if (flag == 'x' || flag == 'p')
		return (ft_strdup("0123456789abcdef"));
	return (ft_strdup("0123456789ABCDEF"));
}

void	convert_to_hexa(char *s1, char *hexa_array, unsigned long int numb)
{
	unsigned long int	res;
	unsigned long int	div;
	int					j;

	res = numb;
	div = 0;
	j = 0;
	while (res > 0)
	{
		if (numb > 15)
		{
			div = numb % 16;
			numb /= 16;
			s1[j] = hexa_array[div];
			res = numb;
		}
		else
		{
			div = numb;
			s1[j] = hexa_array[div];
			res = 0;
		}
		j++;
	}
	s1[j] = '\0';
}
