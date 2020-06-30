/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivas-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 10:00:49 by jrivas-z          #+#    #+#             */
/*   Updated: 2020/06/30 20:02:03 by jrivas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct		s_config {
	int		width;
	int		width_len;
	char	width_char;
	int		precision;
	int		precision_len;
	char	flag;
	int		is_width_arg;
	int		is_precision_arg;
	int		is_minus;
	int		is_cero;
	int		is_width;
	int		is_precision;
	int		total_width;
	int		r_trf_arg;
}					t_config;

typedef struct		s_data_config {
	int		len;
	char	*string_to_print;
	int		z;
	int		j;
	int		is_negative;
}					t_data_config;

int					ft_printf(const char *s1, ...);
int					ft_transform_data(char *s1,
		t_config *config, va_list *args);
int					ft_transform_arg(int *index, char *s1,
		t_config *config, va_list *args);
int					regex_validate(int *index, char *s1, t_config *config);
void				print_arg_with_minus_true(t_config *config,
		t_data_config *data_config, int ceros);
void				print_arg_with_minus_false(t_config *config,
		t_data_config *data_config, int ceros);
int					arg_config_to_print(t_config *config, int is_negative,
		t_data_config *data_config);
char				*ft_strinv(char *s1);
char				*ft_utohex(unsigned long int numb, char flag);
char				*create_malloc_char_pointer_null (char *s1);
char				*create_hexa_array(char flag);
void				convert_to_hexa(char *s1, char *hexa_array,
		unsigned long int numb);
void				printf_arg_width_is_high(t_config *config,
		t_data_config *data_config, int ceros);
void				printf_arg_width_is_low(t_config *config,
		t_data_config *data_config, int ceros);
void				printf_printing_arg(t_config *config,
		t_data_config *data_config, int ceros);
void				printf_arg_hex(t_config *config, va_list *args);
void				get_number_in_range(int *index, char *s1,
		int *property, int *property_len);
int					validate_cero_or_minus(int *index,
		char *s1, t_config *config);
int					validate_width(int *index, char *s1, t_config *config);
int					validate_precision(int *index, char *s1,
		t_config *config);
int					validate_flag(int *index, char *s1, t_config *config);
void				get_width_precision_from_va_args(t_config *config,
		va_list *args);
void				print_arg_with_null_value(t_config *config);
int					config_have_0_or_minus(int *index,
		char *s1, t_config *config);
int					config_is_width_arg(int *index,
		char *s1, t_config *config);
int					config_have_precision(int *index,
		char *s1, t_config *config);
void				print_string(int *j, t_data_config *data_config);
void				print_prefix_when_p_flag(t_config *config);
int					get_precision_real(t_config *config);
void				config_real_width_and_print(t_config *config, int pre);
void				t_config_default(t_config *config);
void				t_data_config_default(t_data_config *data_config);
void				is_numb_nev_to_pos(long long int *numb,
		t_data_config *data_config);
void				printf_arg_int(t_config *config, va_list *args);
char				*ft_itoa_custom (long long int numb, int len);
void				printf_arg_string(t_config *config, va_list *args);
void				printf_arg_unsigned(t_config *config, va_list *args);
void				printf_arg_char(t_config *config, va_list *args);
void				printf_arg_module(t_config*config);
int					ft_nbrlen(long numb);
#endif
