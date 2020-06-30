/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strucs_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivas-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 10:00:49 by jrivas-z          #+#    #+#             */
/*   Updated: 2020/06/16 18:05:04 by jrivas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	t_config_default(t_config *config)
{
	config->width = 0;
	config->width_len = 0;
	config->width_char = ' ';
	config->precision = -1;
	config->precision_len = 0;
	config->flag = 0;
	config->is_width_arg = 0;
	config->is_precision_arg = 0;
	config->is_minus = 0;
	config->is_cero = 0;
	config->is_width = 0;
	config->is_precision = 0;
	config->total_width = 0;
	config->r_trf_arg = 0;
}

void	t_data_config_default(t_data_config *data_config)
{
	data_config->len = -1;
	data_config->string_to_print = NULL;
	data_config->z = -1;
	data_config->j = -1;
	data_config->is_negative = 0;
}
