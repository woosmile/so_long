/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:02:11 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/13 15:40:42 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *s, ...);
int	print_char(char c, int *len);
int	print_str(char *s, int *len);
int	print_addr(void *addr, int *len);
int	print_nbr(int n, int *len);
int	print_nbr_u(unsigned int n, int *len);
int	print_hex(unsigned int n, int *len, char c);

#endif
