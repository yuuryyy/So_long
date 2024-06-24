/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:33:16 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/17 20:46:07 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putformat(char format, va_list ap, int *len)
{
	if (format == '%')
		ft_putchar('%', len);
	else if (format == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if ((format == 'x' || format == 'X'))
		ft_hex(format, va_arg(ap, unsigned int), len);
	else if (format == 'u')
		ft_putu(va_arg(ap, unsigned int), len);
	else if (format == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (format == 'p')
		putadd(va_arg(ap, void *), len);
	else
		ft_putchar(format, len);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			len;
	va_list		ap;

	i = 0;
	len = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &len);
		else if (format[i] == '%' && format[i + 1])
		{
			putformat(format[i + 1], ap, &len);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

//int main()
//{
//	int	i;
//	i = -15;
//	printf("ayo%dub\n", 0567);
//}