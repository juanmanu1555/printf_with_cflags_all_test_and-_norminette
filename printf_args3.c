/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_args3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivas-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/31 10:00:49 by jrivas-z          #+#    #+#             */
/*   Updated: 2020/06/30 20:02:16 by jrivas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(long numb)
{
	int z;

	if (numb >= 0)
		z = 1;
	else
		return (0);
	while (numb > 9)
	{
		numb /= 10;
		z++;
	}
	return (z);
}

void	is_numb_nev_to_pos(long long *numb,
		t_data_config *data_config)
{
	if (*numb < 0)
	{
		*numb *= -1;
		data_config->is_negative = 1;
	}
}

void	printf_arg_int(t_config *config, va_list *args)
{
	t_data_config		data_config;
	long				numb;
	long long			numb2;

	t_data_config_default(&data_config);
	get_width_precision_from_va_args(config, args);
	if (config->precision < -1)
		config->precision = -1;
	numb = (long)va_arg(*args, int);
	numb2 = (long long)numb;
	is_numb_nev_to_pos(&numb2, &data_config);
	numb = (long)numb2;
	data_config.len = ft_nbrlen(numb);
	data_config.string_to_print = ft_itoa_custom(numb2,
			data_config.len);
	printf_printing_arg(config, &data_config,
			arg_config_to_print(config, data_config.is_negative, &data_config));
}

char	*ft_itoa_custom(long long int numb, int len)
{
	int		z;
	char	*s1;

	if (!(s1 = (char *)malloc(len + 1)))
		return (NULL);
	z = len;
	while (len)
	{
		len--;
		s1[len] = numb > 9 ? (numb % 10) + '0' : (numb + '0');
		numb /= 10;
	}
	s1[z] = '\0';
	return (s1);
}

void	printf_arg_string(t_config *config, va_list *args)
{
	t_data_config		data_config;
	char				*s1;

	t_data_config_default(&data_config);
	get_width_precision_from_va_args(config, args);
	if (config->precision < -1)
		config->precision = -1;
	if ((s1 = va_arg(*args, char *)) == NULL)
		s1 = ft_strdup("(null)");
	data_config.string_to_print = ft_strdup(s1);
	data_config.len = (int)ft_strlen(data_config.string_to_print);
	if (config->precision > data_config.len || config->precision == -1)
		config->precision = data_config.len;
	else if (config->precision < data_config.len)
		data_config.len = config->precision;
	if ((config->width == 0) || (config->width < config->precision))
		config->width = config->precision;
	printf_printing_arg(config, &data_config, 0);
}
