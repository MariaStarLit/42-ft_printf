/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:40:41 by mde-avel          #+#    #+#             */
/*   Updated: 2022/12/06 20:35:19 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * It's a function that takes a string and a variable number of arguments, 
 * and prints the string with.
 * the arguments inserted in the appropriate places
 * 
 * @param ch The character that will be used to determine what to print.
 * @param var The va_list variable that will hold the values of the arguments.
 * @param len the length of the string
 * 
 * @return The number of characters printed.
 */

static int	escreve(const char ch, va_list var, size_t	len)
{
	if (!var)
		return (0);
	if (ch == 'c')
		len = ft_putchar(va_arg(var, int));
	if (ch == 's')
		len = ft_putstr(va_arg(var, char *));
	if (ch == 'd' || ch == 'i')
		len = ft_putnbr(va_arg(var, int));
	if (ch == 'u')
		len = ft_putnbru(va_arg(var, unsigned int));
	if (ch == 'x' || ch == 'X')
		len = ft_puthex(va_arg(var, unsigned int), ch);
	if (ch == 'p')
		len = ft_putvod(va_arg(var, t_ull));
	if (ch == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	var;
	size_t	i;
	size_t	cont;

	va_start(var, s);
	i = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			cont += escreve(s[i], var, cont);
		}
		else
		{
			cont += ft_putchar(s[i]);
		}
		i++;
	}
	va_end(var);
	return (cont);
}

// int	main(void)
// {
// 	char			*p;
// 	int				ret;
// 	t_ull			nb;

// 	nb = 21474838;
// 	p = "Minhaf: |%p|";
// 	ret = ft_printf(p, nb);
// 	printf(" -> return: %d\n", ret);
// 	ret = printf("Printf: |%p|", nb);
// 	printf(" -> return: %d\n", ret);
// }
	//char	l; char			*fio;
	//l = 'l'; fio = NULL;