/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:38:18 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/17 14:41:01 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *l);
void	ft_putnbr(int nb, int *l);
void	ft_hex(char x, unsigned int d, int *l);
void	putadd(void *d, int *l);
void	ft_putstr(char *str, int *l);
void	ft_putu(unsigned int n, int *len);

#endif