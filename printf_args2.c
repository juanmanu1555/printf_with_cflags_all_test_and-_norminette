/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_args2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivas-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 10:10:49 by jrivas-z          #+#    #+#             */
/*   Updated: 2020/06/17 16:02:29 by jrivas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(int *j, t_data_config *data_config)
{
	while (*j < data_config->len - data_config->is_negative)
	{
		ft_putchar(data_config->string_to_print[*j]);
		*j += 1;
	}
}

void	print_prefix_when_p_flag(t_config *config)
{
	if (config->flag == 'p')
	{
		ft_putchar('0');
		ft_putchar('x');
	}
}

void	print_arg_with_minus_true(t_config *config,
		t_data_config *data_config, int ceros)
{
	int z;
	int j;

	j = 0;
	z = 0;
	data_config->is_negative == 1 ? ft_putchar('-') : 0;
	while (ceros > 0)
	{
		ft_putchar('0');
		ceros--;
		z++;
	}
	if (config->precision > 0)
	{
		print_prefix_when_p_flag(config);
		print_string(&j, data_config);
	}
	z = 0;
	data_config->len = config->flag == 'p' ?
		config->width - config->precision - 2 :
		config->width - config->precision;
	while (z++ < data_config->len)
	{
		ft_putchar(config->width_char);
	}
}

void	print_arg_with_minus_false(t_config *config,
		t_data_config *data_config, int ceros)
{
	int z;
	int j;
	int len_width_char;

	j = 0;
	z = 0;
	len_width_char = config->flag == 'p' ?
		(config->width - config->precision - 2) :
		(config->width - config->precision);
	if (config->width_char == '0' && data_config->is_negative == 1)
		ft_putchar('-');
	while (z++ < len_width_char)
		ft_putchar(config->width_char);
	if (config->width_char == ' ' && data_config->is_negative == 1)
		ft_putchar('-');
	print_prefix_when_p_flag(config);
	z = 0;
	while (ceros > 0)
	{
		ft_putchar('0');
		ceros--;
	}
	if (config->precision > 0)
		print_string(&j, data_config);
}
