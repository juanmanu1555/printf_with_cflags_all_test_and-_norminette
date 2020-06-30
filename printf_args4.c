/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_args4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivas-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/31 10:00:49 by jrivas-z          #+#    #+#             */
/*   Updated: 2020/06/30 20:03:03 by jrivas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_arg_unsigned(t_config *config, va_list *args)
{
	t_data_config		data_config;
	unsigned long		numb;
	long long int		numb2;

	t_data_config_default(&data_config);
	get_width_precision_from_va_args(config, args);
	if (config->precision < -1)
		config->precision = -1;
	numb = va_arg(*args, unsigned long);
	numb2 = (long long int)numb;
	is_numb_nev_to_pos(&numb2, &data_config);
	numb = (unsigned long)numb2;
	data_config.len = ft_nbrlen(numb);
	data_config.string_to_print = ft_itoa_custom(numb2,
			data_config.len);
	printf_printing_arg(config, &data_config,
			arg_config_to_print(config, data_config.is_negative,
				&data_config));
}

void	printf_arg_char(t_config *config, va_list *args)
{
	t_data_config	data_config;
	int				c;

	t_data_config_default(&data_config);
	get_width_precision_from_va_args(config, args);
	data_config.string_to_print = malloc(1);
	data_config.len = 1;
	if (config->precision < -1)
		config->precision = -1;
	c = va_arg(*args, int);
	data_config.string_to_print[0] = (c - 48) + '0';
	if (config->precision > data_config.len || config->precision == -1)
		config->precision = data_config.len;
	else if (config->precision < data_config.len)
		data_config.len = config->precision;
	if ((config->width == 0) || (config->width < config->precision))
		config->width = config->precision;
	printf_printing_arg(config, &data_config, 0);
}

void	printf_arg_module(t_config *config)
{
	t_data_config	data_config;

	t_data_config_default(&data_config);
	data_config.string_to_print = malloc(2);
	data_config.string_to_print[0] = '%';
	data_config.string_to_print[1] = '\0';
	data_config.len = 1;
	if (config->precision < -1)
		config->precision = -1;
	if (config->precision > data_config.len || config->precision == -1)
		config->precision = data_config.len;
	else if (config->precision < data_config.len)
		data_config.len = config->precision;
	if ((config->width == 0) || (config->width < config->precision))
		config->width = config->precision;
	printf_printing_arg(config, &data_config, 0);
}
