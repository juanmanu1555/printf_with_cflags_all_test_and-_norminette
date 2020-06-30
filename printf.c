/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivas-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:00:49 by jrivas-z          #+#    #+#             */
/*   Updated: 2020/06/17 18:56:07 by jrivas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		regex_validate(int *index, char *s1, t_config *config)
{
	int r_chavepre;

	if (config_have_0_or_minus(index, s1, config) == 0)
		return (0);
	if (config_is_width_arg(index, s1, config) == 0)
		return (0);
	r_chavepre = config_have_precision(index, s1, config);
	if (r_chavepre == 0 || r_chavepre == 1)
		return (r_chavepre);
	if (!(validate_flag(index, s1, config)))
		return (0);
	return (1);
}

int		ft_transform_arg(int *index, char *s1, t_config *config, va_list *args)
{
	if (regex_validate(index, s1, config) == 1)
	{
		if (config->flag == '%')
			printf_arg_module(config);
		if (config->flag == 'c')
			printf_arg_char(config, args);
		if (config->flag == 'u')
			printf_arg_unsigned(config, args);
		if (config->flag == 's')
			printf_arg_string(config, args);
		if (config->flag == 'd' || config->flag == 'i')
			printf_arg_int(config, args);
		if (config->flag == 'x' || config->flag == 'X' || config->flag == 'p')
			printf_arg_hex(config, args);
		return (config->width);
	}
	else
		return (-1);
	return (0);
}

int		ft_transform_data(char *s1, t_config *config, va_list *args)
{
	int index;
	int arg_count;
	int total_width;

	arg_count = 0;
	total_width = 0;
	index = 0;
	while (s1[index])
	{
		if (s1[index] == '%')
		{
			index++;
			arg_count++;
			config->r_trf_arg = ft_transform_arg(&index, s1, config, args);
			if (config->r_trf_arg == -1)
				return (total_width - arg_count + 1);
			total_width += config->r_trf_arg;
			t_config_default(config);
		}
		else
			ft_putchar(s1[index]);
		index++;
		total_width += 1;
	}
	return (total_width - arg_count);
}

int		ft_printf(const char *s1, ...)
{
	int				total;
	t_config		config;
	va_list			args;

	total = 0;
	t_config_default(&config);
	va_start(args, s1);
	total = ft_transform_data((char *)s1, &config, &args);
	va_end(args);
	return (total);
}
