/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_config_validations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivas-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:20:25 by jrivas-z          #+#    #+#             */
/*   Updated: 2020/06/15 17:42:45 by jrivas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		config_have_0_or_minus(int *index, char *s1, t_config *config)
{
	if (s1[*index] == '0' || s1[*index] == '-')
	{
		if (!(validate_cero_or_minus(index, s1, config)))
			return (0);
	}
	return (1);
}

int		config_is_width_arg(int *index, char *s1, t_config *config)
{
	if (s1[*index] == '*')
	{
		config->is_width_arg = 1;
		*index += 1;
	}
	else
	{
		if (s1[*index] >= '1' && s1[*index] <= '9')
		{
			if (!(validate_width(index, s1, config)))
				return (0);
		}
	}
	return (1);
}

int		config_have_precision(int *index, char *s1, t_config *config)
{
	if (s1[*index] == '.')
	{
		*index += 1;
		config->precision = 0;
		if (s1[*index] == '*')
		{
			config->is_precision_arg = 1;
			*index += 1;
		}
		else if (s1[*index] && (s1[*index] >= '0' && s1[*index] <= '9'))
		{
			if (!(validate_precision(index, s1, config)))
				return (0);
		}
		else
		{
			if (!(validate_flag(index, s1, config)))
				return (0);
			return (1);
		}
	}
	return (2);
}
