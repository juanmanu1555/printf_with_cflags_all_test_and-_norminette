/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivas-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 10:00:49 by jrivas-z          #+#    #+#             */
/*   Updated: 2020/06/30 19:57:39 by jrivas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width_precision_from_va_args(t_config *config, va_list *args)
{
	if (config->is_width_arg == 1)
	{
		config->width = va_arg(*args, int);
		if (config->width < 0)
		{
			config->width *= -1;
			config->is_minus = 1;
			config->width_char = ' ';
		}
	}
	if (config->is_precision_arg == 1)
		config->precision = va_arg(*args, int);
}

void	print_arg_with_null_value(t_config *config)
{
	int	precision_real;
	int	spaces;
	int	z;

	z = 0;
	spaces = 0;
	precision_real = 0;
	if (config->flag == 'p')
	{
		precision_real = get_precision_real(config);
		spaces = config->width - precision_real;
		while (z < spaces)
		{
			ft_putchar(config->width_char);
			z++;
		}
		ft_putchar('0');
		ft_putchar('x');
		config_real_width_and_print(config, precision_real);
	}
}

int		get_precision_real(t_config *config)
{
	if (config->precision == -1)
		return (3);
	else if (config->precision == 0)
		return (2);
	return (config->precision + 2);
}

void	config_real_width_and_print(t_config *config, int pre)
{
	int z;

	z = 0;
	if (config->precision > 0)
	{
		if (config->width < config->precision)
			config->width = pre;
		while (z < config->precision)
		{
			ft_putchar('0');
			z++;
		}
	}
	else if (config->precision == -1)
	{
		ft_putchar('0');
		if (config->width < 3)
			config->width = 3;
	}
	else
	{
		if (config->width < 3)
			config->width = 2;
	}
}
