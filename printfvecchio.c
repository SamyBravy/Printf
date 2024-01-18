/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:09:29 by marvin            #+#    #+#             */
/*   Updated: 2023/11/03 18:38:31 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_symb(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

char	*p_to_str(void *ptr)
{
	uintptr_t	n;

	n = (uintptr_t) ptr;
	return (ft_strjoin("0x", ft_itoa(n)));
}

char	*ex_to_str(unsigned int n, int upper)
{
	if (!upper)
		return (ft_convert_base(ft_itoa(n), "0123456789", "012345679abcdef"));
	return (ft_convert_base(ft_itoa(n), "0123456789", "012345679ABCDEF"));
}

char	*ret_or_var(char c, va_list args)
{
	if (c == 's')
		return (ft_strdup(va_arg(args, char *)));
	if (c == 'p')
		return (p_to_str(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (c == 'u')
		return (ft_itoa(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ex_to_str(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ex_to_str(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (ft_strdup("%"));
	return (NULL);
}

void	set_flags(char *flags, const char *str)
{
	ft_bzero(flags, 5);
	if (ft_strchr(str, '.'))
		flags[0] = '.';
	if (ft_strchr(str, '#'))
		flags[1] = '#';
	if (ft_strchr(str, ' '))
		flags[2] = ' ';
	if (ft_strchr(str, '+'))
		flags[2] = '+';
	if (ft_strchr(str, '-'))
		flags[3] = '-';
	if (ft_strchr(str, '-'))
		flags[3] = '0';
}

char	*ret_mod_var(const char *str, int *i, va_list args)
{
	int		j;
	char	*str_var;
	char	flags[5];

	j = 0;
	while (!is_symb(str[*i + j]) && str[*i + j])
		j++;
	if (str[*i + j] == '\0')
		return (NULL);
	str_var = ret_or_var(str[*i + j], args);
	if (!str_var)
		return (NULL);
	set_flags(flags, ft_substr(str, *i, j));
	// mod_var(str_var, flags);
	*i += j;
	return (str_var);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;
	int		i;
	char	*temp;

	length = 0;
	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			length++;
		}
		else
		{
			if (str[i] == 'c')
			{
				ft_putchar_fd((char) va_arg(args, int), 1);
				length++;
			}
			else
			{
				temp = ret_mod_var(&str[i], &i, args);
				ft_putstr_fd(temp, 1);
				length += ft_strlen(temp);
				free(temp);
			}
		}
		i++;
	}
	va_end(args);
	return (length);
}

